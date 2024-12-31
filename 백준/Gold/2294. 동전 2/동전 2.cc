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
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, k, a[104];
int d[10004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for (int i = 0;i <= k;i++) {
        d[i] = INF;
    }

    d[0] = 0;
    for (int i = 0;i < n;i++) {
        for (int j = a[i];j <= k;j++) {
            d[j] = min(d[j], d[j - a[i]] + 1);
        }
    }
    /*for (int i = 1;i <= k;i++) {
        for (int j = 0;j < n;j++) {
            if (i - a[j] >= 0) d[i] = min(d[i], d[i - a[j]] + 1);
        }
    }*/

    if (d[k] == INF) cout << "-1" << "\n";
    else cout << d[k] << "\n";

    return 0;
}
/*

d[0] = 1
d[1] = 1
d[2] = d[2-1] + 1
d[3] = d[3-1] + 1
d[4] = d[4-1] + 1
d[5] = min(d[5-1], d[5-5])
...
d[15] = min(d[15-1]+1, d[15-5]+1, d[15-12]+1)

*/