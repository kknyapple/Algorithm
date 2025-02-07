#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, m;
vector <int> v[54];
int p[54];
int num, a;
bool flag;
int ans;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    if (p[v] < p[u]) swap(u, v);
    else if (p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        p[i] = i; // 부모 초기화
    }
    cin >> num;
    for (int i = 0;i < num;i++) {
        cin >> a;
        p[a] = 0; // 진실을 아는 사람을 0번과 연결
    }
    
    // 파티 참여하는 사람들 merge
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> a;
            v[i].push_back(a); // 파티 정보 저장
            if (j == 0) tmp = a; // 처음 입력된 사람 번호 저장
            else merge(tmp, a); // 파티 오는 사람들 merge
        }
    }

    // 파티 마다 진실을 알고 있는 지 판별
    for (int i = 0;i < m;i++) {
        flag = true;
        for (int k : v[i]) {
            if (find(k) == 0) { // 0번과 연결된 사람은 진실을 아는 사람
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans << "\n";

    return 0;
}