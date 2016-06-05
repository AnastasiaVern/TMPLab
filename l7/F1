#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
vector<int> my_tree;

extern "C" {
	__declspec(dllexport) void add(int k) {
		my_tree.push_back(k);
	}

	__declspec(dllexport) void get() {
		cout << my_tree[0] << endl;
	}

	__declspec(dllexport) void del() {
		my_tree.erase(my_tree.begin());
	}
}
