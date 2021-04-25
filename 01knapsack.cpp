#include<bits/stdc++.h>
using namespace std;

void solve(int w[],int v[],int c,int n,int ci,int cw,int cv,int &ans,int **dp){
    //base case
    if(cw>c){
        return;
    }
    if(ci>=n){
        return;
    }
    if(cw==c){
        if(ans<cv){
            ans=cv;
        }
        return;
    }
    if(dp[ci][cw]!=-1){
        if(ans<dp[ci][cw]){
            ans=dp[ci][cw];
        }
        return;
    }
    //rec case
    //include
    solve(w,v,c,n,ci+1,cw+w[ci],cv+v[ci],ans,dp);
    //exclude
    solve(w,v,c,n,ci+1,cw,cv,ans,dp);
    dp[ci][cw]=ans;
}

int main(){
    clock_t tStart = clock();

    int w[]={1,3,4,5};
    int v[]={1,4,5,7};
    int c=7;
    int ans=0;

    int **dp=new int*[4+1];
    for(int i=0;i<=4;i++){
        dp[i]=new int[c+1];
        for(int j=0;j<=c;j++){
            dp[i][j]=-1;
        }
    }

    solve(w,v,c,4,0,0,0,ans,dp);
    cout<<ans;

    printf("\nExec Time : %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}