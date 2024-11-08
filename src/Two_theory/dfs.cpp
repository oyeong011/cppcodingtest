//
// Created by 권오영 on 24. 10. 15.
//
//using namespace std;
//const int N = 3;
//vector<int> adj[N];
//int visited[N];
//void dfs(int u) {
//    visited[u] = 1;
//    cout << u << "\n";
//    for (int v : adj[u]) {
//        if (visited[v] == 0) {
//            dfs(v);
//        }
//    }
//    cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
//    return;
//}

#include<bits/stdc++.h>
using namespace std;
const int N = 3;
vector<int> adj[N];
int visited[N];
void dfs(int u){
  visited[u] = 1;
  for(int v : adj[u]){
    if(visited[v] == 0){
      dfs(v);
    }
  }
  cout << u << "end\n";
  return;
}