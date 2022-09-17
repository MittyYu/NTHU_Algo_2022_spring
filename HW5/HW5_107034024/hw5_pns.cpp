#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>

using namespace std;

//void quick_sort(int arr[], int fst, int lst);
int prune_search(int arr[], int fst, int lst, int tar);
int find_mid(int arr[], int n);
int partition(int arr[], int l, int r, int x);
void swap(int *a, int *b);

int* mid;

int main(void) {
    //clock_t start, stop;
    int len, tar;

    cin >> len >> tar;
    int* PSarr = new int[len];

    for (int i = 0; i < len; i++) {
        scanf("%d", &PSarr[i]);
    }

    // start = clock();
    int ans = prune_search(PSarr, 0, len - 1, tar);
    // stop = clock();

    cout << ans << endl;
    //cout << double(stop - start) / CLOCKS_PER_SEC << endl;

    //delete[] QSarr;
    delete[] PSarr;
    delete[] mid;
    return 0;
}

int prune_search(int arr[], int fst, int lst, int tar) {
    if(tar < 0 || tar > lst - fst +1) return -1;
    if(fst == lst) return arr[fst];

    int len = lst - fst + 1;
    mid = new int[(len + 4) / 5];
    int i, mfm, p;

    for (i = 0; i < len / 5; i++) {
        mid[i] = find_mid(arr + fst + i * 5, 5);
    }

    if (i * 5 < len) {
        mid[i] = find_mid(arr + fst + i * 5, len % 5);
        i++;
    }

    if(i)
        mfm = mid[i-1];
    else
        mfm = prune_search(mid, 0, i - 1, i / 2);

    p = partition(arr, fst, lst, mfm);

    if (tar - 1 < p - fst) {
        return prune_search(arr, fst, p - 1, tar);
    } else if (tar - 1 > p - fst) {
        return prune_search(arr, p + 1, lst, fst + tar - p - 1);
    } else {
        return arr[p];
    }
}

int find_mid(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n / 2];
}

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(int arr[], int fst, int lst, int m) {
    int i;

    for (i = fst; i < lst; i++) {
        if (arr[i] == m) {
            swap(&arr[i], &arr[lst]);
            break;
        }
    }


    i = fst;

    for (int j = fst; j <= lst - 1; j++) {
        if (arr[j] <= m) {
            swap(&arr[i++], &arr[j]);
        }
    }

    swap(&arr[i], &arr[lst]);

    return i;
}

