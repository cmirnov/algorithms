#include <bits/stdc++.h>
#include <math.h>

using namespace std;


struct pt{
	long long x, y;
	
	bool operator <(const pt &p){
		return x < p.x || (x == p.x && y < p.y);
	}
};

long long ccw(pt &a, pt &b, pt &c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector <pt> convex(vector <pt> arr){
	int n = arr.size();
	vector <pt> ans(2 * n);
	int k = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; ++i){
		while (k >= 2 && ccw(ans[k - 2], ans[k - 1], arr[i]) <= 0) k--;
		ans[k++] = arr[i];
	}
	
	for (int i = n - 2, t = k + 1; i >= 0; --i){
		while (k >= t && ccw(ans[k - 2], ans[k - 1], arr[i]) <= 0) k--;
		ans[k++] = arr[i];
	}
	ans.resize(k - 1);
	return ans;
}


vector <pt> t;

int main(){
	int n;
	cin >> n;
	t.resize(n);
	for (int i = 0;i  < n; ++i){
		cin >> t[i].x >> t[i].y;
	}
	t = convex(t);
	return 0;
}