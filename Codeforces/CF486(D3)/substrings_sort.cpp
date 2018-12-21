#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;

  vector<pair<int, string> > V;
  string S;

  for(int i=0; i<N; i++){
    cin>>S;
    V.push_back({S.size(), S});
  }

  sort(V.begin(), V.end());

  for(int i=0; i<N-1; i++){
    if(V[i+1].second.find(V[i].second)==string::npos){
      cout<<"NO"<<endl;
      return 0;
    }
  }

  cout<<"YES"<<endl;
  for(int i=0; i<N; i++){
    cout<<V[i].second<<endl;
  }

  return 0;
}
