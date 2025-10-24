/*
https://codeforces.com/problemset/problem/1846/E1
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    // (k ^ (d + 2) - 1)/ (k - 1) = n
    int k_bound = sqrt(n);
    for (int k = 2; k <= k_bound; k++) {
        if ((n-1) % k != 0) continue;
        int d_bound = log(n)/log(k);
        for (int d = 1; d <= d_bound; d++) {
            ll num = pow(k, d+2) - 1;
            if (num / (k-1) == n) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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