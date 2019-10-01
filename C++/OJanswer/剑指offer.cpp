#include<iostream>
#include<stack>

using namespace std;

//9.27

//栈实现队列
class Solutione
{
public:
    void push(int node) 
    {
        s1.push(node);
    }

    int pop() 
    {
        while(s1.empty()==false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        int i=s2.top();
        
        s2.pop();
        
        while(s2.empty()==false)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return i;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

#include<vector>

//旋转数组的最小数字
class Solutiond 
{
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if(rotateArray.size()==0)
        {
            return 0;
        }
        
        int min=rotateArray[0];
        
        for(int i=1;i<rotateArray.size();++i)
        {
            if(min>rotateArray[i])
            {
                min=rotateArray[i];
            }
        }
        return min;
    }
};

#include<vector>

//斐波那契数列
class Solutionc
{
public:
    int Fibonacci(int n) 
    {
        vector<int> fib;
        fib.resize(39,0);
        
        fib[1]=1;
        fib[2]=1;
        
        for(int i=3;i<=39;++i)
        {
            fib[i]=fib[i-1]+fib[i-2];
        }
        
        return fib[n];
    }
};

//跳台阶
class Solutionb 
{
public:
    int jumpFloor(int number) 
    {
        if(number==0)
        {
            return 0;
        }
        else if(number<3)
        {
            return number;
        }
        else
        {
            int f=0;
            int f1=1;
            int f2=2;
            
            for(int i=3;i<=number;++i)
            {
                f=f1+f2;
                f1=f2;
                f2=f;
            }
            return f;
        }
    }
};

//变态跳台阶
#include<vector>

class Solutiona
{
public:
    int jumpFloorII(int number) 
    {
        //动态规划问题
        
        //状态:青蛙调到台阶上的方法数
        
        //初始化
        vector<int> F(number+1);
        
        F[0]=1;
        F[1]=1;
        F[2]=2;
        
        //状态转移方程:F(n)=F(n-1)+F(n-2)+F(n-3)...+F(1)
        //F(n-1)=F(n-2)+F(n-3)...+F(1)
        //F(n)=2F(n-1)
        for(int i=3;i<=number;++i)
        {
            F[i] = 2 * F[i - 1];
        }
        //返回结果:F(n)
        return F[number];
    }
};

//矩形覆盖(变式斐波那契)
class Solution0 {
public:
    int rectCover(int number) 
    {
        if(number<=0)
        {
            return 0;
        }
        else if(number<=2)
        {
            return number;
        }
        else
        {
            return rectCover(number-1)+rectCover(number-2);
        }
    }
};

//二进制位1的数量,负数采用补码表示
class Solution1 {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		
		unsigned int nn = n;

		while (nn>0)
		{
			if ((nn & 1) == 1)
			{
				count++;
			}
			nn >>= 1;
		}
		return count;
	}
};

#include<algorithm>
#include<math.h>

//幂运算
class Solution2 {
public:
	double Power(double base, int exponent)
	{
		return pow(base, exponent);
	}
};

#include<vector>

//调整数组奇数和偶数的位置
class Solution3 {
public:
	void reOrderArray(vector<int> &array)
	{
		vector<int> v;

		for (auto e : array)
		{
			if (e % 2 != 0)
			{
				v.push_back(e);
			}
		}

		for (auto e : array)
		{
			if (e % 2 == 0)
			{
				v.push_back(e);
			}
		}

		array = v;
	}
};

//14-17

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{
	}
};

//链表倒数第K个节点
class Solution4 {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		while (k > 0 && fast != nullptr)
		{
			fast = fast->next;
			k--;
		}

		if (fast == nullptr && k > 0)
		{
			return nullptr;
		}

		while (fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
	}
};

//反转链表
class Solution5 {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == nullptr)
		{
			return nullptr;
		}

		ListNode* result = nullptr;

		ListNode* pCur = pHead;
		while (pCur != nullptr)
		{
			ListNode* Next = pCur->next;
			pCur->next = result;
			result = pCur;
			pCur = Next;
		}

		return result;
	}
};

//合并有序链表
class Solution6 {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
		{
			return pHead2;
		}

		if (pHead2 == nullptr)
		{
			return pHead1;
		}

		ListNode* result = nullptr;
		ListNode* last = nullptr;

		ListNode* pCur1 = pHead1;
		ListNode* pCur2 = pHead2;

		while (pCur1 != nullptr && pCur2 != nullptr)
		{
			if (pCur1->val <= pCur2->val)
			{
				if (result==nullptr)
				{
					result = last = pCur1;
				}
				else
				{
					last->next = pCur1;
					last = pCur1;
				}
				pCur1 = pCur1->next;
			}
			else
			{
				if (result == nullptr)
				{
					result = last = pCur2;
				}
				else
				{
					last->next = pCur2;
					last = pCur2;
				}
				pCur2 = pCur2->next;
			}
		}

		if (pCur1 != nullptr)
		{
			last->next = pCur1;
		}

		if (pCur2 != nullptr)
		{
			last->next = pCur2;
		}

		last->next = nullptr;
		return result;
	}
};

//9.28
#include<stack>

//最小栈
class Solution7 
{
public:
    void push(int value) 
    {
        if(s1.empty()==true)
		{
			s1.push(value);
			s1.push(value);
		}
		else
		{
			int top=s1.top();
			s1.pop();

			if(value<s1.top())
			{
				s1.push(top);

				s1.push(value);
				s1.push(value);
			}
			else
			{
				int min=s1.top();
				s1.push(top);

				s1.push(min);
				s1.push(value);
			}
			
		}
		
    }
    void pop() 
    {
        s1.pop();
		s1.pop();
    }

