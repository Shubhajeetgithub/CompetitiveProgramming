#include <bits/stdc++.h>
using namespace std;

vector<set<int>> createAdjacencySet(const vector<int>& intermediateVec) {
    int n = intermediateVec.size();
    vector<set<int>> myVec(n);
    for (int i = 0; i < n; i++) {
        if (intermediateVec[i] != -1) {
            int key = intermediateVec[i] - 1; //0-indexed
            int value = i; //0-indexed
            myVec[key].insert(value);
        }
    }
    return myVec;
}
int dfs(int node, const vector<set<int>>& graph, vector<int>& depths, vector<bool>& visited) {
    //base case
    if (graph[node].empty()) return depths[node] = 1;

    vector<int> childDepth;
    for (int child : graph[node]) {
        visited[child] = true;
        childDepth.push_back(dfs(child, graph, depths, visited));
    }
    return depths[node] = 1 + *(max_element(childDepth.begin(), childDepth.end()));
}
void findDepths(const vector<set<int>>& graph, vector<int>& depths) {
    int n = depths.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            //perform dfs here
            visited[i] = true;
            dfs(i, graph, depths, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    //the intermediate vector is 1-indexed but our adjacency set is 0 indexed

    //create a adjacency list to store a graph
    //if the graph has k "islands" g1, g2, ..., gk
    //then return max(depth(gi)) 1 <= i <= k

    auto graph = createAdjacencySet(p);
    vector<int> depths(n);
    findDepths(graph, depths);
    cout << *(max_element(depths.begin(), depths.end())) << endl;
    return 0;
}