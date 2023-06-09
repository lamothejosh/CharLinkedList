/*
 *  CharLinkedList.cpp
 *  Josh Lamothe
 *  DATE CREATED
 *6/9/2022
 *  CS 15 HW 2
 *
 *  Implementation of the CharLinkedList Class
 *
 */

#include "CharLinkedList.h"

#include <iostream>
#include <sstream>
using namespace std;


/*
Name: Default Constructor
Purpose: create an empty list of size and capacity 0
Parameters:none
Return Values:none 
*/
CharLinkedList::CharLinkedList()
{
    m_front = nullptr;
    m_back = nullptr;
    list_length = 0;
  
}

/*
Name: second constructor
Purpose: creates an list of capacity 1 and adds 1 character to the list
Parameters:a character for the list
Return Values:none 
*/
CharLinkedList::CharLinkedList(char c)
{
    list_length = 1;

    Node *new_node = new Node;
    new_node->letter = c;

    new_node->next = nullptr;
    new_node->prev = nullptr;

    m_front = new_node;
    m_back = new_node;

}

/*
Name:third constructor
Purpose:makes a list of the size that's given, 
that contains the characters in the given array
Parameters:an int that represents the starting length of the list and
an array of characters that will be added to the list 
Return Values:none 
*/
CharLinkedList::CharLinkedList(char arr[],int size)
{
    list_length = size;


        m_front = newNode(arr[0],nullptr, nullptr);
        Node *first_one = m_front;
        list_length = 1;

        for (int i = 1; i < size; i++)
        {
            Node *curr = newNode(arr[i], nullptr, first_one);   

            first_one->next = curr;
            first_one = curr;
            m_back = curr;

            if (i == (size - 1))
            {
                curr->next = nullptr;
            }
            list_length++;
        }

}

/*
Name:new node
Purpose:makes a new node 
Parameters: char holding the char for that node, pointer to the next and prev
Return Values: pointer to the node
*/
CharLinkedList::Node* CharLinkedList::newNode(char letter, Node *next, Node *prev)
{
    Node *new_node = new Node;
    new_node->letter = letter;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}

/*
Name:copy constructor
Purpose:makes a deep copy of the list
Parameters:a pointer to the original list that will be copied
Return Values: address of the original class
*/
CharLinkedList::CharLinkedList(const CharLinkedList &original)
{
    this->list_length = original.list_length;
    
   int len = 0;

       Node *first =  newNode(original.elementAt(0), nullptr, nullptr);
       m_front = m_back = first;
       len++;

     for (int i = 1; i < list_length; i++)
    {
        first->next =  newNode(original.elementAt(i), nullptr , first);
        first = first->next;
        len++;
    }
    this->list_length = len;
    
}

/*
Name: deconstructor
Purpose: deletes and frees up all unused memory
Parameters:none
Return Values:none
*/
CharLinkedList::~CharLinkedList()
{
    memory_free();
}

/*
Name:operator
Purpose:defines the equals operator for this class
Parameters:the address of the right hand side
Return Values:pointer to the copied version of the class
*/
CharLinkedList& CharLinkedList::operator=(const CharLinkedList &rhs)
{
    if(this == &rhs){
        return *this;
    }

    this-> clear();

    this->list_length = rhs.list_length;
    int len = 0;

    Node *first =  newNode(rhs.elementAt(0), nullptr, nullptr);
    this->m_front = first;
    len++;

    for (int i = 1; i < list_length; i++)
    {
        first->next =  newNode(rhs.elementAt(i), nullptr , first);
        first = first->next;
        len++;
    }

    this->list_length = len;

    return *this;
}

/*
Name:print
Purpose: to print out the contents and size of the array 
Parameters:none
Return Values: a string of the print statement
*/
string CharLinkedList::toString() const 
{
    string print_charlist;
    stringstream charlist;
    
    if (list_length == 0)
    {
        string empty_print = "[CharLinkedList of size 0 <<>>]";
        return empty_print;
    }

    charlist <<  m_front->letter;
    Node *mover = m_front;
    
    for (int i = 0; i < list_length - 1; i++)
    {
        mover = mover->next;
        charlist << mover->letter;
    }
    print_charlist = charlist.str();
    
    string print_statement;

    print_statement = "[CharLinkedList of size " + to_string(list_length)
                      + " <<" + print_charlist + ">>]";

    return print_statement;

}

