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
  int N;
  cin>>N;
  if(!(N%3)){
    cout<<"1 "<<"1 "<<N-2<<endl;
  }
  else{
    cout<<"1 "<<"2 "<<N-3<<endl;
  }
  return 0;
}
