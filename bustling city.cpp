#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj_matrix, int start_vertex) {
    int V = adj_matrix.size();
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> result;

    visited[start_vertex] = true;
    q.push(start_vertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);

        for (int neighbor = 0; neighbor < V; ++neighbor) {
            if (adj_matrix[vertex][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj_matrix(V, vector<int>(V, 0));

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
    }

    int start_vertex = 0; // Change this to the desired starting vertex

    vector<int> result = bfs(adj_matrix, start_vertex);

    for (int vertex : result) {
        cout << vertex << " ";
    }

    return 0;
}
//amanlabh--gihtub
