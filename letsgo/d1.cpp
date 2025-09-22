#include <bits/stdtr1c++.h>
using namespace std;
int main(){
    string s;
    cin >> s;

    stack<char> word;

    for(char i : s){
        if(!word.empty() && i == word.top()){
            word.pop();
        }
        else{
            word.push(i);
        }
    }

    if(word.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}