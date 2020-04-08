#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool pair_match(pair<int, int> p1, pair<int, int> p2){
	return (p1.first == p2.first && p1.second == p2.second) 
		|| (p1.first == p2.second && p1.second == p2.first);
}

long long dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &weights, pair<int, int> e1, pair<int, int> e2){
	long long sum = weights[node];
	visited[node] = 1;
	for(auto i : graph[node]){
		if(!visited[i] && !pair_match(e1, make_pair(node, i)) 
		&& !pair_match(e2, make_pair(node, i))){
			sum+=dfs(i, graph, visited, weights, e1, e2);
		}
	}
	return sum;
}

int main(){
	int N, Q, u, v;
	scanf("%d %d", &N, &Q);

	vector<int> weights(N), visited; 
	vector<pair<int, int>> edges;
	vector<vector<int>> graph(N);

	for(int i=0; i<N; i++){
		scanf("%d", &weights[i]);
	}

	for(int i=0; i<N-1; i++){
		scanf("%d %d", &u, &v);
		edges.push_back(make_pair(u-1, v-1));
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}

	for(int i=0; i<Q; i++){
		scanf("%d %d", &u, &v);
		visited = vector<int>(N);

		long long product = 1;

		for(int i=0; i<N; i++){
			if(!visited[i]){
				product = (product * dfs(i, graph, visited, weights, edges[u-1], edges[v-1]) % mod) % mod;
			}
		}

		printf("%lld\n", product<0?mod+product:product);
	}
	return 0;
}