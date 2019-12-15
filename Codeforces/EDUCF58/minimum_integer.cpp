#include<bits/stdc++.h>
using namespace std;

int main(){
  int Q;
  cin>>Q;
  while(Q--){
    long L, R, D;
    cin>>L>>R>>D;
    if(D<L || R<D){
      cout<<D<<endl;
    }
    else{
      long A = D-(R%D);
      cout<<A+R<<endl;
    }
  }
  return 0;
}
