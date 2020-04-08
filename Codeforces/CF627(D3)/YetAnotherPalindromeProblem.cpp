#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
	fastio;
	int T, N, X;
	cin>>T;
	while(T--){
		cin>>N;
		unordered_map<int, int> mp;
		bool flag = false;
		for(int i=0; i<N; i++){
			cin>>X;
			if(mp.find(X)==mp.end())
				mp[X]=i;
			else if(i-mp[X]>1){
				flag = true;
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}