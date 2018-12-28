#include<bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int main(){
  int N, u, v;
  cin>>N;
  map<int, pair<int, int>> M;
  for(int i=1; i<=N; i++){
    cin>>u>>v;
    M[i]={u, v};
  }

  vector<int> V;
  V.push_back(1);
  pair<int, int> C = M[1];
  u = C.ff;
  v = C.ss;
  if(M[v].ff==u || M[v].ss==u){
    V.push_back(v);
    V.push_back(u);
  }
  else{
    V.push_back(u);
    V.push_back(v);
  }
  int i=1;
  while(V.size()<N){
    C = M[V[i]];
    if(V[i+1]==C.ff){
      V.push_back(C.ss);
    }
    else{
      V.push_back(C.ff);
    }
    i++;
  }
  for(auto x:V){
    cout<<x<<" ";
  }
  return 0;
}
