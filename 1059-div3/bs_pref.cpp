/*
https://codeforces.com/problemset/problem/1742/E
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> maxi(n), pref(n);
    ll x;
    cin >> x;
    maxi[0] = x; pref[0] = x;
    for (int i = 1; i < n; i++) {
        ll x; cin >> x;
        maxi[i] = max(maxi[i-1], x);
        pref[i] = pref[i-1] + x;
    }
    while (q--) {
        ll k; cin >> k;
        int id = upper_bound(maxi.begin(), maxi.end(), k) - maxi.begin();
        id--;
        if (id < 0) cout << 0 << " ";
        else cout << pref[id] << " ";
    }
    cout << endl;
    
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