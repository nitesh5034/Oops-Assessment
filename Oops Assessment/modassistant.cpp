#include <iostream>
using namespace std;

int main() {
    int hoursStudied;
    
    cout << "=== Study Mood Assistant ===" << endl;
    cout << "Enter hours studied today: ";
    cin >> hoursStudied;
    
    // Using if-else ladder
    if(hoursStudied >= 8) {
        cout << "\n🎉 EXCELLENT! You're a study superstar!" << endl;
        cout << "Your dedication is inspiring! Keep it up!" << endl;
    }
    else if(hoursStudied >= 5) {
        cout << "\n✨ GREAT JOB! You're on the right track!" << endl;
        cout << "Your consistency will lead to success!" << endl;
    }
    else if(hoursStudied >= 3) {
        cout << "\n👍 GOOD EFFORT! You're making progress!" << endl;
        cout << "Try to push a bit more tomorrow!" << endl;
    }
    else if(hoursStudied >= 1) {
        cout << "\n📚 OKAY START! Every bit helps!" << endl;
        cout << "Remember: Consistency beats intensity!" << endl;
    }
    else if(hoursStudied == 0) {
        cout << "\n⚠️ OH NO! You didn't study today!" << endl;
        cout << "Start small tomorrow - even 30 minutes counts!" << endl;
        cout << "Your future self will thank you!" << endl;
    }
    else {
        cout << "\n❌ ERROR: Invalid input!" << endl;
    }
    
    return 0;
}

/* 
OUTPUT EXAMPLES:
================
Test 1:
Enter hours studied today: 7
✨ GREAT JOB! You're on the right track!
Your consistency will lead to success!

Test 2:
Enter hours studied today: 2
📚 OKAY START! Every bit helps!
Remember: Consistency beats intensity!

Test 3:
Enter hours studied today: 0
⚠️ OH NO! You didn't study today!
Start small tomorrow - even 30 minutes counts!
Your future self will thank you!
*/
