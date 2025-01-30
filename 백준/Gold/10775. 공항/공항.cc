#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

int g, plane;
int gi;
int p[100004];
int ans;

int find(int x) { // 부모 노드 저장
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u == p[v]]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> g >> plane;
    for (int i = 0; i <= g; i++) {
        p[i] = i;
    }
    for (int i = 0; i < plane; i++) {
        cin >> gi;
        int parent = find(gi); // 해당 게이트 부모 찾기
        if (parent == 0) break; // 부모가 0이면 공항 폐쇄
        if (merge(gi, parent - 1)) ans++; // 바로 앞 게이트와 union
    }
    cout << ans << "\n";

    return 0;
}