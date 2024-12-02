#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
// using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, m;
int a, b;
int ans;
int d[104]; // 개수 저장
vector <int> v1[104]; // 정방향 그래프
vector <int> v2[104]; // 역방향 그래프
bool visited[104];

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

int go(vector <int> (&v)[104], int cur) {
    visited[cur] = true;
    int res = 0; // 현재 노드에서 도달 가능한 노드 개수
    for (int nxt : v[cur]) {
        if (visited[nxt]) continue;
        res += go(v, nxt) + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        v1[a].push_back(b); // a > b
        v2[b].push_back(a); // b > a
    }

    int mid = n / 2; // 가볍거나 무거운 구슬 수가 range 보다 크면 중간 구슬이 될 수 없음 
    for (int i = 1; i <= n; i++) {
        init();
        if (go(v2, i) > mid) ans++;
    }

    for (int i = 1; i <= n; i++) {
        init();
        if (go(v1, i) > mid) ans++;
    }

    cout << ans << "\n";

    return 0;
}
