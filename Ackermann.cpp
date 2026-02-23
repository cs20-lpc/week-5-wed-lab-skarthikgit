#include <iostream>
using namespace std;

/*
The Ackermann function A(m, n) is defined recursively as follows:

If m equals 0, then
A(m, n) = n + 1

If m is greater than 0 and n equals 0, then
A(m, n) = A(m − 1, 1)

If m is greater than 0 and n is greater than 0, then
A(m, n) = A(m − 1, A(m, n − 1))
*/
// Ackermann function definition
unsigned long long ackermann(unsigned int m, unsigned int n) {
    // TODO: Complete the code.
    if (m == 0) {
        return n + 1;
    }

    if (m > 0 && n == 0) {
       return ackermann(m - 1, 1);
    }

    return ackermann(m - 1, ackermann(m, n - 1));

}

int main() {
    unsigned int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    // Plain recursion overflows quickly for Ackermann; keep inputs in a safe range.
    if (m > 3 || (m == 3 && n > 10)) {
        cout << "Input too large for recursive demo (safe range: m < 3, or m = 3 with n <= 10)." << endl;
        return 1;
    }

    cout << "Ackermann(" << m << ", " << n << ") = " 
         << ackermann(m, n) << endl;

    return 0;
}
