#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, k;
int a[10004];
ll res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	ll s = 1, e = *max_element(a, a+k);
	while (s <= e) {
		ll mid = (s + e) / 2;
		int cnt = 0;

		for (int i = 0; i < k; i++) {
			cnt += a[i] / mid;
		}

		if (cnt >= n) {
			res = max(res, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	cout << res << "\n";

	return 0;
}
