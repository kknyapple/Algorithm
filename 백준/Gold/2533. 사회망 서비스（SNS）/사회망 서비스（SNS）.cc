#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

int n;
vector<int> tree[1000004];
int a, b;
int ans;
bool visited[1000004];
int d[1000004][2];

void go(int cur) {
    d[cur][0] = 0; // 현재 노드가 얼리가 아닐 때
    d[cur][1] = 1; // 현재 노드가 얼리일 때
    visited[cur] = true;
    for (int nxt : tree[cur]) {
        if (visited[nxt]) continue;
        go(nxt);
        d[cur][0] += d[nxt][1]; // 현재 노드가 얼리가 아닐 때, 주변 노드는 얼리
        d[cur][1] += min(d[nxt][1], d[nxt][0]); // 현재 노드가 얼리가 아닐 때, 주변 노드 얼리 값 중 최소
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n;
    for (int i = 0;i < n - 1;i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    go(1);
    
    cout << min(d[1][0], d[1][1]) << "\n";

    return 0;
}