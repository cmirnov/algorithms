#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
int n, m;

struct Edge {
  int u, v, w;
};

vector <Edge> edges;
vector <int> d;

void FB(int v) {
  d[v] = 0;
  while (true) {
    bool isWork = false;
    for (int i = 0; i < m; ++i) {
      Edge temp = edges[i];
      if (d[temp.u] < INF) {
        if (d[temp.v] > d[temp.u] + temp.w) {
          d[temp.v] = min(d[temp.v], d[temp.u] + temp.w);
          isWork = true;
        }
      }
    }
    if (!isWork) {
      return;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    Edge temp;
    cin >> temp.u >> temp.v >> temp.w;
    temp.u--;
    temp.v--;
    edges.push_back(temp);
  }
  d.resize(n, INF);
  FB(0);
  for (int i = 0; i < n; ++i) {
    cout << d[i] << " ";
  }
}
