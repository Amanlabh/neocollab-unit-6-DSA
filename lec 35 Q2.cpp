#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<int> graph[], vector<int>& path) {
  visited[node] = true;
  path.push_back(node);
  
  for(int nei : graph[node]) {
    if(!visited[nei]) {
      dfs(nei, visited, graph, path); 
    }
  }
}

int main() {

  int V, E;
  cin >> V >> E;

  vector<int> graph[V];

  for(int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u); 
  }

  int startVertex;
  cin >> startVertex;

  vector<bool> visited(V, false);
  vector<int> path;

  cout << "Depth First Traversal starting from vertex " << startVertex << ":" << endl;

  dfs(startVertex, visited, graph, path);

  for(int v : path) {
    cout << v << " "; 
  }

  return 0;
}
//amanlabh--github
