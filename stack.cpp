/*
* Lab 3
* Harmony Trinh and Jayne Tan
* The purpose of this lab is to implement and demonstrate link-based ADTs to store Currency objects and perform different operations on these data structures
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "SinglyLinkedList.cpp"
class Stack : private SinglyLinkedList{
    public:
    Stack(){

    }
    //Pre:
    //Post: nodes of a stack are cleared and deallocated through a linkedlist
    //Return:
    void createStack(){
        createList();
    }

    //Pre: Currency object to be added
    //Post: Currency object is added to the top of the stack
    //Return:
    void push(Currency* a){
        addCurrency(a, 0);
    }

    //Pre:
    //Post: a Currency object is removed from the top of the stack
    //Return: Currency object at stack index 0
    Currency* pop(){
        return removeCurrencyAtIndex(0);
    }

    //Pre:
    //Post: Currency object retrieved from top of the stack
    //Return: Currency object at the top of the stack
    Currency* peek(){
        return getCurrency(0);
    }

    //Pre:
    //Post: stack is printed
    //Return: stack is printed as a string
    std::string printStack(){
        return printList();
    }

    void destructor(){
        
    }

    ~Stack(){

    }
};
