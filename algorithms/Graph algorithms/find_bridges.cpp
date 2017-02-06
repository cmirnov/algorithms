#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > neib;
vector<bool> color;
vector<int> tin;
vector<int> fup;
int curTime = 0;

void dfs (int u, int p = -1) {
  color[u] = true;
  tin[u] = fup[u] = curTime++;
  for (int i = 0; i < neib[u].size(); ++i) {
    int to = neib[u][i];
    if (to == p) {
      continue;
    }
    if (color[to]) {
      fup[u] = min(fup[u], tin[to]);
    }
    else {
      dfs(to, u);
      if (fup[to] > tin[u]) {
        cout << u + 1 << " " << to + 1 << '\n';
      }
      fup[u] = min(fup[u], fup[to]);
    }
  }
  return;
}

void find_bridges(int n, int m) {
  color.resize(n, false);
  tin.resize(n);
  fup.resize(n);
  for (int i = 0; i < n; ++i) {
    if (!color[i]) {
      dfs(i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  neib.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    neib[u - 1].push_back(v - 1);
    neib[v - 1].push_back(u - 1);
  }
  find_bridges(n, m);
}
