
class LexicalUnit
{
private:
	char identificator[20];
	char type[20];
    char descriptor[10];
	int address;
	
	

public:
	LexicalUnit(const char* anIdentificator, const char* aType,const char* aDescriptor, int anAdress);
	LexicalUnit();
	LexicalUnit(LexicalUnit& p);
	~LexicalUnit();
	int setAddress(const char* type);
	char* setDescriptor();
	static int newAddress;
	static int newDescriptorNum;
	static int newDescriptor;
	LexicalUnit& operator = (const LexicalUnit& p);
	char* GetIdentificator();
	char* GetType();
	char* GetDescriptor();
	int GetAddress();
	void Print();

    
};

