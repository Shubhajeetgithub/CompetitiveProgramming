/*
https://codeforces.com/problemset/problem/1669/H
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    int n, k; cin >> n >> k;
    READ_VEC(a, n);
    int cnt = k;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (!((a[j] >> i) & 1)) temp++;
        }
        if (temp == 0) {
            ans |= (1 << i);
        }
        else if (cnt >= temp) {
            ans |= (1 << i);
            cnt -= temp;
        }
    }
    cout << ans << endl;
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