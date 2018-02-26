#include <string.h>

int readline(int n, char* buf);

int main(int argc, char* argv[])
{
	readline(strlen(argv[1]), argv[1]);
	return 0;
}

/* Trying to figure out what else this function needs to check for when it comes to errors.
*  Not sure if it needs anything else.
*/
int readline(int n, char* buf)
{
	int err = 1;

	//If the number of characters in the buffer does not match n
	//return error code 0.
	if(strlen(buf) != n)
	{
		err = 0;
	}

	return err;
}

