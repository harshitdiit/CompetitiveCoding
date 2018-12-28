#include<bits/stdc++.h>
using namespace std;

set<int> factors(int K){
  set<int> V;
  for(int i=1; i<=sqrt(K); i++){
    if(K%i==0){
      V.insert(i);
      V.insert(K/i);
    }
  }
  return V;
}

int main(){
  long N, K;
  cin>>N>>K;

  long ans = INT_MAX;
  long prod = N*K;

  set<int> V = factors(prod);
  for(auto x:V){
    long s = (prod/x)+x;
    if(s>0 && s%K==x){
      ans = min(((prod/x)+x), ans);
    }
  }

  cout<<ans;
  return 0;
}
