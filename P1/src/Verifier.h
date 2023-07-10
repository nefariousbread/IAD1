#include "Element.h"
#include <vector>

/**
 * This class tests the feasabilty of your solution.
 */
class Verifier {

  /**
   * This function has parameters elements, qValue (the actual weighted
   * q-percentile you computed) and the value q. It checks wether the Integer
   * qValue is the weighted q-percentile of the array elements.
   */
public:
  Verifier(){};
  virtual ~Verifier(){};

  bool verify(std::vector<Element> &elements, int qValue, double q); 
};
