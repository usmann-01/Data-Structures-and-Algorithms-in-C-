# Time Complexiy Analysis in C++
## A comprehensive defination of Big Oh

**Big O describes how an algorithm's runtime or space grows as the input size increases. It helps us compare algorithms and predict performance at scale.**

In simple words , the rate at which the number of operations grows as the input size increases.

Or for a flash note : Big-O answers this question:
“How does the algorithm scale as input grows?”

![Big O complexity chart](assets/BIG_O_01.png)

In this diagram we can see that how each time complexity **"Scales"** as the input size or eventually the number of operations increases. We will discuss major time complexities after we get over this major misconception. 

## Time Complexity ≠ Execution Time

**Big O is NOT about how fast your code runs. It's about how it scales.**

Execution time depends on your machine—the same code runs differently on a laptop vs on a Google server.

Big O describes the **growth pattern**:


**For Example :**
A specific O(n²) algorithm might run in 10ms on your computer , but could run under 1ms on a powerful server. That is irrelevant in our analysis of an algorithm.

**Memorise this Mantra :**
Big O measures growth rate, not speed.


## Understanding Different Time Compleixties

### O(1) or Constant Time Complexity
An algorithm with O(1) time complexity performs the same number of operations 
regardless of input size.

**Example :**
Accessing an element from an array through indexing.

Consider this C++ code.

```cpp
#include<iostream>
using namespace std;
int getFirstElement(int arr[]){

}
int main(){
int arr1[5]={1,2,3,4,5};
int arr2[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                21, 22, 23, 24, 25};

cout<<"First element : " <<getFirstElement(arr1)<<endl;

cout<<"First element : " <<getFirstElement(arr2)<<endl;

}
```
Accessing an array element by index takes constant time O(1).
The function getFirstElement() directly returns arr[0] without any loop.
This operation does not depend on the size of the array.
Whether the array has 5 elements or 25 or even **1 billion** elements, the access time remains the same.
Hence, array index access is a classic example of O(1) time complexity.

**O(1) is considered as the best theoretical time complexity, as the execution time remains fixed regardless of input size.**

---
### O(log n) - Logarithmic Time Complexity
An algorithm with O(log n) time complexity reduces the problem size by a constant factor 
with each step (usually half).

**Example:** Binary Search in a sorted array.

Consider this C++ code:
```cpp
#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int target){

int left = 0, right = n - 1;
while(left <= right){
    int mid = left + (right - left) / 2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target)
        left = mid + 1;
    else
        right = mid - 1;
}
return -1;
}
int main(){
int arr[8] = {2, 5, 8, 12, 16, 23, 38, 45};
cout << "Element found at index: " << binarySearch(arr, 8, 23) << endl;
}
```
**No need to worry , these are highly structured ALGORITHMS. Just get the intuition of time complexity at play.**

Binary search works by repeatedly dividing the search interval in half.
With each comparison, it eliminates half of the remaining elements.
For an array of size 8, it takes at most 3 comparisons (8 → 4 → 2 → 1).
For an array of size 1024, it takes at most 10 comparisons (log₂ 1024 = 10).
Even with **1 billion** elements, binary search needs only about 30 comparisons.

**O(log n) is highly efficient and scales extremely well as input size grows. In this one step increases as the data doubles.**

---

### O(n) - Linear Time Complexity
An algorithm with O(n) time complexity performs operations proportional to the input size.
If input doubles, operations roughly double.

**Example:** Finding the maximum element in an unsorted array.

Consider this C++ code:
```cpp
#include
using namespace std;

int findMax(int arr[], int n){
    int maxVal = arr[0];
    
    for(int i = 1; i < n; i++){
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    
    return maxVal;
}

int main(){
    int arr1[5] = {3, 7, 2, 9, 1};
    int arr2[10] = {15, 8, 23, 4, 16, 42, 11, 5, 19, 30};
    
    cout << "Max in arr1: " << findMax(arr1, 5) << endl;
    cout << "Max in arr2: " << findMax(arr2, 10) << endl;
}
```

To find the maximum element, we must examine every element at least once.
The function loops through all `n` elements exactly one time.
For an array of size 5, it performs 5 comparisons.
For an array of size 10, it performs 10 comparisons.
Double the array size, and you double the number of operations.

**O(n) is efficient and acceptable for most practical applications.**

---


### O(n²) - Quadratic Time Complexity
An algorithm with O(n²) time complexity compares each element with every other element.
Double the input, work increases 4 times.

**Example:** Finding duplicate names in a list.

Consider this C++ code:
```cpp
#include
#include
using namespace std;

void findDuplicates(string names[], int n){
    cout << "Duplicate names: ";
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(names[i] == names[j]){
                cout << names[i] << " ";
            }
        }
    }
    cout << endl;
}

int main(){
    string students[5] = {"Ali", "Sara", "Ali", "Ahmed", "Sara"};
    
    findDuplicates(students, 5);
}
```

To find duplicates, we compare each name with every other name.
For 5 students: we make about 25 comparisons (5 × 5).
For 10 students: we make about 100 comparisons (10 × 10).
For 100 students: we make about 10,000 comparisons (100 × 100).
Two nested loops = n² operations.

**O(n²) works for small lists but becomes very slow for large data.This is not considered a good time complexity to have for very large datasets.**

---

### O(2ⁿ) - Exponential Time Complexity
An algorithm with O(2ⁿ) time complexity doubles work for each new element added.
This explodes extremely fast.

**Example:** Trying all possible password combinations.

Consider this C++ code:
```cpp
#include
using namespace std;

int fibonacci(int n){
    if(n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    cout << "fib(5)  = " << fibonacci(5) << endl;
    cout << "fib(10) = " << fibonacci(10) << endl;  // Still fast
    cout << "fib(20) = " << fibonacci(20) << endl;  // Getting slow
}
```

Each Fibonacci call creates 2 more calls, which create 2 more each, and so on.
Like a chain letter - **it explodes!**

fib(5) = 15 function calls.

fib(10) = 177 function calls.

fib(20) = 21,891 function calls.

fib(50) = over 1 trillion calls (would take forever).

**O(2ⁿ) is impractical - avoid it by using better techniques like storing results.**

---


To sum up, **Big O** helps us predict which algorithms will handle growth efficiently 
and which will collapse under increasing data.