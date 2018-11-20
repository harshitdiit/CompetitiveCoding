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

bool checkIfPoss(vector<long long> &V, int N, long long X){
  if(V[N-1]>=X){
    return true;
  }

  for(int i=N; i<V.size(); i++){
    if(V[i]-V[i-N]>=X){
      return true;
    }
  }
  return false;
}

int main(){
  finput; foutput;
  int caseno;
  cin>>caseno;
  for(int i=1; i<=caseno; i++){
    int N;
    string S;
    cin>>N>>S;
    vector<long long> V(N);
    for(int i=0; i<N; i++){
      V[i] = (i==0?0LL:V[i-1]) + S[i]-'0';
    }
    long long ans, mid, low=0, high=V[N-1];
    while(low<=high){
      mid=(low+high)/2;
      if(checkIfPoss(V, N%2?N/2+1:N/2, mid)){
        ans = mid;
        low=mid+1;
      }
      else{
        high=mid-1;
      }
    }
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
  return 0;
}
