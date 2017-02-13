#include <bits/stdc++.h>

using namespace std;

int lower_bound (vector <int> a, int pat) {
  int l = 0;
  int r = a.size();
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (a[mid] <= pat) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  return l;
}

int main() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int pat;
  cin >> pat;
  cout << lower_bound(a, pat);
  return 0;
}
