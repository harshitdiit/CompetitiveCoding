#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long N){
  long long i=2;
  while(i<=sqrt(N)){
    if(N%i==0)
      return 0;
		i++;
  }
  return 1;
}

int prime[1000001]={0};vector <int> p;
void sieve(){
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}

int main(){
  long long N;
  cin>>N;
  sieve();

  long long i;

	if(isPrime(N)){
		cout<<1;
		return 0;
	}

	for(i=0; i<ceil(sqrt(N)); i++){
    if(N%p[i]==0)
        break;
  }

  long long ans;
  if(i==0){
    ans = N/2;
  }
  else{
    ans = 1 + (N-p[i])/2;
  }

  cout<<ans;

  return 0;
}
