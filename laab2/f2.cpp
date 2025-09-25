#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int x){
        data = x;
        next = nullptr;
    }
};


int main(){
    int n;
    cin >> n;

    ListNode* head = new ListNode(0);
    ListNode* dum = head;

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        dum->next = new ListNode(p);
        dum = dum->next;
    }

    int k, idx;
    cin >> k >> idx;

    dum = head;

    for(int i = 0; i < idx; i++){
        dum = dum->next;
    }

    ListNode* temp = dum->next;
    dum->next = new ListNode(k);
    dum = dum->next;
    dum->next = temp;

    ListNode* curr = head->next;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }


    return 0;
}