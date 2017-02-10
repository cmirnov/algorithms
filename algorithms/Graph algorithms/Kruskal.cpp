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
    return parent[u] == u ? u : (parent[u] = get(parent[u]));
  }

  void join (int u, int v) {
    parent[get(u)] = get(v);
  }

  bool is (int u, int v) {
    return get(u) == get(v);
  }
};

struct Edge {
  int u, v, w;
};

int main() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    Edge cur;
    cin >> cur.v >> cur.u >> cur.w;
    edges.push_back(cur);
  }
  sort(edges.begin(), edges.end(), [] (Edge a, Edge b) { return a.w < b.w; });
  vector <Edge> mst;
  for (int i = 0; i < m; ++i) {
    Edge temp = edges[i];
    if (dsu.get(temp.u) != dsu.get(temp.v)) {
      mst.push_back(temp);
      dsu.join(temp.u, temp.v);
    }
  }
  for (int i = 0; i < mst.size(); ++i) {
    cout << mst[i].u << " " << mst[i].v << '\n';
  }
  return 0;
}
