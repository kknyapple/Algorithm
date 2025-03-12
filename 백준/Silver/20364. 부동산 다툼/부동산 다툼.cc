#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, q, duck;
bool visited[2000000]; // 2^20 -> 1048576

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0;i < q;i++) {
        cin >> duck;
        int tmp = duck;
        int ans = 0;
        bool flag = true;
        while (true) { // 부모 노드가 방문 되었는 지 확인
            if (tmp == 0) {
                if(flag) visited[duck] = true;
                break;
            }
            if (visited[tmp]) { // 1번 루트 땅부터 시작해 ans에 최소값을 저장한다
                ans = tmp;
                flag = false; // 땅을 가지 못함
            }
            tmp /= 2;
        }
        cout << ans << "\n";
    }
    
    return 0;
}