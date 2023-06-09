/*
 *  CharLinkedList.h
 *  Josh Lamothe
 *  DATE CREATED
 *6/8/2022
 *  CS 15 HW 2
 *
 *  Interface to a CharLinkedList class
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H
#include <string>


class CharLinkedList {

    public:
    
        //default constructor - creates an empty list
        CharLinkedList(); 

        //constructor - creates a one element array with single character
        CharLinkedList(char c);

        //constructor - creates an array of the given size with char inside 
        CharLinkedList(char arr[], int size);

        //copy constructor- makes a deep copy of the list
        CharLinkedList(const CharLinkedList &other);

        //deconstructor - frees memory created on the heap
        ~CharLinkedList();

        //defining the assignment operator for this class
        CharLinkedList &operator=(const CharLinkedList &rhs);

        bool isEmpty() const; //returns true if the list is empty
        void clear();   //clears the char list
        int size() const;     // returns the size of the char list
        char first() const;   //returns the first element of the list
        char last() const;    //returns the last element of the list
        char elementAt(int index) const;  //returns element at specific index
        std:: string toString() const; //returns a string of the elements

        void pushAtBack(char c);  //adds new character to the back of list
        void pushAtFront(char c); //adds new character to the front of list
        void insertAt(char c, int index); //inserts char at given index
        void insertInOrder(char c); //inserts new char alphabetically
        void popFromFront(); //removes char from the front
        void popFromBack();  // removes a char from the back
        void removeAt(int index);  //removes char at given index
        void replaceAt(char c, int index);  //updates char at given index
        void concatenate(CharLinkedList *other); //combines two linked list


    private:
    
    struct Node{
        char letter;
        Node *next;
        Node *prev;
    };

    Node *m_front;
    Node *m_back;

    void memory_free();
    Node *newNode(char letter, Node *next, Node *prev);


    int list_length;
    
};   
#endif
