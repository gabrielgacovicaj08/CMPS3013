#include <iostream>

using namespace std;

class Heap{
    int *heap;
    int bum;
    
    void bubble_up(int i){
        int parent = i/2;
        while(heap[parent] > heap[i]){
            swap(parent, i);
            i = parent;
            parent = i/2;
            if(!parent) {
                break
            }
        }
    }

    void swap(int i, int j){
        int temp = heap[i];
        heap[i] = heap[j];

    }

    public:
    Heap(){
        heap = new int[100];
        bum = 1;

    }

    int pop(){return 0;}
    void push(int x){
        heap[bum] = x;
        bum++;
        bubble_up(bum - 1);
    }
}
int main() {
    
    return 0;
}
