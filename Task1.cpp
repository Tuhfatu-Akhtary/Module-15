int hasCycle(int A, vector<vector<int>> &B) {
    vector<int> in_degree(A + 1, 0);
    unordered_map<int, vector<int>> adj_list;

    //Create adjacency list and calculate in-degrees
    for (auto &edge : B) {
        int u = edge[0], v = edge[1];
        adj_list[u].push_back(v);
        in_degree[v]++;
    }

    //Kahn's algorithm (queue with nodes having 0 in-degree)
    queue<int> q;
    for (int i = 1; i <= A; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    int visited_count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited_count++;

        // Reduce in-degree of all neighbors
        for (int neighbor : adj_list[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    // If all nodes are visited, no cycle; otherwise, a cycle exists
    return visited_count == A ? 0 : 1;
}



Time Complexity: O(V+E)
Space Complexity: O(V)