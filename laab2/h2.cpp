#include <bits/stdc++.h>
 
using namespace std;
 
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(ListNode* next): val(0), next(next) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
 
ListNode* insert(ListNode* head, ListNode* node, int p){
    /* write your code here */
    if(p == 0){
        node->next = head;
        return node;
    }

    ListNode* dum = head;
    for(int i = 0; i < p-1; i++){
        dum = dum->next;
    }

    ListNode* temp = dum->next;
    dum->next = node;
    dum->next->next = temp;
    return head;

}
 
ListNode* remove(ListNode* head, int p){
    /* write your code here */
    if(p == 0) return head->next;

    ListNode* dum = head;
    for(int i = 0; i < p-1; i++){
        dum = dum->next;
    }
    if(dum->next){
        dum->next = dum->next->next;
    }
    else{
        dum->next = nullptr;
    }
    return head;

}
 
ListNode* replace(ListNode* head, int p1, int p2){
    /* write your code here */
    if(p1 == p2) return head;

    // dummy node zhasau head saqtau ushn
    ListNode* dum = new ListNode(0);
    dum->next = head;
    ListNode* prev = dum;

    // p1 baru
    for(int i = 0; i < p1; i++){
        prev = prev->next;
    }
    // uzel bolu part1->next ol kelesi uzel basy
    ListNode* nodeToMove = prev->next;
    prev->next = nodeToMove->next;
    // head obnova
    head = dum->next;

    // we gona put part1 to p2 position
    if(p2 == 0){
        nodeToMove->next = head;
        head = nodeToMove;
    } else{
        prev = head;
        for(int i = 0; i < p2 - 1; i++){
            prev = prev->next;
        }
        nodeToMove->next = prev->next;
        prev->next = nodeToMove;
    }

    return head;
    // ex)) A B C D E p1 = 2 p2 = 5 ->>  A C D E B
}
 
ListNode* reverse(ListNode* head){
    /* write your code here */
    ListNode* prev = nullptr;
    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;

}
 
void print(ListNode* head){
    /* write your code here */
    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}
 
ListNode* cyclic_left(ListNode* head, int x){
    /* write your code here */
    int n = 1;
    ListNode* dum = head;
    while(dum->next){
        dum = dum->next;
        n++;
    }

    int p;
    p = x % n;

    if(p == 0) return head;

    ListNode* curr = head;
    for(int i = 0; i < p - 1; i++){
        curr = curr->next;
    }

    ListNode* res = curr->next;
    curr->next = nullptr;
    dum->next = head;

    return res;

}
 
ListNode* cyclic_right(ListNode* head, int x){
    /* write your code here */
    int n = 1;
    ListNode* dum = head;
    while(dum->next){
        dum = dum->next;
        n++;
    }

    int p;
    p = x % n;
    if(p == 0) return head;

    ListNode* curr = head;
    for(int i = 0; i < n - p - 1; i++){
        curr = curr->next;
    }

    ListNode* res = curr->next;
    curr->next = nullptr;
    dum->next = head;

    return res;
}
 
int main(){
    ListNode* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new ListNode(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}