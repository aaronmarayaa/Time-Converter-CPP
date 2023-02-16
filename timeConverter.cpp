#include <iostream>
#include <conio.h>
using namespace std;

void clear_screen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear the screen
}

int main() {
    int num_options = 2;
    string options[num_options] = {"Seconds to Hour Minutes and Seconds", "Hour Minutes and Seconds to Seconds"};

    int selected = 0;

    while (true) {
        clear_screen();
        for (int i = 0; i < num_options; i++) {
            if (i == selected) {
                cout << "> ";
                
            }
            cout << options[i] << endl;
        }

        int key = _getch(); 
        switch (key) {
            case 72: // up arrow
                selected = (selected - 1 + num_options) % num_options;
                break;
            case 80: // down arrow
                selected = (selected + 1) % num_options;
                break;
            case 13: // enter key
                clear_screen();

                if(selected == 0){
                    int numberOfSeconds = 0;
                    cout << "\nNumber of seconds: ";
                    cin >> numberOfSeconds;
                    
                    int hours = numberOfSeconds / 3600;
                    int minutes = (numberOfSeconds % 3600) / 60;
                    int seconds = numberOfSeconds - ((hours * 3600) + (minutes * 60));
                    cout << endl << hours << "-hours " << minutes << "-minutes and " << seconds << "-seconds";
                }
                else if(selected == 1){
                    int numberOfHours = 0;
                    int numberOfMinutes = 0;
                    int numberOfSeconds = 0;
                    cout << "Hours: ";
                    cin >> numberOfHours;
                    cout << "Minutes: ";
                    cin >> numberOfMinutes;
                    cout << "Seconds: ";
                    cin >> numberOfSeconds;

                    int totalSeconds = (numberOfHours * 3600) + (numberOfMinutes * 60) + numberOfSeconds;
                    cout << totalSeconds << " seconds";
                }
                return 0;
            default:
                break;
        }
    }

    return 0;
}
