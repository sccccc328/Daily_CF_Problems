// https://codeforces.com/problemset/problem/1204/C
#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 1e6 + 10;

int n, m;
int dist[N][N];
int a[M];

void floyd() {
	for (int k = 1; k <= n; k ++ ) {
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	memset(dist, 0x3f, sizeof dist);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j ++ ) {
			if (s[j - 1] == '1')
				dist[i][j] = s[j - 1] - '0';
			else if (i == j) dist[i][j] = 0;
		}
	}

	floyd();

	cin >> m;
	for (int i = 0; i < m; i ++ ) {
		cin >> a[i];
	}
	vector<int> res;

	res.push_back(a[0]);

	for (int i = 1; i < m - 1; i ++ ) {
		if (dist[res.back()][a[i + 1]] == dist[res.back()][a[i]] + dist[a[i]][a[i + 1]]) continue;
		res.push_back(a[i]);
	}
	res.push_back(a[m - 1]);

	cout << res.size() << endl;
	for (int x : res) {
		cout << x << ' ';
	}
	return 0;
}
