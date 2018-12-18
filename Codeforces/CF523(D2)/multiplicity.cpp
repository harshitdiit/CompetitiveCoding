#include<bits/stdc++.h>
using namespace std;
int maxn = 1000010;
long long mod = 1000000007;

vector<vector<int>> divTable(maxn);
void filltable(int N){
  for(int i=1; i<=N; i++){
    for(int j=i; j<=maxn; j+=i){
      divTable[j].push_back(i);
    }
  }
}

int main(){
  int N;
  cin>>N;
  filltable(N);
  vector<int> V(N);
  for(int i=0; i<N; i++)
    cin>>V[i];

  vector<long long> dp(N+1, 0);
  dp[0]=1;

  for(int i=0; i<N; i++){
    for(auto j=divTable[V[i]].rbegin(); j!=divTable[V[i]].rend(); j++){
      dp[*j] = dp[*j] + dp[(*j)-1];
      dp[*j] = dp[*j]%mod;
    }
  }
  long long totalSub = 0;
  for(int i=1; i<=N; i++){
    totalSub = (totalSub + dp[i])%mod;
  }

  cout<<totalSub;
  return 0;
}
