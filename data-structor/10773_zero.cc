#include <iostream>

using namespace std;

// Linked list Stack
struct Node{
    public:
    Node(int value, Node* nextNode);
        void setNextNode(Node* nextNode);
        Node* getNextNode();
        void setValue(int value);
        int getValue();
    private:
        int _value;
        Node* _nextNode;
};
Node::Node(int value, Node* nextNode){
    this->_value = value;
    this->_nextNode= nextNode;
}

void Node::setNextNode(Node* nextNode){
    this->_nextNode = nextNode;
}

Node* Node::getNextNode(){
    return this->_nextNode;
}

int Node::getValue(){
    return this->_value;
}
void Node::setValue(int value){
    this->_value = value;
}

struct Stack{
    public:
        Stack(){
            this->_tailNode = new Node(0,0);
            this->_headerNode = new Node(0,_tailNode);
        }
        
        void push(int value){
            Node* newNode = new Node(value, this->_tailNode);
            if(_headerNode->getNextNode() == _tailNode){
                _headerNode->setNextNode(newNode);
                size += 1;
                return;
            }
            Node* nextNode = _headerNode->getNextNode();
            _headerNode->setNextNode(newNode);
            newNode->setNextNode(nextNode);
            size += 1 ;
            return;
        }
        void pop(){
            if(_headerNode->getNextNode() == _tailNode){
                return;
            }
            int popedValue = _headerNode->getNextNode()->getValue();
            Node* nextNode = _headerNode->getNextNode()->getNextNode();
            _headerNode->setNextNode(nextNode);
            this->size -= 1;
            return;
        }

        int sum(){
            Node* nextNode = _headerNode->getNextNode();
            if(nextNode == _tailNode){
                return 0;
            }            
            int sum =nextNode->getValue();
            while(nextNode->getNextNode() != _tailNode){
                nextNode = nextNode->getNextNode();
                sum += nextNode->getValue();
            }
            return sum;
        }
        int size = 0;

    private:
        Node* _tailNode;
        Node* _headerNode;
};


int main(){
    // input K
    int K;
    cin >> K;
    Stack stack;
    // 0~K roof
    for(int i =0; i<K;i++){
        // if user input 0, last input is deleted;
        int value;
        cin >> value;
        if(value) stack.push(value);
        else stack.pop();
    }
    // print the remain number's sum
    cout << stack.sum();
    return 0;
}