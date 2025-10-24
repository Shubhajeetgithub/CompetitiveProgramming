/*
https://codeforces.com/problemset/problem/1671/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; ll x;
    cin >> n >> x;
    READ_VEC(a, n);
    sort(a.begin(), a.end());
    vector<ll> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }
    int id = upper_bound(pref.begin(), pref.end(), x) - pref.begin();
    id--;
    if (id == 0) {
        cout << 0 << endl;
        return;
    }
    ll cnt = 0;
    for (int i = 1; i <= id; i++) {
        cnt += ((x - pref[i]) / i) + 1;
    }
    cout << cnt << endl;
    
    
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