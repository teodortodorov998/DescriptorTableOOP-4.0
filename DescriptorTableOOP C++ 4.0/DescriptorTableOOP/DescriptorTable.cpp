#include "DescriptorTable.h"
#include <iostream>
#include <string.h>
#include<stdio.h>
#include <fstream>

using namespace std;

int DescriptorTable::numOfLexUnits = 0;

DescriptorTable::DescriptorTable() {
	
}

DescriptorTable::~DescriptorTable(){}

int DescriptorTable::SearchByID(char* anIdentificator) {
	for (size_t i = 0; i < Table->newDescriptor; i++)
	{
		if (strcmp(Table[i].GetIdentificator(), anIdentificator) == 0)
		{
			return i;
		}
		else {
			return -1;
		}
	}
}



int DescriptorTable::AddLexicalUnit(LexicalUnit& lu) {
	for (size_t i = 0; i < Table->newDescriptor; i++)
	{
		if (strcmp(Table[i].GetType(), lu.GetType()) == 0)
		{
			return 0;
		}
		else {
			Table[numOfLexUnits++] = lu;
			return 1;
		}
	}
	
}

char* DescriptorTable::GetIdentificator() {
	return Table[numOfLexUnits].GetIdentificator();
}

char* DescriptorTable::GetType() {
	return Table[numOfLexUnits].GetType();
}

LexicalUnit DescriptorTable::GetTable(int index) {
	return Table[index];
}

int DescriptorTable::Del(char* anIdentificator) {
	int p = SearchByID(anIdentificator);
	if (p == 0)
	{
		return 0;
	}
	for (size_t i = 0; i < Table->newDescriptor; i++)
	{
		if (strcmp(Table[i].GetIdentificator(), anIdentificator) == 0)
		{
			while (i <= numOfLexUnits) {
				Table[i++] = Table[i + 1];
				}
				
				numOfLexUnits--;
			
			return 1;
		}
		
	}
}

void DescriptorTable::Print() {
	for (size_t i = 0; i < Table->newDescriptor - 1; i++)
	{
		Table[i].Print();
	}
}