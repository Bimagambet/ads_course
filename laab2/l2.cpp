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

int findMaxSum(int n, ListNode* head){
    int cur_sum = head->data;
    int max_sum = head->data;

    ListNode* curr = head->next;

    while(curr){
        cur_sum = max(curr->data, cur_sum + curr->data);
        max_sum = max(max_sum, cur_sum);
        curr = curr->next;

    }

    return max_sum;

}

int main(){
    int n;
    cin >> n;

    int p;
    cin >> p;

    ListNode* head = new ListNode(p);
    ListNode* tail = head;

    for(int i = 1; i < n; i++){
        cin >> p;
        tail->next = new ListNode(p);
        tail = tail->next;
    }

    cout << findMaxSum(n, head) << endl;

    return 0;
}