#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <array>
using namespace std;
#include "Data.h"

// A template function to implement bubble sort.  Code in PowerPoints.
// We can use this for any data type that supports 
// comparison operator < and swap works for it.
template<typename T>
void bubbleSort(vector <T>& a, int size) {
    int i, j;
    bool swapped;//boolean for swap
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                //swaps values
                T temp=a.at(j);
                a.at(j)=a.at(j+1);
                a.at(j+1)=temp;
                swapped = true;
                }
            }
        }
}
//got code from zybooks and changed array to vector/template format for partition and quick sort
template <typename T>
int Partition(vector<T>& numbers, int i, int k) {
    int l;
    int h;
    int midpoint;

    T temp;
    bool done;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    T pivot = numbers.at(midpoint);

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (numbers.at(l) < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers.at(h)) {
            --h;
        }

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            //swap();
            temp = numbers.at(l);
            numbers.at(l) = numbers.at(h);
            numbers.at(h) = temp;

            ++l;
            --h;
        }
    }

    return h;
}
//quick sort code from zybooks and changed array to vector/template format
template <typename T>
void Quicksort(vector<T>& numbers, int i, int k) {
    int j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}
//code from zybooks
template <typename T>
void SelectionSort(vector<T>& numbers, int numbersSize) {
    int i;
    int j;
    int indexSmallest;
    T temp;      // Temporary variable for swap

    for (i = 0; i < numbersSize - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {

            if ( numbers.at(j) < numbers.at(indexSmallest) ) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]//changed this part of zyboks to use swap function instead
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}
//code from my lab 3
template <typename T>
void mergeSortedLists(vector<T>& a, vector<T>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}
template <typename T>
void mergeSort(vector<T>& a, vector<T>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}



int main() {



    ifstream inFile;
    ofstream outFile;
    int length;
    cout<<"Enter a length for the vector:"<<endl;
    cin>>length;

    //opening files
    inFile.open("../ComputerUsage.csv");

    //making vectors
    vector<Data> dataV;
    vector<Data> dataV_B;//bubble sort
    vector<Data> dataV_S;//selection sort
    vector<Data> dataV_Q;//quick sort
    vector<Data> dataV_M;//merge sort
    vector<Data> dataV_tempM;//merge sort

    vector<int> intV;
    vector<int> intV_B;//bubble sort
    vector<int> intV_S;//selection sort
    vector<int> intV_Q;//quick sort
    vector<int> intV_M;//merge sort
    vector<int> intV_tempM;//merge sort


    //making sure all of the files are opened
    if(!inFile.is_open()){
        cout<<"Computer Usage input file did not open."<<endl;
    }
    cout<<"Computer Usage input file opened."<<endl;

    int i=0;
    while(i<length){

        string caseID,activity, duration,codeP;
        getline(inFile,caseID, ',');
        getline(inFile,activity,',');
        getline(inFile,duration, ',');
        getline(inFile,codeP, '\n');

        int caseID2,activity2, duration2,codeP2;
        caseID2=stoi(caseID);
        activity2=stoi(activity);
        duration2=stoi(duration);
        codeP2=stoi(codeP);

        Data computerUsageData=Data(caseID2,activity2, duration2,codeP2);

        //pushes Data member onto stack and queue
        dataV.push_back(computerUsageData);

        i++;
    }

    //making copies for each algorithm to sort
    dataV_B=dataV;//bubble sort
    dataV_S=dataV;//selection sort
    dataV_Q=dataV;//quick sort
    dataV_M=dataV;//merge sort
    dataV_tempM=dataV;

    srand(time(NULL));
    for(int i=0; i<length;i++){
        int randNum=rand()%100;
        intV.push_back(randNum);

    }

    //then copy the vector of random numbers to be sorted
    intV_B=intV;//bubble sort
    intV_S=intV;//selection sort
    intV_Q=intV;//quick sort
    intV_M=intV;//merge sort
    intV_tempM=intV;

    cout<<"SORTING DATA"<<endl;

    //bubble sort
    clock_t start_BubbleSort = clock();
    //bubble sort on data
    bubbleSort(dataV_B, dataV_B.size()-1);
    clock_t end_BubbleSort = clock();
    double elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Bubble sort : "<< elapsed_BubbleSort <<endl;

    clock_t start_BubbleSort2 = clock();
    //bubble sort on data again
    bubbleSort(dataV_B, dataV_B.size()-1);
    clock_t end_BubbleSort2 = clock();
    double elapsed_BubbleSort2 = double(end_BubbleSort2 - start_BubbleSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Bubble sort again : "<< elapsed_BubbleSort2 <<endl;

    //selection sort
    clock_t start_SelectionSort = clock();
    //selection sort on data
    SelectionSort(dataV_S,dataV_S.size()-1);
    clock_t end_SelectionSort = clock();
    double elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Selection sort : "<< elapsed_SelectionSort <<endl;

    clock_t start_SelectionSort2 = clock();
    //selection sort on data again
    SelectionSort(dataV_S,dataV_S.size()-1);
    clock_t end_SelectionSort2 = clock();
    double elapsed_SelectionSort2 = double(end_SelectionSort2 - start_SelectionSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Selection sort again : "<< elapsed_SelectionSort2 <<endl;

    //quick sort
    clock_t start_QuickSort = clock();
    //quick sort on data
    Quicksort(dataV_Q, 0, dataV_Q.size()-1);
    clock_t end_QuickSort = clock();
    double elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Quick sort : "<< elapsed_QuickSort <<endl;

    clock_t start_QuickSort2 = clock();
    //quick sort on data again
    Quicksort(dataV_Q, 0, dataV_Q.size()-1);
    clock_t end_QuickSort2 = clock();
    double elapsed_QuickSort2 = double(end_QuickSort2 - start_QuickSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Quick sort again : "<< elapsed_QuickSort2 <<endl;

    //merge sort
    clock_t start_MergeSort = clock();
    //merge on data
    mergeSort(dataV_M, dataV_tempM, 0, dataV_M.size()-1);
    clock_t end_MergeSort = clock();
    double elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Merge sort : "<< elapsed_MergeSort <<endl;

    clock_t start_MergeSort2 = clock();
    //merge on data again
    mergeSort(dataV_M, dataV_tempM, 0, dataV_M.size()-1);
    clock_t end_MergeSort2 = clock();
    double elapsed_MergeSort2 = double(end_MergeSort2 - start_MergeSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time Data Merge sort again : "<< elapsed_MergeSort2 <<endl;

    cout<<"SORTING INT"<<endl;

    //bubble sort int
    clock_t start_intBubbleSort = clock();
    //bubble sort on data
    bubbleSort(intV_B, intV_B.size()-1);
    clock_t end_intBubbleSort = clock();
    double elapsed_intBubbleSort = double(end_intBubbleSort - start_intBubbleSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Bubble sort : "<< elapsed_intBubbleSort <<endl;

    clock_t start_intBubbleSort2 = clock();
    //bubble sort on data again
    bubbleSort(intV_B, intV_B.size()-1);
    clock_t end_intBubbleSort2 = clock();
    double elapsed_intBubbleSort2 = double(end_intBubbleSort2 - start_intBubbleSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Bubble sort again : "<< elapsed_intBubbleSort2 <<endl;

    //selection sort int
    clock_t start_intSelectionSort = clock();
    //selection sort on data
    SelectionSort(intV_S,intV_S.size()-1);
    clock_t end_intSelectionSort = clock();
    double elapsed_intSelectionSort = double(end_intSelectionSort - start_intSelectionSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Selection sort : "<< elapsed_intSelectionSort <<endl;

    clock_t start_intSelectionSort2 = clock();
    //selection sort on data again
    SelectionSort(intV_S,intV_S.size()-1);
    clock_t end_intSelectionSort2 = clock();
    double elapsed_intSelectionSort2 = double(end_intSelectionSort2 - start_intSelectionSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time intSelection sort again : "<< elapsed_intSelectionSort2 <<endl;

    //quick sort int
    clock_t start_intQuickSort = clock();
    //quick sort on data
    Quicksort(intV_Q, 0, intV_Q.size()-1);
    clock_t end_intQuickSort = clock();
    double elapsed_intQuickSort = double(end_intQuickSort - start_intQuickSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Quick sort : "<< elapsed_intQuickSort <<endl;

    clock_t start_intQuickSort2 = clock();
    //quick sort on data again
    Quicksort(intV_Q, 0, intV_Q.size()-1);
    clock_t end_intQuickSort2 = clock();
    double elapsed_intQuickSort2 = double(end_intQuickSort2 - start_intQuickSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Quick sort again : "<< elapsed_intQuickSort2 <<endl;

    //merge sort
    clock_t start_intMergeSort = clock();
    //merge on data
    mergeSort(intV_M, intV_tempM,0, intV_M.size()-1);
    clock_t end_intMergeSort = clock();
    double elapsed_intMergeSort = double(end_intMergeSort - start_intMergeSort) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Merge sort : "<< elapsed_intMergeSort <<endl;

    clock_t start_intMergeSort2 = clock();
    //merge on data again
    mergeSort(intV_M, intV_tempM, 0, intV_M.size()-1);
    clock_t end_intMergeSort2 = clock();
    double elapsed_intMergeSort2 = double(end_intMergeSort2 - start_intMergeSort2) / CLOCKS_PER_SEC;
    cout <<"Elapsed Time int Merge sort again : "<< elapsed_intMergeSort2 <<endl;




    //closing files
    inFile.close();

    return 0;
}