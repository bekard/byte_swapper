#include <algorithm>
#include <stdexcept>
#include <string>

#include "swap_sequence.h"

SwapSequence::SwapSequence(const std::vector<size_t>& a_vnSequence)
{
	for(size_t i = 0; i < a_vnSequence.size(); ++i) {
		if (a_vnSequence.at(i) >= a_vnSequence.size()) {
			std::string strMsg("Номер " + std::to_string(i) + " байта в последовательности больше, чем общее кол-во байт в перевороте");
			throw std::logic_error(strMsg);
		}
	}
	m_vnBytesSequence = a_vnSequence;
}

void SwapSequence::Swap(const std::vector<char> & a_vchInputBuffer, std::vector<char> & a_vchOutputBuffer) const
{
	const size_t uInputBufferSize(a_vchInputBuffer.size());
	a_vchOutputBuffer.resize(uInputBufferSize);
	for(size_t uIndex = 0; uIndex < uInputBufferSize; ++uIndex) {
		const size_t uSwapIndex = At(uIndex);
		a_vchOutputBuffer.at(uSwapIndex) = a_vchInputBuffer.at(uIndex);
	}
}

size_t SwapSequence::Size() const
{
	return m_vnBytesSequence.size();
}

size_t SwapSequence::At(size_t a_uIndex) const
{
	return m_vnBytesSequence.at(a_uIndex);
}
