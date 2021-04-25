#include<bits/stdc++.h>
using namespace std;

int lcs(string a,string b,int **dp){
    //base case
    if(a.length()==0||b.length()==0){
        return 0;
    }
    // if(dp[a.length()][b.length()]!=-1){
    //     return dp[a.length()][b.length()];
    // }
    //rec case
    //if match
    if(a[a.length()-1]==b[b.length()-1]){
        return 1+lcs(a.substr(0,a.length()-1),b.substr(0,b.length()-1),dp);
    }
    //if not match
    int x=lcs(a.substr(0,a.length()-1),b,dp);
    int y=lcs(a,b.substr(0,b.length()-1),dp);
    return max(x,y);
}

int main(){
    string a="abcde";
    string b="abfce";
    int **dp=new int*[a.length()+1];
    for(int i=0;i<=a.length();i++){
        dp[i]=new int[b.length()+1];
        for(int j=0;j<=b.length();j++){
            dp[i][j]=-1;
        }
    }
    cout<<lcs(a,b,dp);
}