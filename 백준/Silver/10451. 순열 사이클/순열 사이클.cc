#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int t, n;
int num;
int a[1004]; // 연결 노드 저장
bool visited[1004];
int ans;

void init() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> t;
    while (t--) {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) { // 사이클 찾기
            if (visited[i]) continue;

            int idx = i;
            while (true) {
                visited[idx] = true;
                idx = a[idx]; // 다음 노드
                if (idx == i) { // 사이클이 만들어졌을 때
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}