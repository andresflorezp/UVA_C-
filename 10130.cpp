#include <bits/stdc++.h>
int W[1001];
int P[1001];

int DP[1001][31];
using namespace std;


int f(int n,int S){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=S;j++){
            if(j==0 || i==0)DP[i][j]=0;
            else if(j<W[i-1])DP[i][j]=DP[i-1][j];
            else DP[i][j]=max(P[i-1]+DP[i-1][j-W[i-1]],DP[i-1][j]);

        }

    }
    return DP[n][S];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    int N;
    int G;
    int peop;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        int resp=0;
        for(int j=0;j<N;j++){
            cin>>P[j]>>W[j];
        }
        cin>>G;

        for(int k=0;k<G;k++){
            memset(DP,0,sizeof(DP));
            cin>>peop;
            resp+=f(N,peop);


        }
        cout<<resp<<endl;

    }





}
