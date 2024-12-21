#include<bits/stdc++.h>
using namespace std;

// finding largest element in a given array
void q1(){
    int arr[] = {8,10,5,7,9};
    int largest_element = arr[0];
    for(int i=0; i<4;i++){
        if(arr[i] > largest_element){
            largest_element = arr[i];
        }
    }
    cout << largest_element;
}

// second largest and second smallest element without sorting
void q2(){
    int arr[] = {2,4,1,3,8,6};
    int max1;
    int max2;
    if(arr[0] > arr[1]){
        max1 = arr[0];
        max2 = arr[1];
    }
    else{
        max1 = arr[1];
        max2 = arr[0];
    }

    for(int i=2;i<=5;i++){
        if(arr[i]>max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2){
            max2 = arr[i];
        }
    }

    cout << max2;
    
}

// removing duplicates from a sorted array with time complexity O(N)
void q3(){
    int arr[11] = {1,1,2,3,3,4,5,5,5,6,6};
    int k;
    int i=0;
    for(int j=1;j<11;j++){
        if(arr[j] != arr[i]){
            arr[i+1]= arr[j];
            i++;
            k = i;
        }
    }

    for(int i=0;i<=k;i++){
        cout << arr[i] << " ";
    }
    

}

// left rotate the array by k places
void q4(){
    int arr[7] = {1,2,3,4,5,6,7};
    int k = 3;
    int temp[k];

    for(int i=0;i<3;i++){
        temp[i] = arr[i];
    }

    for(int i=0;i<4;i++){
        arr[i] = arr[i+3];
    }

    for(int i=4;i<7;i++){
        arr[i] = temp[i - (k+1)];
    }

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
}


//moving all the zeros to the end within time complexity of O(n)
void q5(){
    int zero = 0;
    int non_negative = 0;
    int arr[8]  = {1,0,2,3,0,4,0,1};

    for(int i=0;i<8;i++){
        if(arr[i] != 0){
            swap(arr[zero],arr[non_negative]);
            zero ++;
            non_negative ++;
        }
        else{
            zero ++;
        }
    }

    for(int i =0;i<8;i++){
        cout << arr[i] << " ";
    }
}

//Finding union of two sorted arrays 
void unionxd(){
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[7] = {2,3,4,4,5,11,12};
    set<int> arr3;
    for(int i=0;i<10;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<10;i++){
        arr3.insert(arr1[i]);
    }
    for(int i=0;i<7;i++){
        arr3.insert(arr2[i]);
    }

    for(auto it = arr3.begin(); it != arr3.end(); ++it){
        cout << *it << " ";
    }
}

//Find the missing number in an array
//Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.
void missing_number(){
    int arr[4] = {1,2,4,5};
    for(int i=1;i<4;i++){
        if(arr[i] != arr[i-1]+1){
            cout << arr[i-1]+1 << " ";
            break;
        }
    }
}
//above approach is fine cause we are just dealing with one number not being present in the array



//Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
void binary(){
    int arr[6] = {1,1,0,1,1,1};
    priority_queue<int> pq;

    int flag = 0;
    for(int i=0;i<6;i++){
        if(arr[i] == 0){
            pq.push(flag);
            flag == 0;
        }
        else{
            flag++;
        }
    }
    cout << pq.top();
}
int main(){
    //q1();
    //q2();
    //q3();
    //q4();
    //q5();
    //unionxd();
    //missing_number();
    binary();
}