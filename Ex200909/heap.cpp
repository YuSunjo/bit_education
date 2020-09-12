//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//HANDLE hHeap = NULL;
//
//typedef int element;
//
//typedef struct TreeNode {
//	element data;
//	struct TreeNode* leftNode;
//	struct TreeNode* rightNode;
//}TreeNode;
//
//typedef struct {
//	TreeNode* root;
//}TreeType;
//
//
//void InitTree(TreeType* t)
//{
//	t->root = NULL;
//}
//
//TreeType* CreateTree(void)
//{
//	TreeType* t = (TreeType*)HeapAlloc(hHeap, 0, sizeof(TreeType));
//	//TreeType* t = (TreeType*)malloc(sizeof(TreeType));
//	return t;
//}
//
//void Error(char* s)
//{
//	printf("---<%s>---\n", s);
//}
//
//
//TreeNode* MakeNode(TreeNode* left, element item, TreeNode* right)
//{
//	TreeNode* newNode = (TreeNode*)HeapAlloc(hHeap, 0, sizeof(TreeNode));
//	//TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//	if (newNode != NULL)
//	{
//		newNode->leftNode = left;
//		newNode->rightNode = right;
//		newNode->data = item;
//	}
//	return newNode;
//}
//
//void SetRoot(TreeType* t, TreeNode* n)
//{
//	t->root = n;
//}
//
//TreeNode* GetRoot(TreeType* t)
//{
//	return t->root;
//}
//
//TreeNode* InsertLeft(TreeNode* parent, element item)
//{
//	parent->leftNode = MakeNode(NULL, item, NULL);
//	return parent->leftNode;
//}
//
//TreeNode* InsertRight(TreeNode* parent, element item)
//{
//	parent->rightNode = MakeNode(NULL, item, NULL);
//	return parent->rightNode;
//}
//
//TreeNode* GetLeft(TreeNode* parent)
//{
//	return parent->leftNode;
//}
//
//TreeNode* GetRight(TreeNode* parent)
//{
//	return parent->rightNode;
//}
//
//element GetData(TreeNode* node)
//{
//	return node->data;
//}
//
//void SetLeft(TreeNode* parent, TreeNode* child)
//{
//	parent->leftNode = child;
//}
//
//void SetRight(TreeNode* parent, TreeNode* child)
//{
//	parent->rightNode = child;
//}
//
//void traversalPreorder(TreeNode* node)
//{
//	printf("%d->", GetData(node));
//	if (GetLeft(node) != NULL)
//		traversalPreorder(GetLeft(node));
//
//	if (GetRight(node) != NULL)
//		traversalPreorder(GetRight(node));
//}
//
//void traversalPostorder(TreeNode* node)
//{
//	if (GetLeft(node) != NULL)
//		traversalPostorder(GetLeft(node));
//
//	if (GetRight(node) != NULL)
//		traversalPostorder(GetRight(node));
//	printf("%d->", GetData(node));
//}
//
//void traversalInorder(TreeNode* node)
//{
//	if (GetLeft(node) != NULL)
//		traversalInorder(GetLeft(node));
//
//	printf("%d->", GetData(node));
//
//	if (GetRight(node) != NULL)
//		traversalInorder(GetRight(node));
//
//}
//
////void DeleteAllNodes(TreeNode* node)
////{
////	if (GetLeft(node) != NULL)
////		DeleteAllNodes(GetLeft(node));
////
////	if (GetRight(node) != NULL)
////		DeleteAllNodes(GetRight(node));
////
////	printf("free: %d\n", GetData(node));
////	free(node);
////}
//
//
//int main(void)
//{
//	hHeap = HeapCreate(HEAP_NO_SERIALIZE, 1024, 0);
//
//	TreeType* tree = CreateTree();
//	InitTree(tree);
//
//	SetRoot(tree, MakeNode(NULL, 10, NULL));
//	TreeNode* node20 = InsertLeft(GetRoot(tree), 20);
//	TreeNode* node30 = InsertRight(GetRoot(tree), 30);
//	TreeNode* node40 = InsertLeft(node20, 40);
//	TreeNode* node50 = InsertRight(node20, 50);
//	TreeNode* node60 = InsertLeft(node30, 60);
//	TreeNode* node70 = InsertRight(node30, 70);
//
//	traversalPreorder(GetRoot(tree));
//	printf("\n");
//
//	traversalPostorder(GetRoot(tree));
//	printf("\n");
//
//	traversalInorder(GetRoot(tree));
//	printf("\n");
//
//	/*DeleteAllNodes(GetRoot(tree));
//	free(tree);*/
//
//	HeapDestroy(hHeap);
//	return 0;
//}