#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n;
int d[100004][3];
int mod = 9901;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    d[1][0] = 1; d[1][1] = 1; d[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        d[i][0] = (d[i - 1][1] + d[i - 1][2]) % mod; // [O X] : i-1 번째는 [X O]나 [X X]가능
        d[i][1] = (d[i - 1][1] + d[i - 1][2]) % mod; // [X O] : i-1 번째는 [O X]나 [X X]가능
        d[i][2] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % mod; // [X X] : i-1 번째는 [O X]나 [X O]나 [X X]가능
        
    }
    cout << (d[n][0] + d[n][1] + d[n][2]) % mod << "\n";

    return 0;
}

/*
    결국 d[i] = (d[i-1]*2 + d[i-2]) % mod라 할 수 있다.
*/