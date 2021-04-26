#include<bits/stdc++.h>
using namespace std;

void ms(int *a,int s,int e){
    if(s==e){
        return;
    }
    //sort 2 sides
    int mid=(s+e)/2;
    ms(a,0,mid);
    ms(a,mid+1,e);
    //merge arrays
    int *temp=new int[e-s+1];
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    //copy back to original array
    for(int i=s;i<=e;i++){
        a[i]=temp[i-s];
    }
}

int main(){
    //       0 1 2 3 4 5 6 7  8
    int a[]={5,3,9,6,0,1,8,13,11};
    int n=sizeof(a)/sizeof(int);
    ms(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}