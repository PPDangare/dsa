#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    bool lflag;
    bool rflag;

public:
    Node(int d)
    {
        data = d;
        left = right = NULL;
        lflag = rflag = 0;
    }

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        rflag = false;
        lflag = false;
    }

    friend class TBT;
};

class TBT
{
    Node *root;
    Node *header;

public:
    TBT()
    {
        root = NULL;
        header = new Node(0);
    }

    void insert(int d)
    {
        Node *p = root;
        if (p == NULL)
        {
            root = new Node(d);
            root->left = header;
            root->right = header;

            root->lflag = true;
            root->rflag = true;
            return;
        }

        Node *q = NULL;
        while (p != header)
        {
            q = p;
            if (d < p->data)
            {
                if (p->lflag)
                {
                    cout << "left " << endl;
                    Node *temp = p->left;
                    p->left = new Node(d);
                    p->left->left = temp;
                    p->lflag = false;
                    p->left->lflag = true;
                    p->left->right = p;
                    p->left->rflag = true;
                    return;
                }
                else
                {
                    p = p->left;
                }
            }
            else
            {
                if (p->rflag)
                {
                    cout << "right" << endl;
                    Node *temp = p->right;
                    p->right = new Node(d);
                    p->right->right = temp;
                    p->rflag = false;
                    p->right->rflag = true;
                    p->right->left = p;
                    p->right->lflag = true;
                    return;
                }
                else
                {
                    p = p->right;
                }
            }
        }
    }

    void Create_TBT()
    {
        cout << "Enter the data in the root node" << endl;
        int d;
        cin >> d;
        insert(d);

        cout << "Keep entering the data , to stop enter -1" << endl;

        while (true)
        {
            cin >> d;
            if (d == -1)
            {
                return;
            }
            insert(d);
        }
    }

    // TRAVERSAL

    void Inorder()
    {
        Node *p = root;

        while (p != header)
        {
            while (!p->lflag)
            {
                p = p->left;
            }
            cout << p->data << " ";
            while (p->rflag)
            {
                p = p->right;
                if (p == header)
                    return;
                cout << p->data << " ";
            }
            p = p->right;
        }
        cout << endl;
    }

    void pre_order()
    {
        Node *p = root;
        while (p != header)
        {
            while (!p->lflag)
            {
                cout << p->data << " ";
                p = p->left;
            }
            cout << p->data << " ";
            while (p->rflag)
            {
                p = p->right;
                if (p == header)
                    return;
            }
            p = p->right;
        }
    }

    Node *delete_node(Node *p, Node *q)
    {
        if (p == NULL)
        {
            return NULL;
        }
        // 1 ] leaf node

        if (q->lflag && q->rflag)
        {
            Node *temp;
            if (q->left == p)
            {
                p->rflag = true;
                temp = q->right;
            }
            else
            {
                p->lflag = true;
                temp = q->left;
            }
            cout << 2 << endl;
            delete q;
            return temp;
        }

        if (q->lflag)
        {
            Node *temp;
            q->right->left = q->left;
            q->right->lflag = true;
            temp = q->right;
            delete q;
            return temp;
        }

        if (q->rflag)
        {
            Node *temp;
            q->left->right = q->right;
            q->left->rflag = true;
            temp = q->left;
            delete q;
            return temp;
        }

        Node *temp = q;
        q = q->left;
        while (!q->rflag)
        {
            q = q->right;
        }
        temp->data = q->data;

        temp->left = delete_node(temp, temp->left);
        return temp;
    }

    Node *delete_data(Node *p, int d)
    {
        if (p == header)
        {
            return p;
        }
        if (p->left->data == d)
        {
            cout << 1 << endl;
            p->left = delete_node(p, p->left);
            return p;
        }
        if (p->right->data == d)
        {
            p->right = delete_node(p, p->right);
            return p;
        }

        if (p->data < d)
        {
            p->right = delete_data(p->right, d);
        }
        else
        {
            p->left = delete_data(p->left, d);
        }
        return p;
    }

    void delete_d(int d)
    {
        root = delete_data(root, d);
    }
};

int main()
{
    TBT t1;

    int n;
    n = 50;
    while (n)
    {
        cout << "1 ] CREATE THREADED BINARY SEARCH TREE" << endl;
        cout << "2 ] INSERT DATA " << endl;
        cout << "3 ] DELETE DATA " << endl;
        cout << "4 ] INORDER TRAVERSAL" << endl;
        cout << "5 ] PREORDER-TRAVERSAL" << endl;
        cout << "6 ] EXIT" << endl;

        cout << "Enter your option" << endl;
        cin >> n;

        switch (n)
        {
        case 1:
        {
            t1.Create_TBT();
            break;
        }
        case 2:
        {
            int d;
            cout << "Enter number to be added" << endl;
            cin >> d;
            t1.insert(d);
            break;
        }
        case 3:
        {
            int d;
            cout << "Enter the data to be deleted " << endl;
            cin >> d;
            t1.delete_d(d);
            break;
        }
        case 4:
        {
            cout << "Inorder traversal" << endl;
            t1.Inorder();
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "PreOrder traversal" << endl;
            t1.pre_order();
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "thank you" << endl;
            n = 0;
            break;
        }
        default:
        {
            cout << "Invalid option ,Please enter the valid option" << endl;
            break;
        }
        }
    }
    return 0;
}