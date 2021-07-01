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
//三种深度优先的遍历方式：前序遍历，中序遍历，后序遍历
//前序遍历，按根，左节点，右节点的顺序遍历
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
//中序遍历，按左节点，根，右节点的顺序遍历
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
//后序遍历，按左节点， 右节点，根的顺序遍历
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


//广度优先的遍历方式：层序遍历
//用队列的先进先出的思想，先让根入队列， 然后出根时，让它的左节点和右节点入队列
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

//一棵树的节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0: BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
//一棵树的叶子节点的个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return ((root->left==NULL)&&(root->right==NULL))? 1:TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//K>0,第K层的叶子结点个数
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
//第K层节点个数
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
//查找某个元素
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

//求二叉树的最大深度
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

//判断一棵二叉树是不是完全二叉树:层序遍历，遍历入队时，子节点为空也入队，当队首元素为NULL时，判断此时队列中的元素是否全为NULL；
//原因：完全二叉树的NULL节点应该时连续存在的；
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
//二叉树销毁
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
	printf("第%d层LeafSize:%d\n", k, TreeKLevelLeafSize(na,k));
	
	BTNode* ret = TreeNodeFind(na, 'C');
	printf("%p\n", nc);
	printf("%p\n", ret); 
	printf("%d\n", BinaryTreeIsComplete);
	return 0;
}

