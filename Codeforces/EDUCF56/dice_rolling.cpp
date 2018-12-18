#include<bits/stdc++.h>
using namespace std;
#define foutput ofstream cout;cout.open("out.txt")

int main(){
  foutput;
  int T;
  cin>>T;
  while(T--){
    int N;
    cin>>N;
    cout<<(N/7)+(N%7?1:0)<<endl;
  }
  return 0;
}
