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

//字符串排列

//如果当时刷到了这个题,吉比特的笔试我应该能过

/*
Dfs(当前这一步的处理逻辑)
{
1. 判断边界，是否已经一条道走到黑了：向上回退
2. 尝试当下的每一种可能
3. 确定一种可能之后，继续下一步 Dfs(下一步)
}
*/

void perm(int k, string str, vector<string>& res)
{
	if (k == str.size() - 1)
	{
		res.push_back(str);
	}

	for(int i=k;i<str.size();++i)
	{
		if(i!=k && str[i]==str[k])
		{
			continue;
		}

		swap(str[k],str[i]);
		perm(k+1,str,res);
		swap(str[k],str[i]);
	}
}


vector<string> Permutation(string str)
{
	vector<string> res;
	perm(0,str,res);

	sort(res.begin(),res.end());
	return res;
}

//10.1

//字符串超过一半的数
class Solution15 
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        if(numbers.size()==0)
        {
            return 0;
        }
        
        sort(numbers.begin(),numbers.end());
        
        int count=0;
        
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==numbers[numbers.size()>>1])
            {
                count++;
            }
        }
        
        if(count>(numbers.size()>>1))
        {
            return numbers[numbers.size()>>1];
        }
        else
        {
            return 0;
        }
    }
};

//最小的K个数
class Solution16 
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        vector<int> result;
        
        if(k>input.size())
        {
            return result;
        }
        sort(input.begin(),input.end());
        
        for(int i=0;i<k;++i)
        {
            result.push_back(input[i]);
        }
        
        return result;
    }
};

//连续子数组中最大和
class Solution17 
{
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int max=array[0];
        int sum=0;
        
        for(int i=0;i<array.size();++i)
        {
            sum+=array[i];
            
            if(sum>max)
            {
                max=sum;
            }
            
            if(sum<0)
            {
                sum=0;
            }
        }
        
        return max;
    }
};

#include<string>

//1-n中1出现的次数
class Solution18 
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count=0;
        
        for(int i=1;i<=n;++i)
        {
            string a=to_string(i);
            
            for(int j=0;j<a.size();++j)
            {
                if(a[j]=='1')
                {
                    count++;
                }
            }
        }
        return count;
    }
};

//把数组排成最小的数
bool cmp(int a,int b)
{
	string A;
	string B;

	A+=to_string(a);
	A+=to_string(b);

	B+=to_string(b);
	B+=to_string(a);

	return A<B;
}

string PrintMinNumber(vector<int> numbers) 
{
    sort(numbers.begin(),numbers.end(),cmp);
        
    string result;
        
    for(int i=0;i<numbers.size();++i)
    {
        result+=to_string(numbers[i]);
    }
        
    return result;
}

//丑数
class Solution19 
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if(index<7)
        {
            return index;
        }
        
        vector<int> res;
        
        int p2=0;
        int p3=0;
        int p5=0;
        
        int putnum=1;
        res.push_back(putnum);
        
        while(res.size()<index)
        {
            putnum=min(res[p2]*2,min(res[p3]*3,res[p5]*5));
            
            if(res[p2]*2 == putnum)
            {
                p2++;
            }
            
            if(res[p3]*3 == putnum)
            {
                p3++;
            }
            
            if(res[p5]*5 == putnum)
            {
                p5++;
            }
            
            res.push_back(putnum);
        }
        return putnum;
    }
};

//10.2

