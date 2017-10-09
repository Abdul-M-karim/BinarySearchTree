#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

struct bst_node {
    int data;
    bst_node* left;
    bst_node* right;
};

class BST {
private:
    bst_node* head;

public:
    BST() {
        head= NULL;
    }

    void insert(int value) {
        if (head == NULL) {
            head = new bst_node;
            head->data = value;
            head->left = NULL;
            head->right = NULL;
        } else {
            bst_node* new_node = new bst_node;
            new_node->data = value;
            new_node->left = NULL;
            new_node->right = NULL;

            bst_node* temp = head;
            while (temp != NULL) {
                if (value < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = new_node;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else if (value > temp->data) {
                    if (temp->right == NULL) {
                        temp->right  = new_node;
                        break;
                    } else {
                        temp = temp->right;
                    }
                } else {
                    break;
                }
            }
        }
    }

    bool find(int value) {
        return find_helper(head, value);
    }

    static bool find_helper(bst_node* root, int value) {
        if (root == NULL) {
            return false;
        } else if (root->data == value) {
            return true;
        } else {
            if (root->data > value) {
                return find_helper(root->left, value);
            } else {
                return find_helper(root->right, value);
            }
        }
    }

    void print_inorder() {
        print_inorder_helper(head);
        cout << '\n';
    }

    static void print_inorder_helper(bst_node* root) {
        if (root != NULL) {
            print_inorder_helper(root->left);
            cout << root->data << " ";
            print_inorder_helper(root->right);
        }
    }

    void print_level_order() {
        queue<bst_node*> q = queue<bst_node*>();
        bst_node* temp = head;
        q.push(temp);

        while(!q.empty()) {
            bst_node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL) {
                q.push(current->left);
            }
            
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};



int main() {
    BST root = BST();

    root.insert(5);
    root.insert(7);
    root.insert(13);
    root.insert(17);
    root.insert(15);
    root.insert(11);
    root.insert(1);
    root.insert(29);
    root.insert(21);
    root.insert(22);

    // cout << root.find(42) << endl;
    // cout << root.find(69) << endl;
    // cout << root.find(-1) << endl;
    // cout << root.find(1001) << endl;

    root.print_level_order();


    return 0;
}