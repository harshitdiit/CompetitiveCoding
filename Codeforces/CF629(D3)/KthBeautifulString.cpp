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
	ll T, N, K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		ll x = (ll)((sqrt(8*K+1)-1.0)/2.0);
		if((x*(x+1))/2<K)
		    x++;
		    
		ll y = ((x-1)*x)/2;
	    ll s = K-y-1;
    	string ans = string(N-x-1,'a')+"b"+string(x-s-1,'a')+"b"+string(s,'a');
		cout<<ans<<endl;
	}

	return 0;
}