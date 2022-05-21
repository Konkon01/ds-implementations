#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template<typename T>
class LinkedList // H1L
{
  struct Node
  {
    T value;
    Node* next;

    Node() : value()
    {
      next = nullptr;
    }
    Node(T val)
    {
      value = val;
      next = nullptr;
    }
  };

private:
  Node* head;

public:
  LinkedList() : head()
  {}

  LinkedList(T val)
  {
    head = new Node();
    Node* newNode = new Node(val);
    head->next = newNode;
  }

  void push(T value)
  {
    Node* newNode = new Node(value);
    Node* temp = head;
    
    while(temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  friend std::ostream& operator<<(std::ostream& os, const LinkedList& obj)
  {
    Node* temp = obj.head;
    temp = temp->next;
    while(temp != nullptr)
    {
      os << temp->value << " ";
      temp = temp->next;
    }
    return os;
  }

  ~LinkedList()
  {
    Node* temp = head;
    while(temp != nullptr)
    {
      Node* deletedNode = temp;
      temp = temp->next;
      delete deletedNode;
    }
  }

};

#endif