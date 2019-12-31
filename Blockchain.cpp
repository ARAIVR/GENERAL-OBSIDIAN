#include "Blockchain.h"

//bockchain code from https://davenash.com/2017/10/build-a-blockchain-with-c/

Blockchain::Blockchain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 4;
}



void Blockchain::AddBlock(Block bNew) {
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}


Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}