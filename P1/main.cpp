#include "src/Element.h"
#include "src/TestSetGenerator.h"
#include "src/Verifier.h"
#include "src/WeightedSelectionAlgorithm.h"
#include "src/WeightedSelectionAlgorithmBySorting.h"
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

/**
 * main.cpp 
 *
 * Hier werden verschiedene Algorithmen auf Korrektheit
 * getestet und ihr Laufzeitverhalten miteinander verglichen.
 */
int main(int argc, char *argv[]) {
  double q;      // the value of q
  int noOfRuns;  // number of runs
  int arraySize; // initial arraysize
  int steps;     // number of steps

  if (argc < 2) {
    q = 0.5;
    noOfRuns = 5;
    steps = 20;
    arraySize = 2;
  } else if (argc != 5)
  {
    std::cout << "The number of provided arguments is not correct." << std::endl;
    std::cout << "You have provided " << argc-1 << " element(s), however 4 or 0 are requested." <<  std::endl;
    return 1;
  }
  else {
    q = atof(argv[1]);
    noOfRuns = atoi(argv[2]);
    steps = atoi(argv[3]);
    arraySize = atoi(argv[4]);
  }

  TestSetGenerator generator;
  Verifier verifier;
  WeightedSelectionAlgorithm yourAlgorithm;
  WeightedSelectionAlgorithmBySorting ourAlgorithm;

  // time of our algorithm
  std::chrono::duration<float> timeslow;
  // time of your algorithm
  std::chrono::duration<float> timequick;
 
  auto start = std::chrono::system_clock::now();

  // run the tests
  for (int step = 0; step < steps; step++) {
  start = std::chrono::system_clock::now();
  timequick = std::chrono::system_clock::now()-start;
  timeslow = timequick; 
  
    for (int run = 0; run < noOfRuns; run++) {

      // generate a random test instance
      std::vector<Element> elements = generator.generate(arraySize);

      // hard copy array
      std::vector<Element> ourElements = elements;
      std::vector<Element> yourElements = elements;


      // our algorithm, compute time:
      
      start = std::chrono::system_clock::now();

      int value = ourAlgorithm.weightedSelectionAlgorithm(ourElements, q);

      timeslow += std::chrono::system_clock::now() - start;

      // verify
      assert(verifier.verify(elements, value, q));


      // your algorithm, compute time:
      
      start = std::chrono::system_clock::now();

      value = yourAlgorithm.weightedSelectionAlgorithm(yourElements, q);

      timequick += std::chrono::system_clock::now() - start;
      
      // verify: Die forlgende Zeile muss auskommentiert werden, um den neuen Algorithmus auf Korrektheit zu prüfen
      // assert(verifier.verify(elements, value, q));
    }

    std::cout << arraySize << " " << timeslow.count() / noOfRuns << "  "
              << timequick.count() / noOfRuns << std::endl;
    arraySize *= 2;
  }
  return 0;
}
