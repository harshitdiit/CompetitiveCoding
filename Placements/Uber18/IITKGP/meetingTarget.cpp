// Ques at https://imgur.com/L9aPElu
// mentioned that r lies between [0,2)

#include<bits/stdc++.h>
using namespace std;

double err = pow(10, -7);

double checkVal(vector<double> &riders, double r){
  double val=0;
  for(int i=0; i<riders.size(); i++){
    val+=riders[i]*pow(r, riders.size()-i-1);
  }
  return val;
}

int main(){
  int T;
  cin>>T;
  while(T--){
    double C;
    int M;
    cin>>C>>M;

    vector<double> riders(M);

    for(int i=0; i<M; i++){
      cin>>riders[i];
    }

    if(riders[M-1]>=C){
      printf("%f\n", 0.0);
      continue;
    }

    double mid, low=0.0, high=2.0;
    while(low<high){
      mid = (low+high)/2.0;
      double val = checkVal(riders, mid);
      if(abs(C-val)<err)
        break;
      else if(val<C){
        low = mid-err;
      }
      else if(val>C){
        high = mid+err;
      }
    }
    printf("%f\n", mid);
  }
  return 0;
}
