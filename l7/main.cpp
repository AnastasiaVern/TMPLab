#include <stdio.h>
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	string library;
	cin >> library;

	HINSTANCE h;

	void(*add) (int);
	void(*get) ();
	void(*del) ();

	if (library == "Queue.dll") h = LoadLibrary(TEXT("F1.dll"));
	if (library == "Prior_Queue.dll")h = LoadLibrary(TEXT("F2.dll"));
	if (!h)
	{
		printf("The library cannot be finded\n");
		system("pause");
		return 0;
	}
	else {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string command;
			cin >> command;
			if (command == "add") {
				int n;
				cin >> n;
				add = (void(*) (int))GetProcAddress(h, "add");
				add(n);
			}
			if (command == "get") {
				get = (void(*) ())GetProcAddress(h, "get");
				get();
			}
			if (command == "del") {
				del = (void(*) ())GetProcAddress(h, "del");
				del();
			}
		}
	}

	FreeLibrary(h);

	return 0;
}
