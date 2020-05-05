#include "LexicalUnit.h"

class DihotTable
{
private:
	LexicalUnit DisTable[4];
	static int lexUnitsNum;
public:
	DihotTable();
	~DihotTable();
	static int deleteCount;
	int Sort();
	int BinSearch(const char* anIdentificator, int l, int r);
	int AddLexUnit(LexicalUnit& lu);
	int Delete(const char* anIdentificator);
	void PrintTable();

};

