#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n; 
    cin >> n;
    vector<ll> b(n), a(n);
    for (ll i = 0; i < n; i++) cin >> b[i];
    a[0] = 1;
    ll val = 2;
    for (ll i = 1; i < n; i++) {
        if (b[i] - b[i-1] == i+1) {
            a[i] = val;
            val++;
        }
        else {
            ll diff = b[i] - b[i-1];
            a[i] = a[i-diff];
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
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