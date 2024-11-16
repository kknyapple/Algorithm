#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
using ll = long long;

int t, n;
ll dp[104];
int num[9] = { 0,0,1,7,4,2,0,8,10 };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    // 가장 작은 수
    for (int i = 1; i < 9; i++) {
        dp[i] = num[i];
    }
    dp[6] = 6;

    for (int i = 9; i < 101; i++) {
        dp[i] = dp[i - 2] * 10 + num[2];

        for (int j = 3; j < 8; j++) {
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
        }
    }

    while (t--) {
        // string mx="";
        cin >> n;

        cout << dp[n]<<" ";

        // 가장 큰 수
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) cout << "1";
        }
        else {
            cout << "7";
            for (int i = 0; i < (n / 2) - 1; i++) cout << "1";
        }

        cout << "\n";
    }

    return 0;
}