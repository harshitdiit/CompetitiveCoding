#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, c, state, coins=1000;

  //Subtask 1

  cin>>N>>c;
  if(N<=1000){
    int i=1;
    while(i<=N){
      cout<<1<<" "<<i<<endl;
      cin>>state;
      if(state){
        break;
      }
      else{
        i++;
      }
    }
    cout<<3<<" "<<i<<endl;
  }

  //Subtask 2

  else if(c<=50){
    vector<int> status(N+1, -1);

    int low=1, high=N;
    int mid;

    while(low<high){
      mid = (low+high)/2;
      cout<<1<<" "<<mid<<endl;
      coins-=1;
      cin>>state;

      if(state==0){
        status[mid]=0;
        low = mid+1;
      }

      else{
        if(mid==1 || status[mid-1]==0){
          low=mid;
          if(coins>=c){
            cout<<2<<endl;
          }
          break;
        }
        cout<<2<<endl;
        status[mid]=-1;
        high=mid;
        coins-=c;
      }
    }
    cout<<3<<" "<<low<<endl;
  }

  //Subtask 3

  return 0;
}
