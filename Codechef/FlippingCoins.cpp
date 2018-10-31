#include<bits/stdc++.h>
using namespace std;

void lazyUpdate(vector<int> &Tree, vector<int> &Lazy, int node, int start, int end, int L, int R){
  if(Lazy[node]!=0){
    Tree[node] = (end-start+1)-Tree[node];
    if(start!=end){
      Lazy[2*node+1] = 1-Lazy[2*node+1];
      Lazy[2*node+2] = 1-Lazy[2*node+2];
    }
    Lazy[node]=0;
  }

  if(start>end || L>end || R<start){
    return;
  }

  if(start>=L && end<=R){
    Tree[node] = (end-start+1)-Tree[node];
    if(start!=end){
      Lazy[2*node+1] = 1-Lazy[2*node+1];
      Lazy[2*node+2] = 1-Lazy[2*node+2];
    }
    return;
  }

  int mid = (end-start)/2 + start;
  lazyUpdate(Tree, Lazy, 2*node+1, start, mid, L, R);
  lazyUpdate(Tree, Lazy, 2*node+2, mid+1, end, L, R);

  Tree[node] = Tree[2*node+1]+Tree[2*node+2];
}

int lazyQuery(vector<int> &Tree, vector<int> &Lazy, int node, int start, int end, int L, int R){
  if(Lazy[node]!=0){
    Tree[node] = (end-start+1)-Tree[node];
    if(start!=end){
      Lazy[2*node+1] = 1-Lazy[2*node+1];
      Lazy[2*node+2] = 1-Lazy[2*node+2];
    }
    Lazy[node]=0;
  }

  if(start>end || L>end || R<start){
    return 0;
  }

  if(start>=L && end<=R){
    return Tree[node];
  }

  int mid = (end-start)/2 + start;
  return lazyQuery(Tree, Lazy, 2*node+1, start, mid, L, R) + lazyQuery(Tree, Lazy, 2*node+2, mid+1, end, L, R);
}

int main(){

  int N, Q;
  cin>>N>>Q;

  vector<int> Tree(4*N+5, 0), Lazy(4*N+5, 0);
  int T, L, R;
  while(Q--){
    cin>>T>>L>>R;
    if(!T){
      lazyUpdate(Tree, Lazy, 0, 0, N-1, L, R);
    }
    else{
      cout<<lazyQuery(Tree, Lazy, 0, 0, N-1, L, R)<<endl;
    }
  }
  return 0;
}
