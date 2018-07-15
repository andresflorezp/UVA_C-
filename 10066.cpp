#include <bits/stdc++.h>
using namespace std;
int n,m;
int DP[101][101];
int TW1[101];
int TW2[101];
int g(int n, int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)DP[i][j]=0;
            else if(TW1[i-1]==TW2[j-1])DP[i][j]=1+DP[i-1][j-1];
            else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);



        }


    }
    return DP[n][m];



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=1;
    while(true){
        cin>>n>>m;
        if(n==0 && m==0)break;

        for(int i=0;i<n;i++)cin>>TW1[i];
        for(int i=0;i<m;i++)cin>>TW2[i];
        memset(DP,0,sizeof(DP));
        cout<<"Twin Towers #"<<cnt<<endl;
        cout<<"Number of Tiles : "<<g(n,m)<<endl;
        cout<<endl;
        cnt++;



    }




}
