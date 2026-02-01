# Array Abstract Data Type (Array ADT)
An Array Abstract Data Type (ADT) is a logical model for an ordered collection of homogeneous elements, defining operations to access, modify, insert, and delete data using integer indices. It abstracts away implementation details, focusing on functionality like get(index) and set(index, value) rather than how memory is allocated.

## Creating an Array ADT

In this lesson, we will create an **Array ADT** that encapsulates common array operations, making them simple and accessible through a clean interface defined in the **array.h** class.

### Why Build an Array ADT?

Once our Array ADT is complete, operations like sorting become much simpler and more intuitive.

**Before (Traditional C++ approach):**
```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

**After (Using Array ADT):**
```cpp
array.sort();
```

This approach is similar to Python's elegant syntax:
```python
list.sort()
```

### What We'll Build

We will implement the underlying functionality for operations like `sort()`, `search()`, `insert()`, and `delete()` within our Array ADT, providing a clean, reusable interface for array manipulation.


# Coding Array ADT Functions

In this section, we will use **C++ Templates** to create a generic Array ADT that works with any data type, not just a fixed one.

### Supported Data Types

Our templated Array ADT will support:

- `int`
- `float`
- `char`
- `string`
- Any user-defined data types (classes/structs)

### What are Templates in C++?

**A C++ template is a powerful feature that enables us to write generic classes or functions. This allows us to create code that works with any data type without rewriting it for each specific type.**

Templates provide **type flexibility** and **code reusability**.

### Template Syntax

Here's how we implement templates in our Array ADT:
```cpp
template <typename T>
class ArrayADT {
private:
    T *arr;      // Pointer to array of type T
    int size;    // Maximum capacity
    int length;  // Current number of elements
};
```

**Key Points:**
- `template <typename T>` declares a template with type parameter `T`
- `T` is a placeholder that can be replaced with any data type
- When you see `T` in the code, think "any possible data type"

### Creating Instances
```cpp
ArrayADT<int> intArray(10);       // Array of integers
ArrayADT<string> strArray(5);     // Array of strings
ArrayADT<double> doubleArray(8);  // Array of doubles
```

The compiler generates appropriate code for each data type at compile time.


# Array ADT functions
### 0. Constructor of our Array ADT
As we know that Array ADT is fundamentally a class so it needs a constructor. In this constructor we will be doing the basic stuff like : 
- Making the dynamic array be ```new``` keyword 
- allocating size 
- initializing length to 0
```cpp
    ArrayADT(int size){
        capacity=size;
        this->length=0;
        arr=new T [size];
        cout<<"Array of size "<<size<<" created!"<<endl;
    }


