#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x){
    if (x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    int cnt = 0, num = 1;
    while(cnt < n){
        num++;
        if(is_prime(num)){
            cnt++;
        }
    }

    cout << num << endl;
    return 0;
}