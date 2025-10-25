/*
Binary Search on answer
https://codeforces.com/problemset/problem/1612/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }

ll sum(ll m, ll k) {
    if (m <= k) {
        return (m * (m + 1)) / 2;
    }
    else return (k * (k + 1)) / 2 + ((m - k) * (3 * k - m - 1)) / 2;
}

void solve() {
    ll k, x;
    cin >> k >> x;
    ll s = 1, e = 2 * k - 1;
    ll i = 1;
    while (s <= e) {
        ll m = s + (e-s)/2;
        if (sum(m, k) < x) {
            i = m + 1;
            s = m + 1;
        }
        else if (sum(m, k) == x) {
            i = m;
            s = m + 1;
        }
        else e = m - 1;
    }
    cout << min(i, 2 * k - 1) << endl;
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