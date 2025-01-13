#include<bits/stdc++.h>
using namespace std;

// Initiliasing DLL
class node{
    public:
    int data;
    node* next;
    node* prev;

    public:
    node(int data1, node* next1, node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

//Q1 Delete all occurences of a key in DLL
node* delocckey(node* head, int key){
    node* dummyhead = new node(-1);
    node* old = dummyhead;
    node* curr = head;
    while(curr != NULL){
        if(curr->data == key){
            node* temp = curr;   
            curr = curr->next;
            if(curr != NULL){curr->prev = old;}
            old->next = curr;
            delete temp;
        }
        else{
            old = curr;
            curr = curr->next;
        }
    }
    return dummyhead->next;
}
//forming DLL for this q
node* DLL(){
    node* first = new node(10);
    node* second = new node(4);
    node* third = new node(100);
    node* fourth = new node(10);
    node* fifth = new node(10);
    node* sixth = new node(6);
    node* seventh = new node(10);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    seventh->prev = sixth;
    sixth->prev = fifth;
    fifth->prev = fourth;
    fourth->prev = third;
    third->prev = second;
    second->prev = first;

    return first;
}

// to print a DLL
void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<< temp->data << "->";
        temp = temp->next;
    }   
    cout << "NULL" << endl; 
}

int main(){
    node* head = DLL();
    int key = 10;
    node* newhead = delocckey(head,key);
    print(newhead);
}