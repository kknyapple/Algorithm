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

int n;
ll d[5004];
ll ans[3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d + n);

    ll tmp = 3000000000;
    for (int i = 0; i < n; i++) { // 고정 포인터
        int l = 0; int r = n - 1;
        while (l < r) {
            // l, r이 고정 포인터와 겹칠 경우
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }

            // l, r 포인터 이동
            ll sum = d[l] + d[r] + d[i];
            if (abs(sum) < abs(tmp)) { // 이전 값보다 0에 더 가까울 때
                ans[0] = d[l]; ans[1] = d[r]; ans[2] = d[i];
                tmp = sum;
            }

            if (sum > 0) r--;
            else if (sum == 0) {
                ans[0] = d[l]; ans[1] = d[r]; ans[2] = d[i];
                break;
            }
            else l++;
        }
    }
    sort(ans, ans + 3); // 오름차순 정렬
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";

    return 0;
}