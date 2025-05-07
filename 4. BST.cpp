#include <iostream>
using namespace std;

class node {
public:
    node* left;
    node* right;
    int data;
};

class linked {
public:
    node* root = NULL;

    node* create(int val) {
        node* t = new node;
        t->data = val;
        t->left = t->right = NULL;
        return t;
    }

    node* insert(node* root, int val) {
        if (root == NULL) {
            root = create(val);
        } else if (val <= root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void inorder(node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    bool search(node* root, int val) {
        if (root == NULL) return false;
        else if (root->data == val) return true;
        else if (val < root->data) return search(root->left, val);
        else return search(root->right, val);
    }

    void swap(node* ptr) {
        if (ptr == NULL) return;
        swap(ptr->left);
        swap(ptr->right);
        node* t = ptr->left;
        ptr->left = ptr->right;
        ptr->right = t;
    }

    node* invert(node* root) {
        swap(root);
        return root;
    }

    int height(node* root) {
        if (root == NULL) {
            return -1;
        }
        int lefth = height(root->left);
        int righth = height(root->right);
        return max(lefth, righth) + 1;
    }

    int mini(node* root) {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        node* t = root;
        while (t->left != NULL) {
            t = t->left;
        }
        return t->data;
    }
};

int main() {
    linked l;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "1. Insert new node" << endl;
    cout << "2. Display BST" << endl;
    cout << "3. Minimum element" << endl;
    cout << "4. Height of the BST" << endl;
    cout << "5. Search element" << endl;
    cout << "6. Swap left and right nodes" << endl;
    cout << "0. Exit" << endl;

    int choice;
    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 0)
            break;

        switch (choice) {
        case 1:
            for (int i = 0; i < n; i++) {
                l.root = l.insert(l.root, arr[i]);
            }
            cout << "Do you want to enter another number? (y/n): ";
            char c;
            cin >> c;
            if (c == 'y') {
                int num;
                cout << "Enter number: ";
                cin >> num;
                l.root = l.insert(l.root, num);
            }
            break;
        case 2:
            cout << "Inorder traversal: ";
            l.inorder(l.root);
            cout << endl;
            break;
        case 3:
            cout << "Minimum element is: " << l.mini(l.root) << endl;
            break;
        case 4:
            cout << "Height = " << l.height(l.root) << endl;
            break;
        case 5:
            cout << "Enter the element to search: ";
            int s;
            cin >> s;
            if (l.search(l.root, s))
                cout << "Element is present" << endl;
            else
                cout << "Element is not present" << endl;
            break;
        case 6:
            l.root = l.invert(l.root);
            cout << "Tree inverted successfully!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    delete[] arr;
    return 0;
}

