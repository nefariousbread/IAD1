#include "WeightedSelectionAlgorithm.h"
#include <vector>
#include <random>
#include <cassert>
#include <iostream>
int WeightedSelectionAlgorithm::weightedSelectionAlgorithm(std::vector<Element> &elements, double q) {
//TODO: your Algorithm implementation goes here to calculate the qValue:
  std::random_device auri;
  std::mt19937 gen(auri());
  std::uniform_int_distribution<> distr(0, elements.size()-1);
  int pivot = distr(gen); //This selects a semi-random element of elements. I have not figured out how to make it truly random.
  int qValue = elements[pivot].getValue();
  int weight = elements[pivot].getWeight();
  int lowerThanWeight = 0;
  int largerThanWeight = 0;
  int totalWeight = 0;

  std::vector<Element> smol;
  std::vector<Element> big;

  //splits up the original vector smaller and bigger Vectors and calculates the corresponding Weights
  for (int i = 0; i < elements.size(); i++) {
    if (elements[i].getValue() < qValue) {
      lowerThanWeight += elements[i].getWeight();
      smol.push_back(elements[i]);
    } else if (elements[i].getValue() > qValue) {
      big.push_back(elements[i]);
      largerThanWeight += elements[i].getWeight();
    }
  }
  totalWeight = lowerThanWeight + largerThanWeight + weight;
  //While loop ends when result is found
  while (1)
  {
    if (largerThanWeight + weight <= (1-q)*totalWeight){
      largerThanWeight += weight;
      big.clear();
      for (int i = 0; i < smol.size(); i++){
        if (smol[i].getValue() > qValue) {
          big.push_back(smol[i]);
         // std::cout << smol[i].getqValue()-value << std::endl;
          smol.erase(smol.begin()+i);//deletes the element i
          largerThanWeight += smol[i].getWeight();
          lowerThanWeight -= smol[i].getWeight();
          i--;
        }
      }
      std::uniform_int_distribution<> distr(0, smol.size()-1);
      int pivot = distr(gen);
      lowerThanWeight -= weight;
    }
    else if (lowerThanWeight + weight < q*totalWeight){
      smol.clear();
      lowerThanWeight += weight;
      for (int i = 0; i < big.size()&& i!=pivot; i++){
        if (big[i].getValue() < qValue) {
          smol.push_back(big[i]);
          //std::cout << smol[i].getqValue()-value << "i" << std::endl;
          big.erase(big.begin()+i);//deletes the element i
          largerThanWeight -= big[i].getWeight();
          lowerThanWeight += big[i].getWeight();
          i--;
        }
      }
      std::uniform_int_distribution<> distr(0, big.size()-1);
      int pivot = distr(gen);
      qValue = big[pivot].getValue();
      weight = big[pivot].getWeight();
      largerThanWeight -= weight;
    } 
    else{
      break;
    }
  }
  return qValue;
}
