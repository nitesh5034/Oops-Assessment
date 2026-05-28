#include <iostream>
using namespace std;

// Method 1: Using pass-by-reference (simpler)
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function (pass-by-reference):" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

// Method 2: Using pointers (explicit)
void swapByPointer(int *a, int *b) {
    int temp = *a;      // Dereference pointer to get value
    *a = *b;            // Assign value at b to a
    *b = temp;          // Assign temp to b
    cout << "Inside function (using pointers):" << endl;
    cout << "*a = " << *a << ", *b = " << *b << endl;
}

// Method 3: Without auxiliary variable using XOR
void swapByXOR(int *a, int *b) {
    *a = *a ^ *b;       // XOR operation
    *b = *a ^ *b;
    *a = *a ^ *b;
    cout << "Inside function (using XOR - no temp variable):" << endl;
    cout << "*a = " << *a << ", *b = " << *b << endl;
}

// Method 4: Using arithmetic operations (addition/subtraction)
void swapByArithmetic(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Inside function (using arithmetic):" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

int main() {
    int num1, num2;
    
    cout << "=== NUMBER SWAP PROGRAM ===" << endl;
    cout << "\nDemonstrating different swap methods:" << endl;
    cout << "====================================\n" << endl;
    
    // Method 1: Using pass-by-reference
    cout << "--- Method 1: Pass-by-Reference ---" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    swapByReference(num1, num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Method 2: Using pointers
    cout << "\n--- Method 2: Using Pointers ---" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    swapByPointer(&num1, &num2);    // Pass address of variables
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Method 3: Using XOR (advanced - no extra variable needed)
    cout << "\n--- Method 3: XOR Method (No Temp Variable) ---" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    swapByXOR(&num1, &num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Method 4: Using arithmetic operations
    cout << "\n--- Method 4: Arithmetic Method (Addition/Subtraction) ---" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    swapByArithmetic(num1, num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Explanation
    cout << "\n=== WHY PASS-BY-REFERENCE/POINTERS IS NECESSARY ===" << endl;
    cout << "Without pass-by-reference (WRONG):" << endl;
    cout << "void swap(int a, int b) {  // Pass-by-value" << endl;
    cout << "    int temp = a;" << endl;
    cout << "    a = b;" << endl;
    cout << "    b = temp;" << endl;
    cout << "}" << endl;
    cout << "❌ Only swaps local copies, not original variables!" << endl;
    
    cout << "\nWith pass-by-reference (CORRECT):" << endl;
    cout << "void swap(int &a, int &b) {  // Pass-by-reference" << endl;
    cout << "    int temp = a;" << endl;
    cout << "    a = b;" << endl;
    cout << "    b = temp;" << endl;
    cout << "}" << endl;
    cout << "✓ Changes affect original variables!" << endl;
    
    cout << "\nWith pointers (ALSO CORRECT):" << endl;
    cout << "void swap(int *a, int *b) {  // Using pointers" << endl;
    cout << "    int temp = *a;" << endl;
    cout << "    *a = *b;" << endl;
    cout << "    *b = temp;" << endl;
    cout << "}" << endl;
    cout << "✓ Uses explicit pointer dereferencing!" << endl;
    
    return 0;
}

/*
OUTPUT EXAMPLE:
================
=== NUMBER SWAP PROGRAM ===

Demonstrating different swap methods:
====================================

--- Method 1: Pass-by-Reference ---
Enter first number: 5
Enter second number: 10
Before swap: num1 = 5, num2 = 10
Inside function (pass-by-reference):
a = 10, b = 5
After swap: num1 = 10, num2 = 5

--- Method 2: Using Pointers ---
Enter first number: 15
Enter second number: 25
Before swap: num1 = 15, num2 = 25
Inside function (using pointers):
*a = 25, *b = 15
After swap: num1 = 25, num2 = 15

--- Method 3: XOR Method (No Temp Variable) ---
Enter first number: 100
Enter second number: 200
Before swap: num1 = 100, num2 = 200
Inside function (using XOR - no temp variable):
*a = 200, *b = 100
After swap: num1 = 200, num2 = 100

--- Method 4: Arithmetic Method (Addition/Subtraction) ---
Enter first number: 7
Enter second number: 3
Before swap: num1 = 7, num2 = 3
Inside function (using arithmetic):
a = 3, b = 7
After swap: num1 = 3, num2 = 7
*/
