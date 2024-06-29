#include<bits/stdc++.h>
using namespace std;


int linearSearch(int* arr, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(0));
    int a;
    ofstream fout("100k.txt");
    for (int i = 0; i < 100000; i++) {
        a = rand() % 6 + 1;
        fout << a << endl;
    }
    fout.close();


    ifstream fin("100k.txt");
    const int size = 100000;
    int* numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        fin >> numbers[i];
    }
    fin.close();


    int key;
    cout << "Enter the number to search: ";
    cin >> key;


    int searchResult = linearSearch(numbers, size, key);

    if (searchResult != -1) {
        cout << "Number found at index " << searchResult << endl;
    } else {
        cout << "Number not found." << endl;
    }



    return 0;
}

