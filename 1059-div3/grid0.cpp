/*
https://codeforces.com/problemset/problem/1703/E
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int numWays = 0;
    int sr = 0, er = n-1, sc = 0, ec = n-1;
    while (sr < er && sc < ec) {
        int m = er - sr + 1;
        // (i, j) , (j , m-i-1), (m-i-1, m-j-1), (m-j-1, i)
        // i = r - sr, j = c - sc, i = 0 to m-2, j = 0
        for (int i = 0; i < m - 1; i++) {
            int cnt0 = 0, cnt1 = 0;
            int r1 = sr + i, c1 = sc;
            int r2 = sr, c2 = sc + m - i - 1;
            int r3 = sr + m - i - 1, c3 = sc + m - 1;
            int r4 = sr + m - 1, c4 = sc + i;
            vector<pair<int, int>> cells = {{r1, c1}, {r2, c2}, {r3, c3}, {r4, c4}};
            for (auto [r, c] : cells) {
                if (grid[r][c] == '1') cnt1++;
                else cnt0++;
            }
            numWays += min(cnt0, cnt1);
        }
        sr++; er--; sc++; ec--;
    }
    cout << numWays << endl;
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