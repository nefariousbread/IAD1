#include "Verifier.h"
#include <iostream>
#include <vector>

  bool Verifier::verify(std::vector<Element> &elements, int qValue, double q) {
    // find this element in orginal array
    int index = -1;
    for (int i = 0; i < elements.size(); i++) {
      if (elements[i].getValue() == qValue) {
        index = i;
      }
    }
    if (index == -1) {
      std::cout << "qValue not in elements" << std::endl;
      return false;
    }

    int value = elements[index].getValue();
    int lowerThanIndexValue = 0;
    int largerThanIndexValue = 0;

    int lowerThanWeight = 0;
    int largerThanWeight = 0;

    for (int i = 0; i < elements.size(); i++) {
      if (i != index) {
        if (elements[i].getValue() < value) {
          lowerThanWeight += elements[i].getWeight();
        } else if (elements[i].getValue() > value) {
          largerThanWeight += elements[i].getWeight();
        }
      }
    }

    int totalWeight = 0;
    totalWeight += lowerThanWeight;
    totalWeight += largerThanWeight;
    totalWeight += elements[index].getWeight();

    bool isWeightedQPerzentil =
        (lowerThanWeight + elements[index].getWeight()) >= q * totalWeight;
    isWeightedQPerzentil = isWeightedQPerzentil &&
                           (largerThanWeight + elements[index].getWeight()) >
                               (1 - q) * totalWeight;

    return isWeightedQPerzentil;
  }
