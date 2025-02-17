#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
#define INF 1e18
using namespace std;
//using ll = long long;

int n, m;
int num;
vector<pair<int, int>> v;
int dir, pos;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    cin >> num;
    while (num--) {
        cin >> dir >> pos;
        v.push_back({ dir, pos });
    }
    cin >> dir >> pos;

    if (dir == 1) {
        for (auto k : v) {
            if (k.X == 3) {
                ans = ans + pos + k.Y;
            }
            else if (k.X == 2) {
                ans = ans + min(pos+k.Y, m-pos+m-k.Y) + n;
            }
            else if (k.X == 4) {
                ans = ans + m - pos + k.Y;
            }
            else {
                ans = ans + abs(pos - k.Y);
            }
        }
    }
    else if (dir == 2) {
        for (auto k : v) {
            if (k.X == 3) {
                ans = ans + pos + n - k.Y;
            }
            else if (k.X == 1) {
                ans = ans + min(pos + k.Y, m - pos + m - k.Y) + n;
            }
            else if (k.X == 4) {
                ans = ans + m - pos + n - k.Y;
            }
            else {
                ans = ans + abs(pos - k.Y);
            }
        }
    }
    else if (dir == 3) {
        for (auto k : v) {
            if (k.X == 1) {
                ans = ans + pos + k.Y;
            }
            else if (k.X == 4) {
                ans = ans + min(pos + k.Y, n - pos + n - k.Y) + n;
            }
            else if (k.X == 2) {
                ans = ans + n - pos + k.Y;
            }
            else {
                ans = ans + abs(pos - k.Y);
            }
        }
    }
    else if (dir == 4) {
        for (auto k : v) {
            if (k.X == 1) {
                ans = ans + pos + m - k.Y;
            }
            else if (k.X == 3) {
                ans = ans + min(pos + k.Y, n - pos + n - k.Y) + m;
            }
            else if (k.X == 2) {
                ans = ans + n - pos + k.Y;
            }
            else {
                ans = ans + abs(pos - k.Y);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}