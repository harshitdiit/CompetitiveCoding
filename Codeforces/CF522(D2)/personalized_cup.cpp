#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int row, column;
  if(s.size()<20 || s.size()%20==0){
    row = s.size()>20?s.size()/20:1;
    column = s.size()>20?20:s.size();
    cout<<row<<" "<<column<<endl;
    for(int i=1; i<=s.size(); i++){
      cout<<s[i-1];
      if(i%20==0)
        cout<<endl;
    }
    return 0;
  }

  for(row=2; row<6; row++){
    if(s.size()/row<20)
      break;
  }

  int asteriks = row - (s.size()%row);
  asteriks = row==asteriks?0:asteriks;

  column = (s.size()+asteriks)/row;

  vector<string> V(row);

  int t=row-1;

  while(asteriks--){
    V[t]+='*';
    t--;
    if(t<0)
      t+=row;
  }

  int r = 0;
  for(int i=0; i<s.size(); i++){
    if(V[r].size()==column){
      r++;
    }

    V[r] += s[i];
  }

  cout<<row<<" "<<column<<endl;
  for(int i=0; i<V.size(); i++){
    cout<<V[i]<<endl;
  }

  return 0;
}
