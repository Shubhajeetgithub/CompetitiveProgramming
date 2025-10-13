/*
https://codeforces.com/problemset/problem/1744/C
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        if (c == 'g') {
            cout << 0 << endl;
            continue;
        }
        vector<int> ids_g;
        vector<int> ids_c;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'g') ids_g.push_back(i);
            else if (s[i] == c) ids_c.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'g') ids_g.push_back(i+n);
        }
        int ans = 0;
        for (const int& id : ids_c) {
            int idx = *lower_bound(ids_g.begin(), ids_g.end(), id);
            ans = max(ans, idx - id);
        }
        cout << ans << endl;
    }
    return 0;
}