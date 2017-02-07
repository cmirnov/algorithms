#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> color;
    vector<vector<int> > sets;
  public:
    DSU (int n) {
      color.resize(n);
      sets.resize(n);
      for (int i = 0; i < n; ++i) {
        color[i] = i;
        sets[i].push_back(i);
      }
      return;
    }
    
    int get (int v) {
      return color[v];
    }

    void join (int u, int v) {
      if (color[u] != color[v]) {
        int idx1 = color[u];
        int idx2 = color[v];
        if (sets[idx1].size() < sets[idx2].size()) {
          for (int i = 0; i < sets[idx1].size(); ++i) {
            sets[idx2].push_back(sets[idx1][i]);
            color[sets[idx1][i]] = color[idx2];
          }
          sets[idx1].clear();
        }
        else {
          for (int i = 0; i < sets[idx2].size(); ++i) {
            sets[idx1].push_back(sets[idx2][i]);
            color[sets[idx2][i]] = color[idx1];
          }
          sets[idx2].clear();
        }
      }
      return;
    }

    bool is (int u, int v) {
      return color[u] == color[v];
    }
};

int main() {
  return 0;
}
