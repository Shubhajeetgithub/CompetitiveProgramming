#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ASK(x, k) ([&](){ \
    cout << "? " << (x) << " " << (k) << endl << flush; \
    int _r; cin >> _r; \
    return _r; \
}())

#define ANS(x) cout << "! " << (x) << endl << flush;

void solve() {
    int n;
    cin >> n;
    int bit_length = 31 - __builtin_clz(n);
    list<int> a;
    list<int> a0;
    int pn = 0;
    for (int i = 1; i <= n - 1; i++) a.push_back(i);
    for (int i = 1; i <= n; i++) a0.push_back(i);
    for (int k = 0; k <= bit_length; k++) {
        int cnt1 = 0, cnt2 = 0;
        int m = a.size();
        int m0 = a0.size();
        vector<pair<int, int>> b(m);
        vector<pair<int, int>> b0(m0);
        int j = 0;
        for (const int& x : a0) {
            if ((x & (1 << k)) != 0) {
                b0[j++] = {x, 1};
                cnt1++;
            } else {
                b0[j++] = {x, 0};
            }
        }
        j = 0;
        for (const int& x : a) {
            int res = ASK(x, 1 << k);
            b[j++] = {x, res};
            cnt2 += res;
        }
        if (cnt1 == cnt2) {
            // kth bit is zero, discard numbers that have kth bit 1
            auto it = a.begin();
            for (int j = 0; j < m; j++) {
                if (b[j].second == 1) it = a.erase(it);
                else ++it;
            }
            auto it0 = a0.begin();
            for (int j = 0; j < m0; j++) {
                if (b0[j].second == 1) it0 = a0.erase(it0);
                else ++it0;
            }
        } else {
            // kth bit is 1
            auto it = a.begin();
            for (int j = 0; j < m; j++) {
                if (b[j].second == 0) it = a.erase(it);
                else ++it;
            }
            auto it0 = a0.begin();
            for (int j = 0; j < m0; j++) {
                if (b0[j].second == 0) it0 = a0.erase(it0);
                else ++it0;
            }
            pn += (1 << k);
        }
    }
    ANS(pn);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}