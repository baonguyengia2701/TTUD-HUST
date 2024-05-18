#include<bits/stdc++.h>


using namespace std;

int GoldMining(int n, int L1, int L2, vector<int> a) {
	int res = 0;
	vector<int> dp(n, 0);
	deque<int> qu;
	for (int i = 0; i < n; ++i) {
		dp[i] = a[i];
		if (!qu.empty() ) {
			dp[i] += dp[qu.front()];
			if (i + 1 - qu.front() > L2) qu.pop_front();
		}

		if (i + 1 - L1 >= 0) {
			while (!qu.empty() && dp[i + 1 - L1] > dp[qu.back()]) qu.pop_back();
			qu.push_back(i + 1 - L1);
		}
		res = max(res, dp[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen('data.txt', 'r', stdin);

	int n, L1, L2;
	vector<int> a;

	cin >> n >> L1 >> L2;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	cout << GoldMining(n, L1, L2, a);
	return 0;
}