#include <iostream>
#include <vector>

using namespace std;

// DFS function returns length of longest path
int dfs(int node, vector<bool>& visited, int count, vector<int> graph[]) {
  visited[node] = true;
  int maxCount = count;

  for(int nei : graph[node]) {
    if(!visited[nei]) {
      int currCount = dfs(nei, visited, count + 1, graph);
      maxCount = max(maxCount, currCount);
    }
  }

  return maxCount;
}

int main() {

  int n, m;
  cin >> n >> m;
  
  // Adjacency list representation
  vector<int> graph[n+1];
  
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  vector<bool> visited(n+1, false);
  
  int maxLen = 0;
  for(int i = 1; i <= n; i++) {
    int pathLen = dfs(i, visited, 0, graph);
    maxLen = max(maxLen, pathLen);
  }
  
  cout << maxLen << endl;

  return 0;
}
//amanlabh--github
