#include "WeightedSelectionAlgorithmBySorting.h"
#include <vector>
  /**
   * Run the algorithm.
   */
int WeightedSelectionAlgorithmBySorting::weightedSelectionAlgorithm(std::vector<Element> &elements, double q) {
    // sort elements by their value
    std::sort(elements.begin(), elements.end(), ElementCompartor());

    // compute totalWeight
    int totalWeight = 0;
    for (int i = 0; i < elements.size(); i++) {
      totalWeight += elements[i].getWeight();
    }

    // find wp element in sorted array
    int lowerThanWeight = 0;
    int idx = -1;
    int pValue;

    while (lowerThanWeight < q * totalWeight) {
      idx++;
      lowerThanWeight += elements[idx].getWeight();
    }

    pValue = elements[idx].getValue();

    return pValue;
  }
