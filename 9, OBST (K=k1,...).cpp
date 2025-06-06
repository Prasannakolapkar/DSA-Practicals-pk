#include <iostream>
using namespace std;

void con_obst(void);
void print(int, int);

float a[20], b[20], wt[20][20], c[20][20];
int r[20][20], n;

int main() {
    int i;
    cout << "\n**** PROGRAM FOR OBST ******\n";
    cout << "\nEnter the number of nodes: ";
    cin >> n;

    cout << "\nEnter the probabilities for successful search:\n";
    cout << "--------------------------------------------\n";
    for (i = 1; i <= n; i++) {
        cout << "p[" << i << "]: ";
        cin >> a[i];
    }

    cout << "\nEnter the probabilities for unsuccessful search:\n";
    cout << "--------------------------------------------\n";
    for (i = 0; i <= n; i++) {
        cout << "q[" << i << "]: ";
        cin >> b[i];
    }

    con_obst();
    print(0, n);
    cout << endl;

    return 0;
}

void con_obst(void) {
    int i, j, l;

    // Initialization for single keys
    for (i = 0; i < n; i++) {
        c[i][i] = 0.0;
        r[i][i] = 0;
        wt[i][i] = b[i];

        wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        c[i][i + 1] = wt[i][i + 1];
        r[i][i + 1] = i + 1;
    }

    // Last diagonal element
    c[n][n] = 0.0;
    r[n][n] = 0;
    wt[n][n] = b[n];

    // Building trees of length >= 2
    for (i = 2; i <= n; i++) {
        for (j = 0; j <= n - i; j++) {
            wt[j][j + i] = wt[j][j + i - 1] + a[j + i] + b[j + i];
            c[j][j + i] = 9999.0;

            for (l = j + 1; l <= j + i; l++) {
                float cost = c[j][l - 1] + c[l][j + i];
                if (cost < c[j][j + i]) {
                    c[j][j + i] = cost;
                    r[j][j + i] = l;
                }
            }

            c[j][j + i] += wt[j][j + i];
        }
    }

    cout << "\n\nOptimal BST is:\n";
    cout << "w[0][" << n << "] :: " << wt[0][n] << "\n";
    cout << "c[0][" << n << "] :: " << c[0][n] << "\n";
    cout << "r[0][" << n << "] :: " << r[0][n] << "\n";
}

void print(int l1, int r1) {
    if (l1 >= r1)
        return;

    if (r[l1][r[l1][r1] - 1] != 0)
        cout << "\nLeft child of " << r[l1][r1] << " :: " << r[l1][r[l1][r1] - 1];

    if (r[r[l1][r1]][r1] != 0)
        cout << "\nRight child of " << r[l1][r1] << " :: " << r[r[l1][r1]][r1];

    print(l1, r[l1][r1] - 1);
    print(r[l1][r1], r1);
}

