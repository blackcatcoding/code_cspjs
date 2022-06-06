#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
    int data;
    Node* pNext;
};

Node* createList(){
    Node *s, *p, *head;
    s = new Node;
    p = NULL;
    head = new Node;
    head->pNext = NULL;
    
    cin >> s->data;

    while(s->data != 0){
        if(head->pNext == NULL) head->pNext = s;
        else p->pNext = s;

        p = s;

        s = new Node;
        cin >> s->data;
    }

    p->pNext = NULL;
    delete s;

    return head;
}

void traverseList(Node* head){
    Node* p = head->pNext;
    while(p){
        cout << p->data << " ";
        p = p->pNext;
    }
}

int main() {


    Node* head = createList();

    traverseList(head);
	
	return 0;
}

