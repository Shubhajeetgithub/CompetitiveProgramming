#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    ll a, b;
    cin >> a >> b;
    ll num = a ^ b;
    vector<ll> x;
    for (int d = 0; d <= 62; d++) {
        if ((num >> d) & 1) {
            x.push_back(1 << d);
            if ((1 << d) > a) {
                cout << -1 << endl;
                return;
            }
            a ^= (1 << d);
        }
    }
    cout << x.size() << endl;
    for (const ll& xi : x) cout << xi << " ";
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