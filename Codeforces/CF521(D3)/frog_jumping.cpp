#include<bits/stdc++.h>
using namespace std;

#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")

int main(){

  finput; foutput;

  int Q;
  cin>>Q;
  while(Q--){
    long long A, B, K;
    cin>>A>>B>>K;
    long long out = (K/2)*(A-B) + (K%2==1?A:0);
    cout<<out<<endl;
  }
  return 0;
}
