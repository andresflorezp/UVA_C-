#include <bits/stdc++.h>

using namespace std;
const int MAX = 21;
int n;
int R[MAX];
int G[MAX];
int B[MAX];

int dp[MAX][4];
#define MIN(A,B) A<B?A:B
long long f(long long i,char color){
    if(i==n)return 0;
    else if(color=='R')return MIN(G[i]+f(i+1,'G'),B[i]+f(i+1,'B'));
    else if(color=='G')return MIN(R[i]+f(i+1,'R'),B[i]+f(i+1,'B'));
    else if(color=='B')return MIN(R[i]+f(i+1,'R'),G[i]+f(i+1,'G'));
    else return MIN(R[i]+f(i+1,'R'),MIN(G[i]+f(i+1,'G'),B[i]+f(i+1,'B')));

}
int g(int i,int color){
    int &ret=dp[i][color];
    if(i==n)return ret=0;
    if(ret!=-1)return ret;
    else if(color==0)return ret= MIN(G[i]+g(i+1,1),B[i]+g(i+1,2));
    else if(color==1)return ret= MIN(R[i]+g(i+1,0),B[i]+g(i+1,2));
    else if(color==2)return ret= MIN(R[i]+g(i+1,0),G[i]+g(i+1,1));
    else return ret= MIN(R[i]+g(i+1,0),MIN(G[i]+g(i+1,1),B[i]+g(i+1,2)));

}


int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>R[j]>>G[j]>>B[j];

        }
        memset(dp,-1,sizeof(dp));
        cout<<g(0,3)<<endl;





    }


    return 0;
}


