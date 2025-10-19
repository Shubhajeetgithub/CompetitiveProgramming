/*
https://codeforces.com/problemset/problem/1808/B
sum is order invariant
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> c(m, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            c[j][i] = x;
        }
    }
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        sort(c[i].begin(), c[i].end());
        int t = n-1;
        for (int j = n-1; j >= 0; j--) {
            sum += (t * c[i][j]);
            t -= 2;
        }
    }
    cout << sum << endl;
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