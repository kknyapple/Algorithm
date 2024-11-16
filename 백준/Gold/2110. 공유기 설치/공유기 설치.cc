#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int n, c;
int ans;
int d[200004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d + n);

    int s = 1; int e = d[n - 1] - d[0];

    while (s <= e) {
        int mid = (e + s) / 2;
        bool flag = true;

        //cout << s<<" "<<e<<" "<< mid << "\n";

        int tmp = d[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (d[i] - tmp >= mid) {
                // cout << d[i] << " " << tmp << "\n";
                tmp = d[i];
                cnt += 1;
            }

            if (cnt == c) {
                break;
            }
        }

        if (cnt != c) flag = false;

        if (flag == true) {
            ans =mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}