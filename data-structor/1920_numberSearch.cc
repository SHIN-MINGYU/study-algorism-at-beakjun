#include <iostream>
#include <algorithm>
using namespace std;


int binarySearch(int searchValue,int length, int arr[]){
    int left = 0;
    int right = length-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(searchValue > arr[mid]){
            left = mid+1;
        }else if(searchValue < arr[mid] ){
            right = mid-1;
        }else{
            return 1;
        }
    }
    return 0;
}

int main(){
    int N;
    cin >> N;
    int* n_arr = new int[N];
    for (int i = 0; i < N; i++){
        cin >> n_arr[i];
    }
    sort(n_arr, n_arr + N);
    int M;
    cin >> M;
    int* m_arr = new int[M];
    for (int i = 0; i < M; i++){
        cin >> m_arr[i];
    }

    for(int i=0; i<M; i++){
        cout << binarySearch(m_arr[i],N,n_arr) << '\n';
    }
    return 0;
}
