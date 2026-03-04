//Slow distance=x+y
//Fast distance=x+y+k.(cycle)
//x+y+k(y+z)=2(x+y)
//x+y+ky+kz=2x+2y
//k(y+z)=x+y
//distance from head to cycle start=distance from meeting point to cycle start
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next = nullptr) : data(data), next(next) {} // LL initialization
};

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}

Node *Cyclestartingpoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow=head; //step 1
            while(slow!=fast){
                slow=slow->next; //Move both pointer same speed
                fast=fast->next;
            }
            return slow; //return slow pointer
        }
    }
    return 0;
}

bool iscycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *Second = new Node(2);
    Node *Third = new Node(3);
    Node *Fourth = new Node(4);

    head->next = Second;
    Second->next = Third;
    Third->next = Fourth;
    Fourth->next = Second;

    bool cycle=iscycle(head);
    Node* node=Cyclestartingpoint(head);

    if(node!=nullptr){
        cout<<"Cycle Detected at node:"<<node->data<<endl;
    }
    else{
        cout<<"No Cycle detected";
    }
}