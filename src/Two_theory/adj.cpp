//
// Created by 권오영 on 24. 10. 14.
//
#include<iostream>
#include<vector>
using namespace std;
const int V = 10;
vector<int> adj[V];
int visited[V];
void go(int idx) {
    cout << idx << "\n";
    visited[idx] = 1;
    for (int there : adj[idx]) {
        if (visited[there]) continue;
        go(there);
    }
    return;
}
int main() {
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    for (int i = 0; i < V; i++) {
        if (adj[i].size() && visited[i] == 0) go(i);
    }
}