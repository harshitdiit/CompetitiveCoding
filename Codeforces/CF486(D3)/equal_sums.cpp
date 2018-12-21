#include<bits/stdc++.h>
#define first ff
#define second ss

using namespace std;

int main(){
  int K, N, s;
  cin>>K;
  vector<vector<int>> V;
  for(int i=1; i<=K; i++){
    cin>>N;
    vector<int> t(N);
    s=0;
    for(int j=0; j<N; j++){
      cin>>t[j];
      s+=t[j];
    }
    for(int j=0; j<N; j++){
      V.push_back(vector<int> ({s-t[j], i, j+1}));
    }
  }
  
  sort(V.begin(), V.end());

  for(int i=0; i<V.size()-1; i++){

    auto x = V[i], y = V[i+1];

    if((x[0]==y[0]) && (x[1]!=y[1])){
      cout<<"YES"<<endl;
      cout<<x[1]<<" "<<x[2]<<endl;
      cout<<y[1]<<" "<<y[2]<<endl;
      return 0;
    }
  }

  cout<<"NO"<<endl;

  return 0;
}
