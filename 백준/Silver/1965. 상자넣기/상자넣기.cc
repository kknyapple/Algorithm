#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, a[1004];
int d[1004];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        d[i] = 1;
        int tmp = 0;
        for (int j = i;j >= 0;j--) { // 앞의 상자 모두 확인
            if (a[i] > a[j]) tmp = max(tmp, d[j]); // 자신보다 작은 상자일 때
        }
        d[i] += tmp; // 상자를 제일 만이 담을 수 있는 경우
        ans = max(ans, d[i]); // 최대 상자 개수 저장
    }
    cout << ans << "\n";

    return 0;
}