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

int breakCheck(char digits[], int N, int fact1, int fact2){
  int digit_sum=0, flag=1, count_good=0;
  F(i, N){
    digit_sum+=(digits[i]-'0');
    if(digit_sum>fact2){
      return 0;
    }
    if(digit_sum==fact2){
      digit_sum=0;
      count_good++;
    }
  }
  if(digit_sum==0 && count_good==fact1){
    return 1;
  }
  return 0;
}

int main(){
  finput; foutput;
  int N, sum=0, max_digit=0;
  cin>>N;
  char digits[N];
  F(i, N){
    cin>>digits[i];
    sum+=(digits[i]-'0');
    max_digit = max(digits[i]-'0', max_digit);
  }
  if(sum==0){
    cout<<"YES"<<endl;
    return 0;
  }
  int fact1, flag=0;
  for(int i=1; i<=(int)sqrt(sum); i++){
    if(sum%i==0){
      int digit_sum=0;
      fact1 = sum/i;
      flag=(i==1?breakCheck(digits,N,fact1,i):(breakCheck(digits,N,i,fact1)||breakCheck(digits, N, fact1, i)));
      if(flag && sum/i!=1){
        cout<<"YES"<<endl;
        return 0;
      }
      else{
        continue;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