//第一个只出现一次的字符
class Solution20 
{
public:
    int FirstNotRepeatingChar(string str) 
    {
        for (int i = 0; i < str.size(); ++i)
        {
            int count = 1;

            for (int j = 0; j < str.size(); ++j)
            {
                if (i != j && str[i] == str[j])
                {
                    count++;
                }
            }

            if (count == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

//数组中的逆序对(暴力求解会超时)
class Solution21 
{
public:
    int InversePairs(vector<int> data) 
    {
		int count=0;

        for(int i=0;i<data.size();++i)
		{
			for(int j=i;j<data.size();++j)
			{
				if(data[i]>data[j])
				{
					count++;
				}
			}
		}
		return count%1000000007;
    }
};

//两个链表的第一个公共节点
class Solution22 
{
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        if(pHead1==nullptr || pHead2==nullptr)
		{
			return nullptr;
		}

		int size1=0;
		int size2=0;

		ListNode* pCur1=pHead1;
		ListNode* pCur2=pHead2;

		while(pCur1!=nullptr)
		{
			size1++;
			pCur1=pCur1->next;
		}

		while(pCur2!=nullptr)
		{
			size2++;
			pCur2=pCur2->next;
		}

		pCur1=pHead1;
		pCur2=pHead2;

		if(size1<size2)
		{
			while(size2-size1>0)
			{
				pCur2=pCur2->next;
				size2--;
			}
		}
		else
		{
			while(size1-size2>0)
			{
				pCur1=pCur1->next;
				size1--;
			}
		}

		while(pCur1!=nullptr && pCur2!=nullptr)
		{
			if(pCur1==pCur2)
			{
				return pCur1;
			}
			pCur1=pCur1->next;
			pCur2=pCur2->next;
		}
		return nullptr;
    }
};

//数字在排序数组中出现的次数
class Solution23 
{
public:
    int GetNumberOfK(vector<int> data ,int k) 
    {
        int count=0;
        
        for(int i=0;i<data.size();++i)
        {
            if(k==data[i])
            {
                count++;
            }
        }
        return count;
    }
};

//二叉树的深度
class Solution24 
{
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
        {
            return 0;
        }
		else if(pRoot->left==nullptr && pRoot->right==nullptr)
		{
			return 1;
		}
        else
		{
			int t1=0;
			int t2=0;

			t1=TreeDepth(pRoot->left);
			t2=TreeDepth(pRoot->right);

			return max(t1,t2)+1;
		}
    }
};

#include<math.h>

//判断是否是平衡二叉树

//后续遍历二叉树,判断左右子树高度差,高度差大于1,返回-1,如果不大于1,返回子树高度(left,right取较大值+1)继续遍历
class Solution25 
{
public:
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        if(GetDepth(pRoot)== -1)
		{
			return false;
		}
		else
		{
			return true;
		}
    }

	int GetDepth(TreeNode* root)
	{
		if(root==nullptr)
		{
			return 0;
		}
	
		int left=GetDepth(root->left);
		int right=GetDepth(root->right);

		if(left== -1)
		{
			return -1;
		}	
		if(right== -1)
		{
			return -1;
		}

		return abs(left-right)>1?-1:1+max(left,right);
	}
};

//数组中只出现一次的数字(其余数字出现两次)
class Solution26 
{
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
    {
        int res=0;
        
        for(int i=0;i<data.size();++i)
        {
            res^=data[i];
        }
        
        int pos=0;
        
        for(int i=0;i<32;++i)
        {
            if(res&1<<i)
            {
                pos=i;
                break;
            }
        }
        
        for(int i=0;i<data.size();++i)
        {
            if(data[i]&1<<pos)
            {
                *num1^=data[i];
            }
            else
            {
                *num2^=data[i];
            }
        }
    }
};

//和为s的连续整数序列

//算法大佬的双指针思路,又清晰时间复杂度也不高
//自己想真是想不到这么棒的思路
class Solution27 
{
public:
    vector<vector<int>> FindContinuousSequence(int sum) 
	{
        int pcur1=1;
		int pcur2=2;

		int sumcur=0;

		vector<vector<int>> result;

		while(pcur2>pcur1)
		{
			sumcur=(pcur1+pcur2)*(pcur2-pcur1+1)/2;

			if(sumcur<sum)
			{
				pcur2++;
			}

			if(sumcur==sum)
			{
				vector<int> res;
				for(int i=pcur1;i<=pcur2;++i)
				{
					res.push_back(i);
				}
				result.push_back(res);
				pcur1++;
			}

			if(sumcur>sum)
			{
				pcur1++;
			}
		}
		return result;
    }
};

//和为s的两个数字
class Solution28 
{
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		int a = 0;
		vector<int> v;

		for (int i = 0; i < array.size(); ++i)
		{
			for (int j = 0; j < array.size(); ++j)
			{
				if (i != j)
				{
					a = array[i] + array[j];
				}

				if (a == sum)
				{
					if (v.empty() == true)
					{
						v.push_back(array[i]);
						v.push_back(array[j]);
					}

					if (array[i] * array[j] < v[0] * v[1])
					{
						v.clear();
						v.push_back(array[i]);
						v.push_back(array[j]);
					}
				}
			}
		}
		return v;
	}
};

