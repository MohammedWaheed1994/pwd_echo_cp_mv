#include <unistd.h>
#include <string.h>



int main(int argc, char **argv)
{
char CurrentWorkingDirectory[100];
size_t Size = 100;
char *Test;
Test = getcwd(CurrentWorkingDirectory, Size);
if(Test == NULL)
{

write(1,"Directory is too long \n",23);

}
	
else
{
write(1,CurrentWorkingDirectory, strlen(CurrentWorkingDirectory));

write(1, "\n",1);
}
return 0;
}
