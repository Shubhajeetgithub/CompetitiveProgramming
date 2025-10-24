/*
https://codeforces.com/problemset/problem/1703/F
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    vector<ll> g(n+1);
    g[0] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll ai;
        cin >> ai;
        if (ai < i) {
            g[i] = 1 + g[i-1];
            if (ai > 0) sum += g[ai-1];
        }
        else g[i] = g[i-1];
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