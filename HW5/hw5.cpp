#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <class T>
void mySwap(T& x,T& y)
{
    T temp;
    temp=x;
    x=y;
    y=temp;
}

void Print(vector<int> v, int size){
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int Partition(vector<int> &v, int l, int r){
    int pivot = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (v[j] < pivot) {
            i++;
            mySwap<int>(v[i], v[j]);
        }
    }
    i++;
    mySwap<int>(v[i], v[r]);
    return i;
}


void QuickSort(vector<int>& v, int l, int r){
    if(l >= r) return;
    int pivot = Partition(v, l, r);
    QuickSort(v, l, pivot - 1);
    QuickSort(v, pivot + 1, r);
}

int main() {

    int n, k;
    cin >> n >> k;
    cout << n << " " << k << "\n";
    vector<int> v;
    for(int i=0; i<n; i++){
        cout  << "hi\n";
        cin >> v[i];
    }  
    cout << "here\n";
    QuickSort(v, 0, n-1);
    cout << v[k-1] << "\n";
    return 0;
}
