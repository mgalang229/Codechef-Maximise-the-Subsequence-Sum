#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// create a copy of vector 'a' and sort it in non-decreasing order
		vector<int> copy_a = a;
		sort(copy_a.begin(), copy_a.end());
		multiset<int> ms;
		for (int i = 0; i < k; i++) {
			ms.insert(copy_a[i]);
		}
		// change the first 'k' elements from the 'copy_a' vector to positive (if they're negative)
		// apply the change to the original vector (since we need to get the maximum subseqeuence from it)
		for (int i = 0; i < n; i++) {
			if (ms.find(a[i]) != ms.end()) {
				ms.erase(ms.find(a[i]));
				if (a[i] < 0) {
					a[i] *= -1;
				}
			}
		}
		// only take the sum of all positive numbers (it's better to use 0 than to take negative numbers)
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				sum += a[i];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
