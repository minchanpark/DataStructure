//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchan Park] Student Number: [21800270]
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include "quecir.h"
using namespace std;
using quecir = CircularQueue*;

quecir newCircularQueue(int capa, int shown){
    quecir s = new CircularQueue;
    s->items = new string[capa]; 
    s->front = -1;
    s->back = -1;
    s->capa=capa;
    s->shown=shown;
    return s;
}

bool full(quecir q) {
    if (q->front == -1) {
        return false;
    }

    if (q->front <= q->back) {
        return q->back - q->front + 1 == q->capa;
    } else {
        return q->back - q->front + 1 + q->capa == q->capa;
    }
}

bool empty(quecir q){
    return q->front == -1;
}

int size(quecir q) {
    if (q->front == -1) return 0;

    int sizenum = 0;
    if(q->front==q->back){
        return sizenum=1;
    }
    else if (q->front < q->back) {
        for (int i = q->front; i <= q->back; i++) {
            sizenum++;
        }
    }
    else if (q->front>q->back) {
        for (int i = q->front; i <= q->capa; i++) {
            sizenum++;
        }
        for (int i = 0; i <= q->front; i++) {
            sizenum++;
        }
    }
    return sizenum;
}

void resize(quecir q, int new_capacity) {
    string* copied = new string[new_capacity];
    int qsize = size(q);
    int j = 0;

    if (qsize > 0) {
        int i = q->front;
        do {
            copied[j++] = q->items[i];
            i = (i + 1) % q->capa;
        } while (i != (q->back + 1) % q->capa);
    }
    delete[] q->items;
    q->front = 0;
    q->back = qsize - 1;
    q->items = copied;
    q->capa = new_capacity;
}


void enqueue(quecir q, string item) {
    int newFront = 0;

   if (full(q)) {
        int newCapacity = q->capa * 2;
        resize(q, newCapacity);
    }

    if (empty(q)) {
        q->back = 0;
        q->front = 0;
        q->items[q->back] = item;
    }
    else{
        q->back = (q->back + 1) % q->capa;
        q->items[q->back] = item;
    }
    
}

string dequeue(quecir q){ 
    string item = q->items[q->front];

    if(q->front == q->back){
        q->back=-1;
        q->front=-1;
        return item;
    }
    else if(q->front<q->back) {
        q->front = (q->front + 1) % q->capa;
    }
    else if(q->front>q->back){
        q->front = (q->front + 1) % q->capa;
    }

    if(size(q)==(q->capa/4)){
        int newCapacity = q->capa / 2;
        resize(q, newCapacity);
    }
    return item;
}

void clear(quecir q){
    q->front=-1;
    q->back=-1;
    for(int i=0; i<q->capa; i++){
        q->items[i]='-';
    }
}
void show_setup(quecir q){// display the current status of the queue
    cout<<"\tSetup: back=["<<q->front<<":"<<q->back<<"], ";
    cout<<"size="<<size(q)<<",";
    cout<<"capacity="<<q->capa<<",";
    cout<<"resize by 2x, show n=32\n";
}   
void show_items(quecir q){
    cout<<"items: [ ";
    if(q->front ==-1){
        for(int i=0; i<q->capa; i++){
            cout<<"- ";
        }
    }
    else if(q->front==0&&q->back==0){
        cout<<q->items[q->front];
        for(int i=1; i<q->capa; i++){
            cout<<"- ";
        }
    }
    else if(q->front<q->back) {
        for(int i=0; i<q->front; i++){
            cout<<"- ";
        }
        for(int i=q->front; i<=q->back; i++){
            cout<<q->items[i]<<" ";
        }
        for(int i=q->back+1; i<q->capa; i++){
            cout<<"- ";
        }
    }
    else if(q->front>q->back){
        for(int i=0; i<=q->capa; i++){
            if(i==q->back)cout<<q->items[i]<<" ";
            else if(i==q->front){
                for(int j=q->front;  j<=q->capa; j++){
                    cout<<q->items[j]<<" ";
                }
            }
            else{cout<<"- ";}
        }
    }
    cout<<"]";
}
void free(quecir q){
    delete[] q->items;
    delete q;
}
void reset(quecir q, int new_capacity){
    free(q);
    q->items=new string[new_capacity];
    q->back=-1;
    q->front=-1;
    q->capa=new_capacity;
    for(int i=0; i<q->capa; i++){
        cout<<"- ";
    }
}
void show_queue(quecir q) { // display quecir status
    int i=0; 
    cout << "\tQueue:[ ";

    if(size(q)==0){
        cout << " ]\n";
        return;
    }

    else if(q->front<q->back){
        for(int i=q->front; i<=q->back; i++){
            cout<<q->items[i]<<" ";
        }
    }
    else if(q->front>q->back){
        for(int i=q->front; i<size(q); i++){
            cout<<q->items[i]<<" ";
        }
        for(int i=0; i<q->back; i++){
            cout<<q->items[i]<<" ";
        }
    }
    else if(q->back==q->front){
        cout<<q->items[0];
    }
    cout << " ]\n";
    return;
}

