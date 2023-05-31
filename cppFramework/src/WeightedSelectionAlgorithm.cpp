#include "WeightedSelectionAlgorithm.h"
#include <vector>
#include <random>
#include <cassert>
#include <iostream>
#include <stack>
int WeightedSelectionAlgorithm::weightedSelectionAlgorithm(std::vector<Element> &elements, double q) {
//TODO: your Algorithm implementation goes here to calculate the qValue:
  int qValue = elements[0].getValue();
  int weight = elements[0].getWeight();
  int lowerThanWeight = 0;
  int largerThanWeight = 0;
  int totalWeight = 0;

  std::stack<Element> smol;
  std::stack<Element> big;
  std::stack<Element> current;

  //splits up the original vector smaller and bigger Vectors and calculates the corresponding Weights
  for (int i = 0; i < elements.size(); i++) {//going through the elements
    if (elements[i].getValue() < qValue) {
      lowerThanWeight += elements[i].getWeight();
      smol.push(elements[i]);//sorting by big and smol
    } else if (elements[i].getValue() > qValue) {
      big.push(elements[i]);
      largerThanWeight += elements[i].getWeight();
    }
  }
  totalWeight = lowerThanWeight + largerThanWeight + weight;//calculate total weight
  while (1)
  {
    if (largerThanWeight + weight <= (1-q)*totalWeight){ //Value needs to be lower
      largerThanWeight += weight;
      current.swap(smol);
      qValue = current.top().getValue();
      weight = current.top().getWeight();
      current.pop();
      while (!big.empty()){
        big.pop();
      }
      while(!current.empty()){
        if (current.top().getValue() > qValue) {
          big.push(current.top());
          largerThanWeight += current.top().getWeight();
          lowerThanWeight -= current.top().getWeight();
        }
        else{
          smol.push(current.top());
        }
        current.pop();
      }
      lowerThanWeight -= weight;
    }
    else if (lowerThanWeight + weight < q*totalWeight){ //Value needs to be higher
      lowerThanWeight += weight;
      current.swap(big);
      qValue = current.top().getValue();
      weight = current.top().getWeight();
      current.pop();
      while (!smol.empty()){
        smol.pop();
      }
      while(!current.empty()){
        if (current.top().getValue() < qValue) {
          smol.push(current.top());
          largerThanWeight -= current.top().getWeight();
          lowerThanWeight += current.top().getWeight();
        }
        else{
          big.push(current.top());
        }
        current.pop();
      }
      largerThanWeight -= weight;
    } 
    else{
      break;
    }
  } 
  return qValue;
}
