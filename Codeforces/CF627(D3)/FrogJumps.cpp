#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int i, st = 0, ls = 0;
		for(i=0; i<s.size(); i++){
			if(s[i]=='R'){
				ls = max(ls, i-st);
				st = i+1;
			}
		}
		ls = max(ls, i-st);
		cout<<ls+1<<endl;
	}
	return 0;
}