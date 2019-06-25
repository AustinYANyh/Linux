#include <iostream>
#include <vector>

using namespace std;

void printData(vector<int> v)
{
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

#if 0
int main()
{
	vector<int> v;

	vector<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> v2(v1.begin(), v1.end());

	vector<int> v3(v2);

	cout << "v1:";

	for (auto e : v1)
	{
		cout <<e << " ";
	}

	cout << endl;

	vector <int>::iterator it = v2.begin();

	cout << "v2:";

	while (it != v2.end())
	{
		cout<< *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v3.rbegin();

	cout << "����v3:";

	while (rit != v3.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<int>::iterator pos = find(v3.begin(), v3.end(), 5);

	//v3.erase(pos);

	//v3.insert(pos, 15);

	//v3.push_back(100);

	//v3.pop_back();

	cout << "v4:";

	vector<int> v4{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	printData(v4);

	v3.swap(v4);

	cout << "��v4����֮���v3:";

	printData(v3);

	cout << v3[5] << endl;

	system("pause");
}
#endif


#if 0
vector<vector<int>> PascalTriangle(int nRows)
{
	//�������������Ҫ�Ŀռ�
	vector<vector<int>> vv;

	vv.resize(nRows);

	for (int i = 0; i < nRows; ++i)
	{
		//ÿ�е�Ԫ�ظ��������
		vv[i].resize(i + 1);

		//ÿһ�е�һ�к�ÿһ�����һ�ж���1
		vv[i][0] = vv[i][i] = 1;
	}

	for (int i = 2; i < nRows; ++i)
	{
		//��1�д������,�ӵڶ��п�ʼ
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
	return vv;
}

void printTriangle(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		//v[i].size()��ʾ��i�е�����
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cout << "������������ǵ�����:";

	int rows = 0;

	cin >> rows;

	vector<vector<int>> vv = PascalTriangle(rows);

	printTriangle(vv);

	system("pause");
}
#endif


#if 0
#include <list>

void printData(list<int> L)
{
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	list<int> L1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	list<int> L2(L1.begin(), L1.end());

	list<int> L3(L2);

	cout << "L1:";

	for (auto e : L1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator it = L2.begin();

	cout << "L2:";

	while (it != L2. end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl; 

	list<int>::reverse_iterator rit = L3.rbegin();

	cout << "L3:";

	while (rit != L3.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> L4{ 1, 3, 3, 7, 9, 1, 7, 9 };

	//����
	L4.sort();

	//ȥ��(ֻ����������)
	L4.unique();

	printData(L4);

	L4.push_front(100);

	L4.push_back(99);

	auto pos = find(L4.begin(), L4.end(), 99);

	L4.insert(pos, 70);

	printData(L4);

	pos = find(L4.begin(), L4.end(), 70);

	L4.erase(pos);

	printData(L4);

	L4.pop_back();

	L4.pop_front();

	printData(L4);

	system("pause");
}
#endif

#include<stack>

#if 0
class MiniStack
{
public:
	void push(int x)
	{
		//���_min�ǿ�ջ,��ѹ��,���xС��_min��ջ��Ԫ��Ҳѹ��
		if (_min.empty() || x < _min.top())
		{
			_min.push(x);
		}

		//_dataջֻҪ��Ԫ��Ҫѹ��Ͷ�Ҫѹ��
		_data.push(x);
	}

	void pop()
	{
		if (_data.top() == _min.top())
		{
			_min.pop();
		}
		_data, pop();
	}

	int top()
	{
		return _data.top();
	}

	int GetMin()
	{
		return _min.top();
	}
private:
	stack<int> _min;
	stack<int> _data;
};
#endif

#if 0
class Solution
{
public:
	bool isPopOrder(vector<int> pushV, vector<int> popV)
	{
		//���pushV��Ԫ�ظ�����popVԪ�ظ�������һ��,�϶������ϵ�������
		if (pushV.size() != popV.size())
		{
			return false;
		}

		//1 2 3 4 5      4 5 3 2 1 
		int inIndex = 0;
		int outIndex = 0;
		stack<int> s;

		//outIndex>popV����ЧԪ�ظ���˵��ȫ����ջ
		while (outIndex < popV.size())
		{
			//���s�ǿ�ջ,��ѹ��Ԫ��
			while (s.empty() || s.top() != popV[outIndex])
			{
				//��ֹԽ��,����ҪС��pushV��Ԫ����Ч����
				if (inIndex < pushV.size())
				{
					s.push(pushV[inIndex++]);
				}
				else
				{
					return false;
				}
			}

			//���ջ����Ԫ�غ�popV[outIndex]һ��,��pop
			s.pop();
			++outIndex;
		}
	}
};
#endif


#if 0
#include <stack>

class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int> s1;
	stack<int> s2;

	MyQueue()
	{

	}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
			while (s1.empty() == false)
			{
				s2.push(s1.top());
				s1.pop();
			}
			int a= s2.top();

			s2.pop();
			while (s2.empty() == false)
			{
				s1.push(s2.top());
				s2.pop();
			}

			return a;
	}

	int peek()
	{
			while (s1.empty() == false)
			{
				s2.push(s1.top());
				s1.pop();
			}
			int a= s2.top();

			while (s2.empty() == false)
			{
				s1.push(s2.top());
				s2.pop();
			}

			return a;
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		if (s1.empty() == true && s2.empty() == true)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	MyQueue q1;

	q1.push(1);
	q1.push(2);

	cout << q1.peek() << endl;//1
	cout << q1.pop() << endl;//1
	cout << q1.empty() << endl;//0

	system("pause");
}
#endif

#include<queue>

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector<vector<int>> vv;

		if (root == nullptr)
		{
			return vv;
		}

		queue<TreeNode*> q;

		q.push(root);

		while (q.empty() == false)
		{
			vector<int> level;

			int levelcount = q.size();

			for (int i = 0; i < levelcount; ++i)
			{
				TreeNode* pCur = q.front();
				level.push_back(pCur->val);

				if (pCur->left != nullptr)
				{
					q.push(pCur->left);
				}

				if (pCur->right != nullptr)
				{
					q.push(pCur->right);
				}

				q.pop();
			}
			vv.push_back(level);
		}
		return vv;
	}
};
