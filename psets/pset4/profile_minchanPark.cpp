//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [minchanPark]] Student Number: [21800270]

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <ctime>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <vector>
#include "sort.h"
#include "rand.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// a helper function
// Compute the number of digit first and return step size such as 100, 1000, 10000 etc.
// Refer to some instructions provided in pset pdf file.
int getStep(int n) {
	int digit = 1;
	int step = 1;

	// compute the number of digit first
	do {
		n = n / 10;
		if (n > 0) digit++;
	} while (n > 0);

	// compute the step
	for (int i = 0; i < (digit - 1); i++)
		step *= 10;
	return step;
}

void profiling(void (*sort_fp)(int*, int, bool (*comp)(int, int)), int* list, const int n, 
               bool (*comp_fp)(int, int)) {
	
	int *saved = new (nothrow) int[n];		// to save the original list into a buffer
	assert(saved != nullptr);
	copy_n(list, n, saved);         		// to use the same sequence during repetitions

	cout << "         N\t repetitions\t   sort(sec)\n";
	for (int i = STARTING_SAMPLES; i <= n; i += getStep(i)) {
		long repetitions = 0;
		clock_t start = clock();
		do {
			repetitions++;                    		// count the repetitions for one second
			copy_n(saved, n, list);	          		// get a copy of list from saved
			sort_fp(list, i, comp_fp);          	// sort
		} while (clock() - start < CLOCKS_PER_SEC); // run it over one sec

		double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		duration /= repetitions;

		cout << fixed;
		cout << setw(10) << i << "\t"
			 << setw(12) << repetitions << "\t"
			 << setw(12) << duration << endl;
	}

	delete[] saved;
}

#if 1
int main(int argc, char *argv[]) {
	int N = 0;
	setvbuf(stdout, nullptr, _IONBF, 0); // prevent the output from buffered on console.

	if (argc == 1) {
		string str;
		cout << "The minimum number of entries is set to " << STARTING_SAMPLES << endl;
		cout << "Enter the number of max entries to sort: ";
		getline(cin, str);
		stringstream ss(str);
		ss >> N;
	}
	else if (argc == 2) {
		char *end;
		N = strtol(argv[1], &end, 10);
		if (N <= 0 || *end != '\0')
			std::cout << "Usage: profiling [N]\n";
	}

	if (N <= STARTING_SAMPLES) {
		cout << "Enter a number greater than " << STARTING_SAMPLES << ".\n";
		exit(EXIT_FAILURE);
	}

	cout << "The maximum sample data size is " << N << endl;
	
	int *list = new (nothrow) int[N];
	assert(list != nullptr);

	vector<string> sort_st = {"insertionsort", "mergesort", "quicksort"};
    void (*sort_fp[])(int*, int, bool (*comp)(int, int)) = {
        insertionsort, mergesort, quicksort};

    for (vector<string> ::size_type s = 0; s < sort_st.size(); s++) {
        cout << "\n" << sort_st[s] << "(): sorted" << endl;
        for (int i = 0; i < N; i++) list[i] = i; 
        profiling(sort_fp[s], list, N, ::less);

        cout << "\n" << sort_st[s] << "(): randomized" << endl;
        randomize(list, N);
        profiling(sort_fp[s], list, N, ::less); 

        cout << "\n" << sort_st[s] << "(): reversed" << endl;
        int j = N - 1;
        for (int i = 0; i < N; i++) list[i] = j--; 
        profiling(sort_fp[s], list, N, ::less);
    }

    delete[] list;
    return EXIT_SUCCESS;
}
#endif
