#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, x;
string str;
int a[10004];
int tail, head;

void push(int x) {
    a[tail] = x;
    tail++;
}

int pop() {
    if (head == tail) return -1;
    head++;
    return a[head - 1];
}

int size() {
    return tail - head;
}

bool empty() {
    if (head == tail) return true;
    return false;
}

int front() {
    if (head == tail) return -1;
    return a[head];
}

int back() {
    if (head == tail) return -1;
    return a[tail - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push") {
            cin >> x;
            push(x);
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
        else if (str == "front") {
            cout << front() << "\n";
        }
        else if (str == "back") {
            cout << back() << "\n";
        }
    }

    return 0;
}