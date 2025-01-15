#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, num;
int a[104];
bool visited[104];
vector<int> v, tmp;
bool flag;

bool go(int cur, int r) {
    if (visited[cur]) {
        if (cur == r) flag = true;
        return flag;
    }
    tmp.push_back(cur);
    visited[cur] = true;
    go(a[cur], r);

    return flag;
}

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    tmp.clear();
    flag = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        init();
        if (go(i, i)) {
            for (int k : tmp) {
                v.push_back(k);
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << "\n";
    for (int k : v) {
        cout << k << "\n";
    }

    return 0;
}