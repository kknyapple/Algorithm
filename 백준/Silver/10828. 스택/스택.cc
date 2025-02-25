#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, num;
string str;
int pos;
int a[10004];

void push(int num) {
    a[pos] = num;
    pos++;
}

int pop() {
    if (pos == 0) return -1;
    pos--;
    return a[pos];
}

int size() {
    return pos;
}

bool empty() {
    if (pos == 0) return true;
    return false;
}

int top() {
    if (pos == 0) return -1;
    return a[pos - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push") {
            cin >> num;
            push(num);
        }
        else if (str == "pop") {
            cout<<pop()<<"\n";
        }
        else if (str == "size") {
            cout << size() << "\n";
        }
        else if (str == "empty") {
            cout << empty() << "\n";
        }
        else if (str == "top") {
            cout << top() << "\n";
        }
    }

    return 0;
}