#include <bits/stdc++.h>
using namespace std;

int is_prime(int x){
    // if (x == 1) return 0;
    // if (x == 2 || x == 3) return 1;

    if (x < 2) return 0;
    for(int i = 2; i * i <= x; i++){
        if (x % i == 0) return 0;
    }
    return 1;
}

int nth(int n){
    int i = 2; 
    //  prime 2 ден басталат

    while(n > 0){
        if(is_prime(i)) n--;
        i++;
    }
    
    return i-1;
    //  while соңында i++ жасап кеткен сон -- орындалады
}

int main(){
    int n;
    cin >> n;

    cout << nth(nth(n)) << endl;

    return 0;
}