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

int n;
int h[604];
int ans = INF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> h[i];
    }
    sort(h, h + n);

    for (int i = 0;i < n;i++) {
        for (int j = i + 3;j < n;j++) {
            int l = i + 1; int r = j - 1; // i, j 사이 값 탐색
            int sumA = h[i] + h[j];
            while (l < r) {
                int sumB = h[l] + h[r];

                if (sumA == sumB) { // 차이가 0
                    cout << 0 << "\n";
                    return 0;
                }

                ans = min(ans, abs(sumA - sumB));
                if (sumA > sumB) l++; // sumA - sumB > 0 이면, sumB가 더 커야지 차이가 줄어든다
                else r--;
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
/*

a b c d
최솟값은 abs(a+d - b+c)

a, d에 포인터를 고정하고 그 사이 값의 합중에서 최솟값을 찾는다

*/