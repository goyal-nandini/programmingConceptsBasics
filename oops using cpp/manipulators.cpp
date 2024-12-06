//manipulators : endl, setw
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
        int basic = 950, allowance = 95, total = 1045;

        cout << setw(10) << "Basic:" << setw(5) << basic << endl
             << setw(10) << "Allowance:" << setw(5) << allowance << endl
             << setw(10) << "Total:" << setw(5) << total << endl;

//manipulators : fixed, setprecision
        float num = 23.456;
        cout <<"default setprecision of 4: " << setprecision(4) << num << endl; // 23.46 (rounding off)
        //cout <<"setprecision of 4 with fixed: " << fixed << setprecision(4) << num << endl; // 23.4560

//         Key Points:
// Default behavior of setprecision: Controls the total significant digits.
 
// Behavior with fixed: Controls the digits after the decimal point.

// Use setprecision alone for significant digits.
// Combine fixed with setprecision to set a specific number of decimal place

        cout << setprecision(3) << float(25); //25.0

    return 0;
}