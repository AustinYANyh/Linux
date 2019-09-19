#include<iostream>
#include<queue>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template<typename T>

class RBTreeNode
{
public:
	RBTreeNode(const T& data = T(), Color color = RED) : _pLeft(nullptr), _pRight(nullptr),
		_pParent(nullptr), _data(data),
		_color(color)
	{

	}

public:
	RBTreeNode<T>* _pParent;
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	T _data;
	Color _color;
};

template<typename T>

class RBTree
{
	typedef RBTreeNode<T> pNode;

public:
	RBTree()
	{
		_pHead = new pNode;
		_pHead->_pParent = nullptr;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	bool Insert(const T& data)
	{
		pNode*& pRoot = GetRoot();

		//��������
		if (pRoot == nullptr)
		{
			pRoot = new pNode(data, BLACK);

			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}
		else
		{
			//�ǿ�������,���ն�����������ʽ
			pNode* pCur = pRoot;
			pNode* pPre = nullptr;

			while (pCur != nullptr)
			{
				pPre = pCur;

				if (pCur->_data < data)
				{
					pCur = pCur->_pRight;
				}
				else if (pCur->_data > data)
				{
					pCur = pCur->_pLeft;
				}
				else
				{
					//Լ����������ͬԪ��
					return false;
				}
			}

			pCur = new pNode(data);

			if (pPre->_data > data)
			{
				pPre->_pLeft = pCur;
			}
			else
			{
				pPre->_pRight = pCur;
			}

			pCur->_pParent = pPre;


			//����Ƿ��ƻ��˶�����������
			while (pPre != _pHead && pPre->_color == RED)
			{
				pNode* Grand = pPre->_pParent;

				//˫�����游�ڵ������
				if (pPre == Grand->_pLeft)
				{
					pNode* uncle = Grand->_pRight;

					//���һ������ڵ����,��Ϊ��
					if (uncle != nullptr && uncle->_color == RED)
					{
						//��p,u��Ϊ��,g��Ϊ��,��g����cur,�������ϵ���
						uncle->_color = BLACK;
						pPre->_color = BLACK;
						Grand->_color = RED;

						pCur = Grand;
						pPre = pCur->_pParent;
					}

					//����ڵ������Ϊ��  ||  ����ڵ㲻����
					else
					{
						//�������cur��˫�׵��Һ���,ת��Ϊ�����
						if (pCur == pPre->_pRight)
						{
							RoateL(pPre);
							swap(pPre, pCur);
						}

						//�������pre��ڣ�g���,cur��pre�����ӣ��ҵ���
						pPre->_color = BLACK;
						Grand->_color = RED;
						RoateR(Grand);
					}
				}
				//˫�����游�ڵ���Һ���
				else
				{
					pNode* uncle = Grand->_pLeft;

					//���һ������ڵ����,��Ϊ��
					if (uncle != nullptr && uncle->_color == RED)
					{
						uncle->_color = BLACK;
						pPre->_color = BLACK;
						Grand->_color = RED;

						pCur = Grand;
						pPre = pCur->_pParent;
					}
					else
					{
						//�������cur��˫�׵�����,ת��Ϊ�����
						if (pCur == pPre->_pLeft)
						{
							RoateR(pPre);
							swap(pPre, pCur);
						}

						//�������pre��ڣ�g���,cur��pre�����ӣ��ҵ���
						pPre->_color = BLACK;
						Grand->_color = RED;
						RoateL(Grand);
					}
				}
			}
		}

		pRoot->_color = BLACK;
		_pHead->_pLeft = GetLeftMost();
		_pHead->_pRight = GetRightMost();

		return true;
	}

	void InorderPrint()
	{
		_InorderPrint(GetRoot());
	}


	void levelPrint()
	{
		_levelPrint(GetRoot());
	}

private:
	pNode*& GetRoot()
	{
		return _pHead->_pParent;
	}

	//��ȡ�����ڵ�
	pNode* GetLeftMost()
	{
		pNode* pCur = GetRoot();

		if (pCur == nullptr)
		{
			return _pHead;
		}

		while (pCur->_pLeft != nullptr)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}

	//��ȡ���Ҳ�ڵ�
	pNode* GetRightMost()
	{
		pNode* pCur = GetRoot();

		if (pCur == nullptr)
		{
			return _pHead;
		}

		while (pCur->_pRight != nullptr)
		{
			pCur = pCur->_pRight;
		}
		return pCur;
	}

#if 0
	void RoateL(pNode* parent)
	{
		pNode* subR = parent->_pRight;
		pNode* subRL = subR->_pLeft;

		pNode* pParent = parent->_pParent;

		parent->_pRight = subRL;

		if (subRL != nullptr)
		{
			subRL->_pParent = parent;
		}

		subR->_pLeft = parent;
		parent->_pParent = subR;

		subR->_pParent = pParent;

		//��������
		if (pParent == _pHead)
		{
			_pHead->_pParent = subR;
		}
		else
		{
			if (pParent->_pLeft = parent)
			{
				pParent->_pLeft = subR;
			}
			else
			{
				pParent->_pRight = subR;
			}
		}
	}
#endif


	void RoateL(pNode* parent)
	{
		pNode* subR = parent->_pRight;
		pNode* subRL = subR->_pLeft;

		parent->_pRight = subRL;

		if (subRL != nullptr)
		{
			subRL->_pParent = parent;
		}

		subR->_pLeft = parent;

		pNode* pParent = parent->_pParent;

		parent->_pParent = subR;
		subR->_pParent = pParent;

		if (pParent == _pHead)
		{
			_pHead->_pParent = subR;
		}
		else
		{
			if (pParent->_pLeft == parent)
			{
				pParent->_pLeft = subR;
			}
			else
			{
				pParent->_pRight = subR;
			}
		}
	}

	void RoateR(pNode* parent)
	{
		pNode* subL = parent->_pLeft;
		pNode* subLR = subL->_pRight;

		parent->_pLeft = subLR;

		if (subLR != nullptr)
		{
			subLR->_pParent = parent;
		}

		subL->_pRight = parent;

		pNode* pParent = parent->_pParent;

		subL->_pParent = pParent;
		parent->_pParent = subL;

		if (pParent == _pHead)
		{
			_pHead->_pParent = subL;
		}
		else
		{
			if (pParent->_pLeft == parent)
			{
				pParent->_pLeft = subL;
			}
			else
			{
				pParent->_pRight = subL;
			}
		}
	}

	void _InorderPrint(pNode* root)
	{
		if (root != nullptr)
		{
			_InorderPrint(root->_pLeft);
			cout << root->_data << " ";
			_InorderPrint(root->_pRight);
		}
	}

	void _levelPrint(pNode* root)
	{
		queue<pNode*> q;
		q.push(root);

		while (q.empty()!=true)
		{
			cout << q.front()->_data << "(" << q.front()->_color << ")" << " ";

			if (q.front()->_pLeft != nullptr)
			{
				q.push(q.front()->_pLeft);
			}

			if (q.front()->_pRight != nullptr)
			{
				q.push(q.front()->_pRight);
			}

			q.pop();
		}
		cout << endl;
	}

private:
	pNode* _pHead;
};

int main()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };

	RBTree<int> rb;

	for (auto e : array)
	{
		rb.Insert(e);
	}

	rb.InorderPrint();

	cout << endl;

	rb.levelPrint();

	system("pause");
	return 0;
}