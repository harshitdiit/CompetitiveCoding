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

int main(){
  finput; foutput;
  long long A, B, N, sum;
  cin>>A>>B;
  sum=A+B;
  for(N=1; N*(N+1)<=2*sum; N++);
  N=(N*(N+1)<=2*sum?N:N-1);
  set<int> S;
  for(int i=N; i>0 && A>0; i--){
    if(i<=A){
      S.insert(i);
      A-=i;
    }
  }
  cout<<S.size()<<endl;
  for(auto i=S.begin(); i!=S.end(); i++){
    cout<<*i<<" ";
  }
  cout<<endl<<N-S.size()<<endl;
  for(int i=N; i>0; i--){
    if(S.find(i)==S.end())
      cout<<i<<" ";
  }
  return 0;
}
