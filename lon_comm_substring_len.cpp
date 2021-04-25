#include<bits/stdc++.h>
using namespace std;

//tabular soln
int main(){
    string a="xcacde";
    string b="yyaabface";
    int n=a.length();
    int m=b.length();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    //fill 1st row and col with 0 -> already filled
    //now fill rest
    int ma=0;
    int x=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=0;
            }
            if(dp[i][j]>ma){
                ma=dp[i][j];
                x=i;
            }
        }
    }
    cout<<"LEN:"<<ma<<"\n";
    cout<<"VAL:"<<a.substr(x-ma,x-(x-ma))<<"\n";
    return 0;
}


//rec soln
// void lcs(string a,string b,int &l,int cl,int **dp){
//     //base case
//     if(a.length()==0||b.length()==0){
//         if(cl>l){
//             l=cl;
//             dp[a.length()][b.length()]=max(dp[a.length()][b.length()],l);
//         }
//         return;
//     }
//     if(dp[a.length()][b.length()]!=-1){
//         if(dp[a.length()][b.length()]>l){
//             l=dp[a.length()][b.length()];
//         }
//         return;
//     }
//     //rec case
//     //match
//     if(a[0]==b[0]){
//         lcs(a.substr(1),b.substr(1),l,cl+1,dp);
//     }else{
//         if(cl>l){
//             l=cl;
//             dp[a.length()][b.length()]=max(dp[a.length()][b.length()],l);
//         }
//         //not match
//         lcs(a.substr(1),b,l,0,dp);
//         lcs(a,b.substr(1),l,0,dp);
//     }
//     dp[a.length()][b.length()]=max(dp[a.length()][b.length()],l);
// }

// int main(){
//     string a="axcmbde";
//     string b="abfcemb";
//     int l=0;
//     int **dp=new int*[a.length()+1];
//     for(int i=0;i<=a.length();i++){
//         dp[i]=new int[b.length()+1];
//         for(int j=0;j<=b.length();j++){
//             dp[i][j]=-1;
//         }
//     }
//     lcs(a,b,l,0,dp);
//     cout<<l<<"\n";

// }