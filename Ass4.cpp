#include <bits/stdc++.h>
using namespace std;

class hashing
{
public:
	long key;
	char name[10];
	friend class hashingFunction;
};

class hashingFunction
{
	hashing h[10];
public:
	hashingFunction();
	int find(long);
	void insert();
	void display();
	void Delete(long);
};

hashingFunction::hashingFunction()
{
	for (int i = 0; i < 10; i++)
	{
		h[i].key = -1;
		strcpy(h[i].name, "NULL");
	}
}

int hashingFunction::find(long k)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (h[i].key == k)
		{
			cout << "\n\t" << h[i].key << " is Found at " << i << " Location With Name " << h[i].name;
			return i;
		}
	}
	if (i == 10)
	{
		return -1;
	}
}

void hashingFunction::Delete(long k)
{
	int index = find(k);
	if (index == -1)
	{
		cout << "\n\tKey Not Found";
	}
	else
	{
		h[index].key = -1;
		strcpy(h[index].name, "NULL");
		cout << "\n\tKey is Deleted";
	}
}

void hashingFunction::display()
{
	cout << "\n\t\tKey\t\tName";
	for (int i = 0; i < 10; i++)
	{
		cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].name;
	}
}

void hashingFunction::insert()
{
	char ans, n[10], ntemp[10];
	long k, temp;
	int hi, cnt = 0, flag = 0, i;

	do
	{
		if (cnt >= 10)
		{
			cout << "\n\thashing Table is FULL";
			break;
		}
		cout << "\n\tEnter a Telephone No: ";
		cin >> k;
		cout << "\n\tEnter a Client Name: ";
		cin >> n;
		hi = k % 10; // hashing function
		if (h[hi].key == -1)
		{
			h[hi].key = k;
			strcpy(h[hi].name, n);
		}
		else
		{
			if (h[hi].key % 10 != hi)
			{
				temp = h[hi].key;
				strcpy(ntemp, h[hi].name);
				h[hi].key = k;
				strcpy(h[hi].name, n);
				for (i = hi + 1; i < 10; i++)
				{
					if (h[i].key == -1)
					{
						h[i].key = temp;
						strcpy(h[i].name, ntemp);
						flag = 1;
						break;
					}
				}
				for (i = 0; i < hi && flag == 0; i++)
				{
					if (h[i].key == -1)
					{
						h[i].key = temp;
						strcpy(h[i].name, ntemp);
						break;
					}
				}
			}
			else
			{
				for (i = hi + 1; i < 10; i++)
				{
					if (h[i].key == -1)
					{
						h[i].key = k;
						strcpy(h[i].name, n);
						flag = 1;
						break;
					}
				}
				for (i = 0; i < hi && flag == 0; i++)
				{
					if (h[i].key == -1)
					{
						h[i].key = k;
						strcpy(h[i].name, n);
						break;
					}
				}
			}
		}
		flag = 0;
		cnt++;
		cout << "\n\t..... Do You Want to Insert More Key: ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}

int main()
{
	long k;
	int ch, index;
	char ans;
	hashingFunction obj;
	do
	{
		cout << "\n\t*** Dictionary (ADT) ***";
		cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
		cout << "\n\t..... Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			obj.insert();
			break;
		case 2:
			obj.display();
			break;
		case 3:
			cout << "\n\tEnter a Key Which You Want to Search: ";
			cin >> k;
			index = obj.find(k);
			if (index == -1)
			{
				cout << "\n\tKey Not Found";
			}
			break;
		case 4:
			cout << "\n\tEnter a Key Which You Want to Delete: ";
			cin >> k;
			obj.Delete(k);
			break;
		case 5:
			break;
		}
		cout << "\n\t..... Do You Want to Continue in Main Menu: ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}