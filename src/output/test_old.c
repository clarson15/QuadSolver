#include <stdio.h>
#include <unistd.h>
#include "foutput.h"

int main(int argc, char* argv[]){
	foutput("Test123", STDOUT_FILENO);
	return 0;
}
