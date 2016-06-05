#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
vector<int> my_tree;

extern "C" {
	__declspec(dllexport) void add(int k) {
		int i;
		if (my_tree.size() == 0)
			my_tree.insert(my_tree.begin(), k);
		else {
			for (i = 0; i < my_tree.size(); i++) {
				if (k <= my_tree[i]) {
					my_tree.insert(my_tree.begin() + i, k);
					break;
				}
			}
			if (i == my_tree.size())
				my_tree.push_back(k);
		}
	}


	__declspec(dllexport) void get() {
		cout << my_tree[0] << endl;
	}

	__declspec(dllexport) void del() {
		my_tree.erase(my_tree.begin());
	}
}
