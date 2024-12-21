#include<bits/stdc++.h>
using namespace std;

//initiliasing LL structure
class node{
    public:
    int data;
    node* next;

    public:
    node(int data1, node* next1){
        data = data1;
        next = next1;
    }

    public:
    node(int data1){
        data = data1;
        next = nullptr;
    }
};

//initialisiing linked list to be used in questions
node* str2LL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        node*temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;   
    }

    return head;
}
//Q-1 Finding middle elements
int mid_el(node* head){
    node* mover1 = head;
    node* mover2 = head;
    while(mover1 != NULL && mover1->next != NULL){
        mover1 = mover1->next->next;
        mover2 = mover2->next;
    }
    return mover2->data;
}
//Q-2 Reversing the LL by iteration
node* appraoch1(node* head){
    node* mover1 = head;
    node* mover2 = mover1->next;
    node* mover3 = mover2->next;
    mover1->next = NULL;

    while(mover1->next != NULL){
        mover2->next = mover1;
        mover1 = mover2;
        mover2 = mover3;
        mover3 = mover2->next;
    }
    return mover1;
}
//Q3 Reversing the LL by recursion 
node* recursion(node* temp1, node* temp2){
    if(temp2 != NULL){
        node* mover = temp2->next;
        temp2->next = temp1;
        return recursion(temp2,mover);
    }
    else{
        return temp1;
    }
}
//Q4 finding loop in a LL
/*
bool find_cycle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL || fast->next != NULL){
        if(fast->next->next = slow || fast->next = slow){
            return true;
        }
        else{
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return false;
}
*/





int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    node* start_point = str2LL(arr);
    int el = mid_el(start_point);
    cout << el <<endl;;
    node* new_head = recursion(NULL,start_point);
    cout << new_head->data <<endl;
    
}