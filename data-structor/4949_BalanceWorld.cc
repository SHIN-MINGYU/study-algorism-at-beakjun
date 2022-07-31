#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    while(true){
        string str;
        vector<char> validator;
        getline(cin,str);
        if(str[0] == '.' && str.length() == 1){
            break;
        }
        bool isSave = true;
        for(int i =0; i < str.length(); i++){
            if(validator.empty() &&( str[i] == ')' || str[i] == ']')){
                isSave = false;
                break;
            }
            else if(str[i] == '('){
                validator.push_back(str[i]);
            }else if(str[i] == '['){
                validator.push_back(str[i]);
            }else if(str[i] == ']' && validator.back() == '['){
                validator.pop_back();
            }else if(str[i] == ')' && validator.back() == '('){
                validator.pop_back();
            }else if(str[i] == ']' && validator.back() == '('){
                isSave = false;
                break;
            }else if(str[i] == ')' && validator.back() == '['){
                isSave = false;
                break;
            }
        }
        if(isSave && validator.empty()){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
    }
    return 0;
}