//
// Created by 권오영 on 24. 10. 11.
//
#include<iostream>
using namespace std;
typedef long long ll;
ll a, tmp = 1, re = 1, cnt = 1;
int main(){
    while(cin >> a != EOF){

        while(true){
            if(tmp % a == 0){
                cout << cnt << "\n";
                cnt = 1; re = 1; tmp = 1; break;
            }
            re *= 10;
            tmp = re + tmp;
            tmp %= a;
            cnt++;
        }
    }
}