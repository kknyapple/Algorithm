#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int n, t, p;
pair<int, int> a[17]; // {t: 기간, p: 금액}
int ans[17];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        a[i].first = t;
        a[i].second = p;
    }

    int end;
    for (int i = n; i > 0; i--) {
        end = i + a[i].first - 1; // 완료 기간
        if (end > n) ans[i] = ans[i + 1]; // 완료 기간이 퇴사일을 넘을 경우
        else ans[i] = max(ans[i + 1], ans[end + 1] + a[i].second);
    }

    cout << ans[1] << "\n";

    return 0;
}
