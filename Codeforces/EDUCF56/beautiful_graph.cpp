#include<bits/stdc++.h>
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")

using namespace std;
long long mod = 998244353;
long long count[2];

long long modexp(long long x, long long b){
	long long ans=1;
	while(b>0){
		if(b%2==1)
			ans=(ans*x)%mod;
		x=(x*x)%mod;
		b/=2;
	}
	return ans;
}

void dfs(vector<vector<int>> &G, vector<int> &V, vector<int> &color, int i, int f, bool &d, long long *X){
  V[i]=1;
  color[i]=f;
  X[f]++;

  for(auto x:G[i]){
    if(V[x]==0){
      dfs(G, V, color, x, !f, d, X);
    }
    else{
      if(color[x]==f){
        d=false;
        return;
      }
    }
  }
}

int main(){
  //finput; //foutput;
  int T;
  cin>>T;

  for(int i=0; i<T; i++){
    int V, E, u, v;
    cin>>V>>E;
    vector<vector<int>> G(V);
    for(int i=0; i<E; i++){
      cin>>u>>v;
      G[u-1].push_back(v-1);
      G[v-1].push_back(u-1);
    }
    long long ans = 1;
    vector<int> vis(V, 0), color(V, -1);
    bool d=true;
    for(int j=0; j<V; j++){
      if(vis[j]==0){
        long long x[2] = {0, 0};
        dfs(G, vis, color, j, 0, d, x);

        if(d==false){
          break;
        }

        long long t = (modexp(2, x[0])+modexp(2, x[1]))%mod;
        if(t==2) t=3;

        ans = (ans*t)%mod;
      }
    }

    if(d==false){
      cout<<0<<endl;
    }
    else{
      cout<<ans<<endl;
    }
  }
  return 0;
}
