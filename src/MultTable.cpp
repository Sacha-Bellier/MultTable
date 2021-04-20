
#include "MultTable.h"

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <thread>

void Run(uint32_t nbToDo, bool print){

	uint32_t *diff = (uint32_t*)malloc(nbToDo * sizeof(uint32_t));
	uint32_t unit[100];
	uint32_t len = 0;

	if (print) {
		for (uint32_t m = 0; m < nbToDo; ++m)
			MultTable(m, nullptr, nullptr, &len, true);
	} else {
		std::thread** th = new std::thread * [10];

		for (int k = 0; k < 10; ++k)
			th[k] = new std::thread(MultTableThread, k, nbToDo, diff, unit, &len);

		for (int k = 0; k < 10; ++k)
			th[k]->join();

		for (uint32_t k = 0; k < nbToDo; ++k)
			std::cout << k << " : " << "RESULT : " << diff[k] << " different pattern\n";

		std::cout << "\n";
		for (uint32_t k = 0; k < len; ++k)
			std::cout << unit[k];

		std::cout << "\n";
	}
	free(diff);
}


void MultTableThread(uint32_t i, uint32_t nb, uint32_t* diff, uint32_t* unit, uint32_t* len) {
	bool fa = false;
	for (uint32_t m = 0; m < nb; m += 10)
		MultTable(m + i, diff, unit, len, fa);
}


void MultTable(uint32_t m, uint32_t* diff, uint32_t* unit, uint32_t* len, bool print) {

	uint32_t **seg = (uint32_t**)malloc(m * sizeof(uint32_t*));
	uint32_t *lenght = (uint32_t*)malloc(m * sizeof(uint32_t));

	for (uint32_t t = 0; t < m; ++t){
		seg[t] = new uint32_t[m];
		uint32_t len = 0;
		for (uint32_t k = 0; k < m; ++k) {
			uint32_t cp = (t * k) % m;
			if (k <= cp) {
				++len;
				seg[t][k] = cp;
			} else if (seg[t][cp] != k) {
				++len;
				seg[t][k] = cp;
			} else
				seg[t][k] = std::numeric_limits<uint32_t>::max();
		}
		lenght[t] = len;
	}

if (print) {
	std::cout << m << ": ";
}

	uint32_t tot = 0;
	for (uint32_t t = 0; t < m; ++t) {
		bool isMainRowEq = false;
		if(lenght[t] != 0) {
			for (uint32_t t_ = t + 1; t_ < m; ++t_) {
				bool isThisRowEq = lenght[t] == lenght[t_] && lenght[t_] != 0;
				if (isThisRowEq)
					for (uint32_t k = 0; k < m; ++k) {
						uint32_t val1 = seg[t][k];
						uint32_t val2 = seg[t_][k];

						if (val1 != std::numeric_limits<uint32_t>::max()) {
							if (val1 != val2) {
								if (seg[t_][val1] != k) {
									isThisRowEq = false;
									k = m;
								}
							}
						}
					}
				if (isThisRowEq) {
					if (print) {
						std::cout << t << "=" << t_ << " ; ";
					}
					isMainRowEq = true;
					lenght[t_] = 0;
				}
			}
		}
		if (!isMainRowEq)
			++tot;
	}

if (print) {
	std::cout << "RESULT : " << tot << " different pattern\n";
} else {
	diff[m] = tot;
	if (m == tot)
		unit[*len++] = m;
}

	for (uint32_t t = 0; t < m; ++t)
		free(seg[t]);
	free(seg);
	free(lenght);
}