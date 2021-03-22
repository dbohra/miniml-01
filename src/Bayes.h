#pragma once

#include "types.h"
#include "PDFHistogram.h"

// ====================== Bayes Train Class =====================
/**
* @brief Bayes training class
* @details This class implements the <a href="http://en.wikipedia.org/wiki/Naive_Bayes_classifier" target="blank">naive Bayes classifier</a>,
* which is based on strong (naive) independence assumptions between the features.
*/
class CBayes 
{
public:
	/**
	* @brief Constructor
	* @param nStates Number of states (classes)
	* @param nFeatures Number of features
	*/
	CBayes(byte nStates, word nFeatures);
	~CBayes(void) = default;

	/**
	* @brief Adds new feature vector
	* @details Used to add a \b featureVector, corresponding to the ground-truth state (class) \b gt for training
	* @param featureVector Multi-dimensinal point: Mat(size: nFeatures x 1; type: CV_8UC1)
	* @param gt Corresponding ground-truth state (class)
	*/
	void addFeatureVec(const Mat& featureVector, byte gt);

	/**
	* @brief Returns the node potential, based on the feature vector
	* @details This function calls calculateNodePotentials() function, which should be implemented in derived classes. After that,
	* the resulting node potential is powered by parameter \b weight.
	* @param featureVector Multi-dimensinal point \f$\textbf{f}\f$: Mat(size: nFeatures x 1; type: CV_{XX}C1)
	* @return The %node potentials on success: Mat(size: nStates x 1; type: CV_32FC1);
	*/
	Mat getPotentials(const Mat& featureVector) const;

	/**
	* @brief Prints estimated prior probabilities
	*/
	void printPriorProbabilities(void);

private:
	byte										m_nStates;			///< Number of states (classes)
	word										m_nFeatures;		///< Number of features
	std::shared_ptr<CPDFHistogram>				m_pPrior;			///< The class prior probability vector
	std::vector<std::shared_ptr<CPDFHistogram>>	m_vPDF;				///< The 1D PDF for node potentials	 [state][feature]
};