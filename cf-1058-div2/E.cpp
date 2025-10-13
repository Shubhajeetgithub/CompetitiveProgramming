#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find_area(const std::vector<std::vector<bool>>& grid, int x, int y) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    using rect_t = std::array<int, 4>;
    using pq_item_t = std::pair<int, rect_t>;
    std::priority_queue<pq_item_t, std::vector<pq_item_t>, std::greater<pq_item_t>> pq;
    std::set<rect_t> visited;
    auto add_to_pq = [&](int u, int d, int l, int r) {
        if (u >= 0 && d < n && l >= 0 && r < m) {
            rect_t rect = {u, d, l, r};
            if (visited.find(rect) == visited.end()) {
                visited.insert(rect);
                int area = (d - u + 1) * (r - l + 1);
                pq.push({area, rect});
            }
        }
    };

    add_to_pq(x, x + 1, y, y + 1);
    add_to_pq(x, x + 1, y - 1, y);
    add_to_pq(x - 1, x, y, y + 1);
    add_to_pq(x - 1, x, y - 1, y);

    while (!pq.empty()) {
        // Get the unvisited rectangle with the smallest area.
        rect_t current_rect = pq.top().second;
        pq.pop();

        auto [u, d, l, r] = current_rect;

        // Check if the four corners of the current rectangle are valid.
        if (grid[u][l] && grid[u][r] && grid[d][l] && grid[d][r]) {
            return (d - u + 1) * (r - l + 1);
        }

        // Expand the current rectangle in four directions (Up, Down, Left, Right).
        add_to_pq(u - 1, d, l, r); // Expand Up
        add_to_pq(u, d + 1, l, r); // Expand Down
        add_to_pq(u, d, l - 1, r); // Expand Left
        add_to_pq(u, d, l, r + 1); // Expand Right
    }
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    vector<vector<int>> area(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') grid[i][j] = true;
        }
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            area[r][c] = find_area(grid, r, c);
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << area[r][c] << " ";
        }
        cout << "\n";
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