#include<bits/stdc++.h>
using namespace std;
#define foutput ofstream cout;cout.open("out.txt")

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,x,y,d;
    cin>>n>>x>>y>>d;

    int rem = x%d;
    int ans = INT_MAX;

    if(abs(x-y)%d==0){
      ans = abs(y-x)/d;
    }
    else{
      if(y%d==1){
        ans = min(ans, (int)(ceil(abs((x-1)/(double)d)) + (y-1)/d));
      }
      if(n%d==y%d){
        ans = min(ans, (int)(ceil(abs((n-x)/(double)d)) + (n-y)/d));
      }
      if(ans==INT_MAX){
        ans = -1;
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}
