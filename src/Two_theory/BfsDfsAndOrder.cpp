//
// Created by 권오영 on 24. 10. 15.
//
#include <iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
const int N = 10;
int visited[N];
vector<int> adj[N];
// void dfs(int u) {
//     if (visited[u])return;
//     visited[u] = 1;
//     for (int there : adj[u]) {
//         dfs(there);
//     }
// }
// void bfs(int here) {
//     queue<int> q;
//     visited[here] = 1;
//     q.push(here);
//     while (q.size()) {
//         int here = q.front(); q.pop();
//         for (int there : adj[here]) {
//             visited[there] = visited[here] + 1;
//             q.push(there);
//         }
//     }
// }
void dfs(int u) {
    if (visited[u]) return;
    visited[u] = 1;
    for (int there : adj[u]) {
        dfs(there);
    }
}
void bfs(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int there : adj[here]) {
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
void postOrder(int here) {
    if (visited[here] == 0) {
        if (adj[here].size() == 1)postOrder(adj[here][0]);
        if (adj[here].size() == 2) {
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1;
        cout << here << ' ';
    }
}
void preOrder(int here) {
    if (visited[here] == 0) {
        visited[here] = 1;
        cout << here << ' ';
        if (adj[here].size() == 1)preOrder(adj[here][0]);
        if (adj[here].size() == 2){
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}
void inOrder(int here) {
    if (visited[here] == 0) {
        if (adj[here].size() == 1) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
        } else if (adj[here].size() == 2) {
            inOrder(adj[here][0]);

            visited[here] = 1;
            cout << here << ' ';
        }else {
            visited[here] = 1;
            cout << here << ' ';
        }
    }
}
int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    int root = 1;
    cout << "\n 트리순회 : postOrder \n";
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder \n";
    preOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : inOrder \n";
    inOrder(root);
    return 0;
}