#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin>>N>>M;
  int notebooks = 0;
  notebooks += (8*N)/M + ((8*N)%M==0?0:1);
  notebooks += (5*N)/M + ((5*N)%M==0?0:1);
  notebooks += (2*N)/M + ((2*N)%M==0?0:1);
  cout<<notebooks;
  return 0;
}
