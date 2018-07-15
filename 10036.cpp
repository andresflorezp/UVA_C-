#include <bits/stdc++.h>

using namespace std;
int dp[10007][105];
int items[10007];

int f(int i,int resp,int n,int k){
    if(i==n)return resp==0;
    else if(dp[i][resp]!=-1)return dp[i][resp];
    else if(f(i+1,((resp+items[i])%k+k)%k,n,k) || f(i+1,((resp-items[i])%k+k)%k,n,k)){
        dp[i][resp]=1;
        return dp[i][resp];
    }
    else{
        return dp[i][resp] = 0;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,n,k;
    cin>>T;

    int data=0;
    for(int i=0;i<T;++i){
        cin>>n>>k;
        for(int j=0;j<n;++j){
            cin>>items[j];

        }
        memset(dp,-1,sizeof(dp));

        if(f(1,((items[0]%k)+k)%k,n,k))cout<<"Divisible"<<'\n';
        else cout<<"Not divisible"<<'\n';


    }

    return 0;
}
