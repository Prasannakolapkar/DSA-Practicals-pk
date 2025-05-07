#include <iostream>
using namespace std;

class Heap {
    int n;
    int *minheap, *maxheap;

public:
    void get();
    void displayMin();
    void displayMax();
    void upAdjust(bool isMaxHeap, int index);
};

void Heap::get() {
    cout << "Enter number of students: ";
    cin >> n;

    minheap = new int[n];
    maxheap = new int[n];

    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        int mark;
        cin >> mark;

        minheap[i] = mark;
        upAdjust(false, i);

        maxheap[i] = mark;
        upAdjust(true, i);
    }
}

void Heap::upAdjust(bool isMaxHeap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (isMaxHeap) {
            if (maxheap[parent] < maxheap[index]) {
                swap(maxheap[parent], maxheap[index]);
                index = parent;
            } else {
                break;
            }
        } else {
            if (minheap[parent] > minheap[index]) {
                swap(minheap[parent], minheap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
}

void Heap::displayMin() {
    cout << "\nMinimum mark is: " << minheap[0] << endl;
    cout << "Min-Heap array:\n";
    for (int i = 0; i < n; i++) {
        cout << minheap[i] << " ";
    }
    cout << endl;
}

void Heap::displayMax() {
    cout << "\nMaximum mark is: " << maxheap[0] << endl;
    cout << "Max-Heap array:\n";
    for (int i = 0; i < n; i++) {
        cout << maxheap[i] << " ";
    }
    cout << endl;
}

int main() {
    Heap H;
    H.get();
    H.displayMin();
    H.displayMax();
    return 0;
}

