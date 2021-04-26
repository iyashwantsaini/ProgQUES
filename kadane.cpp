#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// ==method1==

void kadane(int *a,int n){
    int c=a[0]; //current sum
    int m=a[0]; //max sum
    for(int i=1;i<n;i++){
        if(c+a[i]>a[i]){
            c=a[i]+c;
        }else{
            c=a[i];
        }
        if(c>m){
            m=c;
        }
    }
    cout<<m;
}

int main(){
    int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(a)/sizeof(int);
    kadane(a,n);
}

// ==method2==

// void kadane(int *a,int n,int *s){
//     s[0]=a[0];
//     for(int i=1;i<n;i++){
//         if(a[i]+s[i-1]>a[i]){
//             s[i]=a[i]+s[i-1];
//         }else{
//             s[i]=a[i];
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<s[i]<<" ";
//     }
// }

// int main(){
//     int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
//     int n=sizeof(a)/sizeof(int);
//     int *s=new int[n]{};
//     kadane(a,n,s);
// }