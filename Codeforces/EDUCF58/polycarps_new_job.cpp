#include<bits/stdc++.h>
#define finput ifstream cin;cin.open("in.txt")

#define ff first
#define ss second

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  //finput;


  int Q;
  long maxar=0;
  pair<long, long> maxw={0, 0}, maxh={0, 0}, maxa={0, 0};
  cin>>Q;
  while(Q--){
    char T;
    long H, W;
    cin>>T>>H>>W;
    if(T=='+'){
      if(H>maxh.ff){
        maxh = {H, W};
      }
      if(W>maxw.ss){
        maxw = {H, W};
      }
      if(H*W>maxar){
        maxar = H*W;
        maxa = {H, W};
      }
    }
    else{
      if(maxar>H*W){
        cout<<"NO"<<'\n';
        continue;
      }
      if((H>=maxh.ff && W>=maxh.ss)||(W>=maxh.ff && H>=maxh.ss)){
        if((H>=maxw.ff && W>=maxw.ss)||(W>=maxw.ff && H>=maxw.ss)){
          if((H>=maxa.ff && W>=maxa.ss)||(W>=maxa.ff && H>=maxa.ss))
            cout<<"YES"<<"\n";
          else
            cout<<"NO"<<"\n";
        }
        else{
          cout<<"NO"<<"\n";
        }
      }
      else{
        cout<<"NO"<<"\n";
      }
    }
  }
  return 0;
}
