#include<bits/stdc++.h>
using namespace std;

bool comp(const string &x, const string &y){
  return (x.size()>y.size());
}

bool isPref(string pref, string haystack){
  return (haystack.substr(0, pref.size())==pref);
}

bool isSuff(string suff, string haystack){
  return (haystack.substr(haystack.size()-suff.size(), suff.size())==suff);
}

int main(){
  int N;
  cin>>N;
  string k, poss1, poss2, str, out="";
  vector<string> V, G;
  set<string> P, S;
  for(int i=0; i<2*N-2; i++){
    cin>>k;
    G.push_back(k);
  }

  V=G;
  sort(V.begin(), V.end(), comp);

  poss1 = (V[0].front()+V[0].substr(1, N-2)+V[1].back());
  poss2 = (V[1].front()+V[1].substr(1, N-2)+V[0].back());

  for(int i=0; i<V.size(); i++){
    if(!isPref(V[i], poss1) && !isSuff(V[i], poss1)){
      str = poss2;
      break;
    }
    else if(!isPref(V[i], poss2) && !isSuff(V[i], poss2)){
      str = poss1;
      break;
    }
  }

  if(!str.size()){
    str = poss1;
  }

  for(int i=0; i<V.size(); i+=2){
    if(isPref(V[i], str)){
      P.insert(V[i]);
      S.insert(V[i+1]);
    }
    else{
      P.insert(V[i+1]);
      S.insert(V[i]);
    }
  }

  for(auto x: G){
    if(P.find(x)!=P.end()){
      cout<<"P";
      P.erase(x);
    }
    else{
      cout<<"S";
      S.erase(x);
    }
  }
  return 0;
}
