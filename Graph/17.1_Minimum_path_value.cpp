/*
There is a weighted undirected graph with N nodes and M edges. 
The stress level of a path between two nodes is defined as the weight of the edge with the maximum value present in the path. 
Given a source node "source" and a destination node " destination".
find a path with the minimum stress level. If no such path exists, report -1.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin>>n >>m ;
    vector<pair<int , int>> adj[n+1];
    for(int i=0;i<m ;i++){
        int u , v , w;
        cin>>u>>v>>w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }
    int src , des;
    cin>>src>>des;
    vector<int> dist(n+1 , INT_MAX);
    priority_queue<pair<int , int>> pq;
    pq.push({0 , src});
    dist[src]=0;
    while(!pq.empty()){
        int dis= pq.top().first;
        int prev= pq.top().second;
        pq.pop();
        for(auto it: adj[prev]){
            int next= it.first;
            int nextweight= it.second;
            if(dist[next]> max(dist[prev],nextweight)){
                dist[next]=max(dist[prev], nextweight);
                pq.push({dist[next], next});
            }
        }
    }
    cout<<dist[des]<<endl;
}   