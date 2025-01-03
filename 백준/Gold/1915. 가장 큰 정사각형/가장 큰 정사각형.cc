#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, m;
int d[1004][1004];
string str;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> str;
        for (int j = 1;j <= m;j++) {
            d[i][j] = str[j - 1] - '0'; // j=1 부터 시작이므로 str[j-1]
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (d[i][j] == 0) continue;
            d[i][j] = min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans * ans << "\n";

    return 0;
}

/*

0 1 0 0
0 1 1 1
1 1 1 1
0 1 1 1

0 1 0 0
0 1 1 1
1 1 2 2
0 1 2 3

배열 값이 1일 때
val = min(d[i-1][j], d[i][j-1], d[i-1][j-1])
d[i][j] = val + 1

*/