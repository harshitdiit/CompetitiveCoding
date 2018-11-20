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

int main(){
  finput; foutput;
  long x, y, maxv=0;
  long N;
  cin>>N;
  while(N--){
    cin>>x>>y;
    maxv=max(maxv, x+y);
  }
  cout<<maxv<<endl;
  return 0;
}
