#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N, sum=0;
  cin>>N;
  vector<long long> A(N), pref(N), niceIndex;
  map<long long, long long> M;
  for(int i=0; i<N; i++){
    cin>>A[i];
    sum+=A[i];
    M[A[i]]++;
  }
  for(int i=0; i<N; i++){
    pref[i]=sum-A[i];
  }

  for(int i=0; i<N; i++){
    M[A[i]]--;
    if(pref[i]%2==0 && M[pref[i]/2]>0){
      niceIndex.push_back(i);
    }
    M[A[i]]++;
  }

  cout<<niceIndex.size()<<endl;
  for(int i=0; i<niceIndex.size(); i++)
    cout<<niceIndex[i]+1<<" ";

  return 0;
}
