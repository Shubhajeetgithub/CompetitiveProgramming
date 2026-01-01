#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using ll = long long;
std::vector<std::vector<int>> adj;
std::vector<ll> l, r;
void dfs(int u, std::vector<std::vector<ll>>& dp, int p = -1) {
    dp[0][u] = 0;
    dp[1][u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, dp, u);
        dp[0][u] += std::max(dp[0][v] + abs(l[v] - l[u]), dp[1][v] + abs(r[v] - l[u]));
        dp[1][u] += std::max(dp[0][v] + abs(l[v] - r[u]), dp[1][v] + abs(r[v] - r[u]));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        l.resize(n+1); r.resize(n+1); adj.assign(n+1, {});
        for (int i = 1; i <= n; i++) std::cin >> l[i] >> r[i];
        for (int i = 0; i < n-1; i++) {
            int u, v; std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<std::vector<ll>> dp(2, std::vector<ll>(n+1, 0));
        dfs(1, dp);
        std::cout << std::max(dp[0][1], dp[1][1]) << '\n';
    }
    return 0;
}