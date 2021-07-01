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

	PrevOrder(na);
	printf("\n");
	InOrder(na);
	printf("\n");
	PostOrder(na);
	printf("\n");
	BinaryLevelOrder(na);
	printf("\n");
	
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