//左旋转字符串
class Solution29 
{
public:
    string LeftRotateString(string str, int n)
    {
        string result;
        
        if(str.size()==0)
        {
            return result;
        }
        
        string a = str.substr(0, n);
        string b = str.substr(n,str.size());
        
        result += b;
        result += a;

        return result;
    }
};

//翻转单词序列
class Solution30 
{
public:
    string ReverseSentence(string str)
    {
        reverse(str.begin(), str.end());

        int begin = 0;
        int end = 0;

        while (end<str.size())
        {
            while (str[end] != ' ' && end<str.size())
            {
                end++;
            }

            int nextposition = end+1;

            while (begin < end-1)
            {
                swap(str[begin],str[end-1]);
                begin++;
                end--;
            }
            begin = nextposition;
            end = nextposition;
        }

        return str;
    }
};

//10.3

//不用加减乘除做加法
class Solution31
{
public:
    int Add(int num1, int num2)
    {
        while(num1!=0)
        {
            int tmp=num2;
            num2=num1^num2;
            num1=num1&tmp;
            num1<<=1;
        }
        return num2;
    }
};

//把字符串转换为整数
class Solution32 
{
public:
    int StrToInt(string str)
    {
        long long res = 0;
        int flag=1;

        if (str[0] == '+')
        {
            str[0]='0';
        }

        if (str[0] == '-')
        {
            str[0]='0';
            flag=-1;
        }

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                return 0;
            }
            res = res * 10 + str[i] - '0';
            
            if ((flag==1 && res>INT_MAX) || (flag==-1 && res*flag <INT_MIN))
		    {
			    return 0;
		    }
        }

        return res*flag;
    }
};

//数组中重复的数字(O(N2)常规思路)
class Solution33
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) 
    {
        for(int i=0;i<length;++i)
        {
            for(int j=0;j<length;++j)
            {
                if(i!=j && numbers[i]==numbers[j])
                {
                    *duplication=numbers[i];
                    return true;
                }
            }
        }
        return false;
    }
};

//哈希映射思想(时空复杂度O(N))
    bool duplicate(int numbers[], int length, int* duplication)
    {
        vector<int> hash(length,0);

        for (int i = 0; i < length; ++i)
        {
            hash[numbers[i]]++;
        }

        for (int i = 0; i < length; ++i)
        {
            if (hash[i]>1)
            {
                *duplication = i;
                return true;
            }
        }
		return false;
    }

//字符流中第一个不重复的字符
class Solution34
{
public:
  //Insert one char from stringstream
    char hash[256]={0};
    string a;
    
    void Insert(char ch)
    {
        a+=ch;
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<a.size();++i)
        {
            if(hash[a[i]]==1)
            {
                return a[i];
            }
        }
        return '#';
    }
};

//带环链表的入环点
class Solution35
{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(hasCycle(pHead)==nullptr)
        {
            return nullptr;
        }
        
        ListNode* pH=pHead;
        ListNode* pM=hasCycle(pHead);
        
        while(pH!=pM)
        {
            pH=pH->next;
            pM=pM->next;
        }
        
        return pM;
    }
    
	//判断链表是否有环
    ListNode* hasCycle(ListNode* pHead)
    {
        if(pHead==nullptr)
        {
            return nullptr;
        }
        
        ListNode* fast=pHead;
        ListNode* slow=pHead;
        
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
            {
                return fast;
            }
        }
        return nullptr;
    }
};

//删除链表中重复的节点
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)
	{
		return pHead;
	}

	ListNode* pPre = pHead;
	ListNode* pCur = pHead;
	ListNode* pNext = pHead->next;

	while (pNext != nullptr)
	{
		if (pCur->val == pNext->val)
		{
			while (pNext!=nullptr && pCur->val == pNext->val)
			{
				pNext = pNext->next;
			}

			if (pCur == pHead)
			{
				pHead = pCur = pPre = pNext;

				if (pNext != nullptr)
				{
					pNext = pNext->next;
				}
			}
			else
			{
				pCur = pNext;
				pPre->next = pNext;
				pNext = pCur->next;
			}
		}
		else
		{
			pPre = pCur;
			pCur = pNext;
			pNext = pNext->next;
		}
	}

	return pHead;
}

