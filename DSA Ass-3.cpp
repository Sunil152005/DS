#include <iostream>
#include <cstdlib>

using namespace std;

// create TIBT
struct tibt
{
    int lt;
    tibt* lc;
    char data;
    tibt* rc;
    int rt;
};

// Insert data
tibt* insertt(tibt* root)
{
    tibt *temp, *newn, *head;
    int no, i;
    head = nullptr;
    cout << "Enter the no element:\n";
    cin >> no;
    root = new tibt;
    root->lt = root->rt = 1;
    root->lc = root->rc = root;
    root->data = no;

    for (i=0; i<no; i++)
        {
        newn = new tibt;
        cout << "Enter data: ";
        cin >> newn->data;

        if (head == nullptr)
        {
            head = newn;
            root->lc = head;
            root->lt = 0;
            head->lc = head->rc = root;
            head->lt = head->rt = 1;
        } else
        {
            temp = head;
            while (true)
            {
                if (temp->data > newn->data)
                {
                    if (temp->lt == 1)
                    {
                        newn->lc = temp->lc;
                        newn->rc = temp;
                        newn->lt = newn->rt = 1;
                        temp->lc = newn;
                        temp->lt = 0;
                        break;
                    } else
                    {
                        temp = temp->lc;
                    }
                } else if (temp->data < newn->data)
                {
                    if (temp->rt == 1)
                    {
                        newn->rc = temp->rc;
                        newn->lc = temp;
                        newn->lt = newn->rt = 1;
                        temp->rc = newn;
                        temp->rt = 0;
                        break;
                    } else
                    {
                        temp = temp->rc;
                    }
                }
            }
        }
    }
    return root;
}

// Inorder traversal of tree
void inorder(tibt* head)
{
    tibt *ptr, *succ;
    ptr = head->lc;
    while (ptr->lt == 0)
        ptr = ptr->lc;

    cout << ptr->data;

    while (true)
    {
        if (ptr->rt == 1)
        {
            succ = ptr->rc;
        } else
        {
            ptr = ptr->rc;
            while (ptr->lt == 0)
                ptr = ptr->lc;
            succ = ptr;
        }
        ptr = succ;
        if (ptr == head)
            break;

        cout << " " << ptr->data;
    }
}

// Preorder traversal of tree
void preorder(tibt* head)
{
    tibt *ptr, *succ;
    ptr = head->lc;
    while (ptr->lt == 0)
    {
        cout << " " << ptr->data;
        ptr = ptr->lc;
    }
    cout << " " << ptr->data;

    while (true)
    {
        if (ptr->rt == 1)
        {
            succ = ptr->rc;
        } else
        {
            ptr = ptr->rc;
            cout << " " << ptr->data;

            while (ptr->lt == 0)
            {
                ptr = ptr->lc;
                cout << " " << ptr->data;
            }
            succ = ptr;
        }
        ptr = succ;
        if (ptr == head)
            break;
    }
}

int main()
{
    tibt* root = nullptr;
    int ch;

    while (true)
    {
        cout << "\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Inorder\n";
        cout << "3. Preorder\n";
        cout << "Enter your choice:\n";
        cin >> ch;

        switch (ch)
        {
            case 1:
                root = insertt(root);
                break;

            case 2:
                cout << "Inorder of the tree is:\n";
                inorder(root);
                break;

            case 3:
                cout << "Preorder of the tree is:\n";
                preorder(root);
                break;

            default:
                cout << "Invalid choice!...\n";
        }
    }
    return 0;
}
