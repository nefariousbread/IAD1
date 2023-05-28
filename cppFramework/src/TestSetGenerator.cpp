#include "TestSetGenerator.h"

TestSetGenerator::TestSetGenerator() { upperBoundWeight = 100; }

TestSetGenerator::~TestSetGenerator() {}

std::vector<Element> TestSetGenerator::generate(int arraySize) {

  std::unordered_map<int, bool> valueExists;

  int upperBoundValue = 10 * arraySize;

  std::vector<Element> array;
  for (int i = 0; i < arraySize; i++) {
    std::uniform_int_distribution<int> distribution_value(1, upperBoundValue);
    int value = distribution_value(generator);

    std::uniform_int_distribution<int> distribution_weight(1, upperBoundWeight);
    int weight = distribution_weight(generator) + 1;

    if (!(valueExists.find(value) == valueExists.end())) {
      i--;
      continue;
    } else {
      Element e(value, weight);
      array.push_back(e);
      valueExists[value] = true;
    }
  }
  return array;
}
