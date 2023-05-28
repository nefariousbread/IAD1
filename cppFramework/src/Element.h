#ifndef __ELEMENT_H__
#define __ELEMENT_H__
/**
 * Stores a pair (value, weight).
 */
class Element {

public:
  Element(int v, int w);

  virtual ~Element();

  void setWeight(int w);
  int getWeight();
  void setValue(int v);
  int getValue();

private:
  int value;
  int weight;
};

#endif
