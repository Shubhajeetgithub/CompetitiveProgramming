/*
https://codeforces.com/problemset/problem/1221/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    ll c, m, x;
    cin >> c >> m >> x;
    /*
    p + 2q + r <= c
    2p + q + r <= m
    r <= x
    max(p+q+r) = ?
    */
    ll s = 0, e = min({c, m, (c + m + x)/3});
    ll max_poss = 0;
    while (s <= e) {
        ll f = s + (e - s)/2;
        // checking if p+q+r = f, is possible or not
        // r = f - p - q <= x
        // p <= c - f, q <= m - f, p+q >= f-x
        // f-x <= p+q <= c + m - 2 * f
        // so 3 * f <= c + m + x
        if (f <= min(c, m) && 3 * f <= c + m + x) {
            max_poss = f;
            s = f + 1;
        }
        else e = f - 1;
    }
    cout << max_poss << endl;
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