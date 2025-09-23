#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    string data;
    ListNode* next;

    ListNode(string s){
        data = s;
        next = nullptr;
    }

};

ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;

    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}


int main(){
    int n;
    cin >> n;

    ListNode* head = new ListNode("");
    ListNode* helper = head;
    int cnt = 0;


    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(helper->data == s) continue;
        cnt++;
        helper->next = new ListNode(s);
        helper = helper->next;
    }

    head = reverse(head);
    // head = head->next;

    cout << "All in all: " << cnt << endl;
    cout << "Students: " << endl;

    helper = head;

    while(helper){
        cout << helper->data << endl; 
        helper = helper->next;
    }


    return 0;
}