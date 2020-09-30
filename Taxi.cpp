#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int key;
	vector<int> a(4);
	for (int i = 0; i < n; i++)
	{
		cin >> key;
		a[key % 4]++;
	}
	int taxi = 0;
	taxi += a[0] + a[3];
	if (a[2] % 2 == 0)
	{
		taxi = taxi + a[2] / 2;
	}
	else
	{
		taxi += a[2] / 2 + 1;
	}
	if (a[1] > a[3])
	{
		a[1] -= a[3];
		if (a[2] % 2 != 0)
		{
			a[1] = a[1] - 2;
		}
		if (a[1] > 0)
		{
			taxi = taxi + ceil(((double)a[1]) / 4);
		}

	}
	cout << taxi;
}
