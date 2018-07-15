#include <bits/stdc++.h>

using namespace std;
int M[6];
int vis[6];
int flag;
void print(int n){
    for(int i=0;i<n;i++)cout<<"    ";

}
void f(int n, int resp){
    print(n);
    cout<<"f("<<n<<","<<resp<<")"<<endl;
    if(n==5 && resp==23){
        flag=1;
        return;
    }
    else{
        for(int i=0;i<5;i++){
            if(!vis[i]){
                vis[i]=1;
                f(n+1,resp+M[i]);
                f(n+1,resp*M[i]);
                f(n+1,resp-M[i]);
                vis[i]=0;
            }

        }

    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,e;
    while(true){
        cin>>a>>b>>c>>d>>e;
        if(a==0 && b==0 && c==0 && d==0 && e==0)break;
        M[0]=a;
        M[1]=b;
        M[2]=c;
        M[3]=d;
        M[4]=e;
        flag=0;
        for(int i=0;i<5;i++){
            vis[i]=1;
            f(1,M[i]);
            vis[i]=0;

        }
        if(flag)cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;

    }




    return 0;
}
