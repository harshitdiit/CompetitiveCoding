#include <bits/stdc++.h>
using namespace std;

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
  int N;
  cin>>N;

  sieve();

  int i=0, D=N;
  int minNum=1, ops=0, maxpow=-1, tpow=0;
  while(D!=1){
    if(D%p[i]==0)
      minNum*=p[i];
    while(D%p[i]==0){
      D/=p[i];
      tpow++;
    }

    if(maxpow>0 && tpow>0 && tpow!=maxpow)
      ops=1;

    maxpow=max(tpow, maxpow);
    tpow=0;

    i++;
  }

  int t = maxpow;
  while(t!=1 && t>0){
    if(t%2){
      ops=1;
      break;
    }
    t/=2;
  }

  if(maxpow<1)
    cout<<minNum<<" "<<ops;
  else
    cout<<minNum<<" "<<ops + (int)ceil(log(maxpow)/log(2));

  return 0;
}
