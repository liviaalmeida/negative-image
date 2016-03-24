#ifndef PGM_H_INCLUDED
#define PGM_H_INCLUDED

typedef struct {
     int lenght;
     int width;
     int maxv;
     unsigned char **data;
} PGM;

/*----------------------------------------------------------------------------------------------------
 * Reads PGM
 *
 * Reads image in PGM format and returns struct PGM
  ----------------------------------------------------------------------------------------------------*/
PGM *ReadsPGM (char* input);

/*----------------------------------------------------------------------------------------------------
 * Saves PGM
 *
 * Saves output file with negative image
  ----------------------------------------------------------------------------------------------------*/
void SavesPGM (PGM *img, char* output);

/*----------------------------------------------------------------------------------------------------
 * Negative Region
 *
 * Transforms only area between x0-x1 and y0-y1 to negative
  ----------------------------------------------------------------------------------------------------*/
void NegativeRegion (PGM *img, int x0, int y0, int x1, int y1);

/*----------------------------------------------------------------------------------------------------
 * Negative Image
 *
 * Transforms whole image to negative
  ----------------------------------------------------------------------------------------------------*/
void NegativeImage(PGM *img);

#endif // PGM_H_INCLUDED
