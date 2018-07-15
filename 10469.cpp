#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	int b;
	int c;
	while(cin>>a>>b){
		int c = ((~a)&b) | (a&(~b));
		cout<<c<<endl;
	}
	
	return 0;
	
}


