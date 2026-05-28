#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string DATA_FILE = "productivity_tracker.txt";

struct WeeklyData {
    float hours[7];
    string days[7];
};

void initializeWeek(WeeklyData &week) {
    week.days[0] = "Monday";
    week.days[1] = "Tuesday";
    week.days[2] = "Wednesday";
    week.days[3] = "Thursday";
    week.days[4] = "Friday";
    week.days[5] = "Saturday";
    week.days[6] = "Sunday";
    for(int i = 0; i < 7; i++) {
        week.hours[i] = 0;
    }
}

void saveToFile(const WeeklyData &week) {
    ofstream outFile(DATA_FILE);
    if(!outFile) {
        cout << "Error saving file." << endl;
        return;
    }
    for(int i = 0; i < 7; i++) {
        outFile << week.days[i] << " " << week.hours[i] << endl;
    }
}

void loadFromFile(WeeklyData &week) {
    ifstream inFile(DATA_FILE);
    if(!inFile) {
        return;
    }

    string day;
    float hours;
    int index = 0;
    while(inFile >> day >> hours && index < 7) {
        week.hours[index] = hours;
        index++;
    }
}

void displayMainMenu() {
    cout << "\nStudent Productivity Tracker" << endl;
    cout << "1. Log daily study hours" << endl;
    cout << "2. View weekly report" << endl;
    cout << "3. View daily progress" << endl;
    cout << "4. View statistics" << endl;
    cout << "5. Reset weekly data" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
}

void logDailyHours(WeeklyData &week) {
    cout << "\nLog Daily Study Hours" << endl;
    cout << "Select day to log:" << endl;
    for(int i = 0; i < 7; i++) {
        cout << (i + 1) << ". " << week.days[i] << endl;
    }

    int dayChoice;
    cin >> dayChoice;
    if(dayChoice < 1 || dayChoice > 7) {
        cout << "Invalid choice." << endl;
        return;
    }

    int index = dayChoice - 1;
    cout << "Enter study hours for " << week.days[index] << ": ";
    float hours;
    cin >> hours;
    if(hours < 0) {
        cout << "Hours cannot be negative." << endl;
        return;
    }

    week.hours[index] = hours;
    saveToFile(week);
    cout << "Hours saved." << endl;
}

void viewWeeklyReport(const WeeklyData &week) {
    cout << "\nWeekly Report" << endl;
    float totalHours = 0;
    for(int i = 0; i < 7; i++) {
        cout << week.days[i] << ": " << week.hours[i] << " hours" << endl;
        totalHours += week.hours[i];
    }
    cout << "Total hours: " << totalHours << endl;
    cout << "Average hours: " << (totalHours / 7) << endl;
}

void viewDailyProgress(const WeeklyData &week) {
    cout << "\nDaily Progress" << endl;
    for(int i = 0; i < 7; i++) {
        cout << week.days[i] << ": ";
        int bars = static_cast<int>(week.hours[i]);
        for(int j = 0; j < bars; j++) {
            cout << "#";
        }
        cout << " " << week.hours[i] << endl;
    }
}

void viewStatistics(const WeeklyData &week) {
    cout << "\nStatistics" << endl;
    float totalHours = 0;
    float maxHours = week.hours[0];
    float minHours = week.hours[0];
    int maxDay = 0;
    int minDay = 0;

    for(int i = 0; i < 7; i++) {
        totalHours += week.hours[i];
        if(week.hours[i] > maxHours) {
            maxHours = week.hours[i];
            maxDay = i;
        }
        if(week.hours[i] < minHours) {
            minHours = week.hours[i];
            minDay = i;
        }
    }

    cout << "Total hours: " << totalHours << endl;
    cout << "Average hours: " << (totalHours / 7) << endl;
    cout << "Best day: " << week.days[maxDay] << " (" << maxHours << " hours)" << endl;
    cout << "Lowest day: " << week.days[minDay] << " (" << minHours << " hours)" << endl;
}

void resetWeeklyData(WeeklyData &week) {
    cout << "\nReset all data? (y/n): ";
    char confirm;
    cin >> confirm;
    if(confirm == 'y' || confirm == 'Y') {
        initializeWeek(week);
        saveToFile(week);
        cout << "Data reset." << endl;
    } else {
        cout << "Reset cancelled." << endl;
    }
}

int main() {
    WeeklyData week;
    initializeWeek(week);
    loadFromFile(week);

    bool running = true;
    while(running) {
        displayMainMenu();
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                logDailyHours(week);
                break;
            case 2:
                viewWeeklyReport(week);
                break;
            case 3:
                viewDailyProgress(week);
                break;
            case 4:
                viewStatistics(week);
                break;
            case 5:
                resetWeeklyData(week);
                break;
            case 6:
                running = false;
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}

