#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n;
int a[1000004];
int tmp[1000004];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int idx1 = st, idx2 = mid;
    for (int i = st;i < en;i++) {
        if (idx2 == en) {
            tmp[i] = a[idx1];
            idx1++;
        }
        else if (idx1 == mid) {
            tmp[i] = a[idx2];
            idx2++;
        }
        else if (a[idx1] <= a[idx2]) {
            tmp[i] = a[idx1];
            idx1++;
        }
        else {
            tmp[i] = a[idx2];
            idx2++;
        }
    }
    for (int i = st;i < en;i++) {
        a[i] = tmp[i];
    }
}

void mergeSort(int st, int en) {
    if (st + 1 == en) return;
    int mid = (st + en) / 2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    mergeSort(0,n);
    for (int i = 0;i < n;i++) {
        cout << a[i] << "\n";
    }

    return 0;
}