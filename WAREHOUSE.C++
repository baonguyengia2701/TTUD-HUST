#include<bits/stdc++.h>

using namespace std;

int warehouse(int n, int T, int D, vector<int> a, vector<int> t) {
	int res = 0;
	int dp[n][T + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		for (int j = t[i]; j <= T; ++j) {
			int maxDp = 0;
			for (int k = 1; k <= D && i - k >= 0; ++k) {
				maxDp = max(maxDp, dp[i - k][j - t[i]]);
			}
			dp[i][j] = maxDp + a[i];
		}
		res = max(res, dp[i][T]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen('data.txt', 'r', stdin);

	int n, T, D;
	vector<int> a, t;

	cin >> n >> T>> D;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		t.push_back(x);
	}
	
	cout << warehouse(n, T, D, a, t);
	return 0;
}