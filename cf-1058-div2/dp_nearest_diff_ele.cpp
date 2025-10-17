/*
https://codeforces.com/problemset/problem/1927/D

fix j = r, and find the nearest different element id and set it to i if l <= i, else 
return -1 -1
to find nearest different element -> use dp
*/

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    int n; cin >> n;
    READ_VEC(a, n);
    vector<int> dp(n);
    dp[0] = -1;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) dp[i] = dp[i-1];
        else dp[i] = i-1;
    }
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int i = dp[r];
        if (l <= i) {
            cout << i + 1 << " " << r+1 << endl;
        }
        else {
            cout << -1 << " " << -1 << endl;
        }
    }
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