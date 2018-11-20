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
  int w, h, k;
  cin>>w>>h>>k;
  int ans=0;
  while(k--){
    ans+=2*(w+(h-2));
    w-=4; h-=4;
  }
  cout<<ans;
  return 0;
}
