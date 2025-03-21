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

// Q5 Length of loop in linked list 
// Forming LL with a loop
node* loopLL(){
    node* head  = new node(1);
    node* second = new node(2);
    head->next = second;
    node* third = new node(3);
    second->next = third;
    node* fourth = new node(4);
    node* fifth = new node(5);
    third->next = fourth;
    fourth->next = fifth;
    node* sixth = new node(6);
    fifth->next = sixth;
    sixth->next = third;
    return head;
}
//Solution 
int length_of_loop(node* head){
    node* ptr1 = head;
    node* ptr2 = head;
    int cnt1 = 1;

    if(ptr1->next != NULL && ptr2->next->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        cnt1 ++;
    }
    else  return 0;

    while (ptr2->next != NULL && ptr1 != ptr2 && ptr2 != NULL)
    {
       ptr1 = ptr1->next;
       ptr2  = ptr2->next->next;
       cnt1 ++;
    }
    if( ptr2 == NULL || ptr2->next == NULL){
        return 0;
    }
    else return cnt1 - 1;
}
//Q6 Seggeragate even and odd nodes in LL
node* segoddeven(node* head){
    node* curr = head;
    node* oddhead = new node(0);
    node* evenhead = new node(0);
    node* oddtail = oddhead;
    node* eventail = evenhead;

    while(curr != nullptr){
        if(curr->data & 1){
            oddtail->next = curr;
            oddtail = oddtail->next;
            curr = curr->next;
            oddtail->next = nullptr;
        }
        else{
            eventail->next = curr;
            eventail = curr;
            curr = curr->next;
            eventail->next = nullptr;
        }
    }
    eventail->next = oddhead->next;
    head = evenhead->next;
    delete oddhead;
    delete evenhead;
    return head;
}
//Printing the new LL
void print(node* head){
    node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Q7deleting middle node of ll
node* deletemiddlenode(node * head){
    node* fast = head;
    node* slow = head;
    fast = head->next->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;

}

// Q8 Sorting LL
//algo for finding middle element
node* findmiddle(node* head){
    node* slow = head;
    node* fast = head;
    if(head->next == NULL){
        return head;
    }
    else{
        fast = fast->next->next;
        while(fast != NULL || fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow;
}
// algo for merging
node* merge(node* lefthead, node* righthead){
    node* tempL = lefthead;
    node* tempR = righthead;
    node* temp;
    node* head;

    if(lefthead->data < righthead->data){
        head = lefthead;
    }else head = righthead;

    while(tempL != NULL || tempR != NULL){
        if(tempR->data < tempL->data){
            while(tempR != NULL || tempR->data < tempL->data){
                temp = tempR;
                tempR = tempR->next;
            }
            temp->next = tempL;
        }
        else{
            while(tempL != NULL || tempL->data < tempR->data ){
                temp = tempL;
                tempL = tempL->next;
            }
            temp->next = tempL;
        }

    }

    return head;
}
node* sortLL( node* head){
    node* lefthead;
    node* righthead;
    if(head->next == NULL){
        return head;
    }
    else{
        node* middle = findmiddle(head);
        lefthead = head;
        righthead = middle->next;
        middle->next = NULL;
        lefthead = sortLL(lefthead);
        righthead = sortLL(righthead);
    }

    return merge(lefthead, righthead);
}

// Q9 sorting LL of 0s,1s and 2s
node* sort012(node* head){
    node* zeroeshead = new node(-1);
    node* zeroestail = zeroeshead;
    node* oneshead = new node(-1);
    node* onestail = oneshead;
    node* twoshead = new node(-1);
    node* twostail = twoshead;
    node* temp = head;

    while(temp != NULL){
        switch(temp->data)
        {
        case 1:
            onestail->next = temp;
            onestail = temp;
            temp = temp->next;
            break;
        case 0:
            zeroestail->next = temp;
            zeroestail = temp;
            temp = temp->next;
            break;
        case 2:
            twostail->next = temp;
            twostail = temp;
            temp = temp->next;
            break;
        default:
            break;
        }
    }
    zeroestail->next = oneshead->next;
    onestail->next = twoshead->next;
    return zeroeshead->next;

}
//HARD LL Q
// Q1 Rotate a LL
node* rotate_by_k(node* head, int k){
    int cnt = 1;
    node* count = head;
    while(count->next != NULL){
        cnt ++;
        count = count->next;
    }
    int iteration;
    if(k <= cnt ){iteration = cnt - k;}
    else{iteration = cnt - (k% cnt); }

    count->next = head;
    node* dummyhead = count->next;
    while(iteration != 0){
        iteration -- ;
        count = count->next;
        dummyhead = count->next;

    }

    count->next = NULL;
    return dummyhead;
} // time complexity = o(n);

//Q2 Flattening a LL
// Constructing LL base for the problem in hand
class node2{
    public:
    int data;
    node2* next;
    node2* child;

    public:
    node2(int data1, node2* next1, node2* child1){
        data = data1;
        next = next1;
        child = child1;
    }

    public:
    node2(int data1){
        data = data1;
        next = NULL;
        child = NULL;
    }

};


// Making the LL
node2* unflattenedLL(){
    node2* parent1 = new node2(3);
    node2* parent2 = new node2(2);
    node2* parent3 = new node2(1);
    node2* parent4 = new node2(4);
    node2* parent5 = new node2(5);

    parent1->next = parent2;
    parent2->next = parent3;
    parent3->next = parent4;
    parent4->next = parent5;

    node2* child1 = new node2(10);
    node2* child2 = new node2(7);
    node2* child3 = new node2(11);
    node2* child4 = new node2(12);
    node2* child5 = new node2(9);
    node2* child6 = new node2(6);
    node2* child7 = new node2(8);

    parent2->child = child1;
    
    parent3->child = child2;
    child2->child = child3;
    child3->child = child4;

    parent4->child = child5;

    parent5->child = child6;
    child6->child = child7;

    return parent1;
}
node2* flattenLL(node2* head){
    node2* temp = head;
    while(temp != NULL){
        node2* curr = temp;
        while(curr->child != NULL){
            curr = curr->child;
        }
        curr->child = temp->next;
        temp->next = NULL;
        temp = curr->child;
    }
}
//sorting this flattenedLL
node2* findmiddlenode2(node2* head){
    node2* slow = head;
    node2* fast = head;
    if(head->child == NULL ){
        return head;
    }
    else{
        fast = fast->child->child;
        while(fast!= NULL || fast->child != NULL){
            slow = slow->child;
            fast = fast->child->child;
        }
    }
    return slow;
}
node2* mergeflattenedLL(node2* lefthead, node2* righthead){
    node2* tempL = lefthead;
    node2* tempR = righthead;
    node2* temp;
    node2* head;

    if(lefthead->data <= righthead->data){
        head = lefthead;
    }else { head = righthead;}

    while(tempL != NULL || tempR != NULL){
        if(tempL->data <= tempR->data){
            temp = tempL;
            while(tempL->data <= tempR->data){
                temp = tempL;
                tempL = tempL->child;
            }
            temp->child = tempR;
        }
        else{
            temp = tempR;
            while(tempR->data < tempL->data){
                temp = tempR;
                tempR = tempR->child;
            }
            temp->child = tempL;
        }
    }

    return head;
}
node2* sortflattenedLL(node2* head){
    node2* lefthead;
    node2* righthead;
    if(head->child == NULL){
        return head;
    }
    else{
        node2* middle = findmiddlenode2(head);
        lefthead = head;
        righthead = middle->child;
        middle->child = NULL;
        sortflattenedLL(lefthead);
        sortflattenedLL(righthead);
    }

    mergeflattenedLL(lefthead, righthead);

}

int main(){
    /*
    vector<int> arr = {3,2,5,4,1,6,8,7};
    node* start_point = str2LL(arr);
    */
    /*
    int el = mid_el(start_point);
    cout << el <<endl;;
    node* new_head = recursion(NULL,start_point);
    cout << new_head->data <<endl;
    node* Loop_start_point = loopLL();
    int ans5 = length_of_loop(Loop_start_point);
    cout << ans5 << endl; 
    node* start_pointn = segoddeven(start_point);
    print(start_pointn);
    node* newhead = deletemiddlenode(start_point);
    print(newhead);
    node* sorted_head = sortLL(start_point);
    print(sorted_head);
    */
   /*
   vector<int> arr= {0,1,0,2,1,0,2,2,1,0,2};
   node* startpoint = str2LL(arr);
   node* sortedhead = sort012(startpoint);
   print(sortedhead); */
   /*
    vector<int> arr = {1,2,3,4,5,6,7};
    node* start_point = str2LL(arr);
    node* newhead = rotate_by_k(start_point,300);
    print(newhead);
*/


}