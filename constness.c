#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * http://stackoverflow.com/questions/16021454/difference-between-declared-string-and-allocated-string/16021546#16021546
 */

int main (int argc,char** argv)
{
	const char* constVal="ConstValue";
	char* const constPtr=(char*)malloc(sizeof(char*));
	char* const constPtr1="without malloc";
	*constPtr="ConstPointer";
	const char* val="NewValue";
	const char* val1="NewPointer";
	constVal=val;
	//*constVal="Cannot do this";
	char stack[]="On stack";
	strcpy(constPtr,val1);
	strcpy(stack,"No stack");	
	printf("%s\n%s\n%s\n%s\n",constPtr,constVal,constPtr1,stack);
	free(constPtr);
	return 0;
}
