#include "PDFHistogram.h"

void CPDFHistogram::addPoint(size_t p)
{
	size_t i = MIN(m_vHistogram.size() - 1, p);
	m_vHistogram[i]++;
	m_nPoints++;
}

double CPDFHistogram::getDensity(size_t p)
{
	size_t i = MIN(m_vHistogram.size() - 1, p);
	return m_nPoints ? static_cast<double>(m_vHistogram[i]) / m_nPoints : 0;
}