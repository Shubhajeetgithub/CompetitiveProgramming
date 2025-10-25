#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BIN_LEN(x) (64 - __builtin_clzll((x)))

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    READ_VEC(a, q);
    vector<ll> ans(q);
    vector<pair<char, int>> res;
    res.push_back({s[0], 1});
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) res.back().second++;
        else res.push_back({s[i], 1});
    }
    int m = res.size();
    if (m == 1) {
        if (res[0].first == 'B') {
            for (int i = 0; i < q; i++) ans[i] = BIN_LEN(a[i]);
        }
        else for (int i = 0; i < q; i++) ans[i] = a[i];
    }
    else {
        for (int i = 0; i < q; i++) {
            // working for a[i]
            ll cnt = 0;
            int j = 0;
            while (a[i] != 0) {
                if (res[j].first == 'B') {
                    if (BIN_LEN(a[i]) >= res[j].second) {
                        cnt += res[j].second;
                        a[i] >>= res[j].second;
                    }
                    else {
                        cnt += BIN_LEN(a[i]);
                        a[i] = 0;
                    }
                }
                else {
                    if (a[i] >= res[j].second) {
                        cnt += res[j].second;
                        a[i] -= res[j].second;
                    }
                    else {
                        cnt += a[i];
                        a[i] = 0;
                    }
                }
                j = (j + 1) % m;
            }
            ans[i] = cnt;
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << endl;
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