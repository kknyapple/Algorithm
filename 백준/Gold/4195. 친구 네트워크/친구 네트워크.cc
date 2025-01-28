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

int t, f;
string a, b;
int num[200004]; // 자식 개수
int p[200004]; // 부모

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(v, u);
    else if (p[v] == p[u]) p[u]--;
    p[v] = u;
    num[u] += num[v];
    // num[v] = 1;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> f;

        unordered_map<string, int> um; // {name, idx}
        int cnt = 1;
        for (int i = 0; i < f * 2; i++) {
            p[i] = -1;
            num[i] = 1;
        }
        for (int i = 0; i < f; i++) {
            cin >> a >> b;
            if (um.find(a) == um.end()) { // a가 기존 맵에 없으면 추가
                um[a] = cnt++;
            }
            if (um.find(b) == um.end()) { // b가 기존 맵에 없으면 추가
                um[b] = cnt++;
            }
            merge(um[a], um[b]); // name에 맞는 idx 매개변수 전달
            cout << num[find(um[a])] << "\n";
        }
    }

    return 0;
}