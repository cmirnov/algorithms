#include <bits/stdc++.h>

using namespace std;

class DSU {
  vector <int> parent;
public:

  DSU (int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int get (int u) {
  //return parent[u] == u ? u : get(parent[u]);
    return parent[u] == u ? u : (parent[u] = get(parent[u]));
  }

  void join (int u, int v) {
    parent[get(u)] = get(v);
  }

  bool is (int u, int v) {
    return get(u) == get(v);
  }
};

int main() {

  return 0;
}
