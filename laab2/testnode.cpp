#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next;
};


int main(){
    Node* first = new Node{"the", nullptr};
    Node* second = new Node{"show", nullptr};
    Node* third = new Node{"must", nullptr};

    first->next = second;
    second->next = third;
    third->next = nullptr;

    Node* head = first;

    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }



    return 0;
}