#include<bits/stdc++.h>
using namespace std;
long long kadane(vector<long long > &a) {
	long long sum = 0, best = 0;
	for (int i = 0; i < a.size(); i++) {
		sum = max(a[i], sum + a[i]);
		best = max(best, sum);
	}
	return best;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<long long > v;
	for (int i = 0; i < n; ++i)
	{
		long long key;
		cin >> key;
		v.push_back(key);
	}
	int   p = 1;
	vector<long long> a, b;
	for (int i = 0; i < n - 1; i++) {
		p = 1 - p;
		long long num = abs(v[i] - v[i + 1]);
		long long  pw = pow(-1, p);
		a.push_back(num * pw);
		b.push_back(num * (-1) * pw);
	}
	cout << max(kadane(a), kadane(b));
}