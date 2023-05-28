#include "Element.h"
/**
 * Stores a pair (value, weight).
 */

Element::Element(int v, int w) {
  value = v;
  weight = w;
}

Element::~Element(){};

void Element::setWeight(int w) { weight = w; }

int Element::getWeight() { return weight; }

void Element::setValue(int v) { value = v; }

int Element::getValue() { return value; }
