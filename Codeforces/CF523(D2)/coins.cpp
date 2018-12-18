#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  int coins=0;
  while(K!=0){
    if(N>K){
      N--;
    }
    else{
      coins+=K/N;
      K=K%N;
      N--;
    }
  }
  cout<<coins;
  return 0;
}
