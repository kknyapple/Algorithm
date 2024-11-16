#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int t, v, e, a, b;
vector<int> adj[20004];
int visited[20004];

bool go(int cur) {
    visited[cur] = 1;
    queue<int> q;
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (visited[nxt]) {
                if (visited[nxt] == visited[cur]) return false;
                continue;
            }
            
            if (visited[cur] == 1)visited[nxt] = 2;
            else visited[nxt] = 1;
            
            q.push(nxt);
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 1; i <= v; i++) {
                visited[i] = 0;
                adj[i].clear();
        }
        while (e--) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool flag = true;
        for (int i = 1; i <= v; i++) {
            if (visited[i]) continue;
            if (!go(i)) {
                flag = false;
                break;
            }
        }
        if (flag)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}