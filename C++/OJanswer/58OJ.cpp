#define _CRT_SECURE_NO_WARNINGS

#if 0
#include<iostream>
#include<string>
#include<set>

//100,1,2,3,2
//1,2,3
//3
100 1 2 2 3

using namespace std;

int main()
{
	string s;
	
	while (getline(cin, s))
	{
		set<char> s1;
		int count = 0;

		if (s.size() == 0 )
		{
			cout << 0 << endl;
		}

		for (auto e : s)
		{
			s1.insert(e);
		}
		
		//s1.erase(',');

		for (auto e : s1)
		{
			if (e != ',')
			{
				count++;
			}
		}

		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int st_count = 0;

	while (cin >> st_count)
	{
		vector<int> st_score(st_count);

		for (int i = 0; i < st_count; ++i)
		{
			cin >> st_score[i];
		}

		vector<int> cookie;

		cookie.resize(st_count, 1);

		for (int i = 0; i < st_count; ++i)
		{
			if (i == 0)
			{
				if (st_score[i]>st_score[i + 1])
				{
					cookie[i] = 2;
				}
			}
			else if (i == st_count - 1)
			{
				if (st_score[i] > st_score[i - 1])
				{
					cookie[i] = cookie[i - 1] + 1;
				}
				//else
				//{
				//	cookie[i - 1] += 1;
				//}
			}
			else
			{
				if (st_score[i] > st_score[i + 1] && st_score[i] > st_score[i - 1])
				{
					cookie[i] = max(cookie[i - 1], cookie[i + 1]) + 1;
				}
				else if (st_score[i] > st_score[i + 1] )
				{
					cookie[i] = cookie[i + 1] + 1;
				}
				else if (st_score[i] > st_score[i - 1])
				{
					cookie[i] = cookie[i - 1] + 1;
				}
			}
		}

		int cookies = 0;

		for (auto& e : cookie)
		{
			cookies += e;
		}

		cout << cookies << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v(200);

	for (int i = 0; i < 200; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < 200; ++i)
	{
		int count = 0;
		int tp99 = v[i];

		for (int j = 0; j < 200; ++j)
		{
			if (tp99 >= v[j])
			{
				count++;
			}
		}

		if (count >= 198)
		{
			cout << tp99 << endl;
			break;
		}
		else
		{
			continue;
		}
	}

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string account;

	while (getline(cin, account))
	{
		string a = account.substr(0, account.find("@"));
		string b = account.substr(account.find("@"));

		string M = "MASK";

		string B;
		int j = 0;

		for (int i = 1; i < a.size(); i += 2)
		{
			a.insert(i, M, j, 1);
			j++;

			if (j == 4)
			{
				j = 0;
			}
		}


		cout << a + b << endl;
	}

	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<vector>
using namespace std;


class Solution1 
{
public:
	bool Find(int target, vector<vector<int> > array)
	{
		if (target > array[array.size() - 1][array[0].size() - 1] || target < array[0][0])
		{
			return false;
		}

		int row = array.size();
		int col = array[0].size();

		int a = 0;
		int b = col - 1;

		while (a < row && b >= 0)
		{
			if (target < array[a][b])
			{
				b--;
			}
			else if (target > array[a][b])
			{
				a++;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

/*
class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		char tmp = ' ';
		char a = '%20';

		for (int i = 0; i < length; ++i)
		{
			if (str[i] != (char)" ")
			{
				tmp += str[i];
			}
			else
			{
				tmp += a;
				continue;
			}
		}

	}
};
*/

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{

	}
};

using namespace std;

class Solution3 {
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int> v;

		if (head == nullptr)
		{
			return v;
		}

		ListNode* pCur = head;
		ListNode* result = nullptr;

		while (pCur != nullptr)
		{
			ListNode* Next = pCur->next;
			pCur->next = result;
			result = pCur;
			pCur = Next;
		}

		pCur = result;

		while (pCur != nullptr)
		{
			v.push_back(pCur->val);
			pCur = pCur->next;
		}
		return v;
	}
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution4 {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		int index = 0;

		int left = 0;
		int right = pre.size();

		return _reConstructBinaryTree(pre, vin, index, left, right);
	}

	TreeNode* _reConstructBinaryTree(vector<int> pre, vector<int> vin, int& index, int left, int right)
	{
		if (left >= right)
		{
			return nullptr;
		}

		TreeNode* Root = new TreeNode(pre[index]);

		int i = 0;

		while (vin[i] != pre[index])
		{
			i++;
		}

		if (i > left)
		{
			Root->left = _reConstructBinaryTree(pre, vin, ++index, left, i);
		}

		if (i + 1 < right)
		{
			Root->right = _reConstructBinaryTree(pre, vin, ++index, i + 1, right);
		}

		return Root;
	}
};

#include<stack>

void PostOrder(TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		PostOrder(pRoot->left);
		PostOrder(pRoot->right);
		cout << pRoot->val << " ";
	}
}

class Solution
{
public:
	void push(int node)
	{
		s1.push(node);
	}

	int pop()
	{
		while (s1.empty() == false)
		{
			s2.push(s1.top());
			s1.pop();
		}

		s2.pop();

		while (s2.empty() == false)
		{
			s1, push(s2.top());
			s2.pop();
		}
	}

private:
	stack<int> s1;
	stack<int> s2;
};

int main()
{
	/*
	vector<vector<int>> vv;

	vv.resize(2);

	for (int i = 0; i < 2; ++i)
	{
		vv[i].resize(4);
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> vv[i][j];
		}
	}

	Solution1 s;

	cout << s.Find(11, vv) << endl;
	*/
		/*
	char* str = "ni hao";

	Solution s;

	s.replaceSpace(str, 6);

	cout << str << endl;
	*/

	/*
	vector<int> pre{ 1, 2, 3, 4, 5, 6 };
	vector<int> in{ 3, 2, 1, 5, 4, 6 };

	int index = 0;

	Solution s;
	TreeNode* Root = s.reConstructBinaryTree(pre, in);

	PostOrder(Root);
	*/

	Solution s;

	s.push(1);
	s.push(2); 
	s.push(3); 
	s.push(4);

	s.pop();
	
	
	system("pause");
	return 0;
}