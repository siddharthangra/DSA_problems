#include<bits/stdc++.h>
using namespace std;

//sort the array of 0's, 1's and 2's
void problem_1(){
    int arr[6] = {2,0,2,1,1,0};
    int low = 0;
    int mid = 0;
    int high = 5; //n-1

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low ++;
            mid ++;
        }
        else if(arr[mid] == 1){
            mid ++;
        }
        else{
            swap(arr[high],arr[mid]);
            high --;
        }
    }

    for(int i=0;i<6;i++){
        cout << arr[i] << " ";
    }

}


//Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

// Brute force approach time complexity O(n^3)
void problem_2(){
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int maxi = 0;

    for(int i=0;i<9;i++){
        for(int j=0;j<9-i;j++){
            int sum = 0;
            for(int k=i;k<=i+j;k++){
                sum += arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    cout << maxi;
}

// optimal approach. time complexity O(n^2)
void problem_2_b(){
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int maxi = 0;

    for(int i=0;i<9;i++){
        int sum = 0;
        for(int j=i;j<9;j++){
            sum += arr[j];
            maxi = max(sum,maxi);
        }
    }

    cout << maxi;
}



// STOCK BUY AND SELL //
/* Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */
// Note that you can't sell before you buy i.e if u buy at i=2 you can sell at onnly i>=2
void problem_3(){
    int arr[6] = {7,1,5,3,6,4};
    int j = 0;
    int profit = 0;
    int difference,buy,sell;

    for(int i=0;i<6;i++){
        difference = arr[i] - arr[j];
        profit = max(profit,difference);

        if(difference < 0){
            j = i;
        }
        if(difference >= profit){
            buy = j;
            sell = i;
        }
    }

    cout << "profit: " << profit << endl;
    cout << "Buy on: " << buy << endl;
    cout << "Sell on:" << sell << endl;
}

//PROBLEM-4
/*
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
Start the array with positive element
*/ 

void problem_4(){
    int arr[6] = {1,2,-3,-1,-2,3};
    int positive = 0;
    int negative = 1;
    int i = 0;
    while(i<5){
        if(i%2 == 0){
            if(arr[i] >= 0){
                swap(arr[i],arr[positive]);
                positive +=2;
                i ++;
            }
            else{
                swap(arr[i],arr[negative]);
            }
        }
        else{
            if(arr[i]<0){
                swap(arr[i],arr[negative]);
                negative +=2;
                i++;
            }
            else{
                swap(arr[i],arr[positive]);
            }
        }
    }

    for(int j=0;j<6;j++){
        cout << arr[j] << " "; 
    }
}


//PROBLEM-5
// Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

void problem_5(){
    int arr[5] = {8,4,7,1,0};
    int g = 4;
    cout << arr[g] << " ";
    for(int i = 3;i>=0;i--){
        if(arr[i]>arr[g]){
            g = i;
            cout << arr[g] << " ";
        }
    }
}

//PROBLEM-6
//given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.
// where elements don't have to be in sorted manenr or grouped together
void problem_6(){
    vector<int> arr = {102,4,100,1,101,3,2,1,1};
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int len = 0;
    for(int i=1;i<9;i++){
        if(arr[i] == arr[i-1]+1){
            cnt ++;
        }
        else{
            len = max(len,cnt);
            cnt = 1;
        }
    }
    cout << len;
}
// time complexity = O(nLogn + n)

// Optimal approach
//unoredered set has a time complexity of O(n) to store elements init as well as it's set operaations take O(1) time complexoty
int problem_6_optimal(vector<int> &arr){
    int n= arr.size();
    int length = 1;
    unordered_set<int> temp;

    for(int i=0;i<n;i++){
        temp.insert(arr[i]);
    }

    for(auto it : temp){
        if( temp.find(it-1) == temp.end()){
            int cnt = 1;
            int x = it;
            while(temp.find(x+1) != temp.end()){
                cnt ++;
                x ++;
            }
            length = max(length,cnt);
        }
    }

    return length;

}

//Rotate the matrix 90 degree clockwise
vector<vector<int>> matrices(vector<vector<int>> &matrix, int n){
    vector<vector<int>> new_matrix(n,vector<int>(n,0)); //initializing every element to 0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            new_matrix[i][j] = matrix[n-1-j][i];
        }
    }
    return new_matrix;
}
void rotating_matrix(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n = matrix.size();
    vector<vector<int>> rotated_matrix = matrices(matrix,n);
    for(int i=0;i<rotated_matrix.size();i++){
        for(int j=0;j<rotated_matrix[0].size();j++){
            cout << rotated_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// previous method ime complexity : O(mn) and space complexity O(mn)
// Optimal solution with time complexity O(mn) while spacce complexity O(1)

void transpose_reverse(vector<vector<int>> &matrix, int n){
    //Transposing the matrix
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // reversing the rows
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
}
void rotating_matrix_2(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n = matrix.size();

    transpose_reverse(matrix, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void spiral_matrix(vector<vector<int>> &matrix){
    vector<int> ans;
    int n = matrix.size(); //no' of rows
    int m = matrix[0].size(); // no  of columns

    int top=0; int left = 0; int right = m-1; int bottom = n-1;
    

    while(top<=bottom && left<=right){
        // printing the top row
        for(int i=left; i<=right; i++){
            cout << matrix[top][i] << ",";
        }
        top ++;

        // printing the right column
        for(int i=top;i<=bottom;i++){
            cout << matrix[i][right] << ",";
        }
        right --;
        
        // printng the bottom row
        for(int i=right; i>=left;i--){
            cout << matrix[bottom][i] << ",";
        }
        bottom --;

        // printing the left column
        for(int i = bottom; i >= top; i--){
            cout << matrix[i][left] << ",";
        }
        left++;

    }
}

void printSpiral(vector<vector<int>> mat) {
 
  // Define ans array to store the result.
  vector<int> ans;
 
  int n = mat.size(); // no. of nows
  int m = mat[0].size(); // no. of columns
  
  // Initialize the pointers reqd for traversal.
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
      
    // For moving left to right
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);

    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);

    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);

      left++;
    }
  }
}

//Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
void findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    unordered_map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    cout << cnt;
}


 
int main(){
    //problem_1();
    //problem_2();
    //problem_2_b();
    //problem_3();
    //problem_4();
    //problem_5();
    //problem_6();
    /*
    vector<int> arr = {102,4,101,1,100,3,2,1,1};
    int ans = problem_6_optimal(arr);
    cout << "The longest consecutive sub-sequece is: " << ans;
    */
   //rotating_matrix();
   //rotating_matrix_2();
   /*
   vector<vector<int>> mat = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
   spiral_matrix(mat);
   */
    vector<int> array = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    findAllSubarraysWithGivenSum(array,k);
  
}
