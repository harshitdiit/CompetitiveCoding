#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    int N, K;
    cin>>N>>K;
    int freq = N/K;
    string ans = "";
    for(int i=0; i<K; i++){
      ans = ans + string(freq, 'a'+i);
    }
    ans = ans + string(N-ans.size(), 'a'+(K-1));
    cout<<ans<<"\n";
  }
  return 0;
}
