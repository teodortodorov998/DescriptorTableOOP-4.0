#include "LexicalUnit.h"

struct node{
	int keyValue;
	node* left;
	node* right;
};


class BinTree
{
private:
	static int lexUnitNum;
	LexicalUnit lexUnit[5];
	node* left;
	node* right;
	void DestroyTree(node* leaf);
	void Delete(int key, node* leaf);
	void Insert(int key, node* leaf);
	node* Search(int key, node* leaf);
	int FindSmallest(node* leaf);
	void RemoveRootMatch();
	void RemoveMatch(node* leaf, node* match, bool left);
	void Print(node* leaf);
	node* root;
public:
	BinTree();
	~BinTree();
	void Insert(LexicalUnit& lu);
	void Delete(int key);
	node* Search(int key);
	int FindSmallest();
	void DestroyTree();
	void Print();
};

