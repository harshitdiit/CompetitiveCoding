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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  finput; foutput;
  int N, temp, flag=0;
  cin>>N;
  while(N--){
    cin>>temp;
    flag = flag | temp;
  }
  if(!flag){
    cout<<"EASY"<<endl;
  }
  else{
    cout<<"HARD"<<endl;
  }
  return 0;
}
