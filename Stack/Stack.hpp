#ifndef STACK_HPP
#define STACK_HPP

template<typename T, int N>
class Stack
{
private:
  T* values;
  unsigned int top;
public:
  Stack()
  {
  values = new T[N];
  top = 0;
  }

  int size()
  {
    return N;
  }

  bool isFull()
  {
    return top == N;
  }

  bool isEmpty()
  {
    return top == 0;
  }

  void push( T newElement )
  {
    if( isFull() )
    {
      throw "The Stack is full new elements can't be added!\n";
    }
    values[top++] = newElement;
  }

  T getTop()
  {
    if( isEmpty() )
    {
      throw "The Stack is empty, there is no top element!\n";
    }
    return values[top - 1];
  }

  T pop()
  {
    if( isEmpty() )
    {
      throw "The Stack is empty, there is no element to be popped!\n";
    }
    return values[--top];
  }

  void setEmpty()
  {
    top = 0;
  }

  ~Stack()
  {
    delete[] values;
  }
};



#endif