//把二叉树打印成多行
class Solution36 
{
public:
    vector<vector<int>> Print(TreeNode* pRoot)
    {
        vector<vector<int>> result;

        if (pRoot == nullptr)
        {
            return result;
        }

        queue<TreeNode*> q;
        q.push(pRoot);

        while (q.empty() == false)
        {
            vector<int> res;

            int size = q.size();

            for (int i = 1; i <= size; ++i)
            {
                TreeNode* p = q.front();

                res.push_back(q.front()->val);

                if (p->left != nullptr)
                {
                    q.push(p->left);
                }

                if (p->right != nullptr)
                {
                    q.push(p->right);
                }

                q.pop();
            }

            result.push_back(res);
        }
        return result;
    }
};

//数据流中的中位数
class Solution37 
{
public:
    
    vector<int> v;

    void Insert(int num)
    {
        v.push_back(num);
    }

    double GetMedian()
    {
        sort(v.begin(), v.end());

        if (v.size() % 2 == 0)
        {
            double a = v[v.size() >> 1];
            double b = v[(v.size() >> 1) - 1];
            return (a + b) / 2;
        }
        else
        {
            return v[v.size() >> 1];
        }
    }
};

//滑动窗口的最大值
class Solution 
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> v;
        
        if(num.size()==0 || size==0 || size>num.size())
        {
            return v;
        }
        
        for (int i = 0; i <= num.size() - size; ++i)
        {
            int putnumber = 0;
            int j = 0;

            while (j < size)
            {
                putnumber = max(putnumber, num[i + j]);
                j++;
            }

            v.push_back(putnumber);
        }
        return v;
    }
};

//正则表达式匹配

//思路参考牛客网的大佬，但是学来的就是我的了
bool match(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
	{
		return true;
	}

	if (*str != '\0' && *pattern == '\0')
	{
		return false;
	}

	if (*(pattern + 1) != '*')
	{
		if (*str == *pattern || (*str != '\0' && *pattern == '.'))
		{
			return match(str + 1, pattern + 1);
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (*str == *pattern || (*str != '\0' && *pattern == '.'))
		{
			return match(str, pattern + 2) || match(str + 1, pattern);
		}
		else
		{
			return match(str, pattern + 2);
		}
	}
}

//二叉树的下一个节点

//时间复杂度O（N），空间复杂度O（N），非最优解法
void inOrder(vector<TreeLinkNode*>& res, TreeLinkNode* root)
{
	if (root != nullptr)
	{
		inOrder(res, root->left);
		res.push_back(root);
		inOrder(res, root->right);
	}
}


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	TreeLinkNode* pCur = pNode;

	while (pCur->next != nullptr)
	{
		pCur = pCur->next;
	}

	vector<TreeLinkNode*> res;
	inOrder(res, pCur);

	for (int i = 0; i < res.size(); ++i)
	{
		if (i != res.size() - 1 && res[i] == pNode)
		{
			return res[i + 1];
		}
	}
	return nullptr;
}

//之字形打印二叉树
vector<vector<int>> LevelOrder(TreeNode* root)
{
	queue<TreeNode*> q;

	vector<vector<int>> result;

	q.push(root);

	while (q.empty() == false)
	{
		vector<int> res;

		//size必须单独拿出来，因为插入之后会更改q.size()的值
		int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			res.push_back(q.front()->val);

			TreeNode* p = q.front();

			if (p->left != nullptr)
			{
				q.push(p->left);
			}

			if (p->right != nullptr)
			{
				q.push(p->right);
			}

			q.pop();
		}

		result.push_back(res);
	}
	return result;
}

vector<vector<int> > Print(TreeNode* pRoot)
{
	vector<vector<int>> res = LevelOrder(pRoot);

	for (int i = 0; i < res.size(); ++i)
	{
		if (i % 2 != 0)
		{
			reverse(res[i].begin(), res[i].end());
		}
	}

	return res;
}

//

int main()
{
	/*
	string a = "123";

	vector<string> result = Permutation(a);

	for(int i=0;i<result.size();++i)
	{
		cout<<result[i].c_str()<<endl;
	}
	*/

	/*
	Solution27 s;

	vector<vector<int>> ss=s.FindContinuousSequence(15);

	for(auto e:ss)
	{
		for(int i=0;i<e.size();++i)
		{
			cout<<e[i]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;
	*/

	// string a="luzihan";

	// Solution29 s;

	// cout<<s.LeftRotateString(a,3).c_str()<<endl;

	system("pause");
	return 0;
}