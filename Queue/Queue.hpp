#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template <typename T, int N>
class Queue
{
private:
  T* values;
  int firstOut;
  int length;

public:
  Queue()
  {
    values = new T[N];
    firstOut = 0;
    length = 0;
  }

  int size()
  {
    return N;
  }

  bool isEmpty()
  {
    return length == 0;
  }

  bool isFull()
  {
    return length == N;
  }

  void add( T newElement )
  {
    if( isFull() )
    { 
      throw "The Queue is full, new element can not be added!\n";
    }
    values[(firstOut + length) % N] = newElement;
    length++;
  }

  const T& first()
  {
    if( isEmpty() )
    {
      throw "Queue is empty, there is no first element!\n";
    }
    return values[firstOut];
  }

  const T remove()
  {
    if( isEmpty() )
    {
      throw "Queue is empty, there is no element to be removed!\n";
    }
    T res = values[firstOut];
    firstOut = (firstOut + 1) % N;
    length--;
    return res;
  }

  void setEmpty()
  {
    firstOut = 0;
    length = 0;
  }

  ~Queue()
  {
    delete[] values;
  }
};

#endif