//
// Created by 권오영 on 24. 10. 15.
//
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[100];
queue<int> q;
int visited[100];
void bfs(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int there : adj[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
int main() {

}