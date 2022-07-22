#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> n_arr;

int main(){
    int N, K;
    cin >> N >> K;
    string yosepusu = "<";
    for(int i =0; i<N; i++){
        n_arr.push_back(i+1);
    }
     
    //count : 3番目の数字を確かめるカウンター

    // lostIndex : vectorでpopされて失われたindexの数

    // index : 正確なindex

     
    int count = 0;
    int lostIndex = 0;
    int index = 0;
    while(!n_arr.empty()){
        if(n_arr.size() == 1){
            //もし残った配列の長さが１だったらそのコンマ抜きの数字だけを追加して return
            yosepusu += to_string(n_arr[0]);
            break;
        }
        if((count+1) % K == 0){
            // ループがKの倍数位に回ったらその値を配列から抜いて文字列の中に入れる
            yosepusu += to_string(n_arr[index - lostIndex]) + ", " ;
            n_arr.erase(n_arr.begin() + index - lostIndex);
            lostIndex++;
        }
        index++;
        count++;
        if(n_arr.size() == index-lostIndex){
            //　indexが今探している配列の長さを超える場合indexを初期化
            lostIndex = 0;
            index =0;
        }
    }
    yosepusu += ">";
    cout << yosepusu;
    return 0;
}