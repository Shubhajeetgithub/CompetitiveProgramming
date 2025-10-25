#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }
    
int dfs(const vector<vector<int>>& adj, int parent, vector<int>& WBcnts, string s) {
    if (WBcnts[parent] != -1) return WBcnts[parent];
    
    int sum = 0;
    if (s[parent - 1] == 'W') sum += 1;
    else sum -= 1;
    
    for (const int& child : adj[parent]) {
        sum += dfs(adj, child, WBcnts, s);
    }
    return WBcnts[parent] = sum;
}
    
void solve() {
    int n; cin >> n;
    BUILD_TREE(n, adj);
    string s;
    cin >> s;
    // root is vertex 1
    vector<int> WBcnts(n+1, -1);
    int __ = dfs(adj, 1, WBcnts, s);
    int cnt = 0;
    for (const int& c: WBcnts) {
        if (c == 0) cnt++;
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