#include "WeightedSelectionAlgorithm.h"
#include <vector>
#include <random>

int WeightedSelectionAlgorithm::weightedSelectionAlgorithm(std::vector<Element> &elements, double q) {
//TODO: your Algorithm implementation goes here to calculate the qValue:
  
  unsigned int size = elements.size();

  // pick pivot p uniformly at random
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distrib(0, size - 1);
  Element pivot = elements[distrib(generator)]; // TODO: could pre-store value & maybe weight

  // compute a and b + sum of weights of elements in a, b and total
  std::vector<Element> a, b;
  unsigned int weightSum_a = 0, weightSum_b = 0, weightSum_tot = 0;
  for (Element &e : elements) { // TODO: there might be a more efficient way to do this
    if ( e.getValue() < pivot.getValue() ) {
      a.push_back(e);
      weightSum_a += e.getWeight();
    } else if ( e.getValue() > pivot.getValue() ) {
      b.push_back(e);
      weightSum_b += e.getWeight();
    }
    weightSum_tot += e.getWeight(); // TODO: could compute at the and as sum_a + sum_b + pivot weight and * q because only used such later
  }

  if (weightSum_a > q * weightSum_tot) { // TODO: casting successfull? same down there..
    return WeightedSelectionAlgorithm::weightedSelectionAlgorithm(a, q * weightSum_tot / weightSum_a);
  }

  if (weightSum_a + pivot.getWeight() >= q * weightSum_tot) {
    return pivot.getValue();
  }

  return WeightedSelectionAlgorithm::weightedSelectionAlgorithm(b, (q * weightSum_tot - weightSum_a - pivot.getWeight()) / weightSum_b); // TODO: line shift
}
