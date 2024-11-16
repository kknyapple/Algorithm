#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int t, k;
char com;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		multiset <int> ms;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> com >> n;
			if (com == 'I') ms.insert(n);
			else {
				if (!ms.empty()) {
					if (n == -1) {
						ms.erase(ms.begin());
					}
					else {
						ms.erase(prev(ms.end()));
					}
				}
			}
		}

		if (ms.empty())cout << "EMPTY" << "\n";
		else cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
	}

	return 0;
}
