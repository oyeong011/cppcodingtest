#include<bits/stdc++.h>
using namespace std;
int dp[100004][5][5], a, len = 0, arr[100004];
int getCost(int from, int to) {
  if (from == 0) return 2;
  if (from == to) return 1;
  if (abs(from - to) == 2) return 4;
  return 3;
}
int go(int here, int lf, int rf){
  if(here == len) return 0;
  int &ret = dp[here][lf][rf];
  if(ret != -1) return ret;

  int left = go(here + 1, arr[here], rf) + getCost(lf, arr[here]);
  int right = go(here + 1, lf, arr[here]) + getCost(rf, arr[here]);
  return dp[here][lf][rf] = min(left, right);
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while(1){
    cin >> a;
    if(a==0) break;
    arr[len++] = a;
  }
  memset(dp, -1, sizeof(dp));
  cout << go(0, 0, 0);
}