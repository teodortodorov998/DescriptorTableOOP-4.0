#include <iostream>
#include "BinTree.h"
#include <string>
#include <fstream>



using namespace std;


int main(){

        LexicalUnit lu[5];

        BinTree B;
        
       
        lu[0] = LexicalUnit("i", "int", lu[0].setDescriptor(), 0);
        lu[1] = LexicalUnit("delta", "float", lu[1].setDescriptor(), lu[0].setAddress("int"));
        lu[2] = LexicalUnit("varch", "char", lu[2].setDescriptor(), lu[2].setAddress("float"));
        lu[3] = LexicalUnit("alpha", "double", lu[3].setDescriptor(), lu[3].setAddress("char"));
        lu[4] = LexicalUnit("beta", "long", lu[4].setDescriptor(), lu[4].setAddress("double"));
        
        B.Insert(lu[2]);
        B.Insert(lu[1]);
        B.Insert(lu[3]);
        B.Insert(lu[4]);
        B.Insert(lu[0]);
        B.Print();
        B.Delete(2);
        cout << "Binary tree after deletion: " << endl;
        B.Print();
        
       
        

        return 0;
}


