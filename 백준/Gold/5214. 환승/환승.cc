/*
  5     2
  |     |
4-d2-1-d1-3-d3-6 ...
             |
            ...
*/
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

int n, k, m;
vector <int> v[101004];
int a;
int visited[101004];

void go() {
    queue <int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        if (cur == n) break;
        q.pop();
        for (int nxt : v[cur]) {
            if (visited[nxt]) continue;

            q.push(nxt);
            if(nxt <= n) visited[nxt] = visited[cur] + 1;
            else visited[nxt] = visited[cur]; // dummy node일 경우 거리 체크 X
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a;
            // dummy node랑 연결
            v[a].push_back(n + i);
            v[n + i].push_back(a); 
        }
    }

    go();
    if (visited[n]) cout << visited[n] << "\n";
    else cout << -1 << "\n"; 

    return 0;
}
