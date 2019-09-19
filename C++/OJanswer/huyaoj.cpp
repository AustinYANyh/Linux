#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct BTNode
{
	BTNode() :_pLeft(nullptr), _pRight(nullptr)
	{

	}

	BTNode* _pLeft;
	BTNode* _pRight;
	int _data;
};

BTNode* BinTree()
{
	BTNode* root = new BTNode();

	return root;
}

void BTInsert(BTNode* root, int data, int flag)
{
	if (root == nullptr)
	{
		root->_data = data;
	}
	else
	{
		BTNode* pCur = root;

		while (pCur != nullptr)
		{
			pCur = pCur->_pLeft;
		}
	}
}

void inOrder(BTNode* pRoot)
{
	if (pRoot != nullptr)
	{
		inOrder(pRoot->_pLeft);
		cout << pRoot->_data << endl;
		inOrder(pRoot->_pRight);
	}
}

int main()
{
	/*	cout << pow(2, 3) << endl;*/
	
	int N;

	while (cin >> N)
	{
		int n = pow(2, N) -1;

		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		int index = 0;
		int M = 1;

		BTNode* root = BinTree(v, index,M,3);

		inOrder(root);
	}

	system("pause");
	return 0;
}

