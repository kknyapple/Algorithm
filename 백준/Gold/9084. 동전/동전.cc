#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int t, n, cost[24], m;
int d[10004];

void init() {
    for (int i = 1;i <= m;i++) {
        d[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> cost[i];
        }
        cin >> m;

        init();
        d[0] = 1;
        for (int i = 0;i < n;i++) {
            for (int j = cost[i];j <= m;j++) {
                d[j] += d[j - cost[i]];
            }
        }
        cout << d[m] << "\n";
    }

    return 0;
}

// 5 7 -> d[12] = d[12-5] + d[12-7] -> 5+7, 7+5 중복 제거하기 위해 
// 금액 순회가 아닌 동전 종류 차례대로 순회