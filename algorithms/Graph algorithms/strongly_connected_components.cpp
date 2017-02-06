#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > neib;
vector<vector<int> > neibR;

vector<bool> used;

vector<int> order;
vector<int> comp;

void dfs1(int u) {
  used[u] = true;
  for (int i = 0; i < neib[u].size(); ++i) {
    int to = neib[u][i];
    if (!used[to]) {
      dfs1(to);
    }
  }
  order.push_back(u);
  return;
}

void dfs2(int u) {
  comp.push_back(u);
  used[u] = true;
  for (int i = 0; i < neibR[u].size(); ++i) {
    int to = neibR[u][i];
    if (!used[to]) {
      dfs2(to);
    }
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  neib.resize(n);
  neibR.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    neib[u - 1].push_back(v - 1);
    neibR[v - 1].push_back(u - 1);
  }
  used.resize(n);
  fill(used.begin(), used.end(), false);
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  fill(used.begin(), used.end(), false);
  for (int i = 0; i < n; ++i) {
    int u = order[n - 1 - i];
    if (!used[u]) {
      dfs2(u);
      for (int j = 0; j < comp.size(); ++j) {
        cout << comp[j] + 1 << " ";
      }
      cout << '\n';
      comp.clear();
    }
  }
  return 0;
}

