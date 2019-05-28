#include "Blockchain.h"

Blockchain::Blockchain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 4;
}

void Blockchain::AddBlock(Block bNew) {
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

bool Blockchain::VerifyChain() {
	
	for (int i = 1; i < _vChain.size(); ++i) {
		if (_vChain[i].sPrevHash != _vChain[i - 1].GetHash())
			return false;
	}

	for (int i = 0; i < _vChain.size(); ++i) {
		if (!_vChain[i].VerifyBlock())
			return false;
	}
	
	return true;
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}

string Blockchain::JSonSerialize() {
	stringstream ss;
	for (int i = 0; i < _vChain.size(); ++i) {
		ss << _vChain[i].JSonSerialize() << endl;
	}

	return ss.str();
}