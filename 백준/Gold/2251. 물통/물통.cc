#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
#include <set>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int a, b, c;
int water[3];
bool visited[204][204][204];
set<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> c;
    water[0] = a; water[1] = b; water[2] = c;

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,c });
    visited[0][0][c] = true;
    v.insert(c);

    while (!q.empty()) {
        tie(a, b, c) = q.front();
        q.pop();
        if (a != 0) {
            if (water[1] - b >= a) {
                int tmp1 = 0, tmp2 = a + b, tmp3 = c;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
            else {
                int tmp1 = a + b - water[1], tmp2 = water[1], tmp3 = c;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }

            if (water[2] - c >= a) {
                int tmp1 = 0, tmp2 = b, tmp3 = a+c;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
            else {
                int tmp1 = a + c - water[2], tmp2 = b, tmp3 = water[2];
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
        }
        if (b != 0) {
            if (water[0] - a >= b) {
                int tmp1 = a+b, tmp2 = 0, tmp3 = c;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
            else {
                int tmp1 = water[0], tmp2 = a + b - water[0], tmp3 = c;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }

            if (water[2] - c >= b) {
                int tmp1 = a, tmp2 = 0, tmp3 = c+b;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
            else {
                int tmp1 = a, tmp2 = c + b - water[2], tmp3 = water[2];
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
        }
        if (c != 0) {
            if (water[0] - a >= c) {
                int tmp1 = a + c, tmp2 = b, tmp3 = 0;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
            else {
                int tmp1 = water[0], tmp2 = b, tmp3 = a + c - water[0];
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }

            if (water[1] - b >= c) {
                int tmp1 = a, tmp2 = c + b, tmp3 = 0;
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
            else {
                int tmp1 = a, tmp2 = water[1], tmp3 = c + b - water[1];
                if (!visited[tmp1][tmp2][tmp3]) {
                    q.push({ tmp1,tmp2,tmp3 });
                    visited[tmp1][tmp2][tmp3] = true;
                    if (tmp1 == 0) v.insert(tmp3);
                }
            }
        }
    }

    for (auto k : v) {
        cout << k << " ";
    }

    return 0;
}