/*
https://codeforces.com/problemset/problem/1433/D
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 1; i <= n; i++) {
        ll ai; cin >> ai;
        a[i-1] = {ai, i};
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> edges;
    int i = 0, j = n-1;
    if (a[i].first == a[j].first) {
        cout << "NO\n";
        return;
    }
    edges.push_back({a[i].second, a[j].second});
    while (i < j) {
        bool added = false;
        if (i + 1 < j) {
            if (a[i+1].first != a[j].first) {
                edges.push_back({a[i+1].second, a[j].second});
                i++;
                if (i >= j) break;
                added = true;
            }
        }
        if (j - 1 > i) {
            if (a[i].first != a[j-1].first) {
                edges.push_back({a[i].second, a[j-1].second});
                j--;
                added = true;
            }
        }
        if (!added) break;
    }
    int m = edges.size();
    if (m != n-1) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
        for (auto x: edges) cout << x.first << " " << x.second << endl;
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