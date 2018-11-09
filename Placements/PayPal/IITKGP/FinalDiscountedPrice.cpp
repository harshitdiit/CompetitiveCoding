// Ques at https://imgur.com/9u7UqUo

#include<bits/stdc++.h>
using namespace std;

int findPrice(vector<int> &V, stack<int> &priceIndex){
  stack<int> S;
  int totalPrice = 0;

  for(int i=V.size()-1; i>-1; i--){
    while(!S.empty() && V[S.top()]>V[i]){
      S.pop();
    }
    if(!S.empty()){
      totalPrice+=V[i]-V[S.top()];
      S.push(i);
    }
    else{
      priceIndex.push(i);
      S.push(i);
      totalPrice+=V[i];
    }
  }

  return totalPrice;
}

int main(){
  int N;
  cin>>N;
  vector<int> V(N);
  for(int i=0; i<N; i++){
    cin>>V[i];
  }
  stack<int> priceIndex;
  int totalPrice = findPrice(V, priceIndex);
  cout<<totalPrice<<endl;
  while(!priceIndex.empty()){
    cout<<priceIndex.top()<<" ";
    priceIndex.pop();
  }
  return 0;
}
