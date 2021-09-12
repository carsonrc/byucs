//
// Created by carso on 7/8/2021.
//

#ifndef LAB3LINKEDLIST_LINKEDLIST_H
#define LAB3LINKEDLIST_LINKEDLIST_H
#include "LinkedListInterface.h"
using namespace std;

template <typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& d, Node* n) : data(d), next(n) {}
    };
    Node* head = NULL;
public:

    class Iterator
    {
    private:
        Node* nodePtr;
    public:
        Iterator(Node* np) : nodePtr(np) {}
        ~Iterator() = default;

        bool operator!=(const Iterator& rhs)
        { return this->nodePtr != rhs.nodePtr; }
        bool operator==(const Iterator& rhs)
        {return this->nodePtr == rhs.nodePtr;}
        T& operator*()
        { return nodePtr->data; }
        Iterator& operator++()
        { this->nodePtr = this->nodePtr->next; return *this; }
        Node* getPtr()
        {return nodePtr;}


    };



    Iterator begin() { return Iterator(this->head); }
    Iterator end() { return Iterator(NULL); }


    Iterator find (Iterator first, Iterator last, const T& value)
    {
        Iterator foundIter = NULL;
        while (first != last)
        {
            if (*first == value)
            {
                foundIter = first;
                break;
            }
            ++first;
        }
        return foundIter;
    }

    Iterator insert(Iterator position, const T& value)
    {
        Node* newNode = new Node(value, position.getPtr());

        Iterator previousNode(begin());
        while (previousNode.getPtr()->next != position.getPtr())
        {
            if (position == begin()) {break;}
            else {++previousNode;}
        }
        previousNode.getPtr()->next = newNode;

        return Iterator(newNode);
    }

    Iterator insert_after(Iterator position, const T& value)
    {
        if (position == end()) {return insert(position,value);}
        else { return insert(++position,value);}
    }

    Iterator erase(Iterator position)
    {
        if (position == head)
        {
            pop_front();
            return Iterator(head);
        }
        else if (position == NULL)
        {
            throw string(" Not Found");
        }
        else
        {
            Iterator previousNode(begin());
            while (previousNode.getPtr()->next != position.getPtr()) {++previousNode;}
            previousNode.getPtr()->next = position.getPtr()->next;
            delete position.getPtr();
            return Iterator(++previousNode);
        }
    }

    void replace(Iterator first, Iterator last, const T& old_value, const T& new_value)
    {
        if (old_value == new_value) {return;}
        if (old_value == head->data)
        {
            while (head->data == old_value)
            {
                pop_front();
                insert(Iterator(head->next), new_value);
            }
        }
        while (find(begin(),end(),old_value) != NULL)
        {
            Iterator position = find(begin(),end(), old_value);
            insert(position, new_value);
            erase(position);
        }
    }

    Node* getHead() {return head;}



//end of new stuff =====================================================================================================
    LinkedList(): head(NULL) {}
    ~LinkedList() {clear();}


    /** Insert Node(value) at beginning of linked list */
    void push_front(const T& value)
    {
        Node* newNode = new Node(value, head);
        head = newNode;
    }

    /** Remove Node at beginning of linked list */
    void pop_front()
    {
        Node* headHolder = head->next;
        delete head;
        head = headHolder;

    }

    /** Return reference to value of Node at beginning of linked list */
    T& front()
    {
        return head->data;
    }

    /** Return true if linked list size == 0 */
    bool empty() const
    {
        if (head == NULL)
        {
            return true;
        }
        else return false;
    }

    /** Remove all Nodes with value from linked list */
    void remove(const T& value)
    {
        for (Node *p = head, *q = NULL; p; q = p, p = p->next) // p leads, q trails
            if (p->data == value)
            {
                if (q)
                {
                    q->next = p->next;
                }
                else{
                    head = p->next;
                    delete (p);
                    return;
                }
            }
    }

    /** Remove all Nodes from linked list */
    void clear()
    {
        Node* node_ptr;
        Node* next_node;
        for (node_ptr = head; node_ptr; node_ptr = next_node)
        {
            next_node = node_ptr->next;
            delete node_ptr;
        }
        head = NULL;
    }

    /** Reverse Nodes in linked list */
    void reverse()
    {
        Node* previousNode = NULL;
        Node* currentNode = head;
        Node* nextNode = head;

        while (currentNode != NULL)
        {
            nextNode = nextNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        head = previousNode;
    }

    /** Return the number of nodes in the linked list */
    size_t size() const
    {
        Node* node_ptr = head;
        size_t numberOfNodes = 0;
        while (node_ptr != NULL)
        {
            node_ptr = node_ptr->next;
            numberOfNodes++;
        }
        return numberOfNodes;
    }

    /** Return contents of Linked List as a string */
    string toString() const
    {
        string wholeList;
        Node *node_ptr = head;
        while (node_ptr != NULL)
        {
            wholeList.append(node_ptr->data + " ");
            node_ptr = node_ptr->next;
        }
        if (head == NULL) {wholeList = "Empty!";}
        return wholeList;
    }


};
#endif //LAB3LINKEDLIST_LINKEDLIST_H
