#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;

#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) std::cout << a[i] << " "; std::cout << '\n';

int dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<bool>& vis, int val, std::vector<int>& d, std::vector<int>& s) {
    d[node] = val;
    int sum = 1;
    for (int child : graph[node]) {
        if (vis[child]) continue;
        else {
            vis[child] = true;
            sum += dfs(child, graph, vis, val+1, d, s);
        }
    }
    return s[node] = sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> graph(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v; std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<int> d(n+1), s(n+1, -1);
    std::vector<bool> vis(n+1, false);
    vis[1] = true;
    dfs(1, graph, vis, 0, d, s);
    std::vector<ll> ans(n);
    for (int i = 0; i < n; i++) ans[i] = d[i+1] - s[i+1] + 1;
    // PRINT_VEC(d, n+1);
    // PRINT_VEC(s, n+1);
    // PRINT_VEC(ans, n);
    std::sort(ans.rbegin(), ans.rend());
    // PRINT_VEC(ans, n);
    ll beauty = 0;
    for (int i = 0; i < k; i++) beauty += ans[i];
    std::cout << beauty << std::endl;
    return 0;
}