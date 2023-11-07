#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to print shortest path 
void printShortestPath(vector<int> prev, int source, int dest) {
  vector<int> path;

  int curr = dest;
  while (curr != source) {
    path.push_back(curr);
    curr = prev[curr];
  }

  path.push_back(source);

  cout << "Shortest path length is: " << path.size() - 1 << "\n";
  cout << "Path is: ";
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << " ";
  }
}

// Function for BFS traversal
void bfs(vector<vector<int>> graph, int source, int dest) {
  
  vector<bool> visited(graph.size(), false);
  vector<int> prev(graph.size(), -1);
  queue<int> q;

  q.push(source);
  visited[source] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == dest) {
      printShortestPath(prev, source, dest);
      return; 
    }

    for (int v : graph[u]) {
      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
        prev[v] = u;
      }
    }
  }
}

int main() {

  int v, e;
  cin >> v >> e;

  vector<vector<int>> graph(v);

  for (int i = 0; i < e; i++) {
    int src, dest;
    cin >> src >> dest;

    graph[src].push_back(dest);
    graph[dest].push_back(src); 
  }

  int source, destination;
  cin >> source >> destination;

  bfs(graph, source, destination);

  return 0;
}
//amanlabh--github
