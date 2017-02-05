#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > neib;
vector<int> ans;

vector<bool> color;
int n;


void dfs(int u) {
  color[u] = true;
  for (int i = 0; i < neib[u].size(); ++i) {
    int to = neib[u][i];
    if (!color[to]) {
      dfs(to);
    }
  }
  ans.push_back(u);
  return;
}
void topological_sort() {
  for (int i = 0; i < n; ++i) {
    if (!color[i]) {
      dfs(i);
    }
  }
  reverse(ans.begin(), ans.end());
  return;
}

int main() {
  cin >> n;
  neib.resize(n);
  color.resize(n);
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    while (cur != 0) {
      neib[i].push_back(cur - 1);
      cin >> cur;
    }
  }
  topological_sort();
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}
