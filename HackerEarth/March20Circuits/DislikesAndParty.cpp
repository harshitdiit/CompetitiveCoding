#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int>
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F(i, N) for(int i=0; i<N; i++)
#define MOD 1000000007

int main(){
	fastio;
	ll N, ans;
	set<pair<int, int>> S;

	cin>>N;

	int p1, p2;
	for(int i=0; i<10; i++){
		cin>>p1;
		for(int i=0; i<9; i++){
			cin>>p2;
			S.insert(mk(min(p1, p2), max(p1, p2)));
		}
	}

	cout<<((N*(N-1))/2-S.size());
	return 0; 
}