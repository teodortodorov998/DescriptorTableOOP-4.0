#include "LexicalUnit.h"


class DescriptorTable
{
private:
	LexicalUnit Table[100];
	static int numOfLexUnits;
	
public:
	DescriptorTable();
	~DescriptorTable();
	char* GetIdentificator();
	char* GetType();
	LexicalUnit GetTable(int index);
	int SearchByID(char* anIdentificator);
	int AddLexicalUnit(LexicalUnit& lu);
	int Del(char* anIdentificator);
	void Print();
};

