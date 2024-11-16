#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int a[15][15];
string s;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int visited[15][15];
queue <pair<int, int>> q;
int res;
int drop_flag;

void reset() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = 0;
		}
	}
}

void del(int color) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visited[i][j] != 0 && a[i][j] == color) a[i][j] = 0;
		}
	}
}

void drop() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (a[i][j] == 0) continue;
			if (a[i + 1][j] != 0) continue;

			drop_flag = 1;
			int k = 1;
			while (1) {
				if (i + k <= 11 && a[i + k][j] == 0) {
					k++;
				}
				else break;
			}
			k--;
			if (a[i + k][j] == 0) {
				a[i + k][j] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
}

int go(int y, int x, int color) {
	// cout << y << " " << x << " " << color << "\n";
	visited[y][x] = 1;
	q.push({ y,x });

	int cnt = 1;

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6)continue;
			if (visited[ny][nx])continue;
			// if (a[ny][nx] == 0)continue;

			if (a[ny][nx] == color) {
				visited[ny][nx] = visited[y][x] + 1;
				cnt++;
				q.push({ ny, nx });
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		cin >> s;
		for (int j = 0; j < 6; j++) {
			if (s[j] == '.') a[i][j] = 0;
			else if (s[j] == 'R') a[i][j] = 1;
			else if (s[j] == 'G') a[i][j] = 2;
			else if (s[j] == 'B') a[i][j] = 3;
			else if (s[j] == 'P') a[i][j] = 4;
			else if (s[j] == 'Y') a[i][j] = 5;
		}
	}

	int bomb = 0;


	while (1) {
		int flag = 0;
		for (int k = 1; k <= 5; k++) {
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (a[i][j] == k && visited[i][j] == 0) {
						reset();
						// cout << go(i, j, k) << "\n";
						if (go(i, j, k) >= 4) {
							del(k);
							flag = 1;
						}
					}
				}
			}

		}
		if (flag == 1)bomb++;

		drop_flag = 0;
		drop();

		if (drop_flag == 0)break;
	}
	
	/*cout << "\n";
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}*/

	cout << bomb << "\n";

	return 0;
}
