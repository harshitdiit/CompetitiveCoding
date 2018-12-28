#include<bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

bool ycomp(const pair<int, int> &x, const pair<int, int> &y){
  if(x.ss==y.ss){
    return x.ff<y.ff;
  }
  return x.ss<y.ss;
}

int main(){
  pair<int, int> P[3];
  for(int i=0; i<3; i++){
    cin>>P[i].ff>>P[i].ss;
  }

  set<pair<int,int>> S;

  sort(P, P+3);

  for(int i=P[0].ff+1; i<=P[1].ff; i++){
    S.insert({i, P[0].ss});
  }
  for(int i=P[1].ff; i<=P[2].ff; i++){
    S.insert({i, P[2].ss});
  }

  int x = P[1].ff;

  sort(P, P+3, ycomp);

  for(int i=P[0].ss+1; i<P[1].ss; i++){
    S.insert({x, i});
  }
  for(int i=P[1].ss+1; i<P[2].ss; i++){
    S.insert({x, i});
  }

  for(int i=0; i<3; i++){
    S.insert(P[i]);
  }

  cout<<S.size()<<"\n";
  for(auto y: S){
    cout<<y.ff<<" "<<y.ss<<"\n";
  }
  return 0;
}
