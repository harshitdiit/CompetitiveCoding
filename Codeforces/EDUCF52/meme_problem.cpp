#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    long long N;
    cin>>N;

    double A, B;
    if(N<4 && N!=0){
      cout<<"N"<<endl;
    }
    else{
      double D = sqrt(N*N-4*N);
      A = (N+D)/2;
      B = (N-D)/2;
      printf("Y %.9lf %.9lf\n", A, B);
    }
  }
  return 0;
}
