/*
https://codeforces.com/problemset/problem/1886/C
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        std::string s; std::cin >> s;
        ll pos; std::cin >> pos;
        ll n = s.size();
        ll start = n, end = 1, r = -1;
        while (start >= end) {
            ll mr = (start + end) / 2;
            ll lb = (n - mr) * (n + mr + 1) / 2 + 1;
            ll ub = (n - mr + 1) * (n + mr) / 2;
            if (pos > ub) start = mr - 1;
            else if (pos < lb) end = mr + 1;
            else {
                r = mr;
                break;
            }
        }
        // sr has r lowest char from s
        int req_id = pos - (n - r) * (n + r + 1) / 2 - 1; // 0 based indexing
        std::string sr;
        int del_cnt = n - r;
        std::stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) st.push(s[i]);
            else {
                if (del_cnt > 0) {
                    int curr = s[i] - 'a';
                    while (del_cnt > 0 && !st.empty() && (int)(st.top() - 'a') > curr) {
                        del_cnt--;
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        while (del_cnt > 0) {
            st.pop();
            del_cnt--;
        }
        while (!st.empty()) {
            sr += st.top();
            st.pop();
        }
        std::reverse(sr.begin(), sr.end());
        std::cout << sr[req_id];
    } 
    return 0;
}