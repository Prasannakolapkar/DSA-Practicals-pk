#include <iostream>
#include <cstring>
using namespace std;

class flight {
public:
    int am[10][10];            // adjacency matrix
    char city_index[10][10];   // city names
    flight();                  // constructor
    int create();              // method to create flight paths
    void display(int city_count); // method to display adjacency matrix
};

flight::flight() {
    for (int i = 0; i < 10; i++) {
        strcpy(city_index[i], "xx");
        for (int j = 0; j < 10; j++) {
            am[i][j] = 0;
        }
    }
}

int flight::create() {
    int city_count = 0;
    char s[10], d[10], c;
    int si, di, wt;

    do {
        cout << "\n\tEnter Source City : ";
        cin >> s;

        cout << "\n\tEnter Destination City : ";
        cin >> d;

        // Check or add source city
        int j;
        for (j = 0; j < city_count; j++) {
            if (strcmp(city_index[j], s) == 0) break;
        }
        if (j == city_count) {
            strcpy(city_index[city_count], s);
            city_count++;
        }

        // Check or add destination city
        for (j = 0; j < city_count; j++) {
            if (strcmp(city_index[j], d) == 0) break;
        }
        if (j == city_count) {
            strcpy(city_index[city_count], d);
            city_count++;
        }

        cout << "\n\tEnter Distance From " << s << " To " << d << ": ";
        cin >> wt;

        // Find indices again to fill matrix
        for (j = 0; j < city_count; j++) {
            if (strcmp(city_index[j], s) == 0) si = j;
            if (strcmp(city_index[j], d) == 0) di = j;
        }

        am[si][di] = wt;

        cout << "\n\tDo you want to add more cities.....(y/n) : ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return city_count;
}

void flight::display(int city_count) {
    cout << "\n\tDisplaying Adjacency Matrix :\n\t";
    for (int i = 0; i < city_count; i++) {
        cout << "\t" << city_index[i];
    }
    cout << "\n";

    for (int i = 0; i < city_count; i++) {
        cout << "\t" << city_index[i];
        for (int j = 0; j < city_count; j++) {
            cout << "\t" << am[i][j];
        }
        cout << "\n";
    }
}

int main() {
    flight f;
    int n, city_count = 0;
    char c;

    do {
        cout << "\n\t***** Flight Main Menu *****";
        cout << "\n\t1. Create \n\t2. Adjacency Matrix\n\t3. Exit";
        cout << "\n\t.....Enter your choice : ";
        cin >> n;

        switch (n) {
            case 1:
                city_count = f.create();
                break;
            case 2:
                f.display(city_count);
                break;
            case 3:
                return 0;
            default:
                cout << "\n\tInvalid choice!";
        }

        cout << "\n\tDo you want to continue in Main Menu....(y/n) : ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}

