#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
using ll = long long;

int t, h, w;
string low;
char a[104][104];
bool visited[104][104];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
vector <char> key;
string s;
int ans;
//vector <pair<int, int>> tmp;
map <char, vector<pair<int, int>>> tmp;

void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = ' ';
            visited[i][j] = 0;
        }
    }

    key.clear();
    tmp.clear();
}

void go(int y, int x) {
    queue<pair<int, int>> q;

    if (a[y][x] >= 'A' && a[y][x] <= 'Z') {
        int flag = 0;
        for (auto p : key) {
            if (p - 32 == a[y][x]) {
                flag = 1;
                visited[y][x] = 1;
                q.push({ y,x });
                break;
            }
        }
        if (flag == 0) {
            tmp[a[y][x]].push_back({ y, x });
        }
    }
    else {
        if (a[y][x] >= 'a' && a[y][x] <= 'z') {
            key.push_back(a[y][x]);
            if (tmp.find(a[y][x] - 32) != tmp.end()) {
                for (auto p : tmp[a[y][x] - 32]) {
                    q.push({ p.first, p.second });
                }
                tmp.erase(a[y][x] - 32);
            }
        }
        else if (a[y][x] == '$') {
            ans++;
            //cout << y << " " << x << "\n";
        }

        visited[y][x] = 1;
        q.push({ y,x });
    }




    while (!q.empty()) {
        tie(y, x) = q.front();
        //cout << y << " " << x << " " << a[y][x] << "\n";
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (a[ny][nx] == '*') continue;
            if (visited[ny][nx]) continue;
            
            if (a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') {
                int flag = 0;
                for (auto p : key) {
                    if (p - 32 == a[ny][nx]) {
                        flag = 1; break;
                    }
                }
                if (flag == 0) {
                    tmp[a[ny][nx]].push_back({ ny, nx });
                    continue;
                }
            }
            else if (a[ny][nx] >= 'a' && a[ny][nx] <= 'z') {
                key.push_back(a[ny][nx]);
                if (tmp.find(a[ny][nx] - 32) != tmp.end()) {
                    for (auto p : tmp[a[ny][nx] - 32]) {
                        q.push({ p.first, p.second });
                    }
                    tmp.erase(a[ny][nx] - 32);
                }
            }
            else if (a[ny][nx] == '$') {
                ans++;
                //cout << ny << " " << nx << "\n";

            }

           
            // cout << a[ny][nx] << "\n";
            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> h >> w;
        ans = 0;
        init();

        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) {
                a[i][j] = s[j];
            }
        }
        cin >> low;
        if (low != "0") {
            for (auto p : low) {
                key.push_back(p);
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || i == h - 1) {
                    if (a[i][j] == '*') continue;
                    if (visited[i][j]) continue;
                    go(i, j);
                }
                else {
                    if (j == 0 || j == w - 1) {
                        if (a[i][j] == '*') continue;
                        if (visited[i][j]) continue;
                        go(i, j);
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
