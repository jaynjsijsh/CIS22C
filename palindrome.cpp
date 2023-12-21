/*
Midterm
Jayne Tan
The purpose of this lab is to print out a list of palindromes in descending order from 
a user inputted array of numbers.j
*/
#include <iostream>
#include <iomanip>
using namespace std;



bool isPalindrome(int n){
    int origNum = n;
    int reverseNum = 0;

    if(n < 0){
        return false;
    }

    while(n > 0){
        int digit = n % 10;
        reverseNum = reverseNum * 10 + digit;
        n /= 10;
    }

    return origNum == reverseNum;
}

void sortArray(int arr[], int size){
    for(int i = 0; i < size -1; i++){
        int maxInd = i;

        for(int j = i + 1; j < size; j++){
            if(arr[j] > arr[maxInd]){
                maxInd = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[maxInd];
        arr[maxInd] = temp;
    }
}

int main() {
    int arr[8];
    int arrSize = 0;

    cout << "enter a list of integers : " << endl;

    while (true) {
        int inputNum;
        cin >> inputNum;
        
        if (inputNum == -1) {
            break;
        }

        if (inputNum < 0 || inputNum > 99999) {
            continue;
        }

        if (arrSize >= 8) {
            continue;
        }

        arr[arrSize] = inputNum;
        arrSize++;
    }

    int palinArr[8];
    int palinSize = 0;

    for(int i = 0; i < arrSize; i++){
        if(isPalindrome(arr[i])){
            palinArr[palinSize] = arr[i];
            palinSize++;
        }
    }
    
    sortArray(palinArr, palinSize);

    for(int i = 0; i < palinSize; i++){

        cout << palinArr[i] << " ";
    }
    

}
