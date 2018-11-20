#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin>>A[i];
  }
  int start=0, end=0, maxcount=0, tcount=0;
  for(int i=1; i<N; i++){
    if(A[i-1]==A[i]-1){
      tcount++;
    }
    else{
      if(tcount)
        maxcount = max(maxcount, A[start]==1?tcount:tcount-1);

      start=i;
      end=i;
      tcount=0;
    }
  }
  if(start==end && tcount){
    maxcount = max(maxcount, (A[N-1]==1000 || (start==0 && A[start]==1))?tcount:tcount-1);
  }

  if(N==1000)
    maxcount=1000;

  cout<<maxcount;

  return 0;
}
