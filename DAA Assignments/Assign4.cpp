#include <bits/stdc++.h>
using namespace std;

class avlnode {
public:
    string word;
    string meaning;
    avlnode* l;
    avlnode* r;

    avlnode(string w, string m) : word(w), meaning(m), l(NULL), r(NULL) {}
};

class avlTree {
private:
    avlnode* root;

public:
    avlTree() : root(NULL) {}

    int height(avlnode* node);
    int diff(avlnode* node);

    avlnode* rr(avlnode* parent);
    avlnode* ll(avlnode* parent);
    avlnode* lr(avlnode* parent);
    avlnode* rl(avlnode* parent);

    avlnode* balance(avlnode* node);
    avlnode* insert(avlnode* root, string word, string meaning);

    void inorder(avlnode* node);
    void preorder(avlnode* node);
    void postorder(avlnode* node);

    void insertWord(string word, string meaning) {
        root = insert(root, word, meaning);
    }

    void displayInorder() { inorder(root); }
    void displayPreorder() { preorder(root); }
    void displayPostorder() { postorder(root); }
};

int avlTree::height(avlnode* node) {
    if (node == NULL) return 0;
    return max(height(node->l), height(node->r)) + 1;
}

int avlTree::diff(avlnode* node) {
    if (node == NULL) return 0;
    return height(node->l) - height(node->r);
}

avlnode* avlTree::rr(avlnode* parent) {
    avlnode* temp = parent->r;
    parent->r = temp->l;
    temp->l = parent;
    return temp;
}

avlnode* avlTree::ll(avlnode* parent) {
    avlnode* temp = parent->l;
    parent->l = temp->r;
    temp->r = parent;
    return temp;
}

avlnode* avlTree::lr(avlnode* parent) {
    parent->l = rr(parent->l);
    return ll(parent);
}

avlnode* avlTree::rl(avlnode* parent) {
    parent->r = ll(parent->r);
    return rr(parent);
}

avlnode* avlTree::balance(avlnode* node) {
    int balance_factor = diff(node);

    if (balance_factor > 1 && diff(node->l) >= 0) {
        return ll(node);
    }

    if (balance_factor < -1 && diff(node->r) <= 0) {
        return rr(node);
    }

    if (balance_factor > 1 && diff(node->l) < 0) {
        return lr(node);
    }

    if (balance_factor < -1 && diff(node->r) > 0) {
        return rl(node);
    }

    return node;
}

avlnode* avlTree::insert(avlnode* root, string word, string meaning) {
    if (root == NULL) {
        return new avlnode(word, meaning);
    }

    if (word < root->word) {
        root->l = insert(root->l, word, meaning);
    } else if (word > root->word) {
        root->r = insert(root->r, word, meaning);
    } else {
        cout << "Word already exists!" << endl;
        return root;
    }

    return balance(root);
}

void avlTree::inorder(avlnode* node) {
    if (node != NULL) {
        inorder(node->l);
        cout << node->word << " : " << node->meaning << endl;
        inorder(node->r);
    }
}

void avlTree::preorder(avlnode* node) {
    if (node != NULL) {
        cout << node->word << " : " << node->meaning << endl;
        preorder(node->l);
        preorder(node->r);
    }
}

void avlTree::postorder(avlnode* node) {
    if (node != NULL) {
        postorder(node->l);
        postorder(node->r);
        cout << node->word << " : " << node->meaning << endl;
    }
}

int main() {
    avlTree dictionary;
    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary Menu:";
        cout << "\n1. Insert a word";
        cout << "\n2. Display Inorder (Alphabetical)";
        cout << "\n3. Display Preorder";
        cout << "\n4. Display Postorder";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.insertWord(word, meaning);
                cout << "Word inserted successfully!\n";
                break;

            case 2:
                cout << "\nDictionary (Alphabetical Order):\n";
                dictionary.displayInorder();
                break;

            case 3:
                cout << "\nPreorder Traversal:\n";
                dictionary.displayPreorder();
                break;

            case 4:
                cout << "\nPostorder Traversal:\n";
                dictionary.displayPostorder();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
