#include <iostream>
#include <cstring>
using namespace std;

struct node { 
    char label[60]; 
    int chcount; 
    node *child[50]; 
} *root; 

class general { 
public: 
    void insert(); 
    void display(); 
    general() { 
        root = NULL; 
    } 
}; 

void general::insert() { 
    root = new node(); 
    cout << "Enter the name of the book:" << endl; 
    cin.ignore(); 
    cin.getline(root->label, 60); 
    cout << "Enter the total number of chapters in the book:" << endl; 
    cin >> root->chcount; 

    for (int i = 0; i < root->chcount; i++) { 
        root->child[i] = new node(); 
        cout << "Enter the name of the chapter:" << endl; 
        cin.ignore(); 
        cin.getline(root->child[i]->label, 60); 
        cout << "Enter the number of sections:" << endl; 
        cin >> root->child[i]->chcount; 

        for (int j = 0; j < root->child[i]->chcount; j++) { 
            root->child[i]->child[j] = new node(); 
            cout << "Enter the name of the section:" << endl; 
            cin.ignore(); 
            cin.getline(root->child[i]->child[j]->label, 60); 
            cout << "Enter the number of sub-sections:" << endl; 
            cin >> root->child[i]->child[j]->chcount; 

            for (int k = 0; k < root->child[i]->child[j]->chcount; k++) { 
                root->child[i]->child[j]->child[k] = new node(); 
                cout << "Enter the name of the sub-section:" << endl; 
                cin.ignore(); 
                cin.getline(root->child[i]->child[j]->child[k]->label, 60); 
            } 
        } 
    } 
} 

void general::display() { 
    if (root != NULL) { 
        cout << "********** Hierarchy of Book **********" << endl; 
        cout << "Book Name: " << root->label << endl; 

        for (int i = 0; i < root->chcount; i++) { 
            cout << "-- " << root->child[i]->label << endl; 

            for (int j = 0; j < root->child[i]->chcount; j++) { 
                cout << "---- " << root->child[i]->child[j]->label << endl; 

                for (int k = 0; k < root->child[i]->child[j]->chcount; k++) { 
                    cout << "------ " << root->child[i]->child[j]->child[k]->label << endl; 
                } 
            } 
        } 
    } 
} 

int main() { 
    general g; 
    int ch; 
    do { 
        cout << "~~~~~ MENU ~~~~~" << endl; 
        cout << "1. Insert." << endl; 
        cout << "2. Display." << endl; 
        cout << "3. Exit." << endl; 
        cout << "Enter your choice:" << endl; 
        cin >> ch; 

        switch (ch) { 
            case 1: 
                g.insert(); 
                break; 
            case 2: 
                g.display(); 
                break; 
            case 3: 
                cout << "Exiting..." << endl; 
                break; 
            default: 
                cout << "Invalid choice, please try again." << endl; 
                break; 
        } 
    } while (ch != 3); 

    return 0; 
}

