#include<bits/stdc++.h>
using namespace std;

int calc(int r){
  if(r==0)
    return 0;
  else{
    if(r%2){
      return ((r-1)/2 - r);
    }
    else{
      return (r/2);
    }
  }
}

int main(){
  int Q;
  cin>>Q;
  while(Q--){
    int l, r;
    cin>>l>>r;
    cout<<calc(r)-calc(l-1)<<endl;
  }
  return 0;
}
