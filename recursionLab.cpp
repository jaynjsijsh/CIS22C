/*
* Lab 1
* Harmony Trinh & Jayne Tan
* The purpose of this lab is to identify if every element in an array is prime in a user input array using recursion and iteration
*/
#include <iomanip>
#include <iostream>
using namespace std;

/*
* Function IsArrayPrimeIter(int arr[], int size)
* This function determines whether all members of an array are prime numbers iteratively
*   Pre: arr- non-empty array of integer numbers
*        size- size of the array
*   Post:
*   Result:true or false
* 
*   1 print "Entering IsArrayPrimeIter", next line
*   2 prime = true
*   3 loop(go through every element of the array)
*       1 if(array elemnt is 1)
*           1 prime = false
*       2 end if
*       3 loop(through numbers to check if divisible)
*           1 if(element of array modulus number is 0)
*               1 prime = false
*           2 end if
*       4 end loop
*   4 end loop
*   5 print "Leaving IsArrayPrimeIter", next line
*   6 return prime
* end IsArrayPrimeIter
*/
bool IsArrayPrimeIter(int arr[], int size) {
    cout << "Entering IsArrayPrimeIter \n";
    bool prime = true; //boolean to determine if prime

    // loop through the array
    for (int i = 0; i < size; i++) {
        //if array element is equal to 1 then cannot be prime 
        if (arr[i] == 1) {
            prime = false;

        }

        // loop through all numbers from 2 to the array index divided by 2
        for (int j = 2; j <= arr[i] / 2; j++) {
            // not a prime if arr[i] is divisible by j
            if (arr[i] % j == 0) {
                // cout<< arr[i] << "is prime\n";
                prime = false;

            }
        }
    }
    cout << "Leaving IsArrayPrimeIter \n";
    //cout << prime << "\n";
    return prime;
}

/*
* Function IsPrimeRecur(int num, int divisor)
* This is a helper function for IsArrayPrimeRecur which recursively check if a number is prime
*   Pre: num- number to check
*        divisor- divisor
*   Post:
*   Result: true or false
* 
*   1 print "Entering IsPrimeRecur", next line
*   2 prime = true
*   3 if(number is less than 2)
*       1 prime = false
*       2 print "Leaving IsPrimeRecur", next line
*       3 return prime
*   4 end if
*   5 if(divisor is less than 2)
*       1 print "Leaving IsPrimeRecur", next line
*       2 return prime
*   6 end if
*   7 if(number modulus divisor equals 0)
*       1 prime = false
*       2 print "Leaving IsPrimeRecur", next line
*       3 return prime
*   8 end if
*   9 call IsPrimeRecur again, but decrement divisor by 1
* end IsPrimeRecur
*/
bool IsPrimeRecur(int num, int divisor) {
    cout << "Entering IsPrimeRecur\n";
    bool prime = true;

    // check if the number is valid. if the number is less than 2 then it
    // cannot be prime so return false and exit function
    if (num < 2) {
        prime = false;
        cout << "Leaving IsPrimeRecur" << endl;
        //cout << prime << endl;
        return prime;
    }

    //if divisior is less than 2, then it is prime
    if (divisor < 2) {
        cout << "Leaving IsPrimeRecur \n";
        //cout << prime << "\n";
        return prime;
    }

    // if the number is divisible by the divisor, then it is not prime
    if (num % divisor == 0) {
        prime = false;
        //cout << prime << "\n";
        cout << "Leaving IsPrimeRecur \n";
        return prime;
    }
    //call function again, divisor decreases by 1
    return IsPrimeRecur(num, divisor - 1);
}

/*
* Function IsArrayPrimeRecur(int arr[], int size)
* This function checks if an array only consists of prime numbers recurrsively
*   Pre: arr- non-empty array of integer numbers
*        size- size of the array
*   Post:
*   Return: true or false
* 
*   1 print "Entering IsArrayPrimeRecur", next line
*   2 prime = true
*   3 if(size less than 1)
*        1 print "Leaving IsArrayPrimeRecur", next line
*        2 return prime
*   4 end if
*   5 if(element of array is not prime)
*        1 prime = false
*        2 print "Leaving IsArrayPrimeRecur", next line
*        3 return prime
*   6 end if
*   7 call IsArrayPrimeRecur again, but decrement size by 1
* end IsArrayPrimeRecur
*/
bool IsArrayPrimeRecur(int arr[], int size) {
    cout << "Entering IsArrayPrimeRecur \n";
    bool prime = true;

    //if all elements are prime, prime is true
    if (size < 1) {
        cout << "Leaving IsArrayPrimeRecur \n";
        //cout << "Everything is prime \n";
        return prime;
    }
    
    if (IsPrimeRecur(arr[size - 1], arr[size - 1] - 1) == false) {
        prime = false;
        //cout << "Hit nonprime \n";
        cout << "Leaving IsArrayPrimeRecur \n";
        return prime;
    }
    //call function again, size decreases by 1
    return IsArrayPrimeRecur(arr, size - 1);
}

int main() {
    int SORT_MAX_SIZE = 16; //max size for array
    //user inputs array size
    cout << "Please input an array size" << endl;
    int arrSize;
    cin >> arrSize;

    //check if user input for size is valid, if not request a valid size
    if (arrSize > SORT_MAX_SIZE || arrSize < 1) {
        cout << "Please input a valid array size" << endl;
        cin >> arrSize;
    }

    //ask for user input for an array based on array size
    int* arr = new int[arrSize];
    cout << "Enter array numbers separated by spaces" << endl;
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    // check if array is prime iteratively and print whether array is prime or not
    if (IsArrayPrimeIter(arr, arrSize)) {
        cout << "Prime Array using iteration" << endl;
    }
    else {
        cout << "Not a Prime Array using iteration" << endl;
    }

    // check if array is prime recursively and print whether array is prime or not
    if (IsArrayPrimeRecur(arr, arrSize)) {
        cout << "Prime Array using recursion" << endl;
    }
    else {
        cout << "Not a Prime Array using recursion" << endl;
    }
    cin.get();
    cin.ignore();
    return 0;
}
