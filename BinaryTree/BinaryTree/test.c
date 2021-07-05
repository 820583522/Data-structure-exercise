#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef char BTDateType;
#include<stdlib.h>
#include"Queue.h"
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDateType val;
}BTNode;
//����������ȵı�����ʽ��ǰ�����������������������
//ǰ���������������ڵ㣬�ҽڵ��˳�����
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//�������������ڵ㣬�����ҽڵ��˳�����
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}
//�������������ڵ㣬 �ҽڵ㣬����˳�����
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return ;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}


//������ȵı�����ʽ���������
//�ö��е��Ƚ��ȳ���˼�룬���ø�����У� Ȼ�����ʱ����������ڵ���ҽڵ������
void BinaryLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%c", front->val);
		QueuePop(&q);
		
		if (front->left)
		{
			QueuePush(&q,front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);
}
BTNode* BinaryTreeNodeCreat(BTDateType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	node->val = x;
	return node;
}

//һ�����Ľڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0: BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
//һ������Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return ((root->left==NULL)&&(root->right==NULL))? 1:TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//K>0,��K���Ҷ�ӽ�����
int TreeKLevelLeafSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return root->left == NULL&&root->left == NULL;
	}
	return TreeKLevelLeafSize(root->left, k - 1) + TreeKLevelLeafSize(root->right, k - 1);
}
//��K��ڵ����
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}
//����ĳ��Ԫ��
BTNode* TreeNodeFind(BTNode* root, BTDateType x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
	{
		return root;
	}
	BTNode* ret = TreeNodeFind(root->left, x);
	if (ret)
	{
		return ret;
	}
	else
	{
		ret = TreeNodeFind(root->right, x);
		return ret ? ret : NULL;
	}

}

//���������������
int maxDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int LeftDepth = maxDepth(root->left);
	int RightDepth = maxDepth(root->right);
	return LeftDepth > RightDepth ? LeftDepth + 1 : RightDepth + 1;
}

//�ж�һ�ö������ǲ�����ȫ������:����������������ʱ���ӽڵ�Ϊ��Ҳ��ӣ�������Ԫ��ΪNULLʱ���жϴ�ʱ�����е�Ԫ���Ƿ�ȫΪNULL��
//ԭ����ȫ��������NULL�ڵ�Ӧ��ʱ�������ڵģ�
bool BinaryTreeIsComplete(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front)
			return false;
	}
	QueueDestroy(&q);
	return true;
}
//�жϵ�ֵ������
bool isUnivalTree(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->left&&root->left->val != root->val)
	{
		return false;
	}
	if (root->right&&root->right->val != root->val)
	{
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);

}
//��ת������
BTNode* invertTree(BTNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	BTNode* LefttTree = root->left;
	BTNode** RightTree = root->right;
	root->left = RightTree;
	root->right = LefttTree;
	invertTree(LefttTree);
	invertTree(RightTree);
	return root;
}

//��������ǰ���������������malloc���ٵ�������
void _preorder(BTNode* root, int* arr, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	arr[(*pi)++] = root->val;

	_preorder(root->left, arr, pi);
	_preorder(root->right, arr, pi);
}
int* preorderTraversal(BTNode* root, int* returnSize)
{
	*returnSize = BinaryTreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	_preorder(root, arr, &i);
	return arr;
}

//�ж��������Ƿ���ͬ
bool isSameTree(BTNode* p, BTNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

//�ж�һ����subRoot�Ƿ�����һ����root������
bool isSubtree(BTNode* root, BTNode* subRoot)
{
	if (root == NULL)
	{
		return false;
	}
	if (isSameTree(root, subRoot))
	{
		return true;
	}
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}


//�ж�һ���������ǲ��ǶԳƶ�����
bool _isSymmetric(BTNode* n1, BTNode* n2)
{
	if (n1 == NULL&&n2 == NULL)
	{
		return true;
	}
	if (n1 == NULL || n2 == NULL)
	{
		return false;
	}
	if (n1->val != n2->val)
	{
		return false;
	}
	return _isSymmetric(n1->left, n2->right) && _isSymmetric(n1->right, n2->left);
}
bool isSymmetric(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}

	return _isSymmetric(root->left, root->right);
}
//�ж�һ�����ǲ���ƽ���������ÿ���ڵ���������������ĸ߶Ȳ������1��ʱ�临�Ӷ�O��n�����ú��������������Ľڵ㿪ʼ��飬���������ĸ߶ȸ����׽ڵ�
bool _isBalanced(BTNode* root, int* ph)
{
	if (root == NULL)
	{
		*ph = 0;
		return true;
	}
	int leftHight = 0;
	if (_isBalanced(root->left, &leftHight) == false)
	{
		return false;
	}
	int rightHight = 0;
	if (_isBalanced(root->right, &rightHight) == false)
	{
		return false;
	}
	*ph = fmax(leftHight, rightHight) + 1;
	return abs(leftHight - rightHight)<2;
}
bool isBalanced(BTNode* root)
{
	int hight = 0;
	return _isBalanced(root, &hight);
}


//����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
int main()
{
	BTNode* na = BinaryTreeNodeCreat('A');
	BTNode* nb = BinaryTreeNodeCreat('B');
	BTNode* nc = BinaryTreeNodeCreat('C');
	BTNode* nd = BinaryTreeNodeCreat('D');
	BTNode* ne = BinaryTreeNodeCreat('E');
	BTNode* nf = BinaryTreeNodeCreat('F');

	na->left = nb;
	na->right = nc;
	nb->left = nd;
	nc->left = ne;
	nc->right = nf;

	BTNode prev = *na;
	na=invertTree(na);
	BinaryLevelOrder(&prev);
	printf("\n");
	BinaryLevelOrder(na);
	printf("\n");
	/*PrevOrder(na);
	printf("\n");
	InOrder(na);
	printf("\n");
	PostOrder(na);
	printf("\n");
	BinaryLevelOrder(na);
	printf("\n");*/
	
	int k = 3;
	printf("TreeSize:%d\n", BinaryTreeSize(na));
	printf("LeafSize:%d\n", TreeLeafSize(na));
	printf("��%d��LeafSize:%d\n", k, TreeKLevelLeafSize(na,k));
	
	BTNode* ret = TreeNodeFind(na, 'C');
	printf("%p\n", nc);
	printf("%p\n", ret); 
	printf("%d\n", BinaryTreeIsComplete);
	return 0;
}

