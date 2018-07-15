#include <bits/stdc++.h>
using namespace std;
long long DP[1001];
long long f(int s){
    DP[0]=0;
    DP[1]=2;
    DP[2]=5;
    DP[3]=13;
    for(int i=4;i<=s;i++){
        DP[i]=DP[i-1]+DP[i-2]+DP[i-3];

    }
    return DP[s];
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        cout<<f(n)<<endl;


    }




    return 0;
}
