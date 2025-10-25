#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }

void solve() {
    ll n; cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 - 1 << endl;
    }
    else {
        cout << n / 2 << endl;
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