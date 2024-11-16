#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n;
int ans, a[1004], sum[1000004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum[idx++] = a[i] + a[j];
		}
	}
	sort(sum, sum + idx);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (j >= i) continue;
			if (binary_search(sum, sum + idx, a[i] - a[j])) {
				cout << a[i] << "\n";
				return 0;
			}
		}
	}
	
	/* for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j)continue;
			for (int k = j + 1; k < n; k++) {
				if (i == k || j == k) continue;
				ll tmp = a[i] + a[j] + a[k];
				if (binary_search(a, a + n, tmp)) ans = tmp;
			}
		}
	}*/

	// cout << ans << "\n";

	return 0;
}
