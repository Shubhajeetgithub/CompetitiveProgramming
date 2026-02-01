// desired solution requires fenwick tree

#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
std::vector<int> a;
std::vector<int> min_seg_tree;
std::vector<ll> g, l; // g[i] = # elements to the left of a[i] and greater than it, l[i] = # elements to the right of a[i] and smaller than it
std::vector<ll> G; // G[i] = # all elements greater than a[i]
void build_min_tree(int id, int low, int high) {
    if (low == high) {
        min_seg_tree[id] = a[low];
        return;
    }
    int mid = (low + high) >> 1;
    build_min_tree(2*id + 1, low, mid);
    build_min_tree(2*id + 2, mid+1, high);
    min_seg_tree[id] = std::min(min_seg_tree[2*id+1], min_seg_tree[2*id+2]);
}
int query_gi(int id, int low, int high, int ql, int qr, int i) {
    // no-overlap
    if (low > qr || high < ql) return 0;
    // total overlap
    if (ql <= low && high <= qr) {
        if (min_seg_tree[id] > a[i]) return (high - low + 1);
    }
    if (low == high) {
        return a[low] > a[i] ? 1 : 0;
    }
    int mid = (low + high) >> 1;
    int left = query_gi(2*id + 1, low, mid, ql, qr, i);
    int right = query_gi(2*id + 2, mid+1, high, ql, qr, i);
    return left + right;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    min_seg_tree.assign(4*n, 0);
    build_min_tree(0, 0, n-1);
    g.assign(n, 0); l.assign(n, 0); G.assign(n, 0);
    for (int i = 1; i < n; i++) {
        g[i] = query_gi(0, 0, n-1, 0, i-1, i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        G[i] = query_gi(0, 0, n-1, 0, n-1, i);
        l[i] = n-i-1-(G[i] - g[i]);
        ans += g[i] * l[i];
    }
    std::cout << ans << '\n';
    return 0; 
}