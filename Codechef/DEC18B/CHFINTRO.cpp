#include<bits/stdc++.h>
#define foutput ofstream cout;cout.open("out.txt")

using namespace std;

int main(){
  //foutput;
  int N, R, r;
  cin>>N>>r;
  while(N--){
    cin>>R;
    if(R>=r){
      cout<<"Good boi"<<endl;
    }
    else{
      cout<<"Bad boi"<<endl;
    }
  }
  return 0;
}
