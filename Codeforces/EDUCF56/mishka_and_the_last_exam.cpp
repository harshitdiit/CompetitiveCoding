#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N, X;
  cin>>N;
  vector<long long> arr(N, 0);
  long long small, large;
  for(long long i=0; i<N/2; i++){
    cin>>X;
    if(i==0){
      arr[i]=small=0;
      arr[N-i-1]=large=X;
    }
    else{
      if(X-small<large){
        arr[i]=small;
        arr[N-i-1]=X-small;
        large=X-small;
      }
      else{
        arr[N-i-1]=large;
        arr[i]=X-large;
        small=X-large;
      }
    }
  }
  for(int i=0; i<N; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
