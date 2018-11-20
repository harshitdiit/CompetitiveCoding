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
  //finput; foutput;
  int N, D, M, x, y;
  cin>>N>>D>>M;
  bool loc[M];
  F(i, M){
    cin>>x>>y;
    if(abs(x-y)<=D){
      if((x+y>=D) && (x+y<=2*N-D)){
        loc[i]=true;
      }
      else{
        loc[i]=false;
      }
    }
    else{
      loc[i]=false;
    }
  }
  F(i, M){
    if(loc[i]){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
