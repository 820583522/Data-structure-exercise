#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef char BTDateType;
#include<stdlib.h>

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDateType val;
}BTNode;


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

BTNode* BinaryTreeNodeCreat(BTDateType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	node->val = x;
	return node;
}

//void BinaryTreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	(*psize)++;
//	BinaryTreeSize(root->left, psize);
//	BinaryTreeSize(root->right, psize);
//}
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0: BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
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
	
	int k = 3;
	printf("TreeSize:%d\n", BinaryTreeSize(na));
	printf("LeafSize:%d\n", TreeLeafSize(na));
	printf("第%d层LeafSize:%d\n", k, TreeKLevelLeafSize(na,k));
	
	BTNode* ret = TreeNodeFind(na, 'C');
	printf("%p\n", nc);
	printf("%p\n", ret);
	return 0;
}

