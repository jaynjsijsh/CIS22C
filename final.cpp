#include <iomanip>
#include <iostream>
using namespace std;

unsigned int lcm(unsigned int a, unsigned int b) {
    static unsigned int m = 0;
    // Increments m by adding max value to it
    if (m + b <= m) {
        throw runtime_error("unsigned long long overflow");
    } else {
        m += b;
    }
    // cout << " m = " << m;
    //  If found a common multiple then return the m.
    if ((m % a == 0) && (m % b == 0)) {
        return m;
    } else {
        return lcm(a, b);  // calling the function 
    }
}

int main() {
    cout << lcm(97, 311) << endl;
    try {
        cout << lcm(77777, 67890) << endl;
    } catch (std::runtime_error ex) {
        cout << ex.what();
    }
};