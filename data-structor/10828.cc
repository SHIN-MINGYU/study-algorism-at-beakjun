#include <iostream>
using namespace std;

class Node{
    public:
        Node();
        Node(int value, Node* nextNode);
        void setNextNode(Node* nextNode);
        Node* getNextNode();
        int getValue();
  private:
    int value;
    Node* nextNode;
};
Node::Node(){
}
Node::Node(int value, Node* nextNode){
    this->value = value;
    this->nextNode= nextNode;
}

void Node::setNextNode(Node* nextNode){
    this->nextNode = nextNode;
}

Node* Node::getNextNode(){
    return this->nextNode;
}

int Node::getValue(){
    return this->value;
}

class Stack{
    public:
        void push(int value);
        int pop();
        int size();
        bool empty();
        int top();
        Stack();
        Node* headerNode;
    private:    

        Node* tailNode;
};

Stack::Stack(){
    this->tailNode =new Node(123,0);
    this->headerNode = new Node(0,tailNode);
}

void Stack::push(int value){
    Node* newNode = new Node(value, this->tailNode);
    if(headerNode->getNextNode() == tailNode){
        this ->headerNode -> setNextNode(newNode);
        return;
    }

    Node* nextNode = headerNode->getNextNode();
    while(nextNode != tailNode){
        nextNode = nextNode->getNextNode();
        if(nextNode == tailNode){
            nextNode->setNextNode(newNode);
        }
     }
     return;
}




int main(){
    Stack* stack = new Stack();
    stack->push(1);
    stack->push(2);
    cout << stack->headerNode->getNextNode()->getNextNode()->getValue();
    return 0;
}