#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    char ch;
    int n;

    while(cin >> ch){
        if(ch == '!') break;

        if(ch == '+') {
            cin >> n;
            dq.push_front(n);
        } 
        else if(ch == '-'){
            cin >> n;
            dq.push_back(n);
        }
        else if (ch == '*'){
            if(dq.empty()) cout << "error" << endl;
            else{
                int sum;
                if(dq.size() == 1){
                    sum = dq.front() + dq.back();
                    dq.pop_front();
                } else{
                    sum = dq.front() + dq.back();
                    dq.pop_back();
                    dq.pop_front();

                }
                cout << sum << endl;
            }
        }

    }


    return 0;
}