/*
* Lab 3
* Harmony Trinh and Jayne Tan
* The purpose of this lab is to implement and demonstrate link-based ADTs to store Currency objects and perform different operations on these data structures
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "queue.cpp"
using namespace std;

int main(){
    cout << "Welcome. This project uses linked lists, stacks and queues. Written by Jayne Tan and Harmony Trinh." << endl << endl;
    Currency* curr[20];
    curr[0] = new Dollar(57.12);
    curr[1] = new Dollar(23.44);
    curr[2] = new Dollar(87.43);
    curr[3] = new Dollar(68.99);
    curr[4] = new Dollar(111.22);
    curr[5] = new Dollar(44.55);
    curr[6] = new Dollar(77.77);
    curr[7] = new Dollar(18.36);
    curr[8] = new Dollar(543.21);
    curr[9] = new Dollar(20.21);
    curr[10] = new Dollar(345.67);
    curr[11] = new Dollar(36.18);
    curr[12] = new Dollar(48.48);
    curr[13] = new Dollar(101.00);
    curr[14] = new Dollar(11.00);
    curr[15] = new Dollar(21.00);
    curr[16] = new Dollar(51.00);
    curr[17] = new Dollar(1.00);
    curr[18] = new Dollar(251.00);
    curr[19] = new Dollar(151.00);

    for(int i = 0; i < 20; i++){
        cout << i + 1 << ". " ;
        curr[i]->print();
    }

    cout << endl << "Linked List:" << endl;
    SinglyLinkedList list;
    for(int i = 0; i < 7; i++){
        list.addCurrency(curr[i], 0);
    }
    cout << "Linked list after adding first 7 objects: " << endl << list.printList() << endl;
    Dollar temp(87.43);
    Dollar temp2(44.56);
    if(list.findCurrency(&temp) >= 0){
        cout << "Value found at index: " << list.findCurrency(&temp)  << endl;
    }else{
        cout << "Value does not exist in the array." << endl;
    }

    if(list.findCurrency(&temp2) >=0){
        cout << "Value found at index: " << list.findCurrency(&temp2)  << endl;
    }else{
        cout << "Value does not exist in the array." << endl;
    }
    
    Dollar removal(111.22);
    list.removeCurrency(&removal);
    list.removeCurrencyAtIndex(2);
    cout << "List after removing currencies: " << endl << list.printList() << endl;
    for(int i = 8; i <= 11; i++){
        list.addCurrency(curr[i],i % 5);
        
    }
    //cout << list.printList() << endl;
    list.removeCurrencyAtIndex(6);
    //cout << list.printList() << endl;
    list.removeCurrencyAtIndex(7);
    cout << "List after adding 4 objects and removing Currencys at index 6 & 7: " << endl << list.printList() << endl << endl;

    cout << "Stack:" << endl;
    Stack s;
    for(int i = 19; i >=13; i --){
        s.push(curr[i]);
    }
    cout << "stack after pushing 7 objects: " << endl << s.printStack() << endl << "Peek: ";
    s.peek()->print();
    //s.printStack();
    s.pop();
    s.pop();
    s.pop();
    cout << "Stack after 3 pop: " << endl << s.printStack() << endl;
    for(int i = 0; i < 5; i ++){
        s.push(curr[i]);
    }
    s.pop();
    s.pop();
    cout << "Stack after 5 push and 2 pop:" << endl << s.printStack() << endl << endl;

    cout << "Queue: " << endl;
    Queue q;
    for(int i = 0; i < 7; i++){
        q.enqueue(curr[2*i + 5]);
    }
    cout << "PeekFront: ";
    q.peekFront()->print();
    cout << "PeekRear: ";
    q.peekRear()->print();
    q.dequeue();
    q.dequeue();
    cout << "Queue after 2 dequeue: " << endl << q.printQueue() << endl;
    for(int i = 10; i < 15; i++){
        q.enqueue(curr[i]);
    }
    //cout << q.printQueue() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Queue after 3 dequeue: " << endl << q.printQueue() << endl;

    //ending message 
    cout << "Thank you :)" << endl;
};