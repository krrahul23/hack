#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
int grid[101][101];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, b;
	cin >> n >> b;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	int c = 0;
	vector<int>diff;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] & 1)
			c--;
		else
			c++;
		if (c == 0) {
			diff.push_back(abs(a[i] - a[i + 1]));
		}
	}

	int ans = 0;
	for (int i = 0; i <= diff.size(); i++) {
		for (int j = 0; j <= b; j++) {
			if (i == 0 || j == 0) {
				grid[i][j] = 0;
			}
			else if (diff[i - 1] <= j) {
				grid[i][j] = max(grid[i - 1][j - diff[i - 1]] + 1, grid[i][j - 1]);
			}
			else
				grid[i][j] = grid[i - 1][j];
		}
	}
	cout << grid[diff.size()][b] << endl;
	return 0;
}
