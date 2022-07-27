#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;


bool compare(int i, int j){
    return j < i;
}

vector<int> split(string str){
    istringstream iss;
    iss.str(str);
    string buffer;
    
    vector<int> result;

    while(iss >> buffer){
        result.push_back(stoi(buffer));
    }

    return result;
}

int main(){
    int size;
    cin >> size;
    for(int i = 0; i < size;  i++){
        int N, M;
        cin >> N >> M;
        cin.ignore();

        string priority;
        getline(cin, priority,'\n');
        vector<int> priority_arr = split(priority);
        int count =0;
        while(priority_arr.size()){
            // while vector's size  = 0
            bool isShift = false;
            for(int k = 1; k< priority_arr.size();k++){
                if(priority_arr[0] < priority_arr[k]){
                    // if other document have high priority then first document, the document shift
                    isShift = true;
                    break;
                }
            }

            if(isShift){
                priority_arr.push_back(priority_arr[0]);
                priority_arr.erase(priority_arr.begin());
                // if shift situation
                M -=1;
                if(M < 0){
                    // the selected document is placed last of array
                    M = priority_arr.size()-1;
                }
                continue;
            }else{
                priority_arr.erase(priority_arr.begin());
                //if poped situation
                count++;
                M -=1;
                if(M < 0){
                    // the selected document is poped
                    break;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
