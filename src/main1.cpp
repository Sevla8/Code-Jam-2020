#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <set>

int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;

	for (int x = 1; x <= T; ++x) {
		int N;
		std::cin >> N;

		int M[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				std::cin >> M[i][j];
			}
		}

		int k = 0;
		for (int i = 0; i < N; ++i) {
			k += M[i][i];
		}

		int r = 0;
		bool found = false;
		for (int i = 0; i < N; ++i) {
			found = false;
			for (int j = 0; j < N && !found; ++j) {
				for (int l = j+1; l < N; ++l) {
					if (M[i][j] == M[i][l]) {
						r += 1;
						found = true;
						break;
					}
				}
			}
		}

		int c = 0;
		found = false;
		for (int j = 0; j < N; ++j) {
			found = false;
			for (int i = 0; i < N && !found; ++i) {
				for (int l = i+1; l < N; ++l) {
					if (M[i][j] == M[l][j]) {
						c += 1;
						found = true;
						break;
					}
				}
			}
		}

		std::cout << "Case #" << x << ": " << k << " " << r << " " << c << std::endl;
	}

	return 0;
}
