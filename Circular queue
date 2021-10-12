#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct circularqueue{
	int size;
	int r;
	int f;
	int *arr;
};

int isempty(struct circularqueue *q){
	if (q->r==q->f){
		return 1;
	}
	return 0;
	
}

int isfull(struct circularqueue *q){
	if (((q->r+1)%q->size)==q->f){
		return 1;
	}
	return 0;
}

void enqueue(struct circularqueue *q , int val){
	if (isfull(q)){
		cout<<"this queue is full "<<endl ;
		
	}
	else {
		q->r==(q->r+1)%q->size;
		q->arr[q->r]=val;
		cout<<"Enqued element "<<val<<endl;
	}
	
}

int dequeue(struct circularqueue *q){
	int a=-1;
	if (isempty(q)){
		cout<<" this queue is empty : "<<endl;
	}
	else {
		q->f=(q->f+1)%q->size;
		a=q->arr[q->f];
		
	}
	return -1;
}

int main(){
	struct circularqueue q;
	q.size=4;
	q.f = q.r = 0;
	q.arr=(int*) malloc(q.size*sizeof(int));
	
//	enqueue the elements 
	enqueue(&q , 12);
	enqueue(&q , 15);
	enqueue(&q , 35);
//	dequeue(&q );
	cout<<"Dequeuing the elelments "<<dequeue(&q)<<endl;
	cout<<"Dequeuing the elelments "<<dequeue(&q)<<endl;
	cout<<"Dequeuing the elelments "<<dequeue(&q)<<endl;
	enqueue(&q , 45);
	enqueue(&q , 45);
	enqueue(&q , 45);
	
	if (isempty(&q)){
		cout<<" Queue is empty ";
		cout<<endl;
	}
	if (isfull(&q)){
		cout<<" Queue is full ";
		cout<<endl;
	}
	return 0;
	
	
}
