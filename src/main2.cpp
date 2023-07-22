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
		std::string S;
		std::cin >> S;

		std::string y = "";

		int current_depth = 0;
		int current_position = 0;
		for (std::string::const_iterator it = S.begin(); it != S.end(); ++it) {
			int digit_int = *it - '0';
			std::string digit_string(1, *it);

			int current_depth_tmp = current_depth;

			for (int i = 0; i < current_depth_tmp-digit_int; ++i) {
				y.insert(current_position, ")");
				++current_position;
				--current_depth;
			}

			current_depth_tmp = current_depth;

			for (int i = 0; i < digit_int-current_depth_tmp; ++i) {
				y.insert(current_position, "(");
				++current_depth;
				++current_position;
			}

			y.insert(current_position, digit_string);
			++current_position;


		}

		for (int i = 0; i < current_depth; ++i) {
			y.insert(current_position, ")");
			++current_position;
		}

		std::cout << "Case #" << x << ": " << y << std::endl;
	}

	return 0;
}
