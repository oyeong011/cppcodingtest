#include<bits/stdc++.h>
using namespace std;
int a[9], type;
int main(){
    for(int i = 1; i <= 8; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= 8; i++){
        if(i != a[i]) {
            type = 3;
            break;
        }
        type = 1;
    }
    if(type == 1){
        cout << "ascending";
        return 0;
    }
    
    for(int i = 1; i <= 8; i++){
        if(9-i != a[i]) {
            type = 3;
            break;
        }
        type = 2;
    }
    
    if(type == 2){
        cout << "descending";
        return 0;
    } else {
        cout << "mixed";
    }
}