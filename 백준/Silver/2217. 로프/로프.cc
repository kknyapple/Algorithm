#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, a[100004];
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		res = max(res, a[i] * (n - i));
	}

	cout << res << "\n";
	
	return 0;
}
