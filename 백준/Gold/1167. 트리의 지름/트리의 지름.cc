#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int v;
int par, node, len;
vector <pair<int, int>> a[100004];
int p[100004];
int d[100004];
int res1, res2;

void go(int cur) {
    for (auto next : a[cur]) {
        if (p[cur] == next.first) continue;
        p[next.first] = cur;
        d[next.first] = d[cur] + next.second;
        go(next.first);
    }
    return;
}

/*int dfs(int cur, int lon) {
    for (auto next : a[cur]) {
        if (p[cur] == next.first) continue;
        lon += dfs(next.first, lon);
    }
    return lon;
}*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for (int i = 1; i <= v; i++) {
        cin >> par;
        while (1) {
            cin >> node;
            if (node == -1) break;
            cin >> len;
            a[par].push_back({ node, len });

        }
    }
    int tmp = 0;
    int lon = 0;
    go(1);
    /*for (int i = 1; i <= v; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";*/
    for (int i = 1; i <= v; i++) {
        //cout << d[i] << " ";
        if (lon < d[i]) {
            lon = d[i];
            tmp = i;
        }
    }

    for (int i = 1; i <= v; i++) {
        d[i] = 0;
        p[i] = 0;
    }

    go(tmp);
    //cout << tmp << "\n";
    for (int i = 1; i <= v; i++) {
        res1 = max(res1, d[i]);
        //cout << d[i] << " ";
    }
    //cout << "\n";

    cout << res1 << "\n";

    return 0;
}
