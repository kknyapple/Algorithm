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

int n, a[24][24];
bool visited[24][24];
int sharkSize = 2;
int fishCnt;
int dy[] = { -1,0,0,1 }, dx[] = { 0,-1,1,0 };
pair<int, int> pos;
int ans;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false; 
        }
    }
}

bool go(int y, int x) {
    int cnt = 1;
    visited[y][x] = 1;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({ cnt,y,x });

    while (!q.empty()) {
        tie(cnt,y, x) = q.top(); q.pop();
        if (a[y][x] < sharkSize && a[y][x]!=0) {
            a[y][x] = 9;
            a[pos.X][pos.Y] = 0;
            pos = { y, x };
            fishCnt += 1;
            if (fishCnt == sharkSize) {
                sharkSize += 1;
                fishCnt = 0;
            }
            ans += cnt - 1;
            return true;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny<0 || nx<0 || nx>=n || ny>=n) continue;
            if (visited[ny][nx]) continue;
            if (sharkSize < a[ny][nx]) continue;
            q.push({ cnt+1,ny, nx });
            visited[ny][nx] = true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) pos = { i,j };
        }
    }
    
    while (true) {
        //cout << pos.X << " " << pos.Y << "\n";
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < n; j++) {
        //        cout << a[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        //cout << "\n";
        init();
        if (!go(pos.X, pos.Y)) break;
    }

    cout << ans << "\n";

    return 0;
}