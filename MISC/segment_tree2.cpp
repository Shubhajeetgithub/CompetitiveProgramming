#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using ll = long long;
std::string a;
std::vector<std::array<int, 3>> seg_tree;
void build(int id, int low, int high) {
    if (low == high) {
        seg_tree[id][0] = 0;
        if (a[low] == '(') {
            seg_tree[id][1] = 1;
            seg_tree[id][2] = 0;
        }
        else {
            seg_tree[id][1] = 0;
            seg_tree[id][2] = 1;
        }
        return;
    }
    int mid = (low + high) >> 1;
    build(2*id + 1, low, mid);
    build(2*id + 2, mid+1, high);
    int t = std::min(seg_tree[2*id + 1][1], seg_tree[2*id + 2][2]);
    seg_tree[id][0] = seg_tree[2*id + 1][0] + seg_tree[2*id+2][0] + 2 * t;
    seg_tree[id][1] = seg_tree[2*id + 1][1] + seg_tree[2*id+2][1] - t;
    seg_tree[id][2] = seg_tree[2*id + 1][2] + seg_tree[2*id+2][2] - t;
}
std::array<int,3> query(int id, int low, int high, int ql, int qr) {
    // no-overlap
    if (low > qr || high < ql) return {0, 0, 0};
    // total overlap
    if (ql <= low && high <= qr) {
        return seg_tree[id];
    }
    int mid = (low + high) >> 1;
    auto left = query(2*id + 1, low, mid, ql, qr);
    auto right = query(2*id + 2, mid+1, high, ql, qr);
    int t = std::min(left[1], right[2]);
    return {left[0] + right[0] + 2 * t,
            left[1] + right[1] - t,
            left[2] + right[2] - t};
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> a;
    int n = a.size();
    seg_tree.assign(4*n, {0, 0, 0});
    build(0, 0, n-1);
    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;
        l--; r--;
        auto res = query(0, 0, n-1, l, r);
        std::cout << res[0] << '\n';
    }
    return 0; 
}