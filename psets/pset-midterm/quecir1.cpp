//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;
// size of circular queue, a magic number
const int SIZE = 5;
struct CircularQueue {
    string items[SIZE];
    int front;
    int back;
};
using quecir = CircularQueue *;

quecir newCircularQueue(){
    quecir q = new CircularQueue;
    q->front = -1;
    q->back = -1;
    return q;
}
bool full(quecir q){
    if (q->front == 0 && q->back == SIZE - 1) return true;
    if (q->front == q->back + 1) return true;
    return false;
}
bool empty(quecir q){
    return q->front == -1;
}
void enqueue(quecir q, string item){
    if(full(q)){
        cout << "Queue is full" << endl;
        return;
    } 

    if(q->front == -1) q->front = 0;
    q->back = (q->back + 1) % SIZE;
    q->items[q->back] = item;
    cout << "enqueued: " << item << endl;
}
string dequeue(quecir q){
 if (empty(q)){
    cout << "Queue is empty" << endl;
    return "";
 } 
 string item = q->items[q->front];

 if(q->front == q->back){
    q->front = -1;
    q->back = -1;
 } // q has only one item, we reset the q after deleting it.
 else {
    q->front=(q->front + 1) % SIZE;
 }

 return item;
}

void display(quecir q) { // display quecir status
 int i; 
 if(empty(q)){
    cout << endl << "Empty Queue" << endl;
 }
 else {
    cout << "Front:Back = [" << q->front << ":" << q->back << "]\n";
    cout << "Items:[ ";
    if(q->front>q->back){
        for (i = q->front; i < SIZE; i++) { 
            cout << q->items[i] << ' '; 
        }
        cout << q->items[q->back];
        cout << " ]\n";
        return;
    }
    for(i = q->front; i != q->back; i = i + 1){ cout << q->items[i] << ' ';}
    cout << q->items[i];
    cout << " ]\n";
 }
}

int main() {
    quecir q = newCircularQueue();
    dequeue(q); 
    enqueue(q, "a");
    enqueue(q, "b");
    enqueue(q, "c");
    enqueue(q, "d");
    enqueue(q, "e");
    enqueue(q, "f"); 
    display(q);
    string item = dequeue(q);
    cout << "dequeued: " << item << endl;
    display(q);
    enqueue(q, "g");
    display(q);
    enqueue(q, "h"); 
    dequeue(q);
    dequeue(q);
    display(q); 
    return 0;
}
