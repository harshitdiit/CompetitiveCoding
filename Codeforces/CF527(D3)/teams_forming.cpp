#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, t;
  cin>>N;
  map<int, int> M;
  for(int i=0; i<N; i++){
    cin>>t;
    M[t]++;
  }
  int ans = 0;
  auto last=M.end();
  for(auto x = M.begin(); x!=M.end(); x++){
    if(x->second%2){
      if(last==M.end()){
        last = x;
      }
      else{
        ans += (x->first-last->first);
        last = M.end();
      }
    }
  }

  cout<<ans<<"\n";

  return 0;
}
