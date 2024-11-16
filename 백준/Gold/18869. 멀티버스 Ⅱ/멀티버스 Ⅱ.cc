#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <stack>
using namespace std;

int n, m, p;
int ori[104][10004];
int a[104][10004];
int res;
vector<pair<int, int>> v[104];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p;
			v[i].push_back({p, j});
		}
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 0; i < m ; i++) {
		for (int j = i + 1; j < m; j++) {
			res++;
			for (int k = 0; k < n; k++) {
				if (v[i][k].second != v[j][k].second) {
					res--;
					break;
				}

				if (k == n - 1) continue;

				int tmp1 = v[i][k].first - v[i][k + 1].first;
				int tmp2 = v[j][k].first - v[j][k + 1].first;

				if (tmp1 > 0 && tmp2 > 0) continue;
				if (tmp1 < 0 && tmp2 < 0) continue;
				if (tmp1 == 0 && tmp2 == 0) continue;

				res--;
				break;

			}
		}
	}

	//1 1 1 
	//1 2 3

	//1 1 3 5 4 -> 0 1 2 4 5, 1 1 3 4 5
	//1 2 3 8 5 -> 0 1 2 4 5, 1 2 3 5 8
	cout << res << "\n";
	
	return 0;
}