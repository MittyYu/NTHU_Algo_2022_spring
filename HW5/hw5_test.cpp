#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <numeric>

using namespace std;

void QuickSort(int arr[], int fst, int lst);
int prune_search(int arr[], int fst, int lst, int tar);
int find_mid(int arr[], int fst, int lst);
int partition(int arr[], int l, int r, int x);
void swap(int *a, int *b);

int main(void) {
    cout << "Hello\n";
    ifstream INPUT("input.txt");
    ofstream QSTXT("QS.txt");
    ofstream PSTXT("PS.txt");
    clock_t start, stop;
    int len, tar;
    int QSarr[10000000], PSarr[10000000];

    INPUT >> len >> tar;

    cout << len << " " << tar << "\n";
    for (int i = 0; i < len; i++) {
        INPUT >> QSarr[i];
        PSarr[i] = QSarr[i];
    }

    start = clock();

    QuickSort(QSarr, 0, len - 1);

    stop = clock();

    QSTXT << QSarr[tar - 1] << endl;
    QSTXT << double(stop - start) / CLOCKS_PER_SEC << endl;

    cout << QSarr[tar - 1] << endl;
    cout << double(stop - start) / CLOCKS_PER_SEC << endl;

    start = clock();

    int ans = prune_search(PSarr, 0, len - 1, tar);

    stop = clock();

    PSTXT << ans << endl;
    PSTXT << double(stop - start) / CLOCKS_PER_SEC << endl;

    cout << ans << endl;
    cout << double(stop - start) / CLOCKS_PER_SEC << endl;

    return 0;
}

void QuickSort(int arr[], int fst, int lst) {
    if (fst >= lst) return;

    int p = fst;
    int i = fst;
    int j = lst + 1;
    int tmp;

    do {
        int tmp;

        do {
            i++;
        } while (arr[i] < arr[p]);

        do {
            j--;
        } while (arr[j] > arr[p]);

        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    } while(i < j);

    tmp = arr[fst];
    arr[fst] = arr[j];
    arr[j] = tmp;

    QuickSort(arr, fst, j - 1);
    QuickSort(arr, j + 1, lst);
}

int prune_search(int arr[], int fst, int lst, int tar) {
    int len = lst - fst + 1;
    int mid[(len + 4) / 5];
    int i, mfm, pos;

    for (i = 0; i < len / 5; i++) {
        mid[i] = find_mid(arr + fst + i * 5, 0, 4);
    }

    if (i * 5 < len) {
        mid[i] = find_mid(arr + fst + i * 5, 0, len % 5 - 1);
        i++;
    }

    mfm = (i == 1) ? mid[i - 1] : prune_search(mid, 0, i - 1, i / 2);

    pos = partition(arr, fst, lst, mfm);

    if (tar - 1 < pos - fst) {
        return prune_search(arr, fst, pos - 1, tar);
    } else if (tar - 1 > pos - fst) {
        return prune_search(arr, pos + 1, lst, fst + tar - pos - 1);
    } else {
        return arr[pos];
    }
}

int find_mid(int arr[], int fst, int lst) {
    QuickSort(arr, fst, lst);

    return arr[(lst - fst + 1) / 2];
}

int partition(int arr[], int fst, int lst, int mfm) {
    int i;

    for (i = fst; i < lst; i++) {
        if (arr[i] == mfm) {
            break;
        }
    }

    swap(&arr[i], &arr[lst]);

    i = fst;

    for (int j = fst; j <= lst - 1; j++) {
        if (arr[j] <= mfm) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[lst]);

    return i;
}

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
