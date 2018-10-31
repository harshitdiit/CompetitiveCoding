#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main(){
  long long rooms, port, cumTries=0;
  cin>>rooms;
  vector<long long> numTries(rooms, 0);

  for(int i=0; i<rooms; i++){
    cin>>port;
    for(int j=port-1; j<i; j++){
      numTries[i]=(numTries[j]+numTries[i])%mod;
    }
    numTries[i]=(numTries[i]+2)%mod;
    cumTries=(cumTries+numTries[i])%mod;
  }

  cout<<cumTries;
}
