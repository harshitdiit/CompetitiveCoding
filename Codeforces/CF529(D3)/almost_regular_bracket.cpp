#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, x=0, ops=0, cls=0;
  cin>>N;
  string s;
  cin>>s;
  for(int i=0; i<N; i++){
    if(s[i]=='('){
      x++;
      ops++;
    }
    else{
      x--;
      cls++;
    }

    if(x<-2){
      cout<<0;
      return 0;
    }
  }
  if(x==0){
    cout<<0;
    return 0;
  }

  int ans=0, curr=0;
  for(int i=0; i<s.size(); i++){
    char c = s[i];
    if(c=='('){
      if(ops-cls==2 && i!=0 && curr>0)
        ans++;
      curr++;
    }
    else if(c==')'){
      if(cls-ops==2 && i!=N-1)
        ans++;
      curr--;
      ops--;
      cls--;
    }
  }
  cout<<ans;
  return 0;
}
