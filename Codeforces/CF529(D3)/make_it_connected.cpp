#include<bits/stdc++.h>
using namespace std;

long long cost[200005];

bool comp(int &x, int &y){
  if(cost[x]==cost[y])
    return x<y;
  return cost[x]<cost[y];
}

int root(vector<int> &V, int i){
  int r = i;
  while(V[r]!=r){
    V[r]=V[V[r]];
    r = V[r];
  }
  return r;
}

void unionize(vector<int> &V, vector<int> &size, int A, int B){
  int root_A = root(V, A);
  int root_B = root(V, B);
  if(size[root_A] < size[root_B ]){
		V[root_A] = V[root_B];
		size[root_B] += size[root_A];
	}
  else {
		V[root_B] = V[root_A];
		size[root_A] += size[root_B];
	}
}

int main(){
  int N, M, mincoster=-1;
  long long mincost=LONG_MAX;

  cin>>N>>M;
  vector<int> V(N), P(N), size(N, 1);

  for(int i=0; i<N; i++){
    cin>>cost[i];
    V[i]=i; P[i]=i;
    if(cost[i]<mincost){
      mincoster=i;
      mincost=cost[i];
    }
  }
  sort(P.begin(), P.end(), comp);

  vector<tuple<long long, int, int>> O(M);

  long long w;
  int x, y;

  for(int i=0; i<M; i++){
    cin>>x>>y>>w;
    O[i]=make_tuple(w, x-1, y-1);
  }
  sort(O.begin(), O.end());

  long long total=0;

  for(auto z:O){
    w=get<0>(z); x=get<1>(z); y=get<2>(z);
    long long minc = cost[x]+cost[y];
    minc = minc+((x!=mincoster)+(y!=mincoster))*mincost;

    if(w+mincost+min(cost[x], cost[y])<=minc && root(V, x)!=root(V, y)) {
      total+=w;
      unionize(V, size, x, y);
      //cout<<"OFFER APPLIED "<<x<<" "<<y<<"\n";
      //cout<<"Total : "<<total<<"\n\n";
    }
  }

  for(int i=0; i<N; i++){
    if(root(V, P[i])!=root(V, mincoster)){
      unionize(V, size, mincoster, P[i]);
      total+=(mincost+cost[P[i]]);

      //cout<<"UNION "<<mincoster<<" "<<P[i]<<"\n";
      //cout<<"Total : "<<total<<"\n\n";
    }
  }

  cout<<total;
  return 0;
}
