#include<bits/stdc++.h>

using namespace std;
int fallo(int n,string P){
    vector<int> F(n,0);
    int i=1;
    int j=0;
    while(i<n){
        if(P[i]==P[j]){
            F[i]=j+1;
            i++;
            j++;


        }
        else if(j>0){
            j=F[j-1];

        }
        else{
            F[i]=0;
            i++;

        }

    }
    return F[n-1];



}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string T;
    string RT;
    while(cin>>T){
        RT = T;
        reverse(RT.begin(),RT.end());
        //string atras = T + "@" + RT;
        string adelante = RT + "@" + T;
        int fr = fallo(adelante.size(),adelante);
        cout<<T+ adelante.substr(fr,RT.size()-fr)<<endl;



    }



    return 0;
}
