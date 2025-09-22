#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    string data;
    ListNode* next;

    ListNode(string x){
        data = x;
        next = nullptr;
    }

};


int main(){
    int n, k;
    cin >> n >> k;

    k = k % n;
    
    ListNode* poem = new ListNode("a");
    ListNode* helper = poem; // pointer лист құру үшін

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        helper->next = new ListNode(s); // create new node
        helper = helper->next; // move helper forward
    }


//  басындағы poem-нан бастап к ға алдыға жылжыту.
    ListNode* prev = poem;
    while(k--){
        prev = prev->next;
    }

    // екіге болу
    ListNode* half = prev->next; // жаңа head осы жерден басталады
    prev->next = nullptr; // бірінші жартысын бөлу

    helper->next = poem->next; // helper ол соңғы сөзді сақтады ал poem->next бірінші сөзді сақтады.

    poem->next = half; // енді поем k+1 ден басталады.

    ListNode* temp = poem->next;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }


    return 0;
}