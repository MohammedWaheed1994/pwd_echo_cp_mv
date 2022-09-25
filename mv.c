#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
 


int main(int argc, char* argv[])
{
int fd_Original = 0;
int fd_Copy = 0;
char Buf[500];
int NumberOfReadBytes = 1;
	fd_Original = open(argv[1] ,O_RDWR);
	if(fd_Original == -1)
	{
		if(errno == ENOENT)
		{
			write(1, "File does not exit! \n",22);
		}
		else
		{
			write(1,"General error! \n",16); 
		}

	}
	else
	{
	
		fd_Copy = creat(argv[2],00777);
		
		if(fd_Copy == -1)
		{
			write(1,"Cannot create file! \n",22);
		}
		else
		{
			do
			{
			NumberOfReadBytes = read(fd_Original, Buf, 500);
			write(fd_Copy,Buf,NumberOfReadBytes);
			}
			while(NumberOfReadBytes != 0);
			(void)close(fd_Original);
			
			(void)unlink(argv[1]);			
		}

	}

	return 0;
}
	
