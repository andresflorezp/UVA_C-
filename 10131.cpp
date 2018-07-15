#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int,int>,int>> DS;


bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.first.second>b.first.second;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W,IQ;
    int cnt=1;
    while(cin>>W>>IQ){
        cin>>W>>IQ;
        DS.push_back(make_pair(make_pair(W,IQ),cnt));
        cnt++;

    }
    sort(DS.begin(),DS.end(),cmp);
    int n = DS.size()+1;
    int DP[n];
    int anmax = 0;
    int indexmax=0;
    for(int k=0;k<n;k++){
        DP[k]=1;
        for(int i=0;i<k;i++){
            if(DS[i].first.first<DS[k].first.first && DS[i].first.second>DS[k].first.second){
                DP[k]=max(DP[k],DP[i]+1);
                if(anmax<DP[k]){
                    anmax=DP[k];
                    indexmax=k;

                }

            }
        }

    }
    /*
    cout<<"[";
    for(int k=0;k<n;k++){
        cout<<DS[k].first.first<<" "<<DS[k].first.second<<" "<<DS[k].second<<" ,";


    }

    cout<<"]"<<endl;
    for(int k=0;k<n;k++){
        cout<<DP[k]<<" ";


    }
    cout<<endl;
    */
    vector<int> index;
    int temp=anmax;
    for(int k=indexmax;k>=0;k--){
        if(DP[k]==temp){
            index.push_back(k);
            temp--;

        }
    }
    cout<<index.size()<<endl;
    reverse(index.begin(),index.end());
    for(int i=0;i<index.size();i++){
        cout<<DS[index[i]].second<<endl;


    }







}
