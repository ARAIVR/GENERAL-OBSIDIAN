#pragma once
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;


//code from https://davenash.com/2017/10/build-a-blockchain-with-c/

class Blockchain {
public:
	Blockchain();

	void AddBlock(Block bNew);

private:
	uint32_t _nDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock() const;
};