#include<bits/stdc++.h>

using namespace std;

struct heap {
  heap() {
    h.push_back(0);  // heap should starts from h[1]
    n = 0;
  }
  void add(int x) {
    h.push_back(x);
    n++;
    this->shiftUp(n);
  }
  int extractMin() {
    int res = h[1];
    h[1] = h[n];
    h.pop_back();
    n--;
    this->shiftDown(1);
    return res;
  }

 private:
  vector<int> h;
  int n;
  void shiftUp(int idx) {
    while (idx > 1 && h[idx] < h[idx / 2]) {
      swap(h[idx], h[idx / 2]);
      idx /= 2;
    }
  }
  void shiftDown(int idx) {
    while (idx < n) {
      int m = h[idx] < h[2 * idx] ? idx : 2 * idx;
      m = h[m] < h[2 * idx + 1] ? m : 2 * idx + 1;
      if (m == idx)
        break;
      swap(h[idx], h[m]);
      idx = m;
    }
  }
};

int main() {
  heap h;
  h.add(2);
  h.add(3);
  h.add(1);
  cout << h.extractMin() << endl;
  cout << h.extractMin() << endl;
  cout << h.extractMin() << endl;
  return 0;
}

