#include<bits/stdc++.h>
using namespace std;
//brute force approach Time complexity = O(n^2 + nlogn)
void problem2(){
    int arrival[] = {900,940,950,1100,1500,1800};
    int departure[] = {910,1200,1120,1130,1900,2000};

    priority_queue<int> lanes;

    for(int i =0;i<6;i++){ //deaprture loop
        int count = 0;
        for(int j=i;j<5;j++){
            if(departure[i]>=arrival[j]){
                count ++;
            }
        }
        lanes.push(count);
    }

    cout << "Min. number of lanes needed is: " << lanes.top() ;
}

//Brute force approach time complexity = O(n^2)

int main(){
    //problem2();
    
}