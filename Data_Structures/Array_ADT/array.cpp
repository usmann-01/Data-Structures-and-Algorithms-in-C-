#include<iostream>
#include "array.h"
using namespace std;
int main(){
    ArrayADT<int>Arr(5);
    Arr.append(25);
    Arr.append(20);
    Arr.append(15);
    Arr.append(10);
    Arr.append(5);
    Arr.display();
    Arr.removeLast();
    Arr.display();
    Arr.clear();
    Arr.display();
}