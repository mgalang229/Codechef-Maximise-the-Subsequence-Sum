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
		// sort the sequence in non-decreasing order
		// make sure that the first 'k' elements are converted to positive (if they're negative)
		sort(a.begin(), a.end());
		for (int i = 0; i < k; i++) {
			if (a[i] >= 0) {
				break;
			}
			a[i] *= -1;
		}
		// calculate the sum of all the positive numbers
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				ans += a[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