/*
Name:size
Purpose:give the current size of the list
Parameters:none
Return Values:an int that is the current size of the list
*/
int CharLinkedList::size() const
{
    return list_length;
}

/*
Name:isEmpty
Purpose:determine whether the list is empty or not
Parameters:none 
Return Values: a bool that is true if the list is empty and false if not empty
*/
bool CharLinkedList::isEmpty() const
{
    if(list_length == 0){
        return true;
    }
    else
        return false;
}

/*
Name:first
Purpose:determine the first character in the list
Parameters:none
Return Values:a char that is the first character in the list
*/
char CharLinkedList::first() const
{

     if( isEmpty()){
        throw std::runtime_error("cannot get first of empty LinkedList");
    }

    return m_front->letter;
}

/*
Name:last
Purpose:determine the last character in the list
Parameters:none
Return Values:a char that is the last character in the list
*/
char CharLinkedList::last() const
{
    if (isEmpty())
    {
        throw std::runtime_error("cannot get last of empty LinkedList");
    }

    Node *mover = m_front;

    while (mover->next != nullptr)
    {
        mover = mover->next;
    }
    return mover->letter;
}

/*
Name:elementAt
Purpose:to determine the char at a specific index
Parameters:the index we are looking for
Return Values:a char which resides at the given index
*/
char CharLinkedList::elementAt(int index) const 
{
    if ( index < 0 or index >= list_length){
        string range_prob = "index (" + to_string(index) + 
        ") not in range [0.." + to_string(list_length) + ")";

        throw std::range_error(range_prob);
    }

    Node *mover = m_front;

    for (int i = index; i > 0; i--)
    {
        mover = mover->next;
    }

    return mover->letter;
    
}

/*
Name:pushAtFront
Purpose:add a char to the front
Parameters:the char for the front
Return Values:none
*/
void CharLinkedList::pushAtFront(char c)
{
    Node *new_front = new Node;
    new_front->letter = c;
    new_front->prev = nullptr;
    new_front->next = m_front;
    m_front = new_front;

    if (list_length == 0)
    {
        list_length++;
        return;
    }
    

    Node *before = m_front->next;
    before->prev = new_front;
    list_length++;
}

/*
Name:pushatback
Purpose:adds char to the end of the list
Parameters:the char to add
Return Values:none
*/
void CharLinkedList::pushAtBack(char c)
{
    if (list_length == 0)
    {
        Node *backs = newNode(c, nullptr, nullptr);
        m_front = backs;
        m_back = backs;
    }
    else{
        Node *backs = m_back;
        Node *newback = newNode(c, nullptr, backs);
        backs->next = newback;
        m_back = newback;
    }
    list_length++;
    
}

/*
Name:insertAt
Purpose:inserts the char at the given index
Parameters:an int- the index and a char- the one added to the given spot
Return Values:none
*/
void CharLinkedList:: insertAt(char c, int index)
{
   if ( index < 0 or index > list_length){
        string range_prob = "index (" + to_string(index) + 
        ") not in range [0.." + to_string(list_length) + "]";

        throw std::range_error(range_prob);
        }
    if (index == 0){
       pushAtFront(c);
    }

    if( index > 0 and index < list_length){
        Node *letter_node = new Node;
        letter_node->letter = c;
        Node *mover = m_front; 
        
        for(int i = 0; i < (index - 1); i++){
            mover = mover->next;
        }
        letter_node->next = mover->next;
        letter_node->prev = mover;
        mover->next = letter_node;
        list_length++;
    }
    if (index == list_length){
        pushAtBack(c);
  
    }
}

/*
Name:replaceAt
Purpose:updates the char at a given index with a new char
Parameters:an int-the index of the char, and the char to place
Return Values:none
*/
void CharLinkedList::replaceAt(char c, int index)
{
     if ( index < 0 or index > list_length){
        string range_prob = "index (" + to_string(index) + 
        ") not in range [0.." + to_string(list_length) + ")";

        throw std::range_error(range_prob);
        }

    Node *mover = m_front;
    for (int i = 0; i < index; i++)
    {
        mover = mover->next;        
    }
    mover->letter = c;
        
}

