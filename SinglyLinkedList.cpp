/*
* Lab 3
* Harmony Trinh and Jayne Tan
* The purpose of this lab is to implement and demonstrate link-based ADTs to store Currency objects and perform different operations on these data structures
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "LinkNode.cpp"

class SinglyLinkedList : public LinkNode {
private:
	int count;
	LinkNode* start;
	LinkNode* end;

public:
	SinglyLinkedList() {
		count = 0;
		start = nullptr;
		end = nullptr;
	}
	~SinglyLinkedList() {
		LinkNode* current = start;
		while (current) {
			LinkNode* temp = current;
			current = current->getNext();
			delete temp;
		}
		count = 0;
		start = nullptr;
		end = nullptr;
	}
	//Pre:
	//Post: nodes of a linked list are cleared and deallocated
	//Return:
	void createList() {
		LinkNode* current = start;
		while (current) {
			LinkNode* temp = current;
			current = current->getNext();
			delete temp;
		}
		count = 0;
		start = nullptr;
		end = nullptr;
	}

	//Pre: currcny- pointer to Currency object to be added
	//     index- index of list
	//Post: a new node with a Currency object is added to a linked list at a specific index
	//Return: 
	
	void addCurrency(Currency* currncy, int index) {
		if (index<0 || index > count) {
			throw std::out_of_range("Invalid index");
		}
		LinkNode* newNode = new LinkNode(currncy);
		if (index == 0) {
			newNode->setNext(start);
			start = newNode;
			if (!end) {
				end = start;
			}
		}
		else if (index == count) {
			end->setNext(newNode);
			end = newNode;
		}
		else {
			LinkNode* current = start;
			for (int i = 0; i < index - 1; i++) {
				current = current->getNext();
			}
			newNode->setNext(current->getNext());
			current->setNext(newNode);
		}
		++count;
	}

    //Pre: currncy- pointer to Currency object
	//Post: specific Currency object is removed from the linked list, updates prev and current 
	//Return: 
	void removeCurrency(Currency* currency) {
		if (!start) {
			return;
		}
       
		if (start->getData()->isEqual(*currency)) {
			LinkNode* temp = start;
			start = start->getNext();
			if (temp == end) {
				end = start;
			}
			delete temp;
			--count;
			return;
		}
        //set current pointer to the second node
		//set the previous pointer to the first node
		LinkNode* current = start->getNext();
		LinkNode* prev = start;

        
		while (current) {
			if (current->getData()->isEqual(*currency)) {
				prev->setNext(current->getNext());
				if (current == end) {
					end = prev;
				}
				delete current;
				--count;
				return;
			}

			prev = current;
			current = current->getNext();
		}
	}
    //Pre: currncy- pointer to Currency object
	//Post: index of specific Currency object is found
	//Return: int- index of specific Currency object in the linked list or -1 if not found
	
	int findCurrency(Currency* currncy) {
		LinkNode* current = start;
		int index = 0;
		while (current) {
			if (current->getData()->isEqual(*currncy)) {
				return index;
			}
			current = current->getNext();
			++index;
		}
		return -1;
	}

    //Pre: index
	//Post: Currency object is retrieved based on specified index
	//Return: Currency object stored in the node of the specified index
	Currency* getCurrency(int index) const {
		if (index < 0 || index >= count) {
			throw std::out_of_range("Invalid index");
		}
		LinkNode* current = start;
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
		return current->getData();
	}

    //Pre:
	//Post: list is printed
	//Return: string- list is printed as a string
	std::string printList() const {
		std::string result;
		LinkNode* current = start;

		while (current) {
			Currency* currency = current->getData();
			result += std::to_string(currency->get_whole()) + ".";

			// Ensure the fraction is printed with leading zeros if needed
			if (currency->get_fraction() < 10) {
				result += "0";
			}
			result += std::to_string(currency->get_fraction());

			if (current->getNext()) {
				result += "\t";
			}

			current = current->getNext();
		}
		return result;
	}
    //Pre: 
	//Post: list is checked for if it is empty
	//Return: bool- true if list is empty and false if not empty
	bool isListEmpty() const {
		return count == 0;
	}
    //Pre:
	//Post: number of Currency nodes counted
	//Return: int- number of Curency nodes in the list
	int countCurrency() const {
		return count;
	}
    
    //Pre: Currency object retrieved based on specific index
    //Post:  Currency object is removed from the linked list at specific index
    //Return: Currency object that is stored at the specific index
    Currency* removeCurrencyAtIndex(int index){
        if(!start){
            return nullptr;
        }

        if(index == 0){
            LinkNode* temp = start;
            start = start->getNext();
            Currency *tmp_currency = temp->getData();
            delete temp;
            return tmp_currency;
        } else {
            unsigned int count = 0;
            LinkNode* prev = nullptr;
            for (LinkNode* cur = start; cur!=nullptr; cur=cur->getNext()) {
                if(count == index - 1){
                    prev = cur;
                    break;
                }
                count++;
            } 

            if(prev == nullptr || prev->getNext() == nullptr){
                return nullptr;
            }

            LinkNode* current = prev->getNext();
            Currency* temp_curr = current->getData();
            prev->setNext(current->getNext());
            delete current;
            return temp_curr;
        }
    }
};