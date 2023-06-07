#include <iostream>
#define MAX 50
using namespace std;

class Heap
{
	int arr[MAX], n;

public:
	Heap()
	{
		n = 0;
		for (int i = 0; i < MAX; i++)
		{
			arr[i] = 0;
		}
	}
	void input()
	{
		cout << "Enter no. of entries: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter value no. " << i + 1 << " : ";
			cin >> arr[i];
		}
	}
	void printarr()
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl
			 << endl;
	}
	void heapify(int i, int len = -1)
	{
		len = (len == -1) ? n : len;
		int idx = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < len && arr[idx] < arr[left])
		{
			idx = left;
		}
		if (right < len && arr[idx] < arr[right])
		{
			idx = right;
		}
		if (idx != i)
		{
			printarr(); // prints the array at every pass
			int temp = arr[idx];
			arr[idx] = arr[i];
			arr[i] = temp;

			// printarr();//prints the array at every pass

			heapify(idx, len);
		}
	}
	void arrange()
	{
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(i);
		}
		printarr();
	}
	void extractmax()
	{
		for (int i = 0; i < n; i++)
		{
			int temp = arr[0];
			arr[0] = arr[n - 1 - i];
			arr[n - 1 - i] = temp;
			heapify(0, n - 1 - i);
		}
		printarr();
	}
};

int main()
{
	Heap obj;
	obj.input();
	obj.arrange();
	cout << "After sort: " << endl;
	obj.printarr();
	obj.extractmax();
	return 0;
}
