#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int extract(int num, int start, int end);
int rearrange_digits(int num, int divider);

int main() {
// Number manipulation yeet

// Basic mechanism of how the digit is obtained. Code from Lab Test 2019 and 2020 is below the int main() function

// ********** NOTE THE PATTERN: in (num_digits - x), x equals to the position of the digit in the number, left to right. **********

    printf("**********\n");
    int num = 1234567; // 7 digit number!
    int digit_to_obtain = 0;

    int num_digits = (num == 0) ? 1 : log10(num) + 1; // Good way to get the number of digits fast. Doesn't work for negative numbers though!!! use abs(num)!
    printf("There are %d digits\n", num_digits);

    // Get 1
    digit_to_obtain = num / (int)pow(10, num_digits - 1) % 10; // because 1 234 567 / 1 000 000 gives 1, 1 % 10 = 1.
    printf("Got %d\n", digit_to_obtain);

    // Get 4
    digit_to_obtain = num / (int)pow(10, num_digits - 4) % 10; // because num / 1000 gives 1234, 1234 % 10 = 4
    printf("Got %d\n", digit_to_obtain);

    // Get 7
    digit_to_obtain = num / (int)pow(10, num_digits - 7) % 10; // Note the power of 10 = 0, since this digit is on the extreme right. 1 234 567 % 10 = 7.
    printf("Got %d\n", digit_to_obtain);

// Refer to the answer key for LAB TEST 2020 QUESTION 3 for the EXTRACT function
    printf("**********\n");
    extract(num, 2, 4);

// Refer to the answer key for LAB TEST 2019 QUESTION 4 for the REARRANGE_DIGITS function
    printf("**********\n");
    printf("Rearranged number is %d\n", rearrange_digits(num, 5));
    printf("**********\n");
}

int extract(int num, int start, int end) {
    // Number is 1 2 3 4 5 6 7
    // Index   : 0 1 2 3 4 5 6
    int num_digits = (num == 0) ? 1 : (log10(num) + 1); // Get the number of digits

    int new_end = end < num_digits ? end : num_digits; // Purpose of this line of code is to ensure that the 'end' index actually exists in the number

    int result = 0;
    for (int i = start; i < new_end; i++) {
        int n = num_digits - i - 1; // Because in this question the first digit is labelled as 0, so take the position of the digit - 1
        result = result * 10 + num / (int)pow(10, n) % 10; // How to visualise: Let's say before the line is executed, the value of result is 3. Take 3 * 10 to get 30, so when the next digit is added it'll be in the ones place
        printf("Result is %d \n", result);
    }
    return result;
}

int rearrange_digits(int num, int divider) {
    bool is_negative = false;

    if (num < 0) {
        is_negative = true;
        num = -num;
    }

    int smaller = 0; // Value of the smaller number
    int num_smaller = 0;// Number of digits in smaller number on the left side
    int larger = 0; // Value of the larger number
    int num_larger = 0; // Number of digits in larger number on the right side
    int equal = 0; // Value of the middle portion (ie digits = divider)
    int num_equal = 0; // Number of digits in the equal portion

    while (num > 0) {
        int digit = num % 10;

        if (digit > divider) {
            larger = digit * (int)pow(10, num_larger) + larger; // Same concept as line 54
            num_larger++; 
        } else if (digit < divider) {
            smaller = digit * (int)pow(10, num_smaller) + smaller; // Same concept as line 54
            num_smaller++;
        } else {
            equal = digit * (int)pow(10, num_equal) + equal; // Same concept as line 54
            num_equal++; 
        }

        num /= 10;

    }

    int result = (int)pow(10, num_smaller) * equal 
            + smaller 
            + (int)pow(10, num_smaller + num_equal) * larger;

    if (is_negative) { // Account for negative numbers
        return -result;
    }
    return result;
}