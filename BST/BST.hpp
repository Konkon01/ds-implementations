#ifndef BST_HPP
#define BST_HPP
#include "../Queue/Queue.hpp"

template <typename T>
class BinarySearchTree
{
  struct Node
  {
    T key;
    Node() = delete;
    Node(int value): key(value)
    {
      left = nullptr;
      right = nullptr;
    }
    Node* left;
    Node* right;
  };

private:
  Node* root;

  bool recursiveSearch( Node* &node, T value)
  {
    if( node == nullptr )
      return false;

    if( node->key == value )
      return true;

    return recursiveSearch(node->left, value) || recursiveSearch(node->right, value);
  }


  void deleteSubTree(Node* root)
  {
    if(root->left != nullptr)
      deleteSubTree(root->left);

    if(root->right != nullptr)
      deleteSubTree(root->right);

    delete root;
  }

  Node* unlinkMin(Node* &root)
  {
    Node* temp = root;
    if(root != nullptr)
    {
      Node* pre = nullptr;
      while(temp->left != nullptr)
      {
        pre = temp;
        temp = temp->left;
      }
      if(pre == nullptr)
      {
        root = root->right;
      }
      else
      {
        pre->left = temp->right;
      }
    }
    return temp;
  }

  void deleteNode(Node *&node)
  {
    Node* temp = node;
    if(node->left == nullptr)
    {
      node = node->right;
    }
    else if(node->right == nullptr)
    {
      node = node->left;
    }
    else // root->left != nullptr && root->right != nullptr
    {
      Node* replace = unlinkMin(root->right);
      replace->left = node->left;
      replace->right = node->right;
      node = replace;
    }
    
    delete temp;
  }
  void recDel(Node*&root, T value)
  {
    if(root != nullptr)
    {
      if(root->key > value)
      {
        recDel(root->left, value);
      }
      else if(root->key < value)
      {
        recDel(root->right, value);
      }
      else //root->key == value
      {
        deleteNode(root);
      }
    }
    else
    {
      throw "This value is not in the tree!\n";
    } 
  }

  void inOrder(Node* root)
  {
    if(root->left != nullptr)
      inOrder(root->left);

    std::cout << root->key << " ";

    if(root->right != nullptr)
      inOrder(root->right);
  }

  int subTreeHeight(Node* root)
  {
    if(root == nullptr)
    {
      return -1;
    }
    else
    {
      return std::max(subTreeHeight(root->left), subTreeHeight(root->right)) + 1;
    }
  }

public:
  BinarySearchTree() = delete;

  BinarySearchTree(int rootKey)
  {
    root = new Node(rootKey);
  }


  bool init( T value )
  {
    return recursiveSearch( root, value );
  }

  void push( T newValue )
  {
    Node* temp = root;
    bool found = false;
    while( !found )
    {
      if( temp->key > newValue )
      {
        if( temp->left == nullptr )
        {
          temp->left = new Node(newValue);
          found = true;
        }
        
        temp = temp->left;
      }
      else if( temp->key < newValue )
      {
        if( temp->right == nullptr )
        {
          temp->right = new Node(newValue);
          found = true;
        }
        temp = temp->right;
      }
      else if( temp->key == newValue )
      {
        throw "This value has already been added to the tree!\n";
      }
    }
  }

  void remove( T value )
  {
    recDel(root, value);
  }

  int height()
  {
    return subTreeHeight(root);
  }

  void inOrderTreeTraversal()
  {
    inOrder(root);
  }

  void levelOrderTraversal()
  {
    Queue<Node*, 10> queue;
    queue.add(root);
    while(!queue.isEmpty())
    {
      Node* e = queue.remove();
      if(e->left != nullptr)
        queue.add(e->left);

      if(e->right != nullptr)
        queue.add(e->right);

      std::cout << e->key << " ";
    }
  }

  ~BinarySearchTree()
  {
    deleteSubTree(root);
  }
};

#endif