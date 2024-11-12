// https://codeforces.com/problemset/problem/847/E
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
string s;

bool check(LL mid) {
	int cnt = 0;
	int last = -1;
	for (int i = 0; i < n; i ++ ) {
		cnt -- ;
		if (s[i] == 'P') {
			if (last == -1) {
				cnt = mid + 1;
				continue;
			}
			if (i - last > mid) return false;
			cnt = max((mid - (i - last)) / 2 + 1, (mid - (i - last) * 2) + 1);
			last = -1;
		} else if (s[i] == '*') {
			if (cnt > 0) last = -1;
			else if (last == -1) {
				last = i;
			}
		}
	}
	if (last != -1) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> s;
	LL l = 0, r = 1e6;

	while (l < r) {
		LL mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
	return 0;
}
