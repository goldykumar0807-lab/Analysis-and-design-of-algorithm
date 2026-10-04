//AIM: To revise and implement sorting algorithms for an array of int, 
//float or char type using Selection Sort, Insertion Sort, Bubble Sort,
//Recursive Merge Sort and Recursive Quick Sort. Also, analyze their time complexities in best, 
//average and worst cases and plot the complexity chart for n = 10 to 100.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
// Selection Sort
long long selectionSort(vector<int> a)
{
long long comparisons = 0;
int n = a.size();
for(int i = 0; i < n - 1; i++)
{
int minIndex = i;
for(int j = i + 1; j < n; j++)
{
comparisons++;
if(a[j] < a[minIndex])
{
minIndex = j;
}
}
swap(a[i], a[minIndex]);
}
return comparisons;
}


// Insertion Sort
long long insertionSort(vector<int> a)
{
long long comparisons = 0;
int n = a.size();
for(int i = 1; i < n; i++)


{
int key = a[i];
int j = i - 1;
while(j >= 0)
{
comparisons++;
if(a[j] > key)
{
a[j + 1] = a[j];
j--;
}
else
{
break;
}
}
a[j + 1] = key;
}
return comparisons;
}


// Bubble Sort
long long bubbleSort(vector<int> a)
{
long long comparisons = 0;
int n = a.size();
for(int i = 0; i < n - 1; i++)
{
for(int j = 0; j < n - i - 1; j++)
{
comparisons++;
if(a[j] > a[j + 1])
{
swap(a[j], a[j + 1]);
}
}
}


return comparisons;
}


// Merge Sort
void mergeArray(vector<int>& a, int low, int mid, int high,


long long& comparisons)


{
vector<int> temp;
int i = low;
int j = mid + 1;
while(i <= mid && j <= high)
{
comparisons++;
if(a[i] <= a[j])
{
temp.push_back(a[i]);
i++;
}
else
{
temp.push_back(a[j]);
j++;
}
}
while(i <= mid)
{
temp.push_back(a[i]);
i++;
}
while(j <= high)
{
temp.push_back(a[j]);
j++;
}
for(int k = 0; k < temp.size(); k++)
{
a[low + k] = temp[k];


}
}


void mergeSort(vector<int>& a, int low, int high,


long long& comparisons)


{
if(low < high)
{
int mid = (low + high) / 2;
mergeSort(a, low, mid, comparisons);
mergeSort(a, mid + 1, high, comparisons);
mergeArray(a, low, mid, high, comparisons);
}
}


// Quick Sort
int partitionArray(vector<int>& a, int low, int high,


long long& comparisons)


{
int pivot = a[high];
int i = low - 1;
for(int j = low; j < high; j++)
{
comparisons++;
if(a[j] < pivot)
{
i++;
swap(a[i], a[j]);
}
}
swap(a[i + 1], a[high]);
return i + 1;
}


void quickSort(vector<int>& a, int low, int high,


long long& comparisons)


{
if(low < high)
{
int p = partitionArray(a, low, high, comparisons);
quickSort(a, low, p - 1, comparisons);
quickSort(a, p + 1, high, comparisons);
}
}


int main()
{
srand(time(0));
ofstream file("sorting_data.csv");
file << "n,Selection,Insertion,Bubble,Merge,Quick\n";
for(int n = 10; n <= 100; n += 10)
{
vector<int> a;
// Creating random array
for(int i = 0; i < n; i++)
{
a.push_back(rand() % 1000);
}
long long selection = selectionSort(a);
long long insertion = insertionSort(a);
long long bubble = bubbleSort(a);
vector<int> b = a;
long long merge = 0;
mergeSort(b, 0, n - 1, merge);
vector<int> c = a;
long long quick = 0;
quickSort(c, 0, n - 1, quick);
cout << "n = " << n << endl;


cout << "Selection Sort : " << selection << endl;
cout << "Insertion Sort : " << insertion << endl;
cout << "Bubble Sort : " << bubble << endl;
cout << "Merge Sort : " << merge << endl;
cout << "Quick Sort : " << quick << endl;
cout << "--------------------------" << endl;
file << n << ","
<< selection << ","
<< insertion << ","
<< bubble << ","
<< merge << ","
<< quick << "\n";


}
file.close();
cout << "Data saved in sorting_data.csv";
return 0;
}

