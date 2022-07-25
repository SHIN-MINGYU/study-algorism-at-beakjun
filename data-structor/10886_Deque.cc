#include <iostream>

using namespace std;

struct Node{
    public:
        Node(int value, Node* prevNode, Node* nextNode){
            this->_value = value;
            this->_prevNode = prevNode;
            this->_nextNode = nextNode;
        }
        int getValue(){
            return this->_value;
        }
        void setValue(int value){
            this->_value = value;
        }
        Node* getNextNode(){
            return this->_nextNode;
        }
        void setNextNode(Node* nextNode){
            this->_nextNode = nextNode;
        }
        Node* getPrevNode(){
            return this->_prevNode;
        }
        void setPrevNode(Node* prevNode){
            this->_prevNode = prevNode;
        }
    private:
        int _value;
        Node* _nextNode;
        Node* _prevNode;
};

struct Deque{
    public:
        Deque(){
            this-> _headerNode = new Node(0,0,0);
            this-> _tailNode = new Node(0,0,0);
            _headerNode -> setNextNode(_tailNode);
            _tailNode -> setPrevNode(_headerNode);
        } 
        void pushFront(int value){
                Node* coldNode = _headerNode->getNextNode();
                Node* newNode = new Node(value,_headerNode,coldNode);
                _headerNode->setNextNode(newNode);
                coldNode->setPrevNode(newNode);
                size += 1;
        }
        void pushBack(int value){
            Node* coldNode = _tailNode->getPrevNode();
            Node* newNode = new Node(value,coldNode,_tailNode);
            _tailNode->setPrevNode(newNode);
            coldNode->setNextNode(newNode);

            size +=1;
        }
        int popFront(){
            if(!size) return -1;
            Node* popedNode =_headerNode->getNextNode();
            int popedValue = popedNode->getValue();
            _headerNode -> setNextNode(popedNode->getNextNode());
            popedNode->getNextNode()->setPrevNode(_headerNode);
            size -= 1;
            return popedValue;
        }
        int popBack(){
            if(!size) return -1;
            Node* popedNode =_tailNode->getPrevNode();
            int popedValue = popedNode->getValue();
            _tailNode -> setPrevNode(popedNode->getPrevNode());
            popedNode->getPrevNode()->setNextNode(_tailNode);
            size -= 1;
            return popedValue;
        }
        int size = 0;
        int empty(){
            if(size) return 0;
            return 1;
        }
        int front(){
            if(!size) return -1;
            return _headerNode->getNextNode()->getValue();
        }
        int back(){
            if(!size) return -1;
            return _tailNode->getPrevNode()->getValue();
        }
    private:
        Node* _headerNode;
        Node* _tailNode;
};

int main(){
    Deque* deque = new Deque();
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
         string command;
         cin >> command;
            if(command == "push_front"){
                int value;
                cin >> value;
                deque -> pushFront(value);
            }
            else if(command == "push_back")
            {
                int value;
                cin >> value;
                deque -> pushBack(value);
            }
            else if(command == "pop_front") cout << deque -> popFront() << '\n';
            else if(command == "pop_back") cout << deque -> popBack() << '\n';
            else if(command == "size") cout << deque -> size << '\n';
            else if(command == "empty") cout << deque -> empty() << '\n';
            else if(command == "front") cout << deque -> front() << '\n';
            else if(command == "back") cout << deque -> back() << '\n';
    }
    return 0;
}