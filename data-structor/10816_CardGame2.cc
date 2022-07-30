#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MapArgs{
    // [num : count] 構造でVECTORに入れるために作ったSTRUCT
    int count = 0;
    int num;
    void addCount(){
        count++;
    }
    MapArgs(int num){
        this->num = num;
        count++;
    }
};

int binarySearch(int searchValue, int length, vector<MapArgs>& arr){
    int start = 0;
    int end = length -1;
    while(end >= start){
        int mid = (end+start)/2;
        if(arr[mid].num > searchValue){
            end = mid-1;
        }else if(arr[mid].num < searchValue){
            start = mid +1;
        }else{
            return arr[mid].count;
        }
    }
    return 0;
}

int main(){
    int N,M;
    cin >> N;
    vector<int> sanggneCard;
    for(int i =0; i< N; i++){
        int pushNum;
        cin >> pushNum;
        sanggneCard.push_back(pushNum);
    }

    sort(sanggneCard.begin(),sanggneCard.end()); //　binarySearchのため
    vector<MapArgs> countArr;

    countArr.push_back(MapArgs(sanggneCard[0])); // 

    for(int i = 1; i< sanggneCard.size(); i++){
        if(countArr.back().num == sanggneCard[i]){
            // vectorに入っているstructのNumと一致したら
            countArr.back().addCount();
            // count++を行う
        }else{
            countArr.push_back(MapArgs(sanggneCard[i]));
            //なかったら新しくその値にあったものを入れる
        }
    }
    vector<int> searchCard;
    cin >> M;
    for(int i =0; i< M; i++){
        int pushNum;
        cin >> pushNum;
        searchCard.push_back(pushNum);
    }

    for(int i =0; i<M; i++){
        cout << binarySearch(searchCard[i], countArr.size(), countArr) << ' ';
    }
    return 0;
}