#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  priority_queue<int> Q;
  int i=0;
  while((1<<i)<=N){
    if(N&(1<<i)){
      Q.push(1<<i);
    }
    i++;
  }

  if(Q.size()>K){
    cout<<"NO\n";
    return 0;
  }

  int k = Q.size();

  while(k<K){
    int X = Q.top();
    Q.pop();
    if(X/2==0){
      cout<<"NO\n";
      return 0;
    }
    X/=2;
    Q.push(X);
    Q.push(X);
    k++;
  }

  cout<<"YES\n";

  while(!Q.empty()){
    cout<<Q.top()<<" ";
    Q.pop();
  }
  return 0;
}
