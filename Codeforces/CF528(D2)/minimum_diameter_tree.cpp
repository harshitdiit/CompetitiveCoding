#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &G, vector<int> &V, int i, int &unvisited){
  V[i]=1;
  int vis = 0;
  for(auto x:G[i]){
    if(!V[x]){
      dfs(G, V, x, unvisited);
      vis++;
    }
  }
  if(!vis){
    unvisited++;
  }
}

int main(){
  int N, K;
  double D;
  cin>>N>>K;

  D = (double)K;

  vector<vector<int> > G(N);
  int u, v;
  for(int i=0; i<N-1; i++){
    cin>>u>>v;
    G[u-1].push_back(v-1);
    G[v-1].push_back(u-1);
  }

  int root, max_b = 0;

  for(int i=0; i<N; i++){
    if(G[i].size()>max_b){
      root = i;
      max_b = G[i].size();
    }
  }

  int unvisited=0;
  vector<int> V(N, 0);
  dfs(G, V, root, unvisited);

  double ans = D/unvisited;
  printf("%.6lf",ans + ans*(G.size()>2));
  return 0;
}
