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
    if( !isFull() )
    {
      values[top++] = newElement;
      return;
    }
    std::cout << "The Stack is full new elements can't be added!\n";
  }

  T getTop()
  {
    if( !isEmpty() )
    {
      return values[top - 1];
    }
    std::cout << "The Stack is empty!\n";
  }

  T pop()
  {
    if( isEmpty() )
    {
      std::cout << "The Stack is empty!\n";
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