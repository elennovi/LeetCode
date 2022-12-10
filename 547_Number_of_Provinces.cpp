class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n_nodes = isConnected.size();
        vector<bool> visited(n_nodes, 0); // n nodes, initialized to 0

        // connected components
        int conn_compo = 0;
        for(int i = 0; i < n_nodes; ++i){
            if (!visited[i]) {// not visited -> new connected component
                dfs(i, isConnected, visited); // run a dfs from i
                ++conn_compo;
            }
        }
        return conn_compo;
    }
private: 
    void dfs(int curr, vector<vector<int>> const& isConnected, vector<bool>& visited){
        int n_nodes = isConnected.size();
        visited[curr] = true;
        for(int i = 0; i < n_nodes; ++i) { 
            if (curr != i && !visited[i] && isConnected[curr][i]) // not the same node, not visited and adjacent
                dfs(i, isConnected, visited);
        }
    }

};

// [[1,0,0,1],
//  [0,1,1,0],
//  [0,1,1,1],
//  [1,0,1,1]]
