#pragma once

#include <cstdint>
#include <vector>
#include "Block.h"
#include <sstream>

using namespace std;

class Blockchain {
public:
	Blockchain();

	void AddBlock(Block bNew);

	bool VerifyChain();

	string JSonSerialize();

private:
	uint32_t _nDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock() const;
};