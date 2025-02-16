#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;
using ll = long long;
#define INF 1e18

int n, m;
int lad[104], sna[104]; // [a] -> b로 연결됨
int a, b;
bool visited[104];
int ans = 100;

void go() {
    queue<pair<int, int>> q; // { 보드판 번호, 주사위 굴린 횟수}
    q.push({1, 0}); // 1번 부터 시작
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front().X;
        int cnt = q.front().Y;
        q.pop();
        if (cur == 100) {
            ans = min(ans, cnt);
        }
        for (int i = 1; i <= 6; i++) { // 주사위 1~6
            int nxt = cur + i;
            if (nxt > 100) break;
            if (visited[nxt]) continue;
            if (lad[nxt]) q.push({ lad[nxt], cnt + 1 }); // 사다리가 있을 경우
            else if (sna[nxt]) q.push({ sna[nxt], cnt + 1 }); // 뱀이 있을 경우
            else q.push({ nxt, cnt + 1 });
            visited[nxt] = true;
        }
        
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        lad[a] = b;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        sna[a] = b;
    }
    go();
    cout << ans << "\n";

    return 0;
}