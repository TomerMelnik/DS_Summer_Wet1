//
// Created by Tomer Melnik on 2021/08/23.
//

#ifndef DS_SUMMER_WET1_LINKEDLIST_H
#define DS_SUMMER_WET1_LINKEDLIST_H

#include <memory>
#include "ListNode.h"

// TODO Check all pointer allocations
/*
 * The Linked List utilises the ListNode class to supply the pointers between nodes
 *
 *  LinkedList has to handle the changes when inserting/ deleting nodes etc
 *
 *
 */

template<class T>
class LinkedList {
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;


    friend class CourseManager;
    friend class HashTable;
public:
    LinkedList();

    ~LinkedList();

    void insertFront(const T &input); //Inserts From the Front
    void insertFront(T *input);
    void insertEnd(const T &input);


    T *find( int key); //returns address to node if found, nullptr otherwise


    //void remove(const T &); //The Node is simply removed from the list, not deleted
    void insertAt(std::shared_ptr<ListNode<T>> location,
                  const T &input);  //TODO the list Does not know if the address supplied is part of the list, Up to the user to check its valid

    void removeAt(std::shared_ptr<ListNode<T>> location);
    void remove(int);

    template<class R>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<ListNode<R>> &n);


    void insertEnd(T *input);

    void insertAt(std::shared_ptr<ListNode<T>> location, T *input);
};


template<class T>
LinkedList<T>::LinkedList() {
    head = std::make_shared<ListNode<T>>();
    tail = std::make_shared<ListNode<T> >();

    head->next = tail;
    head->previous = nullptr;

    tail->next = nullptr;
    tail->previous = head;
}

template<class T>
void LinkedList<T>::insertFront(const T &input) {
    // assert(&input != NULL);

    std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(input);

    //Need to check if conversion does not cause problems

    if (head->next == tail) {
        head->next = newNode;
        tail->previous = newNode;

        newNode->next = tail;
        newNode->previous = head;

        return;
    } else {

        std::shared_ptr<ListNode<T>> temp = head->next;
        head->next = newNode;
        newNode->next = temp;

        newNode->previous = head;
        temp->previous = newNode;
    }

}

template<class T>
void LinkedList<T>::insertFront(T *input) {
    // assert(&input != NULL);

    std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(input);

    //Need to check if conversion does not cause problems

    if (head->next == tail) {
        head->next = newNode;
        tail->previous = newNode;

        newNode->next = tail;
        newNode->previous = head;

        return;
    } else {

        std::shared_ptr<ListNode<T>> temp = head->next;
        head->next = newNode;
        newNode->next = temp;

        newNode->previous = head;
        temp->previous = newNode;
    }

}

template<class T>
void LinkedList<T>::insertEnd(const T &input) {
    assert(&input != NULL);
    std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(input);
    //Need to check if conversion does not cause problems

    if (tail->previous == head) {
        head->next = newNode;
        tail->previous = newNode;

        newNode->next = tail;
        newNode->previous = head;
    } else {
        std::shared_ptr<ListNode<T>> temp = tail->previous;
        tail->previous = newNode;
        newNode->previous = temp;
        newNode->next = tail;
        temp->next = newNode;
    }

}


template<class T>
void LinkedList<T>::insertEnd(T *input) {
    assert(&input != NULL);
    std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(input);
    //Need to check if conversion does not cause problems

    if (tail->previous == head) {
        head->next = newNode;
        tail->previous = newNode;

        newNode->next = tail;
        newNode->previous = head;
    } else {
        std::shared_ptr<ListNode<T>> temp = tail->previous;
        tail->previous = newNode;
        newNode->previous = temp;
        newNode->next = tail;
        temp->next = newNode;
    }

}

/*
template<class T>
void LinkedList<T>::remove(const T &n) {
    assert(&n != NULL);
    //std::make_shared<ListNode<NodeTime>>(*time_first)
    std::shared_ptr<ListNode<T>> temp = (*find(n.id())); //O(n) where n is size of List
    if (temp == nullptr) return;
    std::shared_ptr<ListNode<T>> prevNode = temp->previous;
    std::shared_ptr<ListNode<T>> nextNode = temp->next;

    if (nextNode == tail && prevNode == head) {
        tail->previous = head;
        head->next = tail;
        return;
    }

    if (nextNode == tail) { //in case temp is the last node
        prevNode->next = tail;
        tail->previous = prevNode;
        //TODO check if syntax is right, check if removing last node from list works
        return;
    }
    if (prevNode == head) { //in case temp is the first node
        nextNode->previous = head;
        head->next = nextNode;

        return;
    }

    prevNode->next = nextNode;
    nextNode->previous = prevNode;



}
*/

template<class T>
T *LinkedList<T>::find(int key) {
    auto temp = head->next;

    while (temp != tail) {
        if (temp->data->id() == key) return temp->data;

        temp = temp->next;


    }
    return nullptr; //not found
}

template<class T>
void LinkedList<T>::insertAt(std::shared_ptr<ListNode<T>> location, const T &input) {
    assert(location != NULL);
    std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(input);
    std::shared_ptr<ListNode<T>> temp = location->next;
    location->next = newNode;
    newNode->previous = location;
    assert(temp != nullptr);
    temp->previous = newNode;
    newNode->next = temp;
}

template<class T>
void LinkedList<T>::insertAt(std::shared_ptr<ListNode<T>> location, T *input) {
    assert(location != NULL);
    std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(input);
    std::shared_ptr<ListNode<T>> temp = location->next;
    location->next = newNode;
    newNode->previous = location;
    assert(temp != nullptr);
    temp->previous = newNode;
    newNode->next = temp;
}

template<class T>
void LinkedList<T>::removeAt(std::shared_ptr<ListNode<T>> location) {

    std::shared_ptr<ListNode<T>> prevNode = location->previous;
    std::shared_ptr<ListNode<T>> nextNode = location->next;

    location->next = nullptr;
    location->previous = nullptr;

    if (nextNode == tail && prevNode == head) {
        tail->previous = head;
        head->next = tail;

        return;
    }

    if (nextNode == tail) { //in case temp is the last node
        prevNode->next = tail;
        tail->previous = prevNode;

        return;
    }
    if (prevNode == head) { //in case temp is the first node
        nextNode->previous = head;
        head->next = nextNode;
        return;
    }

    prevNode->next = nextNode;
    nextNode->previous = prevNode;

    location.reset();
}

template<class T>
void LinkedList<T>::remove(int key){
    auto temp = head->next;

    while (temp != tail) {
        if (temp != head && temp->data->id() == key) {
            break;
        }
        temp = temp->next;
    }

    if(temp != head && temp != tail)
        removeAt(temp);
}
template<class T>
LinkedList<T>::~LinkedList() {
    auto temp1 = head;

    while (temp1 != nullptr) {
        auto temp2 = temp1->next;
        temp1->previous.reset();
        //if(temp1->next != nullptr)
        //   temp1->next->previous.reset();
        temp1->next.reset();
        temp1.reset();
        temp1 = temp2;
    }
}

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<ListNode<T>> &n) {
os << "\t Head " << std::endl;
auto temp1 = n->head;

while (temp1 != nullptr) {
temp1 = temp1->next;
os << temp1->get()->data << std::endl;
os << "\t | " << std::endl;
os << "\t v " << std::endl;
}
return os;
}



#endif //DS_SUMMER_WET1_LINKEDLIST_H
