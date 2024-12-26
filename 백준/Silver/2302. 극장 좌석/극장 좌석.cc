#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
const int INF = 0x7f7f7f7f;

int n, m, idx;
int d[44]; // n개의 좌석에서 앉을 수 있는 방법 가짓수
int ans = 1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;

    d[0] = 1; d[1] = 1; d[2] = 2; d[3] = 3;
    for (int i = 4; i <= n;i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    int tmp = 0;
    for (int i = 1;i <= m;i++) {
        cin >> idx;
        ans *= d[idx - tmp - 1]; // n = vip좌석 사이 좌석 개수
        tmp = idx;
    }
    ans *= d[n - tmp];

    cout << ans << "\n";

    return 0;
}

/*
n = 1
1
=> 1

n = 2
1 2
2 1
=> 2

n = 3
1 2 3
2 1 3
1 3 2
=> d[1] + 1 = 3

n = 4
1 2 3 4
2 1 3 4
1 3 2 4
1 2 4 3
2 1 4 3
=> d[3] + d[2]

n = 5
1 2 3 4 5
2 1 3 4 5
1 3 2 4 5
1 2 4 3 5
2 1 4 3 5
--
1 2 3 5 4
2 1 3 5 4
1 3 2 5 4
=> d[4] + d[3]

*/