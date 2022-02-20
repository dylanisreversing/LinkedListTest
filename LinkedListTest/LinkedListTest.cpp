// LinkedListTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class LinkedList
{
    class Node
    {
    public:
        int value{};
        Node* next;
        Node* prev;

        Node(int val)
        {
            this->value = val;
            this->next = NULL;
            this->prev = NULL;

        }
    };

    Node* head;
    Node* tail;

public:
    //Constructor for LinkedList
    LinkedList()
    {
        head = new Node(17);
        tail = new Node(12);
        head->next = tail;
        tail->prev = head;
    }

    void addAtTail(int value)
    {
        Node* newTail = new Node(value);
        newTail->prev = this->tail;
        this->tail->next = newTail;
        this->tail = newTail;


    }

    void addAtHead(int value)
    {
        Node* newHead = new Node(value);
        newHead->next = this->head;
        this->head->prev = newHead;
        this->head = newHead;

    }

    int get(int index)
    {
        Node* cur = head;

        for (int count{ 0 }; count < index; ++count)
        {
            cur = cur->next;
        }

        return cur->value;
    }
};

int main()
{
    LinkedList l;
    l.addAtHead(20);
    l.addAtTail(15);

    std::cout << l.get(0) << '\n';
    std::cout << l.get(1) << '\n';
    std::cout << l.get(2) << '\n';
    std::cout << l.get(3) << '\n';
    
}

