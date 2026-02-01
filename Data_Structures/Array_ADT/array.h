#include<iostream>
using namespace std;
template <typename T>
class ArrayADT{
private:
    T *arr;
    int capacity;
    int length;
public:
    ArrayADT(int size){
        capacity=size;
        this->length=0;
        arr=new T [size];
        cout<<"Array of size "<<size<<" created!"<<endl;
    }

    void append(T element){
        arr[length]=element;
        length++;
    }

    void prepend(T element){
        if(length>=capacity){
            cout<<"Array already full."<<endl;
        }
        else{
        length++;
        for(int i=length+1;i>=0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=element;
    }
    }

    void display(){
        for(int i=0;i<length;i++){
            cout<<*(arr+i)<<" ";
        }
        cout<<endl;
    }

    int getLength(){
        return length; 
    }

    bool isEmpty(){
        return (length==0);
    }

    T get(int index){
        if(index < 0 || (index>length && index<capacity)){
            cout << "Uninitialized Element."<<endl;
        }
        else if(index>=capacity){
            cout<<"Operation out of bounds."<<endl;
        }
        else{
            return arr[index];
        }
    }

    void clear(){
        for(int i=0;i<length;i++){
            arr[i]=0;
        }
    }

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

    void insert(int index , T element){
        if(index < 0 || index >= length){
            cout<<"Operation out of bounds."<<endl;
        }
        else if(length>=capacity){
            cout<<"Array is full."<<endl;
        }  
        else{
            for(int i=length;i>index;i--){
                arr[i]=arr[i-1];
            }
            arr[index]=element;
            length++;
        }
    }

    void set(int index ,T element){
        if(index < 0 || index >= length){
            cout<<"Operation out of bounds."<<endl;
        }
        else{
            arr[index]=element;
        }
    }

    int linearSearch(T element){
        for(int i=0;i<length;i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }

    void bubbleSort(){
        T temp;
        bool swapped = false;
        for(int i=0;i<length-1;i++){
            for(int j=0;j<length-i-1;j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swapped = true;
                }
            }
            if(!swapped){break;}
        }
    }

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

    void insertionSort(){
       T key;
       for(int i=1;i<length;i++){
        key = arr[i];
        int j=i;
        while(j>0 && arr[j-1] > key){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j]=key;
       } 
    }

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

    int min(){
        this->bubbleSort();
        return this->arr[0];
    }

    int max(){
        this->bubbleSort();
        return this->arr[length-1];
    }

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

    void removeFirst(){
        this->remove(0);
    }

    void removeLast(){
        this->remove(length-1);
    }

    bool isSorted(){
        for(int i=0;i<length-1;i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    int frequency(T element){
        int count = 0;
        for(int i=0;i<length;i++){
            if(arr[i] == element){
                count++;
            }
        }
        return count;
    }

    int hasDuplicates(){
        for(int i=0;i<length-1;i++){
            for(int j=i+1;j<length;j++){
                if(arr[i]==arr[j]){
                    return true;
                }
            }
        }
        return true;
    }

};
