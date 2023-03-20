#include <iostream>
using namespace std; 

template <class T>
class NumberList
{
protected:
    // Declare a class for the list node
    //template <class T>
    class ListNode
    {
    public:
       T value;
       ListNode *next;
       //ListNode *prev;
/*       ListNode(double value1, ListNode *prev1=nullptr, ListNode *next1 = nullptr)
       {
          this->value = value1;
          this->next = next1;
          this->prev = prev1;
       }  */    
       ListNode(T value1, ListNode* next1 = nullptr)
       {
           this->value = value1;
           this->next = next1;
       }
    };

    ListNode *head;                   // List head pointer
public:
    NumberList() { this->head = nullptr;  }    // Constructor
    ~NumberList();                    // Destructor
    void add(T number);
    void addSorted(T number);
    //void remove(T number);
    void displayList() const;
};

//*****************************************************
// add adds a new element to the end of the list.     *
//***************************************************** 
template <class T>
void NumberList<T>::add(T number)
{
    if (head == nullptr)
        head = new ListNode(number, nullptr);
    else
    {
        // The list is not empty
        // Use nodePtr to traverse the list
        ListNode* nodePtr = head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        // nodePtr->next is nullptr so nodePtr points to last node
        // Create a new node and put it after the last node
        nodePtr->next = new ListNode(number, nodePtr);
    }
}

//***************************************************
// displayList outputs a sequence of all values     *
// currently stored in the list.                    *
//***************************************************
template <class T>
void NumberList<T>::displayList() const
{
    ListNode* nodePtr = this->head;   // Start at head of list
    while (nodePtr)
    {
        // Print the value in the current node
        cout << nodePtr->value << "    ";
        // Move on to the next node
        nodePtr = nodePtr->next;
    }
}

//******************************************************
// Destructor deallocates the memory used by the list. *
//******************************************************
template <class T>
NumberList<T>::~NumberList()
{
    ListNode* nodePtr = this->head;  // Start at head of list
    while (nodePtr != nullptr)
    {
        // garbage keeps track of node to be deleted
        ListNode* garbage = nodePtr;
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        // Delete the "garbage" node
        delete garbage;
    }
}

template <class T>
void NumberList<T>::addSorted(T number)
{
    if (this->head == nullptr || this->head->value >= number)
    {
        this->head = new ListNode(number, this->head);
    }
    else
    {
        ListNode* nodePtr = this->head->next,
            * previousNodePtr = this->head;

        while (nodePtr != nullptr && nodePtr->value < number)
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNodePtr->next = new ListNode(number, nodePtr);
        /*ListNode* newNode = new ListNode(number, previousNodePtr, nodePtr);
        previousNodePtr->next = newNode;
        if (nodePtr != nullptr) nodePtr->prev = newNode;*/

    }
}