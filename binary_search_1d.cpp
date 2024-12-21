#include<bits/stdc++.h>
using namespace std;

void upper_bound(vector<int> &arr, int x){
    int n =   arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(high >= low){
        int mid = (low+high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    cout << ans << endl;

}
void insert_position(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(high >= low){
        int mid  = (high + low)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid +1;
        }
    }
    cout << ans<< endl;
}
void last_occurence(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(high >= low){
        
    }
}

void num_rotation(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int element = arr[0];
    int pointer = (high + low)/2;
    while(high >= low){
        int mid = (high + low)/2;
        if(arr[mid] > arr[high]){
            if(element != min(arr[mid],element)){
                pointer = mid;
            }
            element = min(arr[mid], element);
            low = mid + 1;
        }
        else{
            if(element != min(arr[mid],element)){
                pointer = mid;
            }
            element = min(arr[mid],element);
            high = mid - 1;
        }
    }
    int ans = n - pointer;
    cout << ans << endl;
}
int peak(vector<int> &arr){
    int n = arr.size();
    if(arr[0]> arr[1]){
        return 0;
    }
    else if(arr[n-1]>arr[n-1]){
        return n-1;
    }
    else{
        int low = 1;
        int high = n-2;
        while(high>=low){
            int mid = (high + low)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid] < arr[mid+1]){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
    }
}
int max_el(vector<int> &arr){
    int n = arr.size();
    int maxi = arr[0];
    for(int i = 1;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int min_el(vector<int> &arr){
    int n = arr.size();
    int mini = arr[0];
    for(int i = 1;i<n;i++){
        mini = min(mini,arr[i]);
    }
    return mini;
}
int bouquet(vector<int> &arr, int day, int k){
    int n = arr.size();
    int num_bouquet = 0;
    int num_flowers = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] <= day){
            num_flowers ++;
            if(num_flowers == k){
                num_bouquet ++;
                num_flowers = 0;
            }
        }
        else{
            num_flowers = 0;
        }
    }
    return num_bouquet;
}
void min_days(vector<int> &arr, int m, int k){
    int ans;
    int low = min_el(arr);
    int high = max_el(arr);
    while(high >= low){
        int mid = (high+low)/2;
        if(bouquet(arr,mid,k) >= m){
            high = mid -1;
            ans = mid;
        }
        else{
            low = mid +1;
        }
    }
    cout << ans << endl;

}

void kth_missing_num(vector<int> &arr, int k ){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = k;
    while(high >= low){
        int mid = (high + low)/2;
        if(arr[mid] <= ans){
            
        }
    }
}
int array_sum(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n;i++){
        sum += arr[i];
    }
    return sum;
}
int split_array_check(vector<int> &arr, int limit){
    int n = arr.size();
    int num_subarray = 1;
    int sum = 0;
    for(int i = 0; i<n; i++){
        if(sum + arr[i] <= limit){
            sum += arr[i];
        }
        else{
            num_subarray ++;
            sum = arr[i];
        }
    }
    return num_subarray;
}
void split_array(vector<int> &arr, int k){
    int low = max_el(arr);
    int high = array_sum(arr);
    int ans;
    while(high >= low){
        int mid = (high + low)/2;
        int check = split_array_check(arr, arr[mid]);
        if(check <= k){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
}



int main(){
    vector<int> first = {1,2,4,5,6,8,8,10,10,11};
    upper_bound(first , 8);
    insert_position(first, 7);
    vector<int> lmao = {6,7,8,9,0,1,2,3,4,5};
    num_rotation(lmao);
    vector<int> humph = {1,2,3,4,5,6,7,8,5,1};
    int ans = peak(humph);
    cout << ans << endl;
    vector<int> roses = {7,7,7,7,13,11,12,7};
    min_days(roses,2,3);
    vector<int> robo_da = {3,5,1};
    split_array(robo_da, 3);
}