#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > neib; //adjacency list 
int n; //number of vertexs
vector <bool> color;

void bfs() {
	queue <int> q;
	for (int i = 0; i < n; ++i) {
		if (!color[i]) {
    	q.push(i);
			while (!q.empty()) {
				int u = q.front();
				color[u] = true;
				q.pop();
				for (int j = 0; j < neib[u].size(); ++j) {
					int to = neib[u][j];
					if (!color[to]) {
						q.push(to);
					}
				}
			}
		}
  }
	return;
}

int main() {
	bfs();
	return 0;
}
