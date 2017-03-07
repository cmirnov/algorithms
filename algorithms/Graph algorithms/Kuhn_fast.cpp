#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> neib;
vector<int> mt;
vector<bool> used;
vector<int> p;

bool try_kuhn(int u) {
  if (used[u]) {
    return false;
  }
  used[u] = true;
  for (int i = 0; i < neib[u].size(); ++i) {
    int to = neib[u][i];
    if (mt[to] == -1) {
      mt[to] = u;
      p[u] = to;
      return true;
    }
  }
  for (int i = 0; i < neib[u].size(); ++i) {
    int to = neib[u][i];
    if (try_kuhn(mt[to])) {
      mt[to] = u;
      p[u] = to;
      return true;
    }
  }
  return false;
}

int main() {
  int n, m, num_edges;
  cin >> n >> m >> num_edges;
  neib.resize(n);
  mt.resize(m, -1);
  p.resize(n);
  used.resize(n);
  for (int i = 0; i < num_edges; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    neib[u].push_back(v);
  }
  int ans = 0;
  while (true) {
    fill(used.begin(), used.end(), false);
    bool check = true;
    for (int i = 0; i < n; ++i) {
      if (!used[i] && try_kuhn(i)) {
				ans++;
        check = false;
      }
    }
    if (check) {
      break;
    }
  }
  cout << (ans == n);
}