```

## Table of Contents
1. [append()](#1-arrayappend)
2. [prepend()](#2-arrayprepend)
3. [display()](#3-arraydisplay)
4. [getLength()](#4-arraygetlength)
5. [isEmpty()](#5-arrayisempty)
6. [get()](#6-arrayget)
7. [clear()](#7-arrayclear)
8. [remove()](#8-arrayremove)
9. [insert()](#9-arrayinsert)
10. [set()](#10-arrayset)
11. [linearSearch()](#11-arraylinearsearch)
12. [bubbleSort()](#12-arraybubblesort)
13. [selectionSort()](#13-arrayselectionSort)
14. [insertionSort()](#14-arrayinsertionsort)
15. [binarySearch()](#15-arraybinarysearch)
16. [min()](#16-arraymin)
17. [max()](#17-arraymax)
18. [reverse()](#18-arrayreverse)
19. [removeFirst()](#19-arrayremovefirst)
20. [removeLast()](#20-arrayremovelast)
21. [isSorted()](#21-arrayissorted)
22. [frequency()](#22-arrayfrequency)
23. [hasDuplicates()](#23-arrayhasduplicates)

---

### 1. `Array.append()`

This function is responsible for insertion of element in array depending upon what is stored in length (a variable that marks the size of filled array). Also known as appending an element to an array.

```cpp
void append(T element){
    arr[length]=element;
    length++;
}
```

**Time Complexity: O(1)**

Since we need to perform two operations that are:
- Insertion of the element in length position (end of array)
- Incrementing length by 1

So the number of steps are **f(n) = 2** and Time Complexity is **O(1)**.

---

### 2. `Array.prepend()`

This function is responsible for insertion of element at the beginning of the array (index 0). It shifts all existing elements one position to the right before inserting the new element.

```cpp
void prepend(T element){
    if(length>=capacity){
        cout<=0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=element;
    }
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Check if array is full
- Shift all n elements one position to the right
- Insert the element at index 0
- Increment length by 1

So the number of steps are **f(n) = n + 3** and Time Complexity is **O(n)**.

---

### 3. `Array.display()`

This function is responsible for displaying all elements currently stored in the array from index 0 to length-1.

```cpp
void display(){
    for(int i=0;i<length;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Traverse through all n elements in the array
- Print each element

So the number of steps are **f(n) = n** and Time Complexity is **O(n)**.

---

### 4. `Array.getLength()`

This function is responsible for returning the current number of elements stored in the array (not the total capacity).

```cpp
int getLength(){
    return length; 
}
```

**Time Complexity: O(1)**

Since we need to perform only one operation:
- Return the value of length variable

So the number of steps are **f(n) = 1** and Time Complexity is **O(1)**.

---

### 5. `Array.isEmpty()`

This function is responsible for checking whether the array is empty or not. It returns true if the array contains no elements, false otherwise.

```cpp
bool isEmpty(){
    return (length==0);
}
```

**Time Complexity: O(1)**

Since we need to perform only one operation:
- Compare length with 0 and return the result

So the number of steps are **f(n) = 1** and Time Complexity is **O(1)**.

---

### 6. `Array.get()`

This function is responsible for retrieving the element stored at a specified index. It performs boundary checks to ensure the index is valid.

```cpp
T get(int index){
    if(index < 0 || (index>length && index=capacity){
        cout<<"Operation out of bounds."<<endl;
    }
    else{
        return arr[index];
    }
}
```

**Time Complexity: O(1)**

Since we need to perform the following operations:
- Check if index is valid
- Access and return the element at the given index

So the number of steps are **f(n) = 2** and Time Complexity is **O(1)**.

---

### 7. `Array.clear()`

This function is responsible for clearing all elements in the array by setting them to 0 (or default value).

```cpp
void clear(){
    for(int i=0;i<length;i++){
        arr[i]=0;
    }
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Traverse through all n elements in the array
- Set each element to 0

So the number of steps are **f(n) = n** and Time Complexity is **O(n)**.

---

### 8. `Array.remove()`

This function is responsible for removing an element at a specified index. It shifts all elements after the removed element one position to the left.

```cpp
void remove(int index){
    if(index < 0 || index >= length){
        cout<<"No element there for deletion."<<endl;
    }
    else{
        for(int i=index; i<length-1;i++){
            arr[i]=arr[i+1];
        }
        length--;
    }
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Check if index is valid
- Shift all elements after the index one position to the left
- Decrement length by 1

So the number of steps are **f(n) = n - index** and Time Complexity is **O(n)** in the worst case.

---

### 9. `Array.insert()`

This function is responsible for inserting an element at a specified index. It shifts all elements from that index onwards one position to the right.

```cpp
void insert(int index , T element){
    if(index < 0 || index >= length){
        cout<=capacity){
        cout<index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        length++;
    }
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Check if index is valid and array is not full
- Shift all elements from index to end one position to the right
- Insert the element at the given index
- Increment length by 1

So the number of steps are **f(n) = length - index + 3** and Time Complexity is **O(n)** in the worst case.

---

### 10. `Array.set()`

This function is responsible for updating the value of an element at a specified index with a new value.

```cpp
void set(int index ,T element){
    if(index < 0 || index >= length){
        cout<<"Operation out of bounds."<<endl;
    }
    else{
        arr[index]=element;
    }
}
```

**Time Complexity: O(1)**

Since we need to perform the following operations:
- Check if index is valid
- Update the element at the given index

So the number of steps are **f(n) = 2** and Time Complexity is **O(1)**.

---

### 11. `Array.linearSearch()`

This function is responsible for searching for an element in the array using linear search algorithm. It returns the index of the first occurrence of the element, or -1 if not found.

```cpp
int linearSearch(T element){
    for(int i=0;i<length;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Traverse through all elements in the array in worst case
- Compare each element with the target element

So the number of steps are **f(n) = n** in the worst case and Time Complexity is **O(n)**.

---

### 12. `Array.bubbleSort()`

This function is responsible for sorting the array in ascending order using the bubble sort algorithm. It repeatedly swaps adjacent elements if they are in wrong order.

```cpp
void bubbleSort(){
    T temp;
    bool swapped = false;
    for(int i=0;i arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped = true;
            }
        }
        if(!swapped){break;}
    }
}
```

**Time Complexity: O(n²)**

Since we need to perform the following operations:
- Run nested loops where outer loop runs n-1 times
- Inner loop runs n-i-1 times for each iteration
- Compare and swap adjacent elements if needed

So the number of steps are **f(n) = n × (n-1) / 2** in the worst case and Time Complexity is **O(n²)**.

---

### 13. `Array.selectionSort()`

This function is responsible for sorting the array in ascending order using the selection sort algorithm. It finds the minimum element and places it at the beginning in each iteration.

```cpp
void selectionSort(){
    T temp;
    for(int i=0;i<length-2;i++){
        int min_index=i;
        for(int j=i+1; j<length;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}
```

**Time Complexity: O(n²)**

Since we need to perform the following operations:
- Run nested loops where outer loop runs n-2 times
- Inner loop finds minimum element in unsorted portion
- Swap the minimum element with the first unsorted element

So the number of steps are **f(n) = n × (n-1) / 2** and Time Complexity is **O(n²)**.

---

### 14. `Array.insertionSort()`

This function is responsible for sorting the array in ascending order using the insertion sort algorithm. It builds the sorted array one element at a time by inserting each element into its correct position.

```cpp
void insertionSort(){
   T key;
   for(int i=1;i0 && arr[j-1] > key){
        arr[j] = arr[j-1];
        j--;
    }
    arr[j]=key;
   } 
}
```

**Time Complexity: O(n²)**

Since we need to perform the following operations:
- Run outer loop n-1 times
- For each element, shift all larger elements to the right
- Insert the current element at its correct position

So the number of steps are **f(n) = n × (n-1) / 2** in the worst case and Time Complexity is **O(n²)**.

---

### 15. `Array.binarySearch()`

This function is responsible for searching for an element in a sorted array using the binary search algorithm. It returns the index of the element if found, or -1 if not found.

```cpp
int binarySearch(T element){
    int start = 0;
    int end = length - 1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
```

**Time Complexity: O(log n)**

Since we need to perform the following operations:
- Divide the search space in half in each iteration
- Compare the middle element with target element
- Continue until element is found or search space is empty

So the number of steps are **f(n) = log₂(n)** and Time Complexity is **O(log n)**.

---

### 16. `Array.min()`

This function is responsible for finding and returning the minimum element in the array. It traverses through all elements to find the smallest value.

```cpp
int min(){
    T minimum = arr[0];
    for(int i=1; i<length; i++){
        if(arr[i] < minimum){
            minimum = arr[i];
        }
    }
    return minimum;
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Initialize minimum with first element
- Traverse through all remaining n-1 elements
- Compare each element with current minimum

So the number of steps are **f(n) = n-1** and Time Complexity is **O(n)**.

---

### 17. `Array.max()`

This function is responsible for finding and returning the maximum element in the array. It traverses through all elements to find the largest value.

```cpp
int max(){
    T maximum = arr[0];
    for(int i=1; i maximum){
            maximum = arr[i];
        }
    }
    return maximum;
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Initialize maximum with first element
- Traverse through all remaining n-1 elements
- Compare each element with current maximum

So the number of steps are **f(n) = n-1** and Time Complexity is **O(n)**.

---

### 18. `Array.reverse()`

This function is responsible for reversing the order of elements in the array. It swaps elements from both ends moving towards the center.

```cpp
void reverse(){
    T temp;
    int start = 0;
    int end = length -1;
    while(start <= end){
        temp = arr[start];
        arr[start]=arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Swap elements from start and end moving towards center
- Continue until start and end pointers meet

So the number of steps are **f(n) = n/2** and Time Complexity is **O(n)**.

---

### 19. `Array.removeFirst()`

This function is responsible for removing the first element (at index 0) from the array. It internally calls the remove() function.

```cpp
void removeFirst(){
    this->remove(0);
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Call remove(0) which shifts all remaining elements one position to the left

So the time complexity is the same as remove() and is **O(n)**.

---

### 20. `Array.removeLast()`

This function is responsible for removing the last element from the array. It internally calls the remove() function with the last index.

```cpp
void removeLast(){
    this->remove(length-1);
}
```

**Time Complexity: O(1)**

Since we need to perform the following operations:
- Call remove(length-1) which doesn't require shifting any elements
- Only decrements length by 1

So the number of steps are **f(n) = 1** and Time Complexity is **O(1)**.

---

### 21. `Array.isSorted()`

This function is responsible for checking whether the array is sorted in ascending order. It returns true if sorted, false otherwise.

```cpp
bool isSorted(){
    for(int i=0;i arr[i+1]){
            return false;
        }
    }
    return true;
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Traverse through all elements comparing adjacent pairs
- Return false immediately if any pair is out of order

So the number of steps are **f(n) = n-1** in the worst case and Time Complexity is **O(n)**.

---

### 22. `Array.frequency()`

This function is responsible for counting and returning the number of occurrences of a specified element in the array.

```cpp
int frequency(T element){
    int count = 0;
    for(int i=0;i<length;i++){
        if(arr[i] == element){
            count++;
        }
    }
    return count;
}
```

**Time Complexity: O(n)**

Since we need to perform the following operations:
- Traverse through all n elements in the array
- Compare each element with the target element
- Increment counter when match is found

So the number of steps are **f(n) = n** and Time Complexity is **O(n)**.

---

### 23. `Array.hasDuplicates()`

This function is responsible for checking whether the array contains any duplicate elements. It returns true if at least one element appears more than once, false otherwise.

```cpp
bool hasDuplicates(){
    for(int i=0; i<length-1; i++){
        for(int j=i+1; j<length; j++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }
    return false;
}
```

**Time Complexity: O(n²)**

Since we need to perform the following operations:
- Run nested loops comparing each element with every other element
- Outer loop runs n-1 times
- Inner loop runs n-i-1 times for each iteration
- Return true immediately if duplicate is found

So the number of steps are **f(n) = n × (n-1) / 2** in the worst case and Time Complexity is **O(n²)**.
