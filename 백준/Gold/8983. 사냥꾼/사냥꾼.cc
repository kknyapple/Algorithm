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

int n, m, l;
int d[100004]; // 사대
vector<pair<int, int>> v; // 동물 좌표
int x, y;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> l;
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(d, d + m);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x,y });
    }

    for (auto k : v) { // 동물 좌표가 사대 안에 포함되어 있는지 검사
        x = k.first;
        y = k.second;
        if (y > l) continue;

        // 사대 이분탐색
        int lp = 0; int rp = m - 1;
        while (lp <= rp) {
            int mid = (rp + lp) / 2;
            int dist = abs(d[mid] - x) + y; // 거리 계산
            if (dist <= l) { // 거리 안에 있을 경우
                ans++;
                break;
            }
            else if (d[mid] < x) lp = mid + 1;
            else rp = mid - 1;
        }
    }
    cout << ans << "\n";

    return 0;
}