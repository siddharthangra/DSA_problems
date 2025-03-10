#include<bits/stdtr1c++.h>
using namespace std;

//Q1 Reversing  words in a string

string reverse(string input){
    int n = input.length();
    string dummy;
    for(int i =0; i< n;i++){
        dummy = input[i] + dummy;
    }
    return dummy;
}
void print_string(string input){
    for(int i=0;i<input.length();i++){
        cout << input[i]; 
    }
    cout << endl;
}
string reverse_words(string input){
    string result;
    int i = 0;
    while(i < input.length()){
        string dummy = "";
        while( i < input.length() && input[i] != ' '){
            dummy = input[i] + dummy;
            i ++;
        }
        if(i != input.length()){
            result = result + dummy + " ";
            i++;
        } else { result = result + dummy;}

    }
    return result;
}
int main(){
    string hello = "Hello my name is raj";
    string reversed_hello = reverse(hello);
    string resultant = reverse_words(reversed_hello);
    print_string(resultant);

}