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
	int T, a, b;
	cin>>T; 
	while(T--){
		cin>>a>>b;
		cout<<(!(a%b)?0:(b-(a%b)))<<endl;
	}
	return 0;
}