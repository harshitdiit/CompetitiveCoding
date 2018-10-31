// ques http://codeforces.com/contest/493/problem/C

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin>>N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin>>A[i];
  }
  cin>>M;
  vector<int> B(M);
  for(int i=0; i<M; i++){
    cin>>B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int i=0;
  int d=A[0];

  int max_diff = 3*(N-M);

  while(i<N){
    int cost1 = N-(upper_bound(A.begin(), A.end(), A[i]-1)-A.begin());
    int cost2 = M-(upper_bound(B.begin(), B.end(), A[i]-1)-B.begin());

    if(max_diff<(2*(N-M)+(cost1-cost2))) {
      d = A[i];
      max_diff = 2*(N-M)+(cost1-cost2);
    }
    i++;
  }

  if(2*(N-M)>max_diff){
    d = max(A.back(), B.back())+1;
  }

  int cost1 = N-(upper_bound(A.begin(), A.end(), d-1)-A.begin());
  int cost2 = M-(upper_bound(B.begin(), B.end(), d-1)-B.begin());

  cout<<2*N+cost1<<":"<<2*M+cost2<<endl;

  return 0;
}
