#include <bits/stdc++.h>

using namespace std;
int M[]={1, 5, 10, 25, 50};
long long DP[2][40000];

long long g(int n,int s){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(j==0)DP[i%2][j]=1;
            else if(i==0)DP[i%2][j ]=0;
            else if(M[i-1]>j)DP[i%2][j]=DP[(i-1)%2][j];
            else DP[i%2][j]=DP[i%2][j-M[i-1]]+DP[(i-1)%2][j];

        }


    }
    return DP[n%2][s];



}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        long long resp = g(5,n);

        cout<<resp<<endl;

    }

    return 0;
}
