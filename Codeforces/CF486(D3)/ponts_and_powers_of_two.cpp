#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
  return p1.second < p2.second;
}

int main(){
  int N;
  cin>>N;
  vector<long long> V(N);
  map<long long, long long> M;
  for(int i=0; i<N; i++){
    cin>>V[i];
    M[V[i]]++;
  }
  sort(V.begin(), V.end());
  vector<int> A, C;

  for(int j=1; j<=32; j++){
    int last=0;
    for(int i=1; i<N; i++){
      if(V[i]-V[last] == 1LL<<j){
        C.push_back(V[last]);
        last=i;
      }
      else if(V.size()>0 && V[last]==V[i]){
        C.push_back(V[last]);
      }
    }
    if(C.size()>0){
      C.push_back(V[last]);
    }
    if(A.size()<C.size()){
      A=C;
    }
    C.clear();
  }

  if(A.size()>0){
    cout<<A.size()<<endl;
    for(auto x: A){
      cout<<x<<" ";
    }
  }
  else{
    long long maxe = 0, maxf = 0;
    for(auto x:M){
      if(x.second>maxf){
        maxe = x.first;
        maxf = x.second;
      }
    }
    vector<long long> B(maxf, maxe);
    cout<<B.size()<<endl;
    for(auto x:B){
      cout<<x<<" ";
    }
  }
  return 0;
}
