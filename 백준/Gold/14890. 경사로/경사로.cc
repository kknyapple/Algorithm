#include <iostream>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, l;
int a[104][104];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int cur_cnt = 1;
        bool flag = true;
        for (int j = 0; j < n - 1; j++) {
            int cur = a[i][j], nxt = a[i][j + 1];

            if (abs(cur - nxt) > 1) { // 높이 차이가 1 초과하면 불가능
                flag = false;
                break;
            }

            if (cur == nxt) {
                cur_cnt++;
            }
            else if (cur > nxt) { // 내리막 경사로 설치
                if (cur - nxt != 1) {
                    flag = false;
                    break;
                }
                int idx = j + 1, nxt_cnt = 0;
                while (idx < n && a[i][idx] == nxt && nxt_cnt < l) {
                    nxt_cnt++;
                    idx++;
                }
                if (nxt_cnt != l) {
                    flag = false;
                    break;
                }
                j += l - 1;
                cur_cnt = 0;
            }
            else { // 오르막 경사로 설치
                if (nxt - cur != 1 || cur_cnt < l) {
                    flag = false;
                    break;
                }
                cur_cnt = 1;
            }
        }
        if (flag) ans++;
    }

    for (int j = 0; j < n; j++) {
        int cur_cnt = 1;
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            int cur = a[i][j], nxt = a[i + 1][j];

            if (abs(cur - nxt) > 1) { // 높이 차이가 1 초과하면 불가능
                flag = false;
                break;
            }

            if (cur == nxt) {
                cur_cnt++;
            }
            else if (cur > nxt) { // 내리막 경사로 설치
                if (cur - nxt != 1) {
                    flag = false;
                    break;
                }
                int idx = i + 1, nxt_cnt = 0;
                while (idx < n && a[idx][j] == nxt && nxt_cnt < l) {
                    nxt_cnt++;
                    idx++;
                }
                if (nxt_cnt != l) {
                    flag = false;
                    break;
                }
                i += l - 1;
                cur_cnt = 0;
            }
            else { // 오르막 경사로 설치
                if (nxt - cur != 1 || cur_cnt < l) {
                    flag = false;
                    break;
                }
                cur_cnt = 1;
            }
        }
        if (flag) ans++;
    }

    cout << ans << "\n";
    return 0;
}
