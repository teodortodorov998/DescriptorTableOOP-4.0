#include "DihotTable.h"
#include <iostream>
#include <string>

using namespace std;

int DihotTable::lexUnitsNum = 0;

DihotTable::DihotTable() {
	for (size_t i = 0; i < DisTable->newDescriptor; i++)
	{
		DisTable[i] = LexicalUnit("", "", "", 0);
	}
};
DihotTable::~DihotTable() {};


int DihotTable::BinSearch(const char* anIdentificator, int left, int right) {
	int indexKeeper;
	

	

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (strcmp(DisTable[mid].GetIdentificator(), anIdentificator) == 0) {
			indexKeeper = mid;
			cout << anIdentificator << " has been found in the table at the " << indexKeeper << " place." << endl;
			cout << endl;
			return indexKeeper;
		}
		else if (strcmp(DisTable[mid].GetIdentificator(), anIdentificator) < 0) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		
	}

	indexKeeper = -1;

	if (indexKeeper == -1)
	{
		for (size_t i = 0; i < DisTable->newDescriptor; i++)
		{
			if (strcmp(DisTable[i].GetIdentificator(), anIdentificator) > 0)
			{
				return i;
			}
		}

	}

	

	return indexKeeper;
	
}



int DihotTable::AddLexUnit(LexicalUnit& lu) {
	
	for (size_t i = 0; i < DisTable->newDescriptor; i++)
	{
		if (strcmp(DisTable[i].GetIdentificator(), lu.GetIdentificator()) == 0)
		{
			return 0;
		}
		else if(lexUnitsNum <= 2){
			DisTable[lexUnitsNum++] = lu;
			return 1;
		}
		else if(lexUnitsNum > 2){
			int index = BinSearch(lu.GetIdentificator(), 0, lexUnitsNum);
			for(size_t i = lexUnitsNum; i > index; i--)
			{
				DisTable[i] = DisTable[i - 1];
			}
			DisTable[index] = lu;

			return 1;
		}
		
	}
	
	
}

int DihotTable::Delete(const char* anIdentificator) {
	int p = BinSearch(anIdentificator, 0, lexUnitsNum);
	if (p == -1)
	{
		return 0;
	}
	for (size_t i = 0; i < DisTable->newDescriptor; i++)
	{
		if (p > -1) {
			if (strcmp(DisTable[p].GetIdentificator(), anIdentificator) == 0)
			{
				for (size_t i = p; i < lexUnitsNum; i++)
				{
					DisTable[i] = DisTable[i + 1];
				}
				DisTable[lexUnitsNum] = LexicalUnit("", "", "", 0);
				lexUnitsNum--;
				

				return 1;
			}
		}

	}
}

int DihotTable::Sort() {
	LexicalUnit temp;
	if (lexUnitsNum >= 2)
	{


		for (size_t i = 0; i < DisTable->newDescriptor; i++)
		{
			for (size_t j = 0; j < DisTable->newDescriptor - 1; j++)
			{
				if (strcmp(DisTable[j].GetIdentificator(),DisTable[j + 1].GetIdentificator()) > 0)
				{
					temp = DisTable[j];
					DisTable[j] = DisTable[j + 1];
					DisTable[j + 1] = temp;


				}
			}
		}
		return 1;
	}
	else {
		return -1;
	}
	
}

void DihotTable::PrintTable() {
	for (size_t i = 0; i < lexUnitsNum + 1; i++)
	{
		DisTable[i].Print();
	}
}