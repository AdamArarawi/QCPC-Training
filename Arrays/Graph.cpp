#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& graph, int node) {
    vector<bool> visited(graph.size(), false);
    deque<int> q;
    q.push_back(node);

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop_front();
        if (!visited[current_node]) {
            cout << current_node << '\n';
            visited[current_node] = true;
            for (int i : graph[current_node]) {
                if (!visited[i]) {
                    q.push_back(i);
                }
            }
        }
        
    }
}

void dfs (const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    vector<int> st;

    st.push_back(start);
    while (!st.empty())
    {
        int node = st.back(); st.pop_back();
        if (!visited[node]) {
            cout << node << '\n';
            visited[node] = true;

            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (!visited[*it]) {
                    st.push_back(*it);
                }
            }
        }
    }
    
    
}

int main () {
    vector<vector<int>> graph(5);

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);

    graph[2].push_back(0);
    graph[2].push_back(4);

    graph[3].push_back(1);

    graph[4].push_back(2);

    bfs(graph, 0);
    cout << "###################" << '\n';
    dfs(graph, 0);
    return 0;
}


//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void helper (TreeNode* node, string path, vector<string>& paths) {
        if (!node) {
            paths.push_back(path);
            return;
        }
        if (path != "") path += "->";
        path += to_string(node->val);
        if (node->left) helper(node->left, path, paths);
        if (node->right) helper(node->right, path, paths);
        if (!node->right && !node->left) paths.push_back(path);
        return;
    } 
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        helper(root, "", paths);
        return paths;
    }
};


bool dfsCycleUndir(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for(int neigh : graph[node]){
        if(!visited[neigh]){
            if(dfsCycleUndir(neigh, node, graph, visited))
                return true;
        } else if(neigh != parent){
            return true;
        }
    }
    return false;
}

bool dfsCycleDir(int node, vector<vector<int>>& graph, vector<bool>& path, vector<bool>& visited) {
    visited[node] = true;
    path[node] = true;

    for (int it: graph[node]) {
        if (!visited[it]){
            if (dfsCycleDir(it, graph, path, visited)) {
                return true;
            }
        }
        else if (path[it]) {
            return true;
        }
    }

    path[node] = false;
    return false;
}

void dfsTopo(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for(int neigh : graph[node]){
        if(!visited[neigh])
            dfsTopo(neigh, graph, visited, st);
    }
    st.push(node);
}
