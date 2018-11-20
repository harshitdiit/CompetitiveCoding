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
  int N, nice=0;
  cin>>N;
  vector<int> V(N);
  map<int, int> M, Nice;
  F(i, N){
    cin>>V[i];
    if(M.find(V[i])!=M.end())
      M[V[i]]++;
    else
      M[V[i]]=1;
  }
  for(map<int, int>::iterator it=M.begin(); it!=M.end(); it++){
    if(it->second==1){
      Nice[it->first]=1;
      nice++;
    }
    else{
      Nice[it->first]=0;
    }
  }
  if(nice%2){
    cout<<"NO";
    return 0;
  }
  nice/=2;
  F(i, N){
    if(Nice[V[i]] && nice){
      cout<<'A';
      nice--;
    }
    else if(Nice[V[i]]){
      cout<<'B';
    }
    else{
      cout<<'A';
    }
  }
  return 0;
}
