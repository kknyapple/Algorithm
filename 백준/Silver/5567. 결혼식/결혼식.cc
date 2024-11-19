#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, m, a, b, ans;
vector <int> v[504];
bool visited[504];
queue <pair<int, int>> q;

void go(int cur) { // 친구 관계 깊이를 알아야 해서 bfs로 해야 함
    int cnt;
    visited[cur] = true;
    q.push({ cur, 1 });
    
    while (!q.empty()) {
        tie(cur, cnt) = q.front();
        q.pop();
        
        for (int nxt : v[cur]) {
            if (visited[nxt]) continue;
            if (cnt > 2) continue; // 친구의 친구까지만 초대
            visited[nxt] = true;
            ans++;
            q.push({ nxt, cnt + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    go(1);

    cout << ans << "\n";

    return 0;
}
