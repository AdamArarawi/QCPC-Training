#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) {
                return true; 
            }
        }
        return true;
    }

    /*
        ###################################################################################
    */

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }

        if (n == 1 && edges.size() == 0) {
            return true;
        }

        map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        deque<int> q;
        q.push_back(source);
        while (!q.empty())
        {
            int node = q.front();
            q.pop_front();
            if (node == destination) {
                return true;
            }


            if (!visited[node]) {
                visited[node] = true;
                for (int i : graph[node]) {
                    if (!visited[i]){
                        q.push_back(i);
                    }
                }
            }
        }
        return false;   
    }

    /*
        ###################################################################################
    */

    void dfsnumIslands(vector<vector<char>>& grid, int i, int j) {
        stack<pair<int,int>> st;
        st.push({i,j});
        while (!st.empty())
        {
            pair<int, int> node = st.top(); st.pop();
            int x = node.first;
            int y = node.second;
            if (x < 0 || x >= grid.size() || y < 0 || y >=  grid[x].size() || grid[x][y] == '0') {
                continue;
            }

            grid[x][y] = '0';
            st.push({x + 1, y});
            st.push({x - 1, y});
            st.push({x, y + 1});
            st.push({x, y - 1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int numOfIslands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    numOfIslands++;
                    dfsnumIslands(grid, i, j);
                }
            }
        }
        return numOfIslands;
    }


    /*
        ###################################################################################
    */

    int dfsmaxAreaOfIsland(vector<vector<int>>& grid, int i, int j) {
        stack<pair<int,int>> st;
        st.push({i,j});
        int islandSize = 0;
        while (!st.empty())
        {
            pair<int, int> node = st.top(); st.pop();
            int x = node.first;
            int y = node.second;
            if (x < 0 || x >= grid.size() || y < 0 || y >=  grid[x].size() || grid[x][y] == 0) {
                continue;
            }
            islandSize++;
            grid[x][y] = 0;
            st.push({x + 1, y});
            st.push({x - 1, y});
            st.push({x, y + 1});
            st.push({x, y - 1});
        }
        return islandSize;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int maxSize = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    
                    maxSize = max( maxSize, dfsmaxAreaOfIsland(grid, i, j));
                }
            }
        }
        return maxSize;
    }

    /*
        ###################################################################################
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &p : prerequisites)
            graph[p[0]].push_back(p[1]); 

        vector<bool> visited(numCourses, false); 
        vector<bool> path(numCourses, false);

        for(int i = 0; i < numCourses; ++i) {
            if(visited[i]) continue;

            stack<int> st;
            st.push(i);

            while(!st.empty()) {
                int node = st.top();

                if(path[node]) {
                    return false;
                }

                if(visited[node]) {
                    st.pop();
                    path[node] = false;
                    continue;
                }

                path[node] = true;
                bool hasUnvisited = false;

                for(int neighbor : graph[node]) {
                    if(!visited[neighbor] && !path[neighbor]) {
                        st.push(neighbor);
                        hasUnvisited = true;
                    }
                    else if(path[neighbor]) {
                        return false; 
                    }
                }

                if(!hasUnvisited) {
                    visited[node] = true;
                    path[node] = false;
                    st.pop();
                }
            }
        }
        return true;
    }
};
