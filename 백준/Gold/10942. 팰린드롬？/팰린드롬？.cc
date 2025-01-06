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

int n, m;
int a[2004];
bool d[2004][2004];
int s, e;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for (int i = 0;i < n;i++) {
        // 홀수 구간
        d[i][i] = true;
        int cnt = 1;
        while (i - cnt >= 0 && i + cnt < n) {
            if (a[i - cnt] == a[i + cnt]) { // 대칭인 곳이 같을 경우
                d[i - cnt][i + cnt] = true; // 해당 구간 펠린드롬
                cnt++; // 다음 구간
            }
            else break;
        }

        // 짝수 구간
        int tmp = i + 1;
        if (i + 1 >= n) continue;
        cnt = 0;
        while (i - cnt >= 0 && tmp + cnt < n) {
            if (a[i - cnt] == a[tmp + cnt]) { // 대칭인 곳이 같을 경우
                d[i - cnt][tmp + cnt] = true; // 해당 구간 펠린드롬
                cnt++; // 다음 구간
            }
            else break;
        }
    }

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << d[s - 1][e - 1] << "\n";
    }

    return 0;
}

/*

1 2 1 3 1 2 2

// 홀수
d[0][0] = 1
d[1][1] = 1, d[0][2] = 1
...
d[3][3] = 1, d[2][4] = 1, d[1][5] = 1, d[0][6] = 0

// 짝수
d[0][1] = 0
d[1][2] = 0
...
d[5][6] = 1

*/