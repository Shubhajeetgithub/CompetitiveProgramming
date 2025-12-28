#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class SparseTableGCD {
    vector<vector<T>> st;
    vector<int> lg;
    
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    
public:
    SparseTableGCD(const vector<T>& arr) {
        int n = arr.size();
        int k = n > 0 ? __lg(n) + 1 : 0;
        st.assign(k, vector<T>(n));
        lg.assign(max(1, n) + 1, 0);

        if (n == 0) return;

        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

        st[0] = arr;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = gcd(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }
    
    T query(int l, int r) {
        if (st.empty()) return T(0);
        int len = r - l + 1;
        int i = lg[len];
        return gcd(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n), b(n-1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n-1; i++) b[i] = abs(a[i] - a[i+1]);
        SparseTableGCD<ll> st_gcd(b);
        while (q--) {
            int l, r; cin >> l >> r;
            l--; r--; // 0 based indexing
            if (l == r) {
                cout << 0 << " ";
            }
            else {
                cout << st_gcd.query(l, r-1) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}