    int top() 
    {
        return s1.top();
    }

    int min() 
    {
        int top=s1.top();
		s1.pop();

		int min=s1.top();
		s1.push(top);

		return min;
    }

private:
	stack<int> s1;
	stack<int> s2;
};

//树的子结构(错误代码)
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL)
	{

	}
};

#include<vector>

void preOrder(TreeNode* root,vector<int>& v)
{
	if(root!=nullptr)
	{
		v.push_back(root->val);
		preOrder(root->left,v);
		preOrder(root->right,v);
	}
}

class Solution8
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		vector<int> v1;
		vector<int> v2;

		preOrder(pRoot1,v1);
		preOrder(pRoot2,v2);

		int i=0;
		while(v1[i]!=v2[0])
		{
			i++;
		}

		for(int j=i;j<v2.size();++j)
		{
			if(v1[j]!=v2[j])
			{
				return false;
			}
		}
		return true;
	}
};

//树的子结构(正确代码)
class Solution9
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
		{
			return false;
		}

		bool result = false;

		if (pRoot1->val == pRoot2->val)
		{
			result=isSubtree(pRoot1, pRoot2);
		}
		
		if (result == false)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (result == false)
		{
			result = HasSubtree(pRoot1->right, pRoot2);
		}
        
        return result;
	}

	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr)
		{
			return true;
		}
        
		if (pRoot1 == nullptr)
		{
			return false;
		}
        
		bool result = true;

		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}

		if (result == true)
		{
			result=isSubtree(pRoot1->left, pRoot2->left);
		}
		if (result == true)
		{
			result=isSubtree(pRoot1->right, pRoot2->right);
		}
        
        return result;
	}
};

//9.29
#include<queue>

//二叉树的镜像
void levelOrder(TreeNode* root,vector<TreeNode*>& v)
{
    if(root==nullptr)
	{
		return;
	}

	queue<TreeNode*> q;
	q.push(root);

	while(q.empty()==false)
	{
		v.push_back(q.front());

		if(q.front()->left!=nullptr)
		{
			q.push(q.front()->left);
		}

		if(q.front()->right!=nullptr)
		{
			q.push(q.front()->right);
		}

		q.pop();
	}
}

class Solution10
{
public:
    void _Mirror(TreeNode *pRoot) 
    {
		vector<TreeNode*> v;
        levelOrder(pRoot,v);

		for(int i=0;i<v.size();++i)
		{
			Mirror(v[i]);
		}
    }

	void Mirror(TreeNode *pRoot)
	{
		if(pRoot!=nullptr)
		{
			swap(pRoot->left,pRoot->right);
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
	}
};

//顺时针打印矩阵(VS可以但是代码不通过,时间复杂度可能不满足)
class Solution11
{
public:
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		vector<int> result;

		int row = matrix.size();
		int col = matrix[0].size();

		if (row == 1)
		{
			for (int j = 0; j < col; ++j)
			{
				result.push_back(matrix[0][j]);
			}
			return result;
		}

		if (col == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				result.push_back(matrix[i][0]);
			}
			return result;
		}

		int i = 0;
		int j = 0;
		int time = 0;

		while (result.size() != (row * col))
		{
			for (; j < col - time; ++j)
			{
				result.push_back(matrix[i][j]);
			}

			j--;

			while (i < row -1 - time)
			{
				i++;
				result.push_back(matrix[i][j]);
			}

			time++;

			while (j > time-1)
			{
				j--;
				result.push_back(matrix[i][j]);
			}
			
			while (i > time)
			{
				i--;
				result.push_back(matrix[i][j]);
			}
			j++;
		}

		return result;
	}
};

//栈的压入、弹出序列
class Solution12 
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        vector<int> v;
        int j=0;
        
		for(int i=0;i<pushV.size();++i)
		{
			v.push_back(pushV[i]);

			while(j<popV.size() && v.back()==popV[j])
			{
				v.pop_back();
				j++;
			}
		}
		return v.empty();
    }
};

//从上到下打印二叉树(层序遍历)
class Solution13 
{
public:
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		queue<TreeNode*> q;
		vector<int> v;

		if(root==nullptr)
		{
			return v;
		}

		q.push(root);

		while (q.empty() == false)
		{
			v.push_back(q.front()->val);

			if (q.front()->left != nullptr)
			{
				q.push(q.front()->left);
			}

			if (q.front()->right != nullptr)
			{
				q.push(q.front()->right);
			}

			q.pop();
		}
		return v;
	}
};

//二叉搜索树后续遍历序列
class Solution14 
{
public:
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
		if(sequence.empty()==true)
		{
			return false;
		}

		return isPostOrder(sequence,0,sequence.size()-1);
    }

	bool isPostOrder(vector<int>& sequence,int left,int right)
	{
		if(left>=right)
		{
			return true;
		}
        
		int i=right;
		while(i > left && sequence[i - 1] > sequence[right]) 
        {
            --i;
        }

		for(int j=i-1;j>=left;--j)
		{
			if(sequence[j]>sequence[right])
			{
				return false;
			}
		}

		return isPostOrder(sequence,left,i-1)+isPostOrder(sequence,i,right-1);
	}
};

