#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

int n, m, a[54][54], d, s;
bool isCloud[54][54];
int dy[] = { 0, 0,-1,-1,-1,0,1,1,1 }, dx[] = { 0, -1,-1,0,1,1,1,0,-1 };
int ny[] = { -1,-1,1,1 }, nx[] = { -1,1,1,-1 };
queue<pair<int, int>> pos;
int ans;

void makeInitCloud() {
    isCloud[n][1] = true;
    isCloud[n][2] = true;
    isCloud[n-1][1] = true;
    isCloud[n-1][2] = true;
}

void makeCloud() {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (isCloud[i][j] == true) {
                isCloud[i][j] = false;
                continue;
            }
            if (a[i][j] >= 2) {
                a[i][j] -= 2;
                isCloud[i][j] = true;
            }
        }
    }
}

void moveCloud() {
    queue<pair<int, int>> q;
    // 이동한 구름 위치 큐에 저장
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (isCloud[i][j]) {
                isCloud[i][j] = false;
                int addY = dy[d] * s + i;
                int addX = dx[d] * s + j;
                if (addY >= 0) addY %= n;
                else addY = n - (abs(addY) % n);
                if (addX >= 0) addX %= n;
                else addX = n - (abs(addX) % n);
                if (addY == 0)addY = n;
                if (addX == 0)addX = n;
                q.push({ addY , addX });
            }
        }
    }

    // 이동한 구름 위치 표시
    while (!q.empty()) {
        isCloud[q.front().X][q.front().Y]=true;
        q.pop();
    }
}

void rain() {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (isCloud[i][j]) {
                a[i][j] += 1;
            }
        }
    }
}

void increasWater() {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (isCloud[i][j]) {
                for (int k = 0;k < 4;k++) {
                    int addY = ny[k] + i;
                    int addX = nx[k] + j;
                    if (a[addY][addX]) a[i][j]+=1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0;i < m;i++) {
        cin >> d >> s;
        if (i == 0) {
            makeInitCloud();
        }
        moveCloud();
        rain();
        increasWater();
        makeCloud();
    }

    // 바구니 물의 양의 합 구하기
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            ans += a[i][j];
        }
    }
    cout << ans << "\n";

    return 0;
}