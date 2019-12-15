#include<bits/stdc++.h>
#define finput ifstream cin;cin.open("in.txt")

#define ff first
#define ss second
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int Q;
  cin>>Q;
  while(Q--){
    int N, flag=1;
    cin>>N;
    vector<pair<int, int>> V(N);
    for(int i=0; i<N; i++){
      cin>>V[i].ff>>V[i].ss;
    }
    multiset<pair<int, int>> M(V.begin(), V.end());

    set<pair<int, int>> S1, S2;
    while(!M.empty()){
      if(S1.empty()){
        S1.insert(*(M.begin()));
        M.erase(M.begin());
      }
      else if(S2.empty()){
        S2.insert(*(M.begin()));
        M.erase(M.begin());
      }
      else{
        auto P1 = *(S1.rbegin()), P2 = *(S2.rbegin());
        auto M1 = *(M.begin());
        if(M1.ff>P1.ss){
          S1.insert(M1);
          M.erase(M.begin());
        }
        else if(M1.ff>P2.ss){
          S2.insert(M1);
          M.erase(M.begin());
        }
        else{
          flag=0;
          break;
        }
      }
    }
    if(!flag){
      cout<<-1<<"\n";
      continue;
    }

    for(auto x:V){
      if(S1.find(x)!=S1.end()){
        cout<<1<<" ";
        S1.erase(x);
      }
      else if(S2.find(x)!=S2.end()){
        cout<<2<<" ";
        S2.erase(x);
      }
    }
    cout<<"\n";
  }
  return 0;
}
