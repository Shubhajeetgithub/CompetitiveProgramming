#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int n, k;
std::vector<std::vector<int>> adj;
std::vector<std::vector<ll>> dp;

void dfs(int u, int p = -1) {
    dp[u][0] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int j = 1; j <= k; ++j) {
            dp[u][j] += dp[v][j-1];
        }
    }
}

void dfs2(int u, ll& acc, int p = -1) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, acc, u);
        ll sum = 0;
        for (int x = 1; x < k; ++x) {
            sum += dp[v][x-1] * (dp[u][k-x] - dp[v][k-x-1]);
        }
        acc += sum;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    adj.assign(n+1, {});
    for (int i = 0; i < n-1; ++i) {
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp.assign(n+1, std::vector<ll>(k+1));
    dfs(1);
    ll ans1 = 0;
    for (int i = 1; i <= n; ++i) ans1 += dp[i][k];
    ll ans2 = 0;
    dfs2(1, ans2);
    ans2 /= 2;
    std::cout << ans1 + ans2 << '\n';
    return 0;
}