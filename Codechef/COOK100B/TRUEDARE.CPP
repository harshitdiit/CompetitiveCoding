#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    int t, k;
    set<int> S[4]; //tR, dR, tS, dS
    for(int i=0; i<4; i++){
      cin>>k;
      while(k--){
        cin>>t;
        S[i].insert(t);
      }
    }
    bool flag = true;
    for(auto x:S[2]){
      if(S[0].find(x)==S[0].end()){
        flag = false;
        break;
      }
    }
    if(!flag){
      cout<<"no\n";
      continue;
    }
    for(auto x:S[3]){
      if(S[1].find(x)==S[1].end()){
        flag = false;
        break;
      }
    }
    if(!flag){
      cout<<"no\n";
      continue;
    }
    cout<<"yes\n";
  }
  return 0;
}
