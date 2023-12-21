/**
 * scratch 1
 **/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

static void fix_num_digit_print(double radiusMeasured1) {
    // define total number of digits
    constexpr int digits = 7;

    // round to the 7 th digit, count from MSB
    const double radiusMeasured1_factor =
        pow(10, ceil(log10(radiusMeasured1)) - digits);
    const double radiusMeasured1_rounded =
        round(radiusMeasured1 / radiusMeasured1_factor) * radiusMeasured1_factor;

    // Convert the number to a string
    std::string radiusMeasured1_str = to_string(radiusMeasured1_rounded);

    // then resize and padding (or truncate)
    radiusMeasured1_str.resize(digits + 1, '0');

    // then output
    cout << radiusMeasured1_str << endl;
}

int main() {
    fix_num_digit_print(434.75);
    fix_num_digit_print(434.752987);
    fix_num_digit_print(926052.125);
    fix_num_digit_print(78258.25);
    fix_num_digit_print(78258.2378);
    fix_num_digit_print(782589);
    fix_num_digit_print(7825893);
    fix_num_digit_print(8635476.625);
}
