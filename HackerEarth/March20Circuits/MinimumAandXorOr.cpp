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
	fastio;

	int N, T;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int i=0; i<N; i++){
			cin>>arr[i];
		}
		sort(arr, arr+N);

		int _min = INT_MAX;
		for(int i=0; i<N-1; i++){
			_min = min(_min, (arr[i]&arr[i+1])^(arr[i]|arr[i+1]));
		}
		cout<<_min<<endl;
	}

	return 0;
}