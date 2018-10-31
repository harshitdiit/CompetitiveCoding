//Ques : https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/description/


#include<bits/stdc++.h>
using namespace std;

void transposeGraph(vector<vector<int> > &G, vector<vector<int> > &GT){
    for(int i=1; i<G.size(); i++){
        for(int j=0; j<G[i].size(); j++){
            GT[G[i][j]].push_back(i);
        }
    }
    return;
}

void topsort(vector<vector<int> > &G, stack<int> &S, vector<bool> &visited, int src){
    visited[src]=true;
    for(int i=0; i<G[src].size(); i++){
        if(!visited[G[src][i]])
            topsort(G, S, visited, G[src][i]);
    }
    S.push(src);
}

void dfs(vector<vector<int> > &GT, vector<bool> &visited, vector<int> &scc, int src){
    visited[src]=true;
    scc.push_back(src);

    for(int i=0; i<GT[src].size(); i++){
        if(!visited[GT[src][i]])
            dfs(GT, visited, scc, GT[src][i]);
    }
}

int main(){
    int V, E, src, dest;
    cin>>V>>E;
    vector<vector<int> > G(V+1), GT(V+1);
    for(int i=0; i<E; i++){
        cin>>src>>dest;
        G[src].push_back(dest);
    }
    vector<bool> visited(V+1, false), isCyclic(V+1, false);
    stack<int> S;

    for(int i=1; i<G.size(); i++){
        if(!visited[i])
            topsort(G, S, visited, i);
    }

    transposeGraph(G, GT);

    /*for(int i=1; i<GT.size(); i++){
        cout<<i<<" : ";
        for(int j=0; j<GT[i].size(); j++){
            cout<<GT[i][j]<<" ";
        }
        cout<<endl;
    }*/

    visited = isCyclic;
    vector<int> scc;

    while(!S.empty()){
        int i = S.top();
        S.pop();

        scc.clear();

        if(!visited[i])
            dfs(GT, visited, scc, i);

        /*cout<<"SCC : ";
        for(int i=0; i<scc.size(); i++)
            cout<<scc[i]<<" ";
        cout<<endl;*/

        if(scc.size()>1)
            for(int i=0; i<scc.size(); i++)
                isCyclic[scc[i]]=true;
    }

    for(int i=1; i<isCyclic.size(); i++)
        cout<<isCyclic[i]<<" ";

    return 0;
}
