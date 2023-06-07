#include <iostream>
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

class TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	friend class OBST;
public:
	TreeNode() {
		val = 0;
		left = NULL;
		right = NULL;
	}
};

class Ocost {
	int costval, rootval, weight;
	friend class OBST;
public:
	Ocost() {
		costval = 0;
		rootval = 0;
		weight = 0;
	}
};

class OBST {
	int key[MAX], p[MAX], q[MAX], n, cost;
	Ocost arr[MAX][MAX];
public:
	OBST() {
		n = 0;
		cost = 0;
		for (int i = 0; i < MAX; i++) {
			key[i] = 0;
			p[i] = 0;
			q[i] = 0;
		}
		q[MAX] = 0;
	}
	void input() {
		cout << "Enter no. of entries: ";
		cin >> n;
		cout << "Enter unsuccessful entry no. 0: ";
		cin >> q[0];
		for (int i = 1; i < n; i++) {
			cout << "Enter key no. " << i << " : ";
			cin >> key[i];
			cout << "Enter successful entry no. " << i << " : ";
			cin >> p[i];
			cout << "Enter unsuccessful entry no. " << i << " : ";
			cin >> q[i];
		}
	}
	int getweight(int i, int j) {
		if (i == j) {
			return q[i];
		}
		return arr[i][j - 1].weight + p[j] + q[j];
	}
	int getcost(int i, int j) {
		if (i == j) {
			return 0;
		}
		int minval = MAX, r = 0;
		for (int l = i + 1; l <= j; l++) {
			minval = min(minval, arr[i][l - 1].costval + arr[l][j].costval);
		}
		return minval + getweight(i, j);
	}
	void create() {
		for (int c = 0; c < n; c++) {
			for (int i = 0, j = c; j < n && i < n; i++, j++) {
				arr[i][j].costval = getcost(i, j);
				arr[i][j].weight = getweight(i, j);
			}
		}
		cout << "Array: " << endl;
		for (int c = 0; c < n; c++) {
			for (int i = 0, j = c; j < n && i < n; i++, j++) {
				cout << arr[i][j].rootval << " ";
			}
			cout << endl;
		}
		cout << "Cost: " << arr[0][n - 1].costval << endl;
	}
};

int main() {
	OBST obj;
	obj.input();
	obj.create();
	return 0;
}
