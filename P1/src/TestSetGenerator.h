#include "Element.h"
#include <random>
#include <unordered_map>

/** Generates test cases for correctnes and perfomance test. */
/* Weights are chosen randomly from the set {1,...,upperBoundWeight}. */
class TestSetGenerator {

public:
  TestSetGenerator(); 

  virtual ~TestSetGenerator();

  std::mt19937 generator;      // Mersenne Twister 19937 generator
  /**
   * Generates a test cases, i.e. an array of (value, weight) pairs.
   * @param arraySize The size of the test case, i.e. the number of pairs im the
   * array.
   * @return A test case, i.e. an array of pairs with pairwise distinct values.
   */
  std::vector<Element> generate(int arraySize);

private:
  int upperBoundWeight;
};

