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

int n, m, k;
int r, c;
int a[42][42];
int sticker[12][12];
int tmp[12][12];
int ans;

void spin() {
    for (int i = 0; i < r; i++) { // 90도 회전
        for (int j = 0; j < c; j++) {
            tmp[j][r - 1 - i] = sticker[i][j]; // y, x 좌표 주의
        }
    }

    swap(r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sticker[i][j] = tmp[i][j];
        }
    }
    
}

void attach() {
    int cnt = 0;
    while (true) {
        for (int i = 0; i <= n - r; i++) { // 0 ~ (n-r) 범위 포함해야 함
            for (int j = 0; j <= m - c; j++) { // 0 ~ (m-c) 범위 포함해야 함
                bool flag = true;
                for (int p = 0; p < r; p++) { // 붙일 수 있는 지 확인
                    for (int q = 0; q < c; q++) {
                        if (sticker[p][q] == 1 && a[i + p][j + q] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false) break;
                }
                if (flag == true) { // 붙일 수 있으면 붙이기
                    for (int p = 0; p < r; p++) {
                        for (int q = 0; q < c; q++) {
                            if (sticker[p][q] == 1) {
                                a[i + p][j + q] = 1;
                                ans++;
                            }
                        }
                    }
                    return;
                }
            }
        }
        cnt++;
        if (cnt == 4) { // 0, 90, 180, 270도 회전 완료
            return;
        }
        spin(); // 못 붙였으면 회전해서 다시 확인
    }
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[i][j];
            }
        }
        attach();
    }

    cout << ans << "\n";

    return 0;
}
