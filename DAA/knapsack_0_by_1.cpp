/******************************************************************************
BunnyTHEcoder
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> weight(n), profit(n);
	for (int i = 0; i < n; ++i) cin >> weight[i];
	for (int i = 0; i < n; ++i) cin >> profit[i];
	int capacity;
	cin >> capacity;
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= capacity; ++j) {
			if (weight[i - 1] <= j)
				dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
			cerr << endl;
		}
	}
	cout << dp[n][capacity] << endl;
}
