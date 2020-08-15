#include <iostream>

extern void parse(const char *path);

int main(int argc, char *argv[]) {
	if (argc > 1) {
		parse(argv[1]);
	} else {
		parse("");
	}
	
	return 0;
}
