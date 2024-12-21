#include<bits/stdc++.h>
using namespace std;

// PASCAL'S TRIANGLE
// Variation-1 printing out the nth row of the pascal triangle

vector<int> nthrowofpascaltriangle(int n){
    if(n==1){
        return {1};
        
    }
    else{
        vector<int> prev_row = nthrowofpascaltriangle(n-1);
        vector<int> curr_row(n);

        curr_row[0] = 1;
        for(int i=1;i<n-1;i++){
            curr_row[i] = prev_row[i-1] + prev_row[i];
        }
        curr_row[n-1] = 1;
        return curr_row;
    }
}
// time complexity nlogn + n space complexity 1
void printingnthrow(){
    int n = 4;
    vector<int> print_arr = nthrowofpascaltriangle(n);
    for(int i=0;i<n;i++){
        cout << print_arr[i] << " ";
    }
}
//variation 2  given the row number r and column number c print the element at (r,c)
// time compplexity same as variation 1
void printingelement(){
    int r = 5;
    int c = 3;
    vector<int> wanted_arr = nthrowofpascaltriangle(r);

    cout << wanted_arr[c-1];
}
//variation 3 printing the pascal triangle upto row n
// time complexity
void printingpascaltriangle(int n){
    for(int i=1;i <= n;i++){
        vector<int> arr = nthrowofpascaltriangle(i);
        for(int j=0;j<i;j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}
// the code for variation 2 is not optimal cause it by default take n^2 time complexity cause of loop.
// If u look carefully all the elements of pascal triangle = (n-1)c(R-1) where N is row number and R is column number and NcR is combinatorics
// using this we can find the element with this formula within the time complexity of O(r)
int variation_2(int r, int c){
    int r2 = r-1;
    int c2 = c-1;
    int value = 1;
    for(int i=0;i<c2;i++){
        value = value * (r2-i);
        value = value/(i+1);
    }
    return value;
}

//PROBLEM STATEMENT
//Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.
void n_3(){
    vector<int>  arr = {1,2,2,3,2};
    int n = arr.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]] ++;
    }

    for(auto it=mpp.begin(); it != mpp.end(); it ++){
        if( it->second > n/3){
            cout << it->first << " ";
        }
    }
}

// Find triplets that add up to a zero in an array
void triplets(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end()); // nlogn time complexity 
    int i = 0;
    int j = 1;
    int k = n-1;
    int temp;
    while (i < n-2){
        int sum = arr[i] + arr[j] + arr[k];
        if(k <= j){
            temp = arr[i];
            while(arr[i] <= temp){
                i++ ;
            }
            j = i+1;
            k = n-1;
        }
        else if(sum == 0){
            cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            temp = arr[j];
            while(arr[j] <= temp){
                j++;
            }
            temp = arr[k];
            while(arr[k] >= temp){
                k-- ;
            }
        }
        else if(sum < 0){
            temp = arr[j];
            while(arr[j] <= temp){
                j++;
            }
        }
        else if(sum > 0){
            temp = arr[k];
            while(arr[k] >= temp){
                k-- ;
            }
        }
        
    }
}

//Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
void longest_subarray(vector<int> &arr){
    int n = arr.size();
    unordered_map<int,int> mpp;
    int length = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum +=arr[i];
        if(sum == 0){
            length = i+1;
        }
        else if(mpp.find(sum) != mpp.end()){
            length = max(length, i-mpp[sum]);
        }
        else{
            mpp[sum] = i;
        }
    }

    cout << length;

}


// Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.
void xor_sum(vector<int> &arr, int k){
    int n = arr.size();
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int Xorsum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        Xorsum = Xorsum^arr[i];
        if(mpp.find(Xorsum^k) != mpp.end()){
            int s = mpp[Xorsum^k];
            cnt  +=s;
        }
        mpp[Xorsum] ++;
    }

    cout << cnt;

}
//Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
void intervals(vector<vector<int>> &arr) {
    int n = arr.size(); 
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    for(auto it : ans){
        cout << "[" << it[0] << "," << it[1] << "]";
    }
}
void twice_missing(){
    vector<int> arr = {3,1,2,5,4,6,7,5};
    int n = arr.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(arr[i])!= mpp.end()){
            cout << "{" << arr[i] << "," ;
            mpp[arr[i]] ++;
        }
        else mpp[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(mpp.find(i) == mpp.end()){
            cout << i << "}";
        }
    }
}

void product_subarray(vector<int> &arr){
    int n = arr.size();
    int low = 1;
    int product = 1;
    int high = arr[0];
    int prev_high;
    for(int i = 0;i<n;i++){
        if(arr[i]==0){
            product = 1;
            low = 1;
        }
        else{
            product= product*arr[i];
            prev_high = max(product,product/low);
            high = max(high,prev_high);
            low = min(low,product);
        }
    }
    cout << high;
}
int main(){
    //n_3();
    //triplets(hehe); 
    //longest_subarray(arr);
    //xor_sum(lol, 6);
    //vector<vector<int>> hihi = {{1,3},{8,10},{2,6},{15,16}};
    //intervals(hihi);
    //twice_missing();
    vector<int> wallah = {1,2,-3,0,-4,-5};
    product_subarray(wallah);
    

}