/*
Name:popFromFront
Purpose:removes the first char in the list
Parameters:none
Return Values:none
*/
void CharLinkedList::popFromFront()
{

      if (isEmpty())
    {
        throw std::runtime_error("cannot pop from empty LinkedList");
    }

    if (list_length == 1)
    {
        delete m_front;
        list_length--;
        return;
    }
    
    Node *second = m_front->next;
    delete m_front;
    m_front = second;
    second->prev =nullptr;

    list_length--;
}

/*
Name:popFromBack
Purpose:removes the last char in the list
Parameters:none
Return Values:none
*/
void CharLinkedList::popFromBack()
{
  if (isEmpty())
    {
        throw std::runtime_error("cannot pop from empty LinkedList");
    }
        if (list_length == 1)
    {
        delete m_front;
        list_length--;
        return;
    }

    Node *will_delete = m_front;

    while( will_delete->next != nullptr){
        will_delete = will_delete->next;
    }
    
    Node *new_back = will_delete->prev;
    new_back->next = nullptr;

    delete will_delete;
    will_delete = nullptr;
    list_length--;
}

/*
Name:removeAt
Purpose:removes the char at the given index
Parameters:an int- the index of the char to be removed
Return Values:none
*/
void CharLinkedList::removeAt(int index)
{
    if ( index < 0 or index >= list_length){
    string range_prob = "index (" + to_string(index) + 
    ") not in range [0.." + to_string(list_length) + ")";
    throw std::range_error(range_prob);
    }
    if(index == 0){
        popFromFront();
        return;
    }
    if (index == list_length -1 )
    {
        popFromBack();
        return;
    }
    if (index > 0 and index < (list_length - 1)){
        Node *counter = m_front;
        for (int i = 0; i < (index - 1); i++){
            counter = counter->next;
        }

        Node *deleted = counter->next;  
        Node *before = counter;
        counter = deleted->next; 
        counter->prev = before;
        before->next = counter;
        delete deleted;
        deleted = nullptr;
    }
    list_length--;
}

/*
Name:clear
Purpose:clears the list and makes it empty
Parameters:none
Return Values:none
*/
void CharLinkedList::clear()
{
    if(list_length == 0){
        return;
    }
    if (list_length != 0)
    {
        popFromBack();
    }
    clear();
    
}

/*
Name:memory clear
Purpose:clears the list and makes it empty
Parameters:none
Return Values:none
*/
void CharLinkedList::memory_free()
{
    if(list_length == 0){
        return;
    }
    if (list_length != 0)
    {
        popFromBack();
    }
    memory_free();


}

/*
Name:concatenate
Purpose:combines two list into one list
Parameters:the list being added to the original
Return Values:none
*/
void CharLinkedList::concatenate(CharLinkedList *other)
{
    int size = other->list_length;

    for (int i = 0; i < size; i++)
    {
        pushAtBack(other->elementAt(i));
    }
   
}

/*
Name:insertInOrder
Purpose:places a new char in alphabetical order
Parameters:a new char
Return Values:none
*/
void CharLinkedList::insertInOrder(char c)
{
    
    if(list_length == 0){
        pushAtFront(c);
        return;
    }
    if (c > elementAt(list_length - 1)){
        pushAtBack(c);
    }


    CharLinkedList lowercase = CharLinkedList(*this);
    Node *mover = lowercase.m_front;
    char lower_loop;

    for (int i = 0; i < list_length; i++)
    {
        lower_loop = mover->letter;
        tolower(lower_loop);
        mover->letter = lower_loop;
        if (mover->next != nullptr)
        {
            mover = mover->next;
        }
        
    }

    Node *alpha = lowercase.m_front;

    for (int i = 0; i < list_length; i++)
    {
        if (tolower(c) < alpha->letter)
        {
            this->insertAt(c,i);
            return;
        }
        if (alpha->next != nullptr)
        {
            alpha = alpha->next;
        }
        
    }
    
}
