#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
char a[5][5];
bool check[5][5]; // false: 세로 true:가로
bool visited[5][5];
string s;
int res;

int cal() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	int sum = 0;
	bool dir = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;

			int ny = i;
			int nx = j;
			string cur = "";
			dir = check[i][j];

			while (1) {
				if (ny >= n || nx >= m || dir != check[ny][nx]) {
					break;
				}

				visited[ny][nx] = true;
				cur += a[ny][nx];

				if (dir) nx++;
				else ny++;
			}

			sum += stoi(cur);
		}
	}

	return sum;
}

void make(int y, int x, bool dir) {
	check[y][x] = dir;
	if (y == n - 1 && x == m - 1) {
		res = max(res, cal());

		return;
	}

	if (x + 1 >= m) {
		make(y + 1, 0, true);
		make(y + 1, 0, false);
	}
	else {
		make(y, x + 1, true);
		make(y, x + 1, false);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	make(0, 0, true);
	make(0, 0, false);

	cout << res << "\n";

	return 0;
}