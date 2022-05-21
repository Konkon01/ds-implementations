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
  int length;

public:
  LinkedList() : head(), length(0)
  {}

  LinkedList(T val)
  {
    head = new Node();
    Node* newNode = new Node(val);
    head->next = newNode;
    length = 1;
  }

  int size()
  {
    return length;
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
    length++;
  }

  void insert(T value, int atIndex)
  {
    Node* newNode = new Node(value);
    Node* temp = head;

    while(temp->next != nullptr && atIndex > 0)
    {
      temp = temp->next;
      atIndex--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
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