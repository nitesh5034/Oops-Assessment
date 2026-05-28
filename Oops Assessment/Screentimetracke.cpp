#include <iostream>

using namespace std;

int main() {
    float screenTime[7];
    float totalTime = 0;
    float averageTime = 0;
    float healthyLimit = 4.0;  // 4 hours per day
    
    cout << "=== Weekly Screen Time Tracker ===" << endl << endl;
    
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                     "Friday", "Saturday", "Sunday"};
    
    for(int i = 0; i < 7; i++) {
        cout << "Enter screen time for " << days[i] << " (in hours): ";
        cin >> screenTime[i];
        totalTime += screenTime[i];
    }
    
    averageTime = totalTime / 7;
    
    cout << "\n=== WEEKLY REPORT ===" << endl;
    cout << "----------------------------------------" << endl;
    
    cout << fixed << setprecision(2);
    cout << "Total Screen Time (Week): " << totalTime << " hours" << endl;
    cout << "Average Screen Time (Day): " << averageTime << " hours" << endl;
    cout << "Healthy Limit: " << healthyLimit << " hours/day" << endl;
    
    cout << "\n=== DAILY BREAKDOWN ===" << endl;
    for(int i = 0; i < 7; i++) {
        cout << days[i] << ": " << screenTime[i] << " hours";
        if(screenTime[i] > healthyLimit) {
            cout << " ⚠️ EXCEEDS LIMIT!";
        }
        cout << endl;
    }
    
    cout << "\n=== HEALTH WARNING ===" << endl;
    if(averageTime > healthyLimit) {
        cout << " WARNING: Your average screen time (" << averageTime 
             << " hours) EXCEEDS the healthy limit (" << healthyLimit << " hours)!" << endl;
        cout << "Recommendations:" << endl;
        cout << "• Reduce screen time by " << (averageTime - healthyLimit) << " hours/day" << endl;
        cout << "• Take regular breaks (20-20-20 rule)" << endl;
        cout << "• Use blue light filters" << endl;
        cout << "• Do outdoor activities" << endl;
    } else {
        cout << "✓ GOOD! Your average screen time is within healthy limits!" << endl;
    }
    
    return 0;
}
