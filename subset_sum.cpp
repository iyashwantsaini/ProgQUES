#include<bits/stdc++.h>
using namespace std;

int ss(int n,int a[],int k,int i,int s,int **dp){
    //base case
    if(s==k){
        return 1;
    }
    if(s>k){
        return 0;
    }
    if(i>=n){
        return 0;
    }
    if(dp[i][s]!=-1){
        return dp[i][s];
    }
    //rec case
    //include,exclude
    dp[i][s]=ss(n,a,k,i+1,s+a[i],dp)||ss(n,a,k,i+1,s,dp);
    return dp[i][s];
}

int main(){
    int n=5;
    int k=11;
    int a[]={2,3,7,8,10};
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[k+1];
        for(int j=0;j<=k;j++){
            dp[i][j]=-1;
        }
    }
    cout<<ss(n,a,k,0,0,dp);
}