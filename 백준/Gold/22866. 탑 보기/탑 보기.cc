#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;

int n, h;
//int a[100004];
stack <int> a;
stack <pair<int, int>> st; // index, height
pair<int, int> ans[100004]; // cnt, index

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        a.push(h);

        if (st.size()) {
            while (st.size()) {
                if (st.top().second <= h) {
                    st.pop();
                }
                else {
                    break;
                }
            }
            
            if (st.size()) {
                ans[i].first = ans[i].first + st.size();
                ans[i].second = st.top().first;
            }
            st.push({i,h});
        }
        else {
            st.push({i,h});
        }
    }

    while (st.size()) {
        st.pop();
    }

    for (int i = n; i >=1; i--) {

        // if (a.empty()) break;
        h = a.top();
        a.pop();

        if (st.size()) {
            // cout << i << h << "\n";
            while (st.size()) {
                if (st.top().second <= h) {
                    st.pop();
                }
                else {
                    break;
                }
            }

            if (st.size()) {
                ans[i].first = ans[i].first + st.size();
                if(ans[i].second==0 || abs(i - st.top().first)< abs(ans[i].second - i)) ans[i].second = st.top().first;
                //if (abs(ans[i].second - i) > abs(i - st.top().first)) ans[i].second = st.top().first;
            }
            st.push({ i,h });
        }
        else {
            st.push({ i,h });
        }

  
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i].first) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
        else {
            cout << 0 << "\n";
        }
        
    }
   
    return 0;
}