// Ques at https://imgur.com/7Y5zlLC

#include<bits/stdc++.h>
using namespace std;

void cycleFind(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &stacked, int parent, int &cycleStart){
  if(!visited[parent]){
    visited[parent]=true;
    stacked[parent]=true;
    for(int i=0; i<graph[parent].size(); i++){
      if(!visited[graph[parent][i]])
        cycleFind(graph, visited, stacked, graph[parent][i], cycleStart);
      else{
        if(stacked[graph[parent][i]]){
          cycleStart = graph[parent][i];
        }
        if(cycleStart!=-1)
          return;
      }
    }
  }
  stacked[parent]=false;
  return;
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int &curtime, vector<int> &dtime, int parent){
  visited[parent]=true;
  dtime[parent]=curtime;
  for(int i=0; i<graph[parent].size(); i++){
    if(!visited[graph[parent][i]]){
      curtime++;
      dfs(graph, visited, curtime, dtime, graph[parent][i]);
    }
  }
  return;
}

int main(){
  int N, M, parent_task;
  cin>>N;

  vector<vector<int>> graph(N+1);

  cin>>M;
  vector<int> tasks(M);
  for(int i=0; i<M; i++){
    cin>>tasks[i];
  }
  cin>>M;
  for(int i=0; i<M; i++){
    cin>>parent_task;
    graph[parent_task].push_back(tasks[i]);
  }
  int tasks_possible=0;
  vector<bool> visited(N+1, false), stacked(N+1, false);
  vector<int> dtime(N+1);
  int cycleStart = -1, curtime = 1;

  for(int i=1; i<N+1; i++){
    if(!visited[i]){
      vector<bool> tempV = visited;
      cycleStart=-1;
      cycleFind(graph, tempV, stacked, i, cycleStart);
      curtime=1;
      dfs(graph, visited, curtime, dtime, i);
      if(cycleStart!=-1)
        tasks_possible+=dtime[cycleStart]-1;
      else
        tasks_possible+=curtime;
    }
  }
  cout<<tasks_possible<<endl;
  return 0;
}
