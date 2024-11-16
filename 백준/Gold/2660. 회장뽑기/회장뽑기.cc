#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

int n;
int arr[52][52];
int visited[52][52];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int a, b;
int score = INF;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
    }
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1)break;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    int cnt = 0;
    int c[52] = { 0 };
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp = max(tmp, arr[i][j]);
            // cout<<a[i][j]<<" ";
        }
        c[i] = tmp;
        score = min(score, tmp);
        //cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (score == c[i])cnt++;
    }

    cout << score << " " << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if (score == c[i]) cout << i << " ";
    }

    return 0;
}