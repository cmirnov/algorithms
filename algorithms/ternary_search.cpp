#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x;
}

double ternary_search(double (*f)(double), double l, double r) {
  for (int i = 0; i < (int)(1e6); ++i) {
    double a = (2 * l + r) / 3;
    double b = (l + 2 * r) / 3;
    if (f(a) > f(b)) {
      l = a;
    } else {
      r = b;
    }
  }
  return (r + l) / 2;
}

int main() {
  cout << ternary_search(f, -1, 2);
  return 0;
}
