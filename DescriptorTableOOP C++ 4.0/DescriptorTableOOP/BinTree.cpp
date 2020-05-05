#include "BinTree.h"
#include <iostream>
#include <string>

using namespace std;

int BinTree::lexUnitNum = 0;

BinTree::BinTree() {
	root = NULL;
}

BinTree::~BinTree() {
	DestroyTree();
}



void BinTree::DestroyTree(node* leaf) {
	if (leaf != NULL)
	{
		DestroyTree(leaf->left);
		DestroyTree(leaf->right);
		delete leaf;
	}
}

void BinTree::DestroyTree() {
	DestroyTree(root);
}

void BinTree::Insert(int key, node* leaf) {
	if (key < leaf->keyValue)
	{
		if (leaf->left != NULL)
		{
			Insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->keyValue = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->keyValue)
	{
		if (leaf->right != NULL)
		{
			Insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->keyValue = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

void BinTree::Insert(LexicalUnit& lu) {
	lexUnit[lexUnitNum] = lu;
	if (root != NULL)
	{
		Insert(lexUnit[lexUnitNum].GetAddress(), root);
	}
	else {
		root = new node;
		root->keyValue = lexUnit[lexUnitNum].GetAddress();
		root->left = NULL;
		root->right = NULL;
	}
	lexUnitNum++;
}

node* BinTree::Search(int key, node* leaf) {
	if (leaf != NULL)
	{
		if (key == leaf->keyValue)
		{
			return leaf;
		}
		if (key < leaf->keyValue)
		{
			return Search(key, leaf->left);
		}
		else {
			return Search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

node* BinTree::Search(int key) {
	return Search(key, root);
}

void BinTree::Delete(int key, node* leaf) {
	
	if (root != NULL) {
		if (root->keyValue == key)
		{
			RemoveRootMatch();
		}
		else {
			if (key < leaf->keyValue && leaf->left != NULL)
			{
				if (leaf->left->keyValue == key)
				{
					RemoveMatch(leaf, leaf->left, true);
					
				}
				else {
					Delete(key, leaf->left);
				}

			}else if (key < leaf->keyValue && leaf->right != NULL)
			{
				if (leaf->right->keyValue == key)
				{
					RemoveMatch(leaf, leaf->right, false);
				}
				else {
					Delete(key, leaf->right);
				}

			}
			else {
				cout << "The key " << key << " was not found in the tree" << endl;
			}
		}

	}
	else {
		cout << "The tree is empty" << endl;
	}

	
	
}

void BinTree::Delete(int key) {
	Delete(key, root);
}

int BinTree::FindSmallest() {
	return FindSmallest(root);
}

int BinTree::FindSmallest(node* leaf) {
	if (root == NULL)
	{
		return -1;
	}
	else {
		if (leaf->left != NULL) {
			return FindSmallest(leaf->left);

		}
		else {
			return leaf->keyValue;
		}
	}
}

void BinTree::RemoveRootMatch() {
	if (root != NULL)
	{
		node* delPtr = root;
		int rootKey = root->keyValue;
		int smallestInRightSubtree;

		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		else if(root->left == NULL && root->right != NULL){
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
		}
		else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
		}
		else {
			smallestInRightSubtree = FindSmallest(root->right);
			Delete(smallestInRightSubtree, root);
			root->keyValue = smallestInRightSubtree; 
		}
	}
	else {
		cout << "Cannot remove root. The tree is empty\n";
	}

}

void BinTree::RemoveMatch(node* leaf, node* match, bool left) {
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->keyValue;
		int smallestInRightSubtree;

		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			if (left == true)
			{
				leaf->left = NULL;
			}
			else {
				leaf->right = NULL;
			}
			delete delPtr;
		}
		else if(match->left == NULL && match->right != NULL){
			if (left == true)
			{
				leaf->left = match->right;
			}
			else {
				leaf->right = match->right;
			}
			match->right = NULL;
			delPtr = match;
			delete delPtr;
		}
		else if (match->left != NULL && match->right == NULL) {
			if (left == true)
			{
				leaf->left = match->left;
			}
			else {
				leaf->right = match->left;
			}
			match->left = NULL;
			delPtr = match;
			delete delPtr;
		}
		else {
			smallestInRightSubtree = FindSmallest(match->right);
			Delete(smallestInRightSubtree, match);
			match->keyValue = smallestInRightSubtree;
		}

		
	}
	else {
		cout << "Cannot remove match. The tree is empty." << endl;
	}
}

void BinTree::Print(node* leaf) {
	if (root != NULL)
	{
		if (leaf->left != NULL)
		{
			Print(leaf->left);
		}
		if (leaf->right != NULL)
		{
			Print(leaf->right);
		}
		cout << leaf->keyValue << " - ";
		for (size_t i = 0; i < lexUnitNum; i++)
		{
			if (leaf->keyValue == lexUnit[i].GetAddress())
			{
				lexUnit[i].Print();
			}
		}
		cout << endl;
		
	}
	else {
		cout << "The tree is empty!" << endl;
	}
	
}

void BinTree::Print() {
	Print(root);
}