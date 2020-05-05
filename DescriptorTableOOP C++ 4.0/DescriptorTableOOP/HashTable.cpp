#include "HashTable.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


int HashTable::desTableSize = 0;


HashTable::HashTable() {
	
	for (size_t i = 0; i < hashTableSize; i++)
	{
		hashTable[i] =  LexicalUnit("", "", "", 0);
		
	}
}


HashTable::~HashTable(){}



int HashTable::Hash(const char* key) {
	int asciiValue = 0;
	for (size_t i = 0; i < strlen(key); i++)
	{
		asciiValue += (int)key[i];
	}

	int index = asciiValue % hashTableSize;
	return index;
}

int HashTable::Collision(int index) {
	for (size_t i = index; i < hashTableSize; i++)
	{
		if (strcmp(hashTable[i].GetIdentificator(), "") == 0)
		{

			return i;
		}
	}
	for (size_t i = 0; i < index; i++)
	{
		if (strcmp(hashTable[i].GetIdentificator(), "") == 0)
		{

			return i;
		}
	}
}

int HashTable::AddLexUnit(LexicalUnit& lu) {
	int index = Hash(lu.GetIdentificator());
	int collisionIndex;

	if (strcmp(hashTable[index].GetIdentificator(), "") != 0)
	{
		collisionIndex = Collision(index);

		DescriptorTable[desTableSize] = lu;

		hashTable[collisionIndex] = DescriptorTable[desTableSize];
		desTableSize++;
		return 1;
	}
	else {
		DescriptorTable[desTableSize] = lu;

		hashTable[index] = DescriptorTable[desTableSize];

		desTableSize++;
		return 1;
	}
	
	
	return 0;
}

int HashTable::Search(const char* key) {
	int index = Hash(key);
	
		for (size_t i = index; i < hashTableSize; i++)
		{
			if (strcmp(key, hashTable[i].GetIdentificator()) == 0) {
				cout << "The lexical unit '" << key << "' was found in position " << i << " in the Hash Table." << endl;

				return i;
			}
		}

		for (size_t i = 0; i < index; i++)
		{
			if (strcmp(key, hashTable[i].GetIdentificator()) == 0) {
				cout << "The lexical unit '" << key << "' was found in position " << i << " in the Hash Table." << endl;

				return i;
			}
		}

		if (strcmp(hashTable[index].GetIdentificator(), "") == 0)
		{ 
			cout << "The lexical unit '" << key << "' should be in position " << index << " in the Hash Table." << endl;
			return index;
		}
	
}



int HashTable::Delete(const char* key) {
	int index = Search(key);

	
	hashTable[index] = LexicalUnit("", "", "", 0);
	
	cout << "The lexical unit '" << key << "' was deleted from position " << index << " in the Hash Table." << endl;

	return 1;
}

void HashTable::Print() {
	for (size_t i = 0; i < hashTableSize; i++)
	{
		
		hashTable[i].Print();
	}
}