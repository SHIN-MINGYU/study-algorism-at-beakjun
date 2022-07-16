#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Node{
    public:
        Node();
        Node(int value, Node* nextNode);
        void setNextNode(Node* nextNode);
        Node* getNextNode();
        void setValue(int value);
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
void Node::setValue(int value){
    this->value = value;
}


class Stack{
    public:
        void push(int value);
        int pop();
        bool empty();
        int top();
        Stack();
        int size = 0;
    private:    
        Node* headerNode;
        Node* tailNode;
};

Stack::Stack(){
    this->tailNode =new Node(0,0);
    this->headerNode = new Node(0,tailNode);
}

void Stack::push(int value){
    Node* newNode = new Node(value, this->tailNode);
    if(headerNode->getNextNode() == tailNode){
        headerNode->setNextNode(newNode);
        size += 1;
        return;
    }
    Node* nextNode = headerNode->getNextNode();
    headerNode->setNextNode(newNode);
    newNode->setNextNode(nextNode);
    size += 1 ;
    return;
}

int Stack::pop(){
    if(headerNode->getNextNode() == tailNode){
        return -1;
    }
    int popedValue = headerNode->getNextNode()->getValue();
    Node* nextNode = headerNode->getNextNode()->getNextNode();
    headerNode->setNextNode(nextNode);
    this->size -= 1;
    return popedValue;
}

bool Stack::empty(){
    if(this->size == 0){
        return 1;
    }
    return 0;
}

int Stack::top(){
    if(this->headerNode->getNextNode() != tailNode){
        return headerNode->getNextNode()->getValue();
    }
    return -1;
}


vector<string> split(string str, char Delimiter){
    istringstream iss;
    iss.str(str);
    string buffer;
    
    vector<string> result;

    while(iss >> buffer){
        result.push_back(buffer);
    }

    return result;
}

bool startsWith(const std::string &str, const std::string &prefix) {
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

int main(){
    Stack* stack = new Stack();
    int N = 0;
    cin >> N;
    for(int i = 0; i <= N; i++){
        string command;
        getline(cin,command);
        if(startsWith(command ,"push")){
            vector<string> number = split(command,' ');
            int pushNum = stoi(number[1]);
            stack->push(pushNum); 
        }else if (startsWith(command ,"pop")){
            cout << stack->pop() << endl;
        }else if (startsWith(command ,"size")){
            cout << stack->size << endl;
        }else if (startsWith(command ,"empty")){
            cout << stack->empty() << endl;
        }else if (startsWith(command ,"top")){
            cout << stack->top() << endl;
        }
    }
    return 0;
}