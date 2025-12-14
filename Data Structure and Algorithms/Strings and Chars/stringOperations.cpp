#include<iostream>
using namespace std;
int findLength(char name[]){
    int count = 0;

    for (int i = 0; name[i] != 0; i++){
        count++;
    }

    return count;
}
char* reverse(char string[]){
    int start = 0, end = findLength(string) - 1;

    while (start < end){
        swap(string[start++], string[end--]);
    }

    return string;
}

int main(){
    char name[20];
    
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is " << findLength(name) << " characters long.\n";
    cout << "Reverse of your name is: " << reverse(name) << endl;
    
    for (char &ch : name){
        ch = tolower(ch);
    }

    cout << name;

    return 0;
}