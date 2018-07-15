#include <bits/stdc++.h>

using namespace std;
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
int f(int i,int j){
    if(i>=j){
        return 1;
    }
    else if(j%2==0){
        return 1+f(i,j/2);

    }
    else{
        1+f(i,(j*3)+1);

    }




}
int g(int i,int j){
    int MAXI = 0;
    while(j>=i){
        int coun=1;
        int n=i;
        while(n!=1){
            if(n%2==0){
                n/=2;

                coun++;
            }
            else{
                n=(3*n)+1;
                coun++;
            }

        }
        MAXI = MAX(MAXI,coun);
        i++;

    }

    return MAXI;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int ini;
    int fin;
    while(cin>> n>> m){
        fin = MAX(n,m);
        ini = MIN(n,m);
        cout<<n<<" "<<m<<" "<<g(ini,fin)<<endl;

    }
    return 0;

}
