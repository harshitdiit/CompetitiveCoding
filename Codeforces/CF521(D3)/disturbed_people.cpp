#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin>>A[i];
  }

  vector<int> isDisturbed(A.size(), 0), off(A.size(), 0);
  int disturbed=0, count=0;

  for(int i=1; i<A.size()-1; i++){
    isDisturbed[i] = (A[i-1]==1 && A[i+1]==1 && A[i]==0);
    if(isDisturbed[i]){
      count++;
      A[i+1]=0;
    }
  }

  cout<<count;

  return 0;
}
