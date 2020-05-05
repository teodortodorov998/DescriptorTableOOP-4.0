#include "LexicalUnit.h"
class HashTable
{
private:
	
	static const int hashTableSize = 128;
    static int desTableSize;
	LexicalUnit DescriptorTable[5];
	LexicalUnit hashTable[hashTableSize];
	
public:
	HashTable();
	~HashTable();
	int Hash(const char* key);
	int Collision(int index);
	int Search(const char* anIdentificator);
	int AddLexUnit(LexicalUnit& lu);
	int Delete(const char* anIdentificator);
	void Print();
};

