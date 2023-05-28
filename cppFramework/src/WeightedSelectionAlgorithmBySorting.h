#include "Element.h"
#include <algorithm>
#include <vector>
/**
 * Slow implementation with runtime O(nlogn) (you should implement a
 * better algorithm which has a expected runtime of O(n)).
 */

// Comparator for sorting Elements
struct ElementCompartor {
  bool operator()(Element &first, Element &sec) {
    if (first.getValue() < sec.getValue())
      return true;
    else
      return false;
  }
};

class WeightedSelectionAlgorithmBySorting {

public:
  WeightedSelectionAlgorithmBySorting(){};
  virtual ~WeightedSelectionAlgorithmBySorting(){};

  /**
   * The actual Algorithm.
   */
  int weightedSelectionAlgorithm(std::vector<Element> &elements, double q);
};
