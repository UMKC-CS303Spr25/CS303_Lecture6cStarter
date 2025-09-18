#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace myList {
	template <typename ItemType>
	class LinkedList {

	private:
		struct DNode {
			ItemType data;
			DNode* nextPtr;
			DNode* prevPtr;

			DNode() : data(0), nextPtr(nullptr), prevPtr(nullptr) {}


			// Constructor
			DNode(const ItemType& data_item, DNode* prev, DNode* next) :
				data(data_item),
				prevPtr(prev),
				nextPtr(next) {}
		};

		DNode* head;
		DNode* tail;
		int numItems;


	public:

		class iterator {
			friend class LinkedList;

		private:
			DNode* current;			// A pointer to the current DNode 

		public:
			iterator(DNode* position) :
				current(position) {
				std::cout << "Default constructor\n";
			}

			//used for *iterator = newValue
			ItemType& operator*() const {
				std::cout << "myIterator* = newValue\n";
				if (current == nullptr)
					throw std::invalid_argument("Attempt to dereference end()");

				return current->data;
			}

			//used to get current data value:  example iterator->data()
			ItemType* operator->() const {
				std::cout << "Using myIterator->\n";
				if (current == nullptr)
					throw std::invalid_argument("Attempt to dereference end()");

				return &(current->data);
			}

			// Equality comparison
			bool operator==(const iterator& other) const {
				return current == other.current;
			}

			iterator& operator++() {
				std::cout << "prefix operator ++\n";
				if (current == nullptr)
					throw std::invalid_argument("Attempt to advance past end()");
				current = current->nextPtr;

				return *this;
			}

			iterator operator++(int) {
				std::cout << "postfix operator ++\n";
				// Make a copy of the current value.
				iterator return_value = *this; //*this returns a dereferenced pointer
				// Advance self forward.
				++(*this);
				// Return old value.
				return return_value;   // Return the value prior to increment
			}

			iterator& operator--() {
				std::cout << "postfix operator --\n";
				if (current->prevPtr == nullptr)   // no prior elements
					throw std::invalid_argument("There are no previous elements");
				else
					current = current->prevPtr;
				return *this;
			}


			iterator  operator--(int) {
				std::cout << "prefix operator --\n";
				// Make a copy of the current value.
				iterator return_value = *this;
				// Move self backward.
				if (current)
					current = current->prevPtr;
				// Return old value.
				return return_value;   // Return the value prior to decrement
			}
		};


		class constIterator {

		private:
			DNode* current;			// A pointer to the current DNode 

		public:
			constIterator(DNode* position) :
				current(position) {
				std::cout << "Default constructor\n";
			}

			//used for *iterator = newValue
			const ItemType& operator*() const {
				std::cout << "myIterator* = newValue\n";
				if (current == nullptr)
					throw std::invalid_argument("Attempt to dereference end()");

				return current->data;
			}

			//used to get current data value:  example iterator->data()
			const ItemType* operator->() const {
				std::cout << "Using myIterator->\n";
				if (current == nullptr)
					throw std::invalid_argument("Attempt to dereference end()");

				return &(current->data);
			}

			// Equality comparison
			bool operator==(const constIterator& other) const {
				return current == other.current;
			}

			constIterator& operator++() {
				std::cout << "prefix operator ++\n";
				if (current == nullptr)
					throw std::invalid_argument("Attempt to advance past end()");
				current = current->nextPtr;

				return *this;
			}

			constIterator operator++(int) {
				std::cout << "postfix operator ++\n";
				// Make a copy of the current value.
				constIterator return_value = *this; //*this returns a dereferenced pointer
				// Advance self forward.
				++(*this);
				// Return old value.
				return return_value;   // Return the value prior to increment
			}

			constIterator& operator--() {
				std::cout << "postfix operator --\n";
				if (current->prevPtr == nullptr)   // no prior elements
					throw std::invalid_argument("There are no previous elements");
				else
					current = current->prevPtr;
				return *this;
			}
			constIterator  operator--(int) {
				std::cout << "prefix operator --\n";
				// Make a copy of the current value.
				constIterator return_value = *this;
				// Move self backward.
				if (current)
					current = current->prevPtr;
				// Return old value.
				return return_value;   // Return the value prior to decrement
			}
		};

		LinkedList();
		DNode* getHeadPtr() { return head; }
		DNode* getTailPtr() { return tail; }
		iterator begin() { return head; }
		iterator end() { return tail; }
		size_t getNumItems() { return numItems; }
		bool empty() { return numItems == 0; }
		void pushBack(const ItemType& d);
		void pushFront(const ItemType& d);

		ItemType back();
		ItemType front();

		ItemType popBack();
		ItemType popFront();
		string printList() const;

		bool find(const ItemType& d);
		bool remove(const ItemType& d);

		void insert(const size_t pos, const ItemType& newValue);
		bool addBefore(const ItemType& item, const ItemType& value);

	 
 
		//PRE:  sends an iterator position
		//POST: verifies position is valid.
		//          special case 1: the list is empty – throw error
		//          special case 2: points to the end of the list – throw error
		//      if valid, saves the value, checks for special case deletion
		//	        special case 3: removes the head pointer
		//	        special case 4: removes the tail pointer
		//          ‘normal’ erase
		//       return iterator to node following ‘pos’


		iterator erase(iterator pos) {
			cout << "erase node at pos\n";
			//special case 1: the list is empty


			//special case 2: points to the end of the list


			// Create an iterator that references the position following pos.
			iterator return_value = pos;

			// Check for special cases.
			
			return return_value;
			
		}
 
		//PRE:  accepts an iterator to the location of item to insert & a value to insert
		//POST: verifies position is valid.
		//      adds list to front if pos is the head
		//      add to end of list if list is empty or position is nullptr
		//      otherise, creates the node & adjusts prev & next pointers
		//      returns iterator to new value
		iterator insert(iterator pos, const ItemType& newValue) {
			cout << "insert node in front of pos\n";

			//pos is set to headptr or list is empty


			//pos is set to nullptr


			// otherwise, creates the node & adjusts prev & next pointers
			DNode* newItem = new DNode;

			return iterator(newItem);
		}

		//PRE:  accepts an index
		//POST: verifies position is valid.
		//          special case 1: the list is empty – throw error
		//          special case 2: points to the end of the list – throw error
		//      if valid, searches for the index
		//         returns the data at that index
		ItemType operator[] (size_t n) {
			ItemType temp = 0;
			if (numItems == 0)
				throw exception("No Elements in the list\n");
			else if (n > numItems - 1)
				throw exception("Accessing out of range\n");

			size_t i = 0;
			DNode* tempPtr;
			tempPtr = head;

			while (tempPtr != nullptr) {
				if (i == n) {
					temp = tempPtr->data;
					return temp;
				}
				tempPtr = tempPtr->nextPtr;
				++i;
			}
			cout << endl;
			return temp;
		}
	};

	//default constructor
	template <typename ItemType>
	LinkedList<ItemType>::LinkedList() {
		cout << "default constructor\n";
		head = nullptr;
		tail = nullptr;
		numItems = 0;
	}
	
	//PRE:  accepts an input value
	//POST: setup the node 
	//      if list is empty, set head & tail
	//      else add to the tail
	//      increment numItems
	template <typename ItemType>
	void LinkedList<ItemType>::pushFront(const ItemType& d) {
		cout << "pushfront\n";
		DNode* newItem = new DNode;
		newItem->data = d;
		newItem->nextPtr = nullptr;
		newItem->prevPtr = nullptr;

		if (head == nullptr) {
			head = newItem;
			tail = newItem;
		}
		else {
			newItem->nextPtr = head;
			head->prevPtr = newItem;
			head = newItem;
		}
		++numItems;
	}

	//PRE:  none
	//POST: if list is empty - throw error  
	//      if not, save data from head
	//      set delNode, adjust pointers, delete delNode
	//      check for empty list
	//      decrement numItems & return saved item
	template <typename ItemType>
	ItemType LinkedList<ItemType>::popFront() {
		cout << "popfront:  ";
		if (head == nullptr) {
			throw runtime_error("No items in list");
		}

		ItemType popItem = head->data;
		DNode* delPtr = head;
		head->nextPtr->prevPtr = nullptr;
		head = head->nextPtr;
		if (head == nullptr)
			tail = nullptr;
		delete delPtr;
		delPtr = nullptr;
		--numItems;

		return popItem;
	}

	//PRE:  none
	//POST: if list is empty - throw error  
	//      if not, return data at the head
	template <typename ItemType>
	ItemType LinkedList<ItemType>::front() {
		//list is empty
		if (head == nullptr) {
			throw runtime_error("No items in list");
		}
		ItemType popItem = head->data;
		return popItem;
	}

	//YOUR TURN TASK 1: PUSHBACK
	//PRE:  accepts an input value
	//POST: if list is empty - pushFront
	//      else etup new node
	//      add to the tail
	//      adjust pointers
	//      increment numItems

	template <typename ItemType>
	void LinkedList<ItemType>::pushBack(const ItemType& d) {
		cout << "pushback\n";

		if (head == nullptr) {
			pushFront(d);
		}
		else {
			//you do this
		}
	}

	//YOUR TURN TASK 2: POPBACK
	//PRE:  none
	//POST: if list is empty - throw error  
	//      if not, save data from tail
	//      set delNode, adjust pointers, delete delNode
	//      check for empty list
	//      decrement numItems & return saved item
	template <typename ItemType>
	ItemType LinkedList<ItemType>::popBack() {
		cout << "popback:  ";
		//list is empty
		if (tail == nullptr) {
			throw invalid_argument("No items in list");
		}

		//you do this!
	}

	//PRE:  none
	//POST: if list is empty - throw error  
	//      if not, return data at the tail
	template <typename ItemType>
	ItemType LinkedList<ItemType>::back() {
		//list is empty
		if (tail == nullptr) {
			throw runtime_error("No items in list");
		}
		ItemType popItem = tail->data;
		return popItem;
	}

	//PRE:  none
	//POST: if list is empty - throw error  
	//      if not, print list using iterator
	template <typename ItemType>
	string LinkedList<ItemType>::printList() const {
		//list is empty
		if (head == nullptr) {
			throw runtime_error("No items in list");
		}
		string out = "";
		LinkedList<ItemType>::constIterator cIt = head;

		out += "printList   " + to_string(numItems) + ": { ";
		while (!(cIt == nullptr)) {
			out += to_string(*cIt) + ", ";
			++cIt;
		}
		out += " }";
		return out;
	}
	
	//PRE:  provide item to find
	//POST: if list is empty - return not found (false)  
	//      otherise walk through list to find value
	//      if found return true
	//      return false otherwise
	template <typename ItemType>
	bool LinkedList<ItemType>::find(const ItemType& d) {

		if (numItems == 0) {
			return false;
		}

		DNode* tempPtr;
		tempPtr = head;

		while (tempPtr != nullptr && tempPtr->data != d) {
			tempPtr = tempPtr->nextPtr;
		}

		if (tempPtr == nullptr || tempPtr->data != d)
			return false;
		else
			return true;
	}

	//PRE:  sends an item value from the list
	//POST: case 1: list is empty - return false
	//      case 2: found at thead of list (ajust pointers)
	//      case 3:  search the list for the first value in the list matching 'd'
	//      if found,adjust pointers,decrement numItems, return true
	//      else return false
	template <typename ItemType>
	bool LinkedList<ItemType>::remove(const ItemType& d) {

		//special case 1: the list is empty
		if (numItems == 0)
			return false;

		DNode* tempPtr;
		tempPtr = head;

		//special case 2: delete head of list
		if (tempPtr != nullptr && tempPtr->data == d) {
			head = head->nextPtr;
			head->prevPtr = nullptr;
			delete tempPtr;
			tempPtr = nullptr;
			--numItems;
			return true;
		}

		//regular case: advance through list to find matching data or end of list
		while (tempPtr != nullptr
			&& tempPtr->data != d) {
			tempPtr = tempPtr->nextPtr;
		}

		if (tempPtr != nullptr
			&& tempPtr->data == d) {   //delete the next node

			tempPtr->prevPtr->nextPtr = tempPtr->nextPtr;
			if (tempPtr->nextPtr == nullptr) {
				tail = tempPtr->prevPtr;
			}
			else {
				tempPtr->nextPtr->prevPtr = tempPtr->prevPtr;
				tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
			}
			delete tempPtr;
			--numItems;
			return true;
		}
		return false;
	}

	//TASK 3 YOUR TURN : INSERT
	//PRE:  position (index) & value
	//POST: verifies position
	//      creates a new node
	//      case 1: pos = 0 (head)
	//      case 2: pos = numItems (tail)
	//      case 3: loops to get to position
	//        sets up pointers
	//        increments numItems
	template <typename ItemType>
	void LinkedList<ItemType>::insert(const size_t pos, const ItemType& newValue) {

		//d is value at headptr or list is empty
		if (pos < 0 || pos > numItems) {
		}

		DNode* newItem = new DNode;
		newItem->data = newValue;
		newItem->nextPtr = nullptr;
		newItem->prevPtr = nullptr;
		cout << pos << " = " << numItems << endl;

		if (pos == 0) {
			pushFront(newValue);
			return;
		}
		else if (pos == numItems) {
			pushBack(newValue);
			return;
		}

		DNode* tempPtr;
		tempPtr = head;
		size_t count = 0;

		//add loop to get to item right before position
 

		//if not at the end of list and we are at the right place
		//adjust pointers
 

	}
	//TASK 4
	//PRE:  accepts 2 values (d & newValue)
	//      'd' (item that will follow newValue) & newValue
	//POST: case 1: 'd' is at the front of the list or is the head
	//      case 2: 'd' is not in the list, then add value to the end of the list
	//      case 3: find 'd' and insert value before 'd'

	template <typename ItemType>
	bool LinkedList<ItemType>::addBefore(const ItemType& d, const ItemType& value) {

		//d is value at headptr or list is empty
		if (head == nullptr || head->data == d) {
			pushFront(value);
			return true;
		}
		//if 'd' is not found - pushback
		else if (!find(d)) {
			pushBack(value);
			return true;
		}

		DNode* newItem = new DNode;
		newItem->data = value;
		newItem->nextPtr = nullptr;
		newItem->prevPtr = nullptr;

		//add before d

		DNode* tempPtr;
		tempPtr = head;

		while (tempPtr != nullptr
			&& tempPtr->nextPtr != nullptr
			&& tempPtr->nextPtr->data != d) {
			tempPtr = tempPtr->nextPtr;
		}

		if (tempPtr != nullptr
			&& tempPtr->nextPtr != nullptr
			&& tempPtr->nextPtr->data == d) {
			newItem->nextPtr = tempPtr->nextPtr;
			newItem->prevPtr = tempPtr;
			tempPtr->nextPtr->prevPtr = newItem;
			tempPtr->nextPtr = newItem;

			++numItems;
			return true;
		}
		return false;
	}


}