#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin>>T;
  vector<long long> V(T);
  for(int i=0; i<T; i++){
    cin>>V[i];
  }
  for(int i=0; i<T; i++){
    cout<<((1<<V[i])-(1-2*(1&V[i])))/3<<" "<<(1<<V[i])<<" ";
  }
  return 0;
}
