#include <iostream>
#include <string>
#define max 20

using namespace std;

struct employee {
    string name;
    long int code;
    string designation;
    int exp;
    int age;
};

int num = 0;
employee emp[max];

void build() {
    cout << "\nBuild The Table\n";
    cout << "Maximum Entries can be " << max << "\n";
    cout << "Enter the number of entries required: ";
    cin >> num;

    if (num > max) {
        cout << "Maximum number of entries is 20\n";
        num = max;
    }

    cin.ignore(); // clear newline character

    for (int i = 0; i < num; i++) {
        cout << "\nEntry " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, emp[i].name);
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cin.ignore(); // clear buffer
        cout << "Designation: ";
        getline(cin, emp[i].designation);
        cout << "Experience (years): ";
        cin >> emp[i].exp;
        cout << "Age: ";
        cin >> emp[i].age;
        cin.ignore();
    }
}

void insert() {
    if (num < max) {
        int i = num++;
        cout << "\nEnter the information of the new Employee:\n";
        cin.ignore(); // clear buffer
        cout << "Name: ";
        getline(cin, emp[i].name);
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cin.ignore();
        cout << "Designation: ";
        getline(cin, emp[i].designation);
        cout << "Experience (years): ";
        cin >> emp[i].exp;
        cout << "Age: ";
        cin >> emp[i].age;
    } else {
        cout << "\nEmployee Table Full\n";
    }
}

void deleteIndex(int i) {
    for (int j = i; j < num - 1; j++) {
        emp[j] = emp[j + 1];
    }
}

void deleteRecord() {
    cout << "\nEnter the Employee ID to delete record: ";
    int code;
    cin >> code;

    bool found = false;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            deleteIndex(i);
            num--;
            found = true;
            cout << "Record deleted successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Employee ID not found.\n";
    }
}

void searchRecord() {
    cout << "\nEnter the Employee ID to search: ";
    int code;
    cin >> code;

    bool found = false;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "\nRecord Found:\n";
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Designation: " << emp[i].designation << "\n";
            cout << "Experience: " << emp[i].exp << " years\n";
            cout << "Age: " << emp[i].age << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee ID not found.\n";
    }
}

void showMenu() {
    int option;
    do {
        cout << "\n-------------------------\n";
        cout << "Employee Management System\n";
        cout << "-------------------------\n";
        cout << "1. Build Table\n";
        cout << "2. Insert New Entry\n";
        cout << "3. Delete Entry\n";
        cout << "4. Search a Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: build(); break;
            case 2: insert(); break;
            case 3: deleteRecord(); break;
            case 4: searchRecord(); break;
            case 5: cout << "Exiting Program.\n"; break;
            default: cout << "Invalid option. Please select between 1-5.\n";
        }
    } while (option != 5);
}

int main() {
    showMenu();
    return 0;
}

