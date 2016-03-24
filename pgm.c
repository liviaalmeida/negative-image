#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

PGM *ReadsPGM(char* input)
{
	PGM* img;
	char* type;
	int i, j;
	int aux;

	/* Allocates space for img and type */
	img = (PGM*)malloc(sizeof(PGM));
	type = (char*)malloc(3*(sizeof(char)));

	/* Input data */
	FILE *file;
	file = fopen(input,"r");
	fgets(type,3,file);
	fscanf(file,"%d %d %d",&img->lenght,&img->width,&img->maxv);

	/* Allocates space for data matrix */
	img->data=(unsigned char**)malloc(img->width*(sizeof(unsigned char*)));
	for (i=0; i<img->width; i++)
	{
		img->data[i]=(unsigned char*)malloc(img->lenght*(sizeof(unsigned char)));
	}

	/* Reads data from image and casts value as char to store on data matrix */
	for (i=0; i<img->width; i++)
	{
		for (j=0; j<img->lenght; j++)
		{
			fscanf(file,"%d",&aux);
			img->data[i][j] = (unsigned char) aux;
		}
	}
	free(type);
	return img;
}

void SavesPGM(PGM *img, char* output)
{
	int i, j;
	int aux;

	/* Opens output file and writes initial values */
	FILE *file;
	file = fopen(output,"w");
	fprintf(file,"P2\n%d %d\n%d\n",img->lenght,img->width,img->maxv);

	 /* Prints value stored as char to output file as int */
	for (i=0; i<img->width; i++)
	{
		for (j=0; j<img->lenght; j++)
		{
			aux = (int) img->data[i][j];
			fprintf(file,"%d ",aux);
		}
	}
}

void NegativeRegion(PGM *img, int x0, int y0, int x1, int y1)
{
	int i, j;
	for (i=x0; i<x1; i++)
	{
		for (j=y0; j<y1; j++)
		{
			img->data[i][j] = img->maxv - img->data[i][j];
		}
	}
}

void NegativeImage(PGM *img)
{
	int i, j;
	for (i=0; i<img->width; i++)
	{
		for (j=0; j<img->lenght; j++)
		{
			img->data[i][j] = img->maxv - img->data[i][j];
		}
	}
}