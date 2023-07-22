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

struct interval {
	int S;
	int E;

	bool conflict(const interval &other) const {
		return this->S < other.S && this->E > other.S || other.S < this->S && other.E > this->S;
	}

	bool conflict(const std::vector<interval> &other) const {
		for (std::vector<interval>::const_iterator it = other.begin(); it != other.end(); ++it) {
			if (this->conflict(*it)) {
				return true;
			}
		}
		return false;
	}
};

bool operator<(const interval &a, const interval &b) {
	return a.S == b.S ? a.E < b.E : a.S < b.S;
}

int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;

	for (int x = 1; x <= T; ++x) {
		int N;
		std::cin >> N;

		interval activities[N];
		for (int i = 0; i < N; ++i) {
			interval inter;
			std::cin >> inter.S;
			std::cin >> inter.E;

			activities[i] = inter;
		}

		std::vector<interval> Cameron;
		std::vector<interval> Jamie;
		std::string y = "";
		bool impossible = false;

		for (int i = 0; i < N; ++i) {

// std::cout << y << std::endl;

			interval inter = activities[i];
			if (!inter.conflict(Cameron)) {
				Cameron.push_back(inter);
				y.push_back('C');
			}
			else if (!inter.conflict(Jamie)) {
				Jamie.push_back(inter);
				y.push_back('J');
			}
			else {
				y = "IMPOSSIBLE";
				impossible = true;
				break;
			}
		}

		std::cout << "Case #" << x << ": " << y << std::endl;
	}

	return 0;
}
