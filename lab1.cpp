#include <iostream>
#include <iomanip>
using namespace std;

int main() {

}

bool isArrayPrimeIter(int arr[], int size) {
    cout << "Entering isArrayPrimeIter" << endl;
    for(int i = 0; i < size - 1; i++){
        for(j = 2; j < sqrt(arr[i]); j++){
            if (arr[i] % j){
                cout << "Leaving isArrayPrimeIter" << endl;
                return false;
            }
        }
    }
    cout << "Leaving isArrayPrimeIter" << endl;
    return true;
}

bool isArrayPrimeRecur(int arr[], int size){
    /*
    enter functin
    do
    isprimerecur
    isarrayprimerecur()
    while true
    */
}

bool isPrimeRecur(int num, int div){
    if (num < 2){
        return false;
    }
    
    if(div == 1){
        return true;
    }

    if(num % div == 0){
        return false;
    }


    return isPrimeRecur(num, div - 1);
}