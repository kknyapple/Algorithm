#include <bits/stdc++.h>
using namespace std;

int n, k, dp[1001][1001]; // dp[i][j]: i색상환에서 j개의 색을 고르는 경우의 수
const int mod = 1e9 + 3;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) dp[i][1] = i;
    for(int i=4; i<=n; i++){
        for(int j=2; j<=k; j++){
            if(j > i/2) break;
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % mod;
        }
    }
    cout << dp[n][k] << '\n';
}