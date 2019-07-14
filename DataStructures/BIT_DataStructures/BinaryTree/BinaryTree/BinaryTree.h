#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#ifndef _BINARYTREE_H_

#define _BINARYTREE_H_

#define BTREE_END '#'
#define BTREE_PRINT(data) printf("%c ", (data))
typedef char BTDataType;

// 三叉链 
typedef struct BinaryTreeNode 
{    
	struct BinTreeNode* _pParent; // 指向当前节点的双亲    
	struct BinTreeNode* _pLeft;   // 指向当前节点左孩子    
	struct BinTreeNode* _pRight; // 指向当前节点右孩子    
	BTDataType _data; // 当前节点值域 
}BTNode;
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi, BTNode* parent); //二叉树的建立
void BinaryTreeDestory(BTNode** root); //二叉树的销毁

int BinaryTreeSize(BTNode* root); //二叉树的结点数
int BinaryTreeLeafSize(BTNode* root); //二叉树的叶子结点数
int BinaryTreeLevelKSize(BTNode* root, int k); //二叉树在指定层的结点数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x); //查找指定数据

// 遍历 
void BinaryTreePrevOrder(BTNode* root); 
void BinaryTreeInOrder(BTNode* root); 
void BinaryTreePostOrder(BTNode* root);

// 非递归遍历 // 层序遍历 
void BinaryTreeLevelOrder(BTNode* root); 
// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root); 
void BinaryTreeInOrderNonR(BTNode* root); 
void BinaryTreePostOrderNonR(BTNode* root);

void BinaryTreePrint(BTNode* root);

void TestBinaryTree();

#endif //_BINARYTREE_H_