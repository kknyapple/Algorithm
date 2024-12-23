#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

const ll MOD = 1000000009;
int t, n;
ll d[1000004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // 4
    // 1 + 3 -> d[3]
    // 2 + 2 -> d[2]
    // 3 + 1 -> d[1]

    d[1] = 1; d[2] = 2; d[3] = 4;
    for (int i = 4;i <= 1000000;i++) {
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % MOD;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << d[n] % MOD << "\n";
    }

    return 0;
}