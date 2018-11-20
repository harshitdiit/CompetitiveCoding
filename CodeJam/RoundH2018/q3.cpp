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

ll MOD=1000000007;
int Maxn=2000010;

ll factorial[2000010];

ll modexp(ll x, ll b){
	ll ans=1;
	while(b>0){
		if(b%2==1)
			ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		b/=2;
	}
	return ans;
}

ll modinv(ll x){
  return modexp(x, MOD-2);
}

ll nCr(ll N, ll R){
  return (((factorial[N]*modinv(factorial[R]))%MOD)*modinv(factorial[N-R]))%MOD;
}


int main(){
  finput; foutput;

  factorial[0]=1;
  for(int i=1; i<Maxn; i++){
    factorial[i]=(factorial[i-1]*i)%MOD;
  }

  int caseno;
  cin>>caseno;
  for(int i=1; i<=caseno; i++){
    int N, M;
    cin>>N>>M;
    long long ans = factorial[2*N];
    int sign = -1;
    for(int j=1; j<=M; j++){
      long long temp = (((nCr(M, j)*factorial[j])%MOD)*2*factorial[2*N-j])%MOD;
      ans = (ans+sign*temp)%MOD;
      ans = ans<0?ans+MOD:ans;
      sign *= -1;
    }
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
  return 0;
}
