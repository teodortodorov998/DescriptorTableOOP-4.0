#include "LexicalUnit.h"
#include <iostream>
#include <string.h>



using namespace std;

int LexicalUnit::newAddress = 0;
int LexicalUnit::newDescriptorNum = 1;
int LexicalUnit::newDescriptor = 0;


LexicalUnit::LexicalUnit() {
	strcmp(identificator, "");
	strcmp(type, "");
	strcmp(descriptor, "");
	address = 0;
}

LexicalUnit::LexicalUnit(const char* anIdentificator, const char* aType, const char* aDescriptor, int anAdress) {
	strcpy_s(identificator, anIdentificator);
	strcpy_s(type, aType);
	strcpy_s(descriptor, aDescriptor);
	address = anAdress;

	
}

LexicalUnit::LexicalUnit(LexicalUnit& p) {
	strcpy_s(identificator, p.identificator);
	strcpy_s(type, p.type);
	strcpy_s(descriptor, p.descriptor);
	address = p.address;
}

LexicalUnit::~LexicalUnit() {}

LexicalUnit& LexicalUnit::operator = (const LexicalUnit& p) {
	strcpy_s(identificator, p.identificator);
	strcpy_s(type, p.type);
	strcpy_s(descriptor, p.descriptor);
	address = p.address;
	return *this;
}

char* LexicalUnit::GetIdentificator() {
	return identificator;
}

char* LexicalUnit::GetType() {
	return type;
}

char* LexicalUnit::GetDescriptor() {
	return descriptor;
}

int LexicalUnit::GetAddress() {
	return address;
}

int LexicalUnit::setAddress(const char* type) {
    
	int size = 0;
	address = newAddress;

		if (strcmp(type, "int") == 0)
		{
			size = 2;
			
		}
		if (strcmp(type, "char") == 0)
		{
			size = 1;
			
		}
		if (strcmp(type, "float") == 0)
		{
			size = 4;
			
		}
		if (strcmp(type, "double") == 0)
		{
			size = 8;
			
		}

	
	newAddress += size;
	return newAddress;
}



char* LexicalUnit::setDescriptor() {
	
	sprintf_s(descriptor, "V%d", newDescriptorNum);
	newDescriptorNum++;
	newDescriptor++;
	return descriptor;
}



void LexicalUnit::Print() {
	
	cout << identificator << " " << type << " " << descriptor << " " << address << endl;
	cout << endl;
}