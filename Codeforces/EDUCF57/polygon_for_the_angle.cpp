#include<bits/stdc++.h>
using namespace std;

long gcd(long A, long B){
  if(A==0)
    return B;
  return gcd(B%A, A);
}

int main(){
  int T;
  cin>>T;
  while(T--){
    long Q;
    cin>>Q;



    long G = gcd(180, Q);
    long sides = 180/G;
    if(sides - Q/G >= 2)
      cout<<sides<<"\n";
    else {
      cout<<sides*2<<"\n";
    }
  }
  return 0;
}
