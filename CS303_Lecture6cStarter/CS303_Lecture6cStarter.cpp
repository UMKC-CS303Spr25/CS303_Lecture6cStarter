// CS303_Lecture6cStarter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// CS303_Lecture6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "LinkedList.h"

int main()
{
    // create a doubly linked list
    // setup the initial nodes of Harry & Sam
    myList::LinkedList<int> newList;

    try {
        newList.pushBack(1);
        newList.pushBack(2);
        newList.pushBack(3);
        newList.pushBack(4);
        newList.pushFront(10);
        newList.pushFront(20);
        newList.pushFront(30);
        newList.pushFront(40);
        cout << newList.popFront() << endl;
        cout << newList.popBack() << endl;
    }
    catch (std::invalid_argument& err) {
        std::cout << "Invalid argument error caught " << err.what() << std::endl;
    }
    catch (std::runtime_error& err) {
        std::cout << "Runtime error caught " << err.what() << std::endl;
    }
    catch (...) {
        std::cout << "some other error caught\n";
    }

    //using an iterator with the doubly linked list
    myList::LinkedList<int>::iterator newListIter = newList.getHeadPtr();
    cout << "FRONT:   " << newList.back() << endl;
    cout << "BACK:    " << newList.front() << endl;
    cout << "FIND 20: " << newList.find(20) << endl;
    cout << "FIND 25: " << newList.find(25) << endl;
    if (newList.addBefore(105, 99))
        cout << "New Item Added 99\n";
    if (newList.addBefore(30, 98))
        cout << "New Item Added 98\n";
    if (newList.addBefore(3, 97))
        cout << "New Item Added: 97\n";
    if (newList.remove(20))
        cout << "Item Removed: 20\n";
    newList.insert(5, 96);

    cout << newList.printList() << endl;

    while (!(newListIter == nullptr)) {
        std::cout << *newListIter << "\n";
        newListIter++;
    }
    cout << newList.printList() << endl;
    try {
        cout << "\nUse new erase function\n";
        myList::LinkedList<int>::iterator newListIter2 = newList.getHeadPtr();
        newListIter2 = newList.erase(newListIter2);
        newListIter2++;
        newListIter2++;
        newListIter2 = newList.erase(newListIter2);
        newListIter2 = newList.getTailPtr();
        newListIter2 = newList.erase(newListIter2);
        //newList.erase(nullptr);
        cout << newList.printList() << endl;

        cout << "\nUse new insert function\n";
        myList::LinkedList<int>::iterator newListIter3 = newList.getHeadPtr();
        newList.insert(newListIter3, 111);
        newListIter3++;
        newListIter3++;
        newListIter3++;
        newList.insert(newListIter3, 555);
        newListIter3 = newList.getTailPtr();
        newList.insert(newListIter3, 888);
        newList.insert(nullptr, 999);
        cout << newList.printList() << endl;
    }
    catch (std::invalid_argument& err) {
        std::cout << "Invalid argument error caught " << err.what() << std::endl;
    }
    catch (std::runtime_error& err) {
        std::cout << "Runtime error caught " << err.what() << std::endl;
    }
    catch (...) {
        std::cout << "some other error caught\n";
    }

}