#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int dest, vector<bool>& visited, vector<int> graph[]) {
  visited[node] = true;

  if (node == dest) {
    return true; 
  }

  for (int nei : graph[node]) {
    if (!visited[nei]) {
      if (dfs(nei, dest, visited, graph)) {
        return true;
      }
    }
  }

  return false;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> graph[n];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int start, end;
  cin >> start >> end;

  vector<bool> visited(n, false);

  if (dfs(start, end, visited, graph)) {
    cout << "There is a path from " << start << " to " << end << "\n";
  } else {
    cout << "There is no path from " << start << " to " << end << "\n"; 
  }

  return 0;
}
//amanlabh--github
