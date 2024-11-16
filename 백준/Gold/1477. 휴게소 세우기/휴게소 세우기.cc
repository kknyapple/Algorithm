#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, m, l;
int a[54];
int tmp[54];
int rest[54];
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	a[n + 1] = l;


	for (int i = 1; i <= n + 1; i++) {
		a[i - 1] = a[i] - a[i - 1];
		tmp[i - 1] = a[i - 1];
	}
	

	int mx = 0;
	int idx = 0;
	while (m--) {
		mx = 0;
		idx = 0;
		for (int i = 0; i <= n; i++) {
			if (mx < tmp[i]) {
				mx = tmp[i];
				idx = i;
			}
		}

		rest[idx]++;
		tmp[idx] = (a[idx] + rest[idx]) / (rest[idx] + 1);
	}


	cout << *max_element(tmp, tmp + n + 1) << "\n";

	// 82 201 411 555 622 755
	// 82 119 210 144 67 133 45
	/*
	82/2 = 41
	119/2 = 60
	210/3 = 70
	144/3 = 48
	67
	133/2 = 67
	45
	*/

	//  101 * 1000 = 100,000
	
	return 0;
}
