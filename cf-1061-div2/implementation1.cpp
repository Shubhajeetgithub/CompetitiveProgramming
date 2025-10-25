/*
https://codeforces.com/problemset/problem/1498/B

Initialize height of box as 1.
Initialize current layer size as W.
Pick the largest available rectangle that can fit into the current layer, and place it there. Repeat until this layer cannot fit any more rectangles.
If more rectangles remain, increment height by 1 and now repeat the last three steps. Else, output the current value of height.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n, w, box_width;
    cin >> n >> box_width;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        cin >> w;
        st.insert(w);
    }

    int height = 1, space_left = box_width;

    while (!st.empty()) {
        auto it = st.upper_bound(space_left);
        if (it != st.begin()) {
            it--;
            int val = *it;
            space_left -= val;
            st.erase(it);
        } else {
            space_left = box_width;
            height++;
        }
    }

    cout << height << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}