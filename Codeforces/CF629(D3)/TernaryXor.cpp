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

// Fast I/O
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
	int T, N;
	cin>>T;
	while(T--){
		cin>>N;
		char X[N];
		int X1[N], X2[N];
		int last_set = 0;
		for(int i=0; i<N; i++){
			cin>>X[i];
			if(!last_set){
				X1[i] = (X[i]-48)/2;
				X2[i] = (X[i]-48)-X1[i];
				if(X[i]=='1')
				    last_set=1;
			}
			else{
				X2[i] = 0;
				X1[i] = (X[i]-48);
			}
		}
		for(int i=0; i<N; i++){
			cout<<X1[i];
		}
		cout<<endl;
		for(int i=0; i<N; i++){
			cout<<X2[i];
		}
		cout<<endl;
	}
	return 0;
}