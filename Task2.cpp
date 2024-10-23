int dfs(int node, int parent, vector<int> &A, unordered_map<int, vector<int>> &adj_list, int good_count, int C) {
    if (A[node - 1] == 1)
        good_count++;  // Increment good node count if this node is good

    if (good_count > C)  // If good node count exceeds C, this path is not valid
        return 0;

    // Check if this is a leaf node (only connected to its parent)
    bool is_leaf = adj_list[node].size() == 1 && node != 1;
    if (is_leaf)
        return 1;

    int valid_paths = 0;
    for (int neighbor : adj_list[node]) {
        if (neighbor != parent)
            valid_paths += dfs(neighbor, node, A, adj_list, good_count, C);
    }
    return valid_paths;
}

int countValidPaths(vector<int> &A, vector<vector<int>> &B, int C) {
    unordered_map<int, vector<int>> adj_list;

    // Create adjacency list from edges
    for (auto &edge : B) {
        int u = edge[0], v = edge[1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // Start DFS from the root node (node 1)
    return dfs(1, -1, A, adj_list, 0, C);
}



Time Complexity: O(N)
Space Complexity: O(N)

//N is the number of Nodes