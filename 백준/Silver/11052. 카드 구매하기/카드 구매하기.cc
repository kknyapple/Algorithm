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

int n, p[10004];
int d[10004]; // 카드 n개를 갖기 위해 지불해야 하는 금액 최댓값

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    /*
    ex) d[4] = max({p[4], d[1] + p[3], d[2] + p[2], d[3] + p[1]})
    */

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = max(d[i], p[j] + d[i - j]);
        }
    }

    cout << d[n] << "\n";

    return 0;
}