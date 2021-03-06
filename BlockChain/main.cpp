// BlockChain.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <cstdint>
#include "Blockchain.h"

using namespace std;

int main()
{
	Blockchain bChain = Blockchain();

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(Block(1, "Block 1 Data"));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(Block(2, "Block 2 Data"));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(Block(3, "Block 3 Data"));
	
	cout << "Blockchain valid: " << bChain.VerifyChain() << endl;

	cout << bChain.JSonSerialize();

	getchar();

	return 0;
}

