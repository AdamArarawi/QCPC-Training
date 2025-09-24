#include <bits/stdc++.h>
using namespace std;

vector<int> bfsShortestPath(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);  
    queue<int> q;

    q.push(start);
    dist[start] = 0;  

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(int neighbor : adj[node]) {
            if(dist[neighbor] == -1) { 
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}


int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);

    vector<int> distances = bfsShortestPath(0, adj);

    for(int i = 0; i < n; i++) {
        cout << "Distance from 0 to " << i << " = " << distances[i] << '\n';
    }

    return 0;
}