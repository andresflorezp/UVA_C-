#include <bits/stdc++.h>

using namespace std;
int M[]={5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const double EPS = (1e-7);
long long DP[2][40000];
long long f(int i,int S){
    if(S==0)return 1;
    else if(i==0)return 0;
    else if(M[i-1]>S)return f(i-1,S);
    else{
        return f(i,S-M[i-1])+f(i-1,S);

    }


}
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
    double n;

    while(true){
        cin>>n;
        int val = (int)(n*100+EPS);
        if(val==0)break;
        cout<<setw(6)<<fixed<<setprecision(2)<<n<<setw(17)<<g(11,val)<<endl;

    }

    return 0;
}
