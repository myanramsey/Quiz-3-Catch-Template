/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    Node* q1 = head;
    Node* q3 = head; //between fast and slow
    int totalEntries = 1;
    bool superSlowIncrement = false;
    bool mediumFastIncrement = true;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        totalEntries += 2;
        if(superSlowIncrement) {
            q1 = q1->next;
            superSlowIncrement = false;
        } else {
            superSlowIncrement = true;
        }
        slow = slow->next;
        if(mediumFastIncrement) {
            q3 = q3->next->next;
            mediumFastIncrement = false;
        } else {
            q3 = q3->next;
            mediumFastIncrement = true;
        }
        fast = fast->next->next;
    }
    if(fast->next == nullptr) {
        //odd number of entries
    } else {
        //even number of entries
        totalEntries++;
    }

    float q1Value;
    float q3Value;
    if(totalEntries%2 == 0) {
        //Even Entries
        if(int(ceil(totalEntries/2.00))%2 == 0) {
            //Even Number Q1 & Q3
            q1Value = (q1->value * 1.00 + q1->next->value * 1.00) / 2;
            q3Value = (q3->value * 1.00 + q3->next->value * 1.00) / 2;
        } else {
            //Odd Number Q1 & Q3
            q1Value = q1->value;
            q3Value = q3->next->value;
        }
    } else {
        //Odd
        totalEntries--;
        if(int(ceil(totalEntries/2.00)) % 2 == 0) {
            q1Value = q1->value;
            if(totalEntries == 4) {
                q1Value = (head->next->value * 1.00 + head->value * 1.00) / 2;
                q3Value = (q3->value * 1.00 + q3->next->value * 1.00) / 2;
            } else {
                //e
                q3Value = (q3->value * 1.00 + q3->next->value * 1.00) / 2;
            }

        } else {
            //o
            q1Value = q1->value;
            q3Value = q3->value;
        }

    }
    cout << q1Value << " : " << q3Value << endl;
    return q3Value - q1Value;
}