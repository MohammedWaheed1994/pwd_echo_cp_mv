#include <string.h>
#include <unistd.h>



int main(int argc, char* argv[])
{
int iterator = 0;

	for(iterator = 1; iterator < argc; iterator++)
	{
		write(1, argv[iterator],strlen(argv[iterator]));
		write(1, " ",1);	
	}	
	write(1,"\n",1);




	return 0;
}
