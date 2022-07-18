#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    Node(int value, Node* nextNode){
        this->_value = value;
        this->_nextNode = nextNode;
    }
    public:
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
    private:
        int _value;
        Node* _nextNode;
};

struct Queue{
    Queue(){
        _tailNode = new Node(0,0);
        _headerNode = new Node(0,_tailNode);
    }
    public:

        void push(int value){
            Node* newNode = new Node(value, _tailNode);
            if(!size){
                // if size = 0, set newNode behind headerNode
                _headerNode->setNextNode(newNode);
                size += 1;
                return;
            }
            // else
            Node* nextNode = _headerNode->getNextNode();
            while(nextNode->getNextNode() != _tailNode){
                // search the node what exist at behind tailNode
                nextNode = nextNode->getNextNode();
            }
            // then set newNode behind the searched Node 
            nextNode->setNextNode(newNode);
            size += 1 ;
            return;
        }

        int pop(){
            if(!size){
                return -1;
            }
            int popedValue = _headerNode->getNextNode()->getValue();
            Node* nextNode = _headerNode->getNextNode()->getNextNode();
            // nextNode is index Num 1 Node
            _headerNode->setNextNode(nextNode);
            // the nextNode connect to hedaerNode
            // then index Num 0 Node poped
            this->size -= 1;
                return popedValue;
        }

        int size = 0;

        bool empty(){
            if(!size)return 1;
            return 0;
        }
        
        int front(){
            if(!size) return -1;
            Node* nextNode = _headerNode->getNextNode();
            return nextNode->getValue();
        }

        int back(){
            if(!size) return -1;
            Node* nextNode = _headerNode->getNextNode();
            while(nextNode->getNextNode() != _tailNode){
                nextNode =nextNode->getNextNode();
            }
            return nextNode->getValue();
        }

    private:
        Node* _headerNode;
        Node* _tailNode;

};

vector<string> split(string str){
    istringstream iss;
    iss.str(str);
    string buffer;
    
    vector<string> result;

    while(iss >> buffer){
        result.push_back(buffer);
    }

    return result;
}

bool startsWith(string &str,const string &prefix) {
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

int main(){
    Queue queue;
    int N = 0;
    cin >> N;
    for(int i=0; i<N+1;i++){
        string command;
        getline(cin,command);
        if(startsWith(command ,"push")){
            vector<string> number = split(command);
            int pushNum = stoi(number[1]);
            queue.push(pushNum); 
        }else if (startsWith(command ,"pop")){
            cout << queue.pop() << endl;
        }else if (startsWith(command ,"size")){
            cout << queue.size << endl;
        }else if (startsWith(command ,"empty")){
            cout << queue.empty() << endl;
        }else if (startsWith(command ,"front")){
            cout << queue.front() << endl;
        }else if (startsWith(command,"back")){
            cout << queue.back() << endl;
        }
    }
    return 0;
}