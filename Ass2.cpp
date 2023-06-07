#include <bits/stdc++.h>
using namespace std;

class node
{
	int data;
	node *left;
	node *right;

public:
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
	int getdata()
	{
		return data;
	}
	friend class bst;
};

class bst
{
	node *root;

public:
	bst()
	{
		root = NULL;
	}

	node *getroot()
	{
		return root;
	}

	void create()
	{
		cout << "enter the no of elements ::";
		int d;
		cin >> d;
		cout << "enter the data ::";
		int a;
		cin >> a;

		root = new node(a);
		d = d - 1;

		while (d--)
		{
			cin >> a;
			node *n, *temp;
			temp = root;

			while (true)
			{
				if (temp->data == a)
				{
					continue;
				}
				if (a < (temp->data) && temp->left != NULL)
				{
					temp = temp->left;
				}

				else if (a < (temp->data) && temp->left == NULL)
				{
					n = new node(a);
					temp->left = n;
					break;
				}

				else if (a > (temp->data) && temp->right != NULL)
				{
					temp = temp->right;
				}

				else if (a > (temp->data) && temp->right == NULL)
				{
					n = new node(a);
					temp->right = n;
					break;
				}
			}
		}
	}

	node *search(int d)
	{
		if (root == NULL)
		{
			cout << "binary search tree is empty " << endl;
			return NULL;
		}

		node *temp = root;
		while (temp->data != d)
		{
			if (temp != NULL)
			{
				if (d < temp->data)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}

			if (temp == NULL)
			{
				cout << "DATA NOT FOUND" << endl;
				return NULL;
			}
		}
		cout << "DATA FOUND" << endl;
		return temp;
	}

	void inorder_traverse(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}

		inorder_traverse(temp->left);
		cout << temp->data << " ";
		inorder_traverse(temp->right);
	}

	void preorder_traverse(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		cout << temp->data << " ";
		preorder_traverse(temp->left);
		preorder_traverse(temp->right);
	}

	void postorder_traverse(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		postorder_traverse(temp->left);
		postorder_traverse(temp->right);
		cout << temp->data << " ";
	}

	void insert(int a)
	{
		node *n, *temp;
		temp = root;
		if (root == NULL)
		{
			n = new node(a);
			root = n;
			return;
		}

		while (true)
		{
			if (a < (temp->data) && temp->left != NULL)
			{
				temp = temp->left;
			}

			else if (a < (temp->data) && temp->left == NULL)
			{
				n = new node(a);
				temp->left = n;
				break;
			}

			else if (a > (temp->data) && temp->right != NULL)
			{
				temp = temp->right;
			}

			else if (a > (temp->data) && temp->right == NULL)
			{
				n = new node(a);
				temp->right = n;
				break;
			}
		}
	}

	void min_value(node *temp)
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		cout << "minimum value is :: " << temp->data << endl;
	}

	void max_value(node *temp)
	{
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		cout << "maximum value is :: " << temp->data << endl;
	}

	node *find_min(node *temp)
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}

	void delete_value(int a)
	{
		node *temp = root;
		node *parent = NULL;

		if (root == NULL)
		{
			cout << " tree is empty " << endl;
			return;
		}
		while (temp->data != a)
		{
			parent = temp;
			if (temp->data > a)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}

			if (temp == NULL)
			{
				cout << "\ndata is not present\n";
				return;
			}
		}

		if (temp->left == NULL && temp->right == NULL)
		{
			if (temp != root)
			{
				if (parent->left == temp)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}
			else
			{
				root = NULL;
			}
			delete temp;
		}

		else if (temp->left && temp->right)
		{
			node *succ = find_min(temp->right);
			int val = succ->data;

			delete_value(succ->data);
			temp->data = val;
		}

		else
		{
			node *child;
			if (temp->left != NULL)
			{
				child = temp->left;
			}
			else
			{
				child = temp->right;
			}

			if (temp != root)
			{
				if (parent->left == temp)
				{
					parent->left = child;
				}
				else
				{
					parent->right = child;
				}
			}

			else
			{
				root = child;
			}
			delete temp;
		}
	}

	int height(node *temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		return max(height(temp->left), height(temp->right)) + 1;
	}

	int width(node *temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		int a = width(temp->left);
		int b = width(temp->right);

		int c = height(temp->left) + height(temp->right) + 1;
		return max(a, max(b, c));
	}

	void mirror(struct node *node)
	{
		if (node == NULL)
			return;
		else
		{
			struct node *temp;

			mirror(node->left);
			mirror(node->right);

			temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
	}
};

int main()
{
	bst b;
	b.create();
	b.inorder_traverse(b.getroot());
	cout << endl;

	while (true)
	{
		cout
			<< "1:to insert\n2:to search\n3:to find minimum value\n4:to find maximum value\n5:to delete value"
			<< endl;
		cout << "6:to find height" << endl;
		cout << "7:to find width" << endl;
		cout << "8:to swap the nodes" << endl;
		cout << endl;
		int q;
		cout << "enter the choice ::";
		cin >> q;

		if (q == 1)
		{
			int a;
			cout << "enter the value to insert ::";
			cin >> a;
			b.insert(a);
			b.inorder_traverse(b.getroot());
			cout << endl;
		}

		else if (q == 2)
		{
			int a;
			cout << "enter the value to find ::";
			cin >> a;
			// b.insert(a);
			node *got = b.search(a);
		}

		else if (q == 3)
		{
			b.min_value(b.getroot());
		}

		else if (q == 4)
		{
			b.max_value(b.getroot());
		}

		else if (q == 5)
		{
			int a;
			cout << "enter the value to delete ::";
			cin >> a;
			b.delete_value(a);
			b.inorder_traverse(b.getroot());
			cout << endl;
		}
		else if (q == 6)
		{
			cout << "height of tree is:: ";
			cout << b.height(b.getroot());
			cout << endl;
		}
		else if (q == 7)
		{
			cout << "width of tree is:: ";
			cout << b.width(b.getroot());
			cout << endl;
		}

		else if (q == 8)
		{
			cout << "inorder traversal of mirrored tree is :: ";
			b.mirror(b.getroot());
			b.inorder_traverse(b.getroot());
			cout << endl;
		}

		else if (q == 0)
		{
			cout << "\n ending the program ........\n"
				 << endl;
			break;
		}

		else
		{
			cout << "\nenter the correct choice" << endl;
		}
	}

	return 0;
}