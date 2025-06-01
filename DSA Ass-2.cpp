#include <iostream>
#include <cstdlib>
using namespace std;

// Definition of the node structure
struct node
{
    struct node *left, *right;
    int data;
};

// Function to insert a node into the BST
struct node* insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *newn = new node;
        newn->data = data;
        newn->left = newn->right = NULL;
        return newn;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to create a BST
struct node* createBST(struct node* root)
{
    int data;
    cout << "\nEnter root node value: ";
    cin >> data;
    root = insertNode(root, data);

    while (1)
    {
        cout << "Enter next node value (0 to stop): ";
        cin >> data;

        if (data == 0)
            break;
        root = insertNode(root, data);
    }
    return root;
}

// Function to perform in-order traversal
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to calculate the height of the tree
int height(struct node *root)
{
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Function to delete a node from the BST
struct node* FindMin(struct node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* Delete(struct node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        } else if (root->left == NULL)
        {
            struct node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL)
        {
            struct node* temp = root;
            root = root->left;
            delete temp;
        } else
        {
            struct node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

// Function to search for a node in the BST
struct node* searchBT(struct node* root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return searchBT(root->right, data);
    else
        return searchBT(root->left, data);
}

// Queue functions for level-wise traversal
#define MAX 20
struct node* q[MAX];
int f = -1, r = -1;

void enq(struct node* temp)
{
    if (r == MAX - 1)
    {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (f == -1) f = 0;
    q[++r] = temp;
}

struct node* deq()
{
    if (f == -1)
    {
        cout << "Queue Underflow!" << endl;
        return NULL;
    }
    struct node* temp = q[f];
    if (f == r) f = r = -1; // Reset queue if last element dequeued
    else f++;
    return temp;
}

int isempty()
{
    return f == -1;
}

// Function to print level-wise traversal of the tree
void levelwise(struct node* root)
{
    if (root == NULL)
    {
        cout << "\nEmpty Tree!" << endl;
        return;
    }

    enq(root);
    enq(NULL); // Marker for new level

    while (!isempty())
    {
        struct node* temp = deq();

        if (temp == NULL)
        {
            cout << endl;
            if (!isempty())
                enq(NULL); // Add marker for the next level
        } else
        {
            cout << temp->data << " ";
            if (temp->left)
                enq(temp->left);

            if (temp->right)
                enq(temp->right);
        }
    }
}

// Function to create the mirror image of the tree
struct node* mirror(struct node* root)
{
    if (root == NULL)
        return NULL;
    struct node* left = mirror(root->left);
    struct node* right = mirror(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// Main function
int main()
{
    struct node *root = NULL;
    int newData, del, ch;

    while (1)
    {
        cout << "\n\nMenu:\n";
        cout << "1. Create BST\n";
        cout << "2. Insert Node\n";
        cout << "3. In-order Traversal\n";
        cout << "4. Height of Tree\n";
        cout << "5. Delete Node\n";
        cout << "6. Search Node\n";
        cout << "7. Level-wise Printing\n";
        cout << "8. Mirror Image\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                root = createBST(root);
                break;

            case 2:
                cout << "Enter new value to insert into BST: ";
                cin >> newData;
                root = insertNode(root, newData);
                break;

            case 3:
                cout << "In-order traversal of the BST:\n";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "The height of the tree is: " << height(root) << endl;
                break;

            case 5:

                cout << "Enter the data to delete: ";
                cin >> del;
                root = Delete(root, del);
                break;

            case 6:
                cout << "Enter the data to search: ";
                cin >> del;
                {
                    struct node* found = searchBT(root, del);
                    if (found)
                        cout << "Node with value " << del << " found in the BST." << endl;
                    else
                        cout << "Node with value " << del << " not found in the BST." << endl;
                }
                break;

            case 7:
                cout << "Level-wise printing of the tree: \n";
                levelwise(root);
                break;

            case 8:
                root = mirror(root);
                cout << "The mirror image of the tree (in-order traversal): \n";
                inorder(root);
                cout << endl;
                break;

            case 9:
                cout << "Exiting..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
