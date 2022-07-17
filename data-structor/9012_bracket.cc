#include <iostream>

using namespace std;


int main(){
    // 1. set loof count
    int N;
    cin >> N;
    for(int i =0; i<N; i++){
        // 2. input brackets in loof
        string brackets;
        cin >> brackets;
        int leftBracket = 0;
        bool iscorrect = true;
        for(char bracket : brackets){
            // 3. brackets loof
            if(bracket == '('){
                // 4. if leftBracket, +1 in leftBracket
                leftBracket += 1;
            }else if(bracket == ')' && leftBracket > 0){
                // 5. if rightBracket, check leftBracket count
                // 5-1. if more than 0, leftBracket variable minus 1
                leftBracket -=1;
            }else {
                // 6. if lectBracket count is less than 0, break and iscorrect variable set false and loof braak; 
                iscorrect = false;
                break;
            }
        }
        // 7. print the result
        if(leftBracket != 0 || !iscorrect){
            cout << "NO" << endl; 
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}