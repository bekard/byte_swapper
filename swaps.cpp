#include <array>
#include <fstream>
#include <string>
#include <vector>

#include "swaps.h"

void SwapInFile(const std::string& a_strOriginalPath, const std::string& a_strCopyPath, const SwapSequence& a_Sequence)
{
	std::ifstream ifsOriginal(a_strOriginalPath, std::ios::binary);
	std::ofstream ofsCopy(a_strCopyPath, std::ios::binary);

	std::vector<char> vchInputBuffer, vchOutputBuffer;
	vchInputBuffer.resize(a_Sequence.Size());

	if(ifsOriginal.is_open() && ofsCopy.is_open()) {
		while(!ifsOriginal.eof()) {
			ifsOriginal.read(vchInputBuffer.data(), vchInputBuffer.size());
			a_Sequence.Swap(vchInputBuffer, vchOutputBuffer);
			ofsCopy.write(vchOutputBuffer.data(), vchOutputBuffer.size());
		}
	}
}
