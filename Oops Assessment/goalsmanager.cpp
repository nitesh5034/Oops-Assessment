#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string FILENAME = "daily_goals.txt";

// Function to write goals to file
void writeGoals() {
    ofstream outFile(FILENAME);  // Open file in write mode
    
    if(!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    
    cout << "\n=== Add Daily Goals ===" << endl;
    cout << "Enter your goals for today (type 'done' when finished):" << endl;
    
    string goal;
    int goalNumber = 1;
    
    cin.ignore();  // Clear input buffer
    
    while(true) {
        cout << "Goal " << goalNumber << ": ";
        getline(cin, goal);
        
        if(goal == "done" || goal == "DONE") {
            break;
        }
        
        if(!goal.empty()) {
            outFile << goalNumber << ". " << goal << endl;
            goalNumber++;
        }
    }
    
    outFile.close();  // Close file
    cout << "✓ Goals saved successfully to " << FILENAME << endl;
}

// Function to read and display goals
void readGoals() {
    ifstream inFile(FILENAME);  // Open file in read mode
    
    if(!inFile) {
        cout << "\nNo goals file found. Please add goals first!" << endl;
        return;
    }
    
    cout << "\n=== Your Daily Goals ===" << endl;
    cout << "----------------------------------------" << endl;
    
    string line;
    bool hasGoals = false;
    
    while(getline(inFile, line)) {
        if(!line.empty()) {
            cout << line << endl;
            hasGoals = true;
        }
    }
    
    if(!hasGoals) {
        cout << "No goals set yet!" << endl;
    }
    
    cout << "----------------------------------------" << endl;
    inFile.close();  // Close file
}

// Function to append goals (add more goals)
void appendGoals() {
    ifstream checkFile(FILENAME);
    int startNumber = 1;
    string line;
    
    // Count existing goals
    while(getline(checkFile, line)) {
        if(!line.empty()) startNumber++;
    }
    checkFile.close();
    
    ofstream outFile(FILENAME, ios::app);  // Open in append mode
    
    if(!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }
    
    cout << "\n=== Add More Goals ===" << endl;
    cout << "Enter additional goals (type 'done' when finished):" << endl;
    
    string goal;
    
    cin.ignore();  // Clear input buffer
    
    while(true) {
        cout << "Goal " << startNumber << ": ";
        getline(cin, goal);
        
        if(goal == "done" || goal == "DONE") {
            break;
        }
        
        if(!goal.empty()) {
            outFile << startNumber << ". " << goal << endl;
            startNumber++;
        }
    }
    
    outFile.close();
    cout << "✓ New goals added!" << endl;
}

// Function to clear all goals
void clearGoals() {
    char confirm;
    cout << "\n⚠️ Are you sure you want to delete all goals? (y/n): ";
    cin >> confirm;
    
    if(confirm == 'y' || confirm == 'Y') {
        ofstream outFile(FILENAME);  // Open in write mode (overwrites)
        
        if(outFile) {
            outFile.close();
            cout << "\n✓ All goals cleared!" << endl;
        }
    } else {
        cout << "❌ Clear operation cancelled." << endl;
    }
}

// Menu function
void displayMenu() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║      DAILY GOALS MANAGER v1.0        ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\n1. Add New Goals (overwrites existing)" << endl;
    cout << "2. View Today's Goals" << endl;
    cout << "3. Add More Goals (append)" << endl;
    cout << "4. Clear All Goals" << endl;
    cout << "5. Exit" << endl;
    cout << "\nEnter your choice (1-5): ";
}

int main() {
    int choice;
    
    cout << "Welcome to Daily Goals Manager!" << endl;
    cout << "This program helps you track and manage your daily goals." << endl;
    cout << "Data is saved to: " << FILENAME << endl;
    
    while(true) {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                writeGoals();
                break;
            case 2:
                readGoals();
                break;
            case 3:
                appendGoals();
                break;
            case 4:
                clearGoals();
                break;
            case 5:
                cout << "\nThank you for using Daily Goals Manager! 💪" << endl;
                cout << "Keep achieving your goals! 🎯" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-5." << endl;
        }
    }
    
    return 0;
}

/*
FILE MODES EXPLAINED:
=====================

ofstream - WRITE MODE
- Creates new file or overwrites existing
- Use when starting fresh
- outFile << "content"

ifstream - READ MODE
- Opens existing file
- Fails if file doesn't exist
- getline(inFile, line)

ios::app - APPEND MODE
- Adds content to end of file
- Doesn't overwrite existing data
- outFile << "new content"

FILE STRUCTURE:
===============
daily_goals.txt format:
1. Complete C++ assignment
2. Study for exam
3. Exercise for 30 minutes

OUTPUT EXAMPLE:
================
Welcome to Daily Goals Manager!
This program helps you track and manage your daily goals.
Data is saved to: daily_goals.txt

╔════════════════════════════════════════╗
║      DAILY GOALS MANAGER v1.0        ║
╚════════════════════════════════════════╝

1. Add New Goals (overwrites existing)
2. View Today's Goals
3. Add More Goals (append)
4. Clear All Goals
5. Exit

Enter your choice (1-5): 1

=== Add Daily Goals ===
Enter your goals for today (type 'done' when finished):
Goal 1: Complete C++ assignment
Goal 2: Study for exam
Goal 3: Exercise for 30 minutes
Goal 4: done
✓ Goals saved successfully to daily_goals.txt

Enter your choice (1-5): 2

=== Your Daily Goals ===
----------------------------------------
1. Complete C++ assignment
2. Study for exam
3. Exercise for 30 minutes
----------------------------------------

Enter your choice (1-5): 3

=== Add More Goals ===
Enter additional goals (type 'done' when finished):
Goal 4: Read a chapter
Goal 5: done
✓ New goals added!

Enter your choice (1-5): 5

Thank you for using Daily Goals Manager! 💪
Keep achieving your goals! 🎯
*/
