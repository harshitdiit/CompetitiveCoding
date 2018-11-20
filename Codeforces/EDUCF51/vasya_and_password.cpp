#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int>
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")
#define F(i, N) for(int i=0; i<N; i++)
#define MOD 1000000007

int Ctype(char A){
  if(A>='a' && A<='z')
    return 0;
  if(A>='A' && A<='Z')
    return 1;
  else if(A>='0' && A<='9')
    return 2;
}

char returnChar(int A){
  if(A==0) return 'a';
  if(A==1) return 'A';
  if(A==2) return '0';
}

int main(){
  finput; foutput;
  int T;
  cin>>T;
  while(T--){
    string S;
    cin>>S;
    unordered_map <int, int> M;
    F(i, S.size()){
      int type = Ctype(S[i]);
      if(M.find(type)!=M.end()){
        M[type]++;
      }
      else{
        M[type]=1;
      }
    }
    /*
    for(map<int, int>::iterator it=M.begin(); it!=M.end(); it++)
      cout<<it->first<<"->"<<it->second<<endl;
    */
    bool flag = true;
    vector<int> missing;
    map<int, bool> abundant;
    F(i, 3){
      if(M.find(i)==M.end()){
        flag = false;
        missing.push_back(i);
        abundant[i] = false;
      }
      else if(M[i]>1){
        abundant[i] = true;
      }
      else{
        abundant[i] = false;
      }
    }

    /*
    F(i, missing.size())
      cout<<missing[i]<<" ";
    cout<<endl;
    F(i, 3)
      cout<<i<<"->"<<abundant[i]<<" ";
    cout<<endl;
    cout<<"Flag "<<flag<<endl;
    */

    if(flag){
      cout<<S<<endl;
      //cout<<"unchanged"<<endl;
    }
    else{
      F(i, missing.size()){
        F(j, S.size()){
          int type = Ctype(S[j]);
          //cout<<type<<"type"<<endl;
          if(abundant[type]){
            S[j]=returnChar(missing[i]);
            break;
          }
        }
      }
      cout<<S<<endl;
    }
  }
  return 0;
}
