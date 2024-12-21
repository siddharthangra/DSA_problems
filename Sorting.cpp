#include<bits/stdc++.h>
using namespace std;

void selection_sort(){
    int arr[7] = {4,2,5,123,5,12,1};
   
    for(int i=0; i<6; i++){
        int k=i;   //k is used to find the smalled number out of all before swaping
        for(int  j=i+1; j<7; j++){
            if(arr[j]<arr[k])   
            k = j; //changing k for every element smaller than current k's value 
        }
        swap(arr[i],arr[k]);

    }

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
}

void bubble_sort(){
    int arr[7] = {4,2,5,123,5,12,1};
    for(int i=0; i<6; i++){
        for(int j=0; j<7-i; j++){
            if(arr[j+1]< arr[j])
            swap(arr[j],arr[j+1]);
        }
    }

    for(int i=0; i<7;i++){
        cout << arr[i] << " ";
    }
}

void insertion_sort(){
    int arr[7] = {14,9,15,12,6,8,13};
    for(int i=1;i<7;i++){
        for(int j=i;j>0;j--){
            if (arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else break;
        }
    }

    for(int i=0;i<7;i++){
        cout << arr[i]<< " ";
    }
}


void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;     
    int right = mid + 1;   
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void divide(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    divide(arr, low, mid);  // left half
    divide(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

void merge_sort(){
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;
    divide(arr, 0, n - 1);

    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
}

void recursive_bubble_sort(int arr[], int n){
    if(n>1){
        for(int i=0; i<n; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        recursive_bubble_sort(arr,n-1);
    }
}

void recursive_insertion_sort(int arr[], int n, int i){
    while(i< n){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else break;
        }
        i++;
        recursive_insertion_sort(arr,n,i);
    
    }
}


int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
