#include <iostream>
#include "EducationSystem.h"

using namespace std;

void showHeader() {
    cout << "\n============================================================\n";
    cout << "           INDUS UNIVERSITY COURSE REGISTRATION SYSTEM       \n";
    cout << "           Student Project | Enrollment: IU2541230014       \n";
    cout << "============================================================\n";
}

void showMenu() {
    cout << "\n======================== MAIN MENU ========================\n";
    cout << "  1. Add Record\n";
    cout << "  2. Display Records\n";
    cout << "  3. Search Record\n";
    cout << "  4. Update Record\n";
    cout << "  5. Delete Record\n";
    cout << "  6. Main Transaction / Process (Course Enrollment)\n";
    cout << "  7. Report (Occupancy & Credit Load)\n";
    cout << "  8. Save / Load Data\n";
    cout << "  9. Exit\n";
    cout << "============================================================\n";
    cout << "Enter your choice (1-9): ";
}

int main() {
    EducationSystem sys("Data/");

    showHeader();
    cout << "Initializing system and loading saved records...\n";
    sys.initialize();

    int choice = 0;
    bool running = true;

    while (running) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid choice! Please enter a number between 1 and 9.\n";
            continue;
        }
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1:
                sys.addRecordMenu();
                break;
            case 2:
                sys.displayRecordsMenu();
                break;
            case 3:
                sys.searchRecordMenu();
                break;
            case 4:
                sys.updateRecordMenu();
                break;
            case 5:
                sys.deleteRecordMenu();
                break;
            case 6:
                sys.mainTransaction();
                break;
            case 7:
                sys.generateReports();
                break;
            case 8:
                sys.saveLoadMenu();
                break;
            case 9:
                cout << "\nSaving all records to disk before exiting...\n";
                sys.saveAllData();
                cout << "Thank you for using the Course Registration System!\n";
                cout << "Goodbye.\n\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice! Please select between 1 and 9.\n";
                break;
        }
    }

    return 0;
}
