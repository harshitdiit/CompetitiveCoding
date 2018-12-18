#include<bits/stdc++.h>
using namespace std;

vector<int> V(4);

int F(int a, int b){
  if(!(a||b)){
    return V[0];
  }
  if(a^b){
    return V[1+a];
  }
  return V[3];
}

int isGood(int a, int b, int c){
  return (F(F(a,b), c) == F(a, F(b,c)));
}

int main(){
  vector<string> A = {"No", "Yes"};

  int T;
  cin>>T; while(T--){
    for(int i=0; i<4; i++){
      cin>>V[i];
    }

    int flag=1;

    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        for(int k=0; k<2; k++){
          flag = flag && isGood(i, j, k);
        }
      }
    }


    cout<<A[flag]<<endl;
  }
  return 0;
}
