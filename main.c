#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

int main (int argc, char **argv)
{
	PGM img;
	if(argc == 7)
	{
		img = *ReadsPGM(argv[1]);
		NegativeRegion(&img,atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]));
		SavesPGM(&img,argv[2]);
	}
	else
	{
		if (argc == 3)
		{
			img = *ReadsPGM(argv[1]);
			NegativeImage(&img);
			SavesPGM(&img,argv[2]);
		}
		else
		{
			printf("Number of arguments is not fit to execution");
		}
	}
	return 0;
}