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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll gcd(ll A, ll B){
  if(A==0)
    return B;
  return gcd(B%A, A);
}

int main(){
	ll x, y, p, q;
	cin>>x>>y>>p>>q;

	ll m1 = ((x*p)/gcd(x, p))/p;
	ll m2 = (y*q/gcd(y, q))/q;

	ll b3 = m1*m2/gcd(m1, m2);
	ll b1 = (b3*p)/x;
	ll b2 = (b3*q)/y;

	cout<<b1<<" "<<b2<<" "<<b3;
	return 0;
}