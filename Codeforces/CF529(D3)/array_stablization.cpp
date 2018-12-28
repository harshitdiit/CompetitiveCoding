#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> V(N);
  for(int i=0; i<N; i++){
    cin>>V[i];
  }
  sort(V.begin(), V.end(), greater<int>());
  cout<<min(*(V.begin())-*(V.end()-2), *(V.begin()+1)-*(V.end()-1));
  return 0;
}
