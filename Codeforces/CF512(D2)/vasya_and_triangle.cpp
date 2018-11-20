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

unsigned ll min(unsigned ll x, unsigned ll y){
  return x>y?x:y;
}

int main(){
  finput; foutput;
  unsigned long long N, M, K, Area;
  cin>>N>>M>>K;
  bool isPossible = (2*N*M)%K==0?1:0;
  if(!isPossible){
    cout<<"NO"<<endl;
    return 0;
  }
  Area = (2*N*M)/K;
  if(K==2){
  	cout<<"YES"<<endl;
  	cout<<0<<" "<<0<<endl;
  	cout<<N<<" "<<0<<endl;
  	cout<<0<<" "<<M<<endl;
  	return 0;
  }
  for(unsigned ll i=1; i<=min(N, min(M, (unsigned long long)sqrt(Area))); i++){
    if(Area%i==0){
      if(i<=N && (Area/i)<=M){
        cout<<"YES"<<endl<<"0 0"<<endl<<i<<" 0"<<endl<<"0 "<<Area/i<<endl;
        return 0;
      }
      else if(Area/i<=N && i<=M){
        cout<<"YES"<<endl<<"0 0"<<endl<<"0 "<<i<<endl<<Area/i<<" 0"<<endl;
        return 0;
      }
    }
  }
  cout<<"NO"<<endl;
}
