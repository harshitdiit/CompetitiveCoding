#include<bits/stdc++.h>
using namespace std;

int main(){
  int X, j=0;
  cin>>X;
  int N = (-1+(int)sqrt(1+8*X))/2;
  string enc, dec;
  cin>>enc;
  for(int i=1; i<=N; i++){
    dec+=enc[j];
    j+=i;
  }
  cout<<dec;
  return 0;
}
