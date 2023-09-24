#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func);
#endif

int partition(int list[], int io, int hi){
	DPRINT(
		cout<<"parktition pivot: "<<list[hi]<<endl
	);
	int pivot=list[hi];
	int i=(io-1);
	for(int j=io; j<=hi-1; j++){
		if(list[j]<=pivot){
			i++;
			swap(list[j], list[i]);
		}
	}
	swap(list[hi], list[i]);
	return (i+1);
}

void quicksort(int* list, int io, int hi){
	if(io<hi){
		int pi=partition(list, io, hi);
		DPRINT(cout<<" 1 pivot(" << pi<<")="<<list[pi]<<"\n");
		quicksort(list, io, pi-1);
		DPRINT(cout<<" r pivot("<< pi<<")="<<list[pi]<<"\n");
		quicksort(list, pi+1, hi);
	}
}

void quicksort(int *a, int n){
	quicksort(a, 0, n-1);
}

#if 1
int main(){
	int list[]={54, 26, 93, 17, 77, 31, 44, 55, 20};
	cout<<"UNSORTED: \n";
	for(auto x: list) cout<<x<<" "; cout<<endl;

	quicksort(list, sizeof(list)/sizeof(list[0]));
	cout<<"QUICK SORTED: \n";
	for(auto x: list) cout<<x<<" "; cout<<endl;
}
#endif

