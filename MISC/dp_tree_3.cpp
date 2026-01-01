#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
std::vector<std::vector<int>> adj;
std::vector<int> depth;
std::vector<double> dp;
void dfs(int u, int p = -1) {
    dp[u] = depth[u];
    double sum = 0;
    int childCount = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = 1 + depth[u];
        dfs(v, u);
        sum += dp[v];
        childCount++;
    }
    if (childCount > 0) dp[u] = sum / childCount;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    adj.assign(n+1, {});
    depth.assign(n+1, 0);
    dp.assign(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    std::cout << std::setprecision(15) << dp[1] << '\n';
    return 0;
}