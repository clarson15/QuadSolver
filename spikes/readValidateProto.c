#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function takes a buffer containing a line and an integer with
 * the character length of the line. The function takes a line and 
 * makes sure the arguments can be put into float values. 
 *
 * Flaws: I may have inadvertanly combined both the readline function and
 * the validate function we need into one function. I'll have to look into 
 * this later. Also, this only works on the basis that the input will not
 * be in scientific notation. Also signicant unit testing still needs to
 * be implemented.
 */
int readLine(int n, char * buf)
{
	char line[300];
	strcpy(line, buf);
	char *tokens[3];
	int ret = 1;

	//Splits line into 3 tokens seperated by spaces.
	tokens[0] = strtok(line, " ");
	for(int i = 1; i < 3; i++)
	{
		tokens[i] = strtok(NULL, " ");
	}

    //Returns error code 0 if too few arguments
	if(tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL)
	{
		ret = 0;

	} 

    //Returns error code -1 if one or more arguments isn't a valid float
	else if(atof(tokens[0]) == 0.0 || atof(tokens[1]) == 0.0 || atof(tokens[2]) == 0.0)
	{
		ret = -1;
	}

	return ret;
}

//Tests readLine function
void testReadLine()
{
	char * line = "1.8 2.5 3.7";
	int t = readLine((int) strlen(line), line);
	printf("%d\n", t);

	line = "1.8 2.5";
	t = readLine((int) strlen(line), line);
	printf("%d\n", t);

	line = "A bad line";
	t = readLine((int) strlen(line), line);
	printf("%d\n", t);
}

//Runs tests
int main()
{
	testReadLine();
}

