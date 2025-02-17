#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
#define INF 1e18
using namespace std;
using ll = long long;

int n;
int a[4004][4];
vector<int> sumAB, sumCD;
ll ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) { // 배열 두개 합 구하기
        for (int j = 0; j < n; j++) {
            sumAB.push_back(a[i][0] + a[j][1]);
            sumCD.push_back(a[i][2] + a[j][3]);
        }
    }
    sort(sumAB.begin(), sumAB.end()); // 오름차순 정렬
    sort(sumCD.begin(), sumCD.end(), greater<int>()); // 내림차순 정렬

    int l = 0, r = 0;
    while (l < sumAB.size() && r < sumCD.size()) {
        int sum = sumAB[l] + sumCD[r];

        if (sum == 0) {
            long long cnt1 = 1, cnt2 = 1;

            // 같은 값이 여러 번 나올 경우 개수 세기
            while (l + 1 < sumAB.size() && sumAB[l] == sumAB[l + 1]) {
                cnt1++;
                l++;
            }
            while (r + 1 < sumCD.size() && sumCD[r] == sumCD[r + 1]) {
                cnt2++;
                r++;
            }

            ans += cnt1 * cnt2;
            l++; r++;
        }
        else if (sum < 0) l++;
        else r++;
    }

    cout << ans << "\n";

    return 0;
}
/*
3
-1 -7 0 -9
0 1 1 0
7 9 3 2
*/