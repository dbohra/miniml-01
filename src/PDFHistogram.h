#pragma once

#include "types.h"

// ================================ Histogram PDF Class ==============================
/**
* @brief Histogram-based PDF class (1D)
* @details This class makes use of distribution histograms in order to estimate the PDF. The length of the histogram is \b length,
* thus arguments \b point of the addPoint() and getDensity() functions should be also in range [0; \b length].
* @param length The length of the histogram
*/	
class CPDFHistogram 
{
public:
	CPDFHistogram(size_t length) : m_nPoints(0), m_vHistogram(length, 0) {}
	~CPDFHistogram(void) = default;

	/**
	 * @brief Adds a sample point for PDF estimation.
	 * @param p The sample point.
	 */
	void addPoint(size_t p);
	/**
	 * @brief Returns the probability density value for the argument \b point.
	 * @param p The sample point.
	 * @returns The corresponding probaility density value.
	 */
	double getDensity(size_t p);
	/**
	 * @brief Checks weather the PDF was estimated.
	 * @retval true if at least one sample was added with the addPoint() function.
	 * @retval false otherwise
	 */
	bool isEstimated(void) const { return m_nPoints != 0; }


private:
	std::vector<long>	m_vHistogram;	///< Data
	long				m_nPoints;		///< The number of samples, added with the addPoint() function
};
