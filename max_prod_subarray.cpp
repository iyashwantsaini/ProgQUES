#include<bits/stdc++.h>
using namespace std;

void mps(int *a,int n){
    int maxe=a[0];
    int mine=a[0];
    int ans=maxe;
    for(int i=1;i<n;i++){
        maxe=max(a[i],max(a[i]*maxe,a[i]*mine));
        mine=min(a[i],min(a[i]*maxe,a[i]*mine));
        ans=max(ans,maxe);
    }
    cout<<ans<<"\n";
}

int main(){
    int a[]={6,-3,-10,0,2};
    int n=sizeof(a)/sizeof(int);
    mps(a,n);
    return 0;
}