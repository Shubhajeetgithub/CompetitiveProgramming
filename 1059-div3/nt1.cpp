/*
https://codeforces.com/problemset/problem/1734/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    vector<bool> to_be_deleted(n+1, false);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '0') to_be_deleted[i] = true;
    }
    vector<bool> deleted = to_be_deleted;
    ll cost = 0;
    for (ll i = 1; i <= 1LL * n; i++) {
        for (ll j = 1; j * i <= 1LL * n; j++) {
            if (!to_be_deleted[j*i]) break;
            if (deleted[j*i]) {
                cost += i;
                deleted[i*j] = false;
            }
        }
    }
    cout << cost << endl;
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