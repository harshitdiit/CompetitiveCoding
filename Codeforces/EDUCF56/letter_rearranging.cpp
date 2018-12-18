#include<bits/stdc++.h>
using namespace std;
#define foutput ofstream cout;cout.open("out.txt")

int dict[26];

int main(){
  foutput;
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    for(int i=0; i<26; i++){
      dict[i]=0;
    }
    for(int i=0; i<s.size(); i++){
      dict[s[i]-'a']++;
    }
    string ans;
    int flag=1;
    for(int i=0; i<26; i++){
      if(dict[i]==s.size()){
        cout<<-1<<endl;
        flag=0;
      }
      ans+= string(dict[i], 'a'+i);
    }
    if(flag){
      cout<<ans<<endl;
    }
  }
  return 0;
}
