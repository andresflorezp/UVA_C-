#include <bits/stdc++.h>
using namespace std;
#define MAX(A,B) A>B?A:B
char M[100][100];
int visi[27];
char abcd[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int t(int i,int j,int n,int m,char target){
    if(i>=n || j>=m || i<0 || j<0){
        return 0;

    }
    if(M[i][j]=='.' || M[i][j]!=target){
        return 0;

    }
    M[i][j]='.';
    int resp=1;
    resp+=t(i+1,j,n,m,target);
    resp+=t(i-1,j,n,m,target);
    resp+=t(i,j+1,n,m,target);
    resp+=t(i,j-1,n,m,target);
    return resp;





}

bool compare(pair<char,int> a,pair<char,int> b){
    if(a.second>b.second)return a.second>b.second;
    else if(a.second==b.second && a.first<b.first)return a.first<b.first;
    else return false;



}

int main(){
    int n,m;
    int cnt=1;
    vector<pair<char,int>> respuestas;
    while(true){
        cin>>n>>m;
        if(n==0 && m==0)break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>M[i][j];

            }

        }
        int respu=0;

        memset(visi,0,sizeof(visi));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!='.'){
                    char c = M[i][j];
                    respu = t(i,j,n,m,c);
                    respuestas.push_back(make_pair(c,respu));

                }

            }
        }


        sort(respuestas.begin(),respuestas.end(),compare);
        cout<<"Problem "<<cnt<<":"<<endl;
        for(int i=0;i<respuestas.size();i++){
            if(respuestas[i].second>0){
                cout<<respuestas[i].first<<" "<<respuestas[i].second<<endl;
            }


        }
        cnt++;
        respuestas.clear();




}
}







