#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};


int main(){
    int n;
    cin >> n;

    Node* thread = new Node(0);
    Node* helper = thread;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        helper->next = new Node(k);
        helper = helper->next;
    }

    Node* temp = thread->next;

    while(temp && temp->next){
        cout << temp->data << " ";
        temp = temp->next->next;
    }
    
    if(temp) cout << temp->data << endl;

    return 0;
}