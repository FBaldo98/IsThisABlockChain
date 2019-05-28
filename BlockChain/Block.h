#pragma once

#include <iostream>
#include <cstdint>
#include <time.h>
#include "nlohmann/json.hpp"

using namespace std;

class Block {
public:
	string sPrevHash;

	Block(uint32_t nIndexIn, const string &sDataIn);

	string GetHash();

	void MineBlock(uint32_t nDifficulty);

	bool VerifyBlock();

	string JSonSerialize();

private:
	uint32_t _nIndex;
	int64_t _nNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	string _CalculateHash() const;
};