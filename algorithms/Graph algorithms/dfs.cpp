#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > neib; // adjacency list
vector<bool> color;

void dfs(int u) {
  if (color[u]) {
    return;
  }
  color[u] = true;
  for (int i = 0; i < neib[u].size(); ++i) {
    int to = neib[u][i];
    if (!color[to]) {
      dfs(to);
    }
  }
  return;
}

int main() {
  dfs(0);
  return 0;
}

