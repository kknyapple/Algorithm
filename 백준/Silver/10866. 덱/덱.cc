#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, a[20004], x;
int tail = 10000, head = 10000;
string str;

void push_front(int x) {
    head--;
    a[head] = x;
}

void push_back(int x) {
    a[tail] = x;
    tail++;
}

int pop_front() {
    if (head == tail) return -1;
    head++;
    return a[head - 1];
}

int pop_back() {
    if (head == tail) return -1;
    tail--;
    return a[tail];
}

int size() {
    return tail - head;
}

bool empty() {
    if (tail == head) return true;
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
        if (str == "push_front") {
            cin >> x;
            push_front(x);
        }
        else if (str == "push_back") {
            cin >> x;
            push_back(x);
        }
        else if (str == "pop_front") {
            cout << pop_front() << "\n";
        }
        else if (str == "pop_back") {
            cout << pop_back() << "\n";
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
