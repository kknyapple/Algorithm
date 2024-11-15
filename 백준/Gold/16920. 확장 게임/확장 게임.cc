#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

int n, m, p;
string s;
char a[1004][1004];
int si[10];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int res[10];
queue <pair<int, int>> q[10];

void go(int player) {
	for (int k = 0; k < si[player]; k++) {
		int qSize = q[player].size();
		if (qSize == 0) return;

		while (qSize--) {
			int y, x;
			tie(y, x) = q[player].front();
			q[player].pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
				if (a[ny][nx] == '.') {
					q[player].push({ ny, nx });
					a[ny][nx] = player;
					res[player]++;
				}

			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> si[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];

			if (a[i][j] >= '1' && a[i][j] <= '9') {
				q[a[i][j]-'0'].push({ i,j });
				res[a[i][j] - '0']++;
			}
		}
	}

	while (1) {
		int cnt = 0;
		for (int player = 1; player <= p; player++) {
			if (q[player].empty()) cnt++;
			else go(player);
		}
		if (cnt == p) break;
	}

	for (int i = 1; i <= p; i++) {
		cout << res[i] << " ";
	}

	return 0;
}