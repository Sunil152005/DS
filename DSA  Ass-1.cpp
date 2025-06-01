//Recusive and non-recursive inorder, preorder, postorder

#include <iostream>
using namespace std;

// create struct node
struct node {
    node* left;
    node* right;
    char data;
};

// create a node newn
node* createnode(char data)
{
    node* newn = new node;
    newn=(struct node*)malloc(sizeof(struct node));
    newn->left = NULL;
    newn->right = NULL;
    newn->data = data;
    return newn;
}

// create a node btree
node* btree(node* root)
{
    int ch;
    char ans;
    cout << "\nEnter data to be entered in the tree:\n";
    ch = cin.get();
    cin.ignore();
    while (ch != '$')
    {
        node* newn = createnode(ch);
        node* temp = root;

        while (1)
        {
            cout << "Left or Right of " << temp->data << " (l/r):";
            ans = cin.get();
            cin.ignore();

            if (ans == 'l' || ans == 'L')
            {
                if (temp->left == NULL)
                {
                    temp->left = newn;
                    break;
                } else
                {
                    temp = temp->left;
                }
            } else if (ans == 'r' || ans == 'R')
            {
                if (temp->right == NULL)
                {
                    temp->right = newn;
                    break;
                } else
                {
                    temp = temp->right;
                }
            }
        }
        cout << "\nEnter the data to be inserted:\n";
        ch = cin.get();
        cin.ignore();
    }
    return root;
}

// Inorder traversal
void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

// Preorder traversal
void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

// Non-Recursive traversal using stack
node* stack[10];
int top = -1;

void push(node* nod)
{
    top++;
    stack[top] = nod;
}

node* pop()
{
    node* temp = stack[top];
    top--;
    return temp;
}

int isempty()
{
    return top == -1;
}

//Non-Recursive inorder
void ninorder(node* root)
{
    node* temp = root;
    while (temp != NULL || !isempty()) {
        if (temp != NULL)
        {
            push(temp);         // Push current node to stack
            temp = temp->left;  // Move to left child
        } else {
            temp = pop();       // Pop from stack
            cout << temp->data; // Visit node
            temp = temp->right; // Move to right child
        }
    }
}

// Non-Recursive preorder
void npreorder(node* root)
{
    node* temp = root;
    while (temp != NULL || !isempty())
    {
        if (temp != NULL)
        {
            cout << temp->data; // Visit node
            push(temp);         // Push current node to stack
            temp = temp->left;  // Move to left child
        } else {
            temp = pop();       // Pop from stack
            temp = temp->right; // Move to right child
        }
    }
}

int main()
{
    char ch;
    int choice;
    node* root;

    cout << "Enter the root node:\n";
    ch = cin.get();
    cin.ignore();

    root = createnode(ch);
    root = btree(root);

    while (1) {
        cout << "1. R Inorder\n2. R Preorder\n3. R Postorder\n4. NonR Inorder\n5. NonR Preorder\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\nR Inorder traversal of the tree: ";
                inorder(root);
                break;

            case 2:
                cout << "\nR Preorder traversal of the tree: ";
                preorder(root);
                break;

            case 3:
                cout << "\nR Postorder traversal of the tree: ";
                postorder(root);
                break;

            case 4:
                cout << "\nNonR Inorder traversal of the tree: ";
                ninorder(root);
                break;

            case 5:
                cout << "\nNonR Preorder traversal of the tree: ";
                npreorder(root);
                break;

            default:
                cout << "Invalid choice! Exiting...\n";
                return 0;
        }
        cout << "\n";
    }
    return 0;
}
