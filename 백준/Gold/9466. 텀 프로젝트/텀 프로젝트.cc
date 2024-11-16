#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int t, n;
int a[100004];
int visited[100004]; // 1: 팀에 속하지 않음, 2: 팀 구성 완료
int root; // 싸이클 시작 노드
int flag = 1; // 0: 팀 구성 제외 표시
int res;

void go(int cur) {
	if (visited[cur] == 0) {
		visited[cur] = 1;
		go(a[cur]);
		visited[cur]++;
		if (flag == 0) {
			res++;
		}
		else if (cur == root) {
			flag = 0;
		}

	}
	else if (visited[cur] == 1) {
		root = cur;
		visited[cur]++;
		return;
	}
	else {
		flag = 0;
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			visited[i] = 0;
		}
		res = 0;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i <= n; i++) {
			flag = 1;
			if (visited[i] == 0) {
				go(i);
			}
		}

		cout << res << "\n";
	}

	return 0;
}
