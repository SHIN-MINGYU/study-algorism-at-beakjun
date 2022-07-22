#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    queue<int> queue;
    for(int i=0; i<N; i++){
        queue.push(i+1);
    }
    for(int i=0; i<N-1;i++){
        // 始めの数字を消す
        queue.pop();
        //　消された配列の中でINDEX0の数字を探して消す
        int popedNum =queue.front();
        queue.pop();
        //　入れる
        queue.push(popedNum);
    }
    cout << queue.front() << '\n';
    return 0;
}