#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
	fastio;
	int T, N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N], _min = INT_MAX;
		for(int i=0; i<N; i++){
			cin>>arr[i];
			_min = min(_min, arr[i]);
		}

		bool flag = true;
		for(int i=0; i<N; i++){
			if((arr[i]-_min)%2){
				flag = false;
				break;
			}
		}

		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}
