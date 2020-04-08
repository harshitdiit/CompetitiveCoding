#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int>
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")
#define F(i, N) for(int i=0; i<N; i++)
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
	ll T, N, K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		if(!(N%2)){
			if(!(K%2)){
				cout<<(K*K<=N?"YES":"NO")<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
		else{
			if(K%2){
				cout<<(K*K<=N?"YES":"NO")<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}

		}
	}
	return 0;
}