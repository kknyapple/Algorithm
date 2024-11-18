#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
//const int INF = 0x3f3f3f3f;

int n, w[14];
bool selected[14];
int ans;

void go(int cnt, int sum) {
    // cout << sum << " ";
    if (cnt == n - 2) {
        ans = max(sum, ans);
        // cout << "\n";
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        if (selected[i]) continue;
        selected[i] = true;
        int tmp = w[i];
        w[i] = 0;
        int left = 0;
        int right = 0;
        for (int k = i - 1; k >= 0; k--) {
            if (w[k] == 0) continue;
            left = w[k];
            break;
        }
        for (int k = i + 1; k <= n-1; k++) {
            if (w[k] == 0) continue;
            right = w[k];
            break;
        }
        // cout << "lr: "<<left << " " << right << "\n";
        go(cnt + 1, sum + (left * right));
        selected[i] = false;
        w[i] = tmp;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    go(0, 0);

    cout << ans << "\n";

    return 0;
}
