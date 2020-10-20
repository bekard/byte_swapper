#pragma once

#include <vector>
#include <string>

class SwapSequence
{
public:
	SwapSequence(const std::vector<size_t>& a_vnSequence);

	void Swap(const std::vector<char>& a_vchBuffer, std::vector<char> & a_vchOutputBuffer) const;
	size_t Size() const;
	size_t At(size_t a_uIndex) const;

private:
	std::vector<size_t> m_vnBytesSequence;
};
