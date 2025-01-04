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
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, k;
string str1, str0;
bool visited[2][100004];

struct jump {
    int lr; int idx; int sec;
};

bool go() {
    queue <jump> q;
    q.push({ 0,0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int lr = q.front().lr;
        int idx = q.front().idx;
        int sec = q.front().sec;
        q.pop();

        if (idx >= n || idx+k>=n) {
            return true;
        }

        if (lr == 0) {
            if (!visited[0][idx + 1] && str0[idx + 1] == '1') { // 한 칸 앞으로 이동
                q.push({ 0, idx + 1, sec+1 });
                visited[0][idx + 1] = true;
            }
            if (!visited[0][idx - 1] && idx - 1 > sec && str0[idx - 1] == '1') { // 한 칸 뒤로 이동
                q.push({ 0, idx - 1 , sec + 1 });
                visited[0][idx - 1] = true;
            }
            if (!visited[1][idx + k] && str1[idx + k] == '1') { // 반대편 줄로 k 칸 앞으로 점프
                q.push({ 1, idx + k, sec + 1 });
                visited[1][idx + k] = true;
            }
        }
        else {
            if (!visited[1][idx + 1] && str1[idx + 1] == '1') {
                q.push({ 1, idx + 1, sec + 1 });
                visited[1][idx + 1] = true;
            }
            if (!visited[1][idx - 1] && idx - 1 > sec && str1[idx - 1] == '1') {
                q.push({ 1, idx - 1, sec + 1 });
                visited[1][idx - 1] = true;
            }
            if (!visited[0][idx + k] && str0[idx + k] == '1') {
                q.push({ 0, idx + k, sec + 1 });
                visited[0][idx + k] = true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    cin >> str0;
    cin >> str1;

    if (go()) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}