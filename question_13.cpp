//Given an array A[1..n] of integers, compute the length of a longest alternating subsequence.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
int n;
cout<<"enter size of vector : ";
cin>>n;
vector<int> A(n); 
cout<<"enter elements of vector : ";
for(int i=0;i<n;i++) cin>>A[i];
vector<int> up(n, 1), down(n, 1);
for (int i = 0; i < n; i++) {
for (int j = 0; j < i; j++) {
if (A[i] > A[j])
up[i] = max(up[i], down[j] + 1);
else if (A[i] < A[j])
down[i] = max(down[i], up[j] + 1);
}
}
int answer = 0;
for (int i = 0; i < n; i++)
answer = max(answer, max(up[i], down[i]));
cout << "Length of longest alternating subsequence = "
<< answer << endl;
return 0;
}
