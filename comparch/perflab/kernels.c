/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "zhy",              /* Team name */

    "Haoyu Zhao",     /* First member full name */
    "zhaohy16@mails.tsinghua.edu.cn",  /* First member email address */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
  int i, j;
  int p,q;

  for (i = 0; i < dim; i += 16) {
    for (j = 0; j < dim; j ++) {
      //for (t = j; t < j + 16; t++) {
	p = (dim - 1 - j) * dim + i;
	q = i * dim + j;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	dst[p++] = src[q];q += dim;
	  //dst[RIDX(dim-1-t, s, dim)] = src[RIDX(s, t, dim)];
      //}
    }
  }
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
  int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	  dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
  int i, j;
  int cur_idx,cur_idx_u,cur_idx_d;
  int r_1,r_2,r_3,g_1,g_2,g_3,b_1,b_2,b_3;

  pixel cur_pixel;

  i = 0;
  j = 0;
  cur_pixel.red =
    (unsigned short)(((int)(src[RIDX(0, 0, dim)].red + src[RIDX(0, 1, dim)].red +
			    src[RIDX(1, 0, dim)].red + src[RIDX(1, 1, dim)].red)) /
		     4);
  cur_pixel.green =
    (unsigned short)(((int)(src[RIDX(0, 0, dim)].green + src[RIDX(0, 1, dim)].green +
			    src[RIDX(1, 0, dim)].green + src[RIDX(1, 1, dim)].green)) /
		     4);
  cur_pixel.blue =
    (unsigned short)(((int)(src[RIDX(0, 0, dim)].blue + src[RIDX(0, 1, dim)].blue +
			    src[RIDX(1, 0, dim)].blue + src[RIDX(1, 1, dim)].blue)) /
		     4);
  dst[RIDX(0, 0, dim)] = cur_pixel;
  
  i = 0;
  j = dim - 1;
  cur_pixel.red =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
			    src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) /
		     4);
  cur_pixel.green =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
			    src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) /
		     4);
  cur_pixel.blue =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
			    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) /
		     4);
  dst[RIDX(i, j, dim)] = cur_pixel;
  
  i = dim - 1;
  j = 0;
  cur_pixel.red =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
			    src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) /
		     4);
  cur_pixel.green =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
			    src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) /
		     4);
  cur_pixel.blue =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
			    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) /
		     4);
  dst[RIDX(i, j, dim)] = cur_pixel;
  
  i = dim - 1;
  j = dim - 1;
  cur_pixel.red =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
			    src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red)) /
		     4);
  cur_pixel.green =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
			    src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green)) /
		     4);
  cur_pixel.blue =
    (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
			    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue)) /
		     4);
  dst[RIDX(i, j, dim)] = cur_pixel;
  
  j = 0;
  for (i = 1; i < dim - 1; i+=2)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
				src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red +
				src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
				src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green +
				src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
				src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue +
				src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;
      
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red +
				src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j + 1, dim)].red +
				src[RIDX(i + 2, j, dim)].red + src[RIDX(i + 2, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green +
				src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j + 1, dim)].green +
				src[RIDX(i + 2, j, dim)].green + src[RIDX(i + 2, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue +
				src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue +
				src[RIDX(i + 2, j, dim)].blue + src[RIDX(i + 2, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i + 1, j, dim)] = cur_pixel;
    }
  for (; i < dim - 1; i++)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
				src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red +
				src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
				src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green +
				src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
				src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue +
				src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;
    }
  
  i = dim - 1;
  for (j = 1; j < dim - 1; j+=2)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
				src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
				src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
				src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
				src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
				src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
				src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;

      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
				src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
				src[RIDX(i, j + 2, dim)].red + src[RIDX(i - 1, j + 2, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
				src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
				src[RIDX(i, j + 2, dim)].green + src[RIDX(i - 1, j + 2, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
				src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
				src[RIDX(i, j + 2, dim)].blue + src[RIDX(i - 1, j + 2, dim)].blue)) /
			 6);
      dst[RIDX(i, j + 1, dim)] = cur_pixel;
    }
  for (; j < dim - 1; j++)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
				src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
				src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
				src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
				src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
				src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
				src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;
    }
  
  j = dim - 1;
  for (i = 1; i < dim - 1; i+=2)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
				src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
				src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
				src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green +
				src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
				src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
				src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;

      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
				src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
				src[RIDX(i + 2, j, dim)].red + src[RIDX(i + 2, j - 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green +
				src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
				src[RIDX(i + 2, j, dim)].green + src[RIDX(i + 2, j - 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
				src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
				src[RIDX(i + 2, j, dim)].blue + src[RIDX(i + 2, j - 1, dim)].blue)) /
			 6);
      dst[RIDX(i + 1, j, dim)] = cur_pixel;
    }
  for (; i < dim - 1; i++)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
				src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
				src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
				src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green +
				src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
				src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
				src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;
    }
  
  i = 0;
  for (j = 1; j < dim - 1; j+=2)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
				src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
				src[RIDX(i, j + 1, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
				src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
				src[RIDX(i, j + 1, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
				src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
				src[RIDX(i, j + 1, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;

      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j + 1, dim)].red + src[RIDX(i + 1, j + 1, dim)].red +
				src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
				src[RIDX(i, j + 2, dim)].red + src[RIDX(i + 1, j + 2, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j + 1, dim)].green + src[RIDX(i + 1, j + 1, dim)].green +
				src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
				src[RIDX(i, j + 2, dim)].green + src[RIDX(i + 1, j + 2, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j + 1, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue +
				src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
				src[RIDX(i, j + 2, dim)].blue + src[RIDX(i + 1, j + 2, dim)].blue)) /
			 6);
      dst[RIDX(i, j + 1, dim)] = cur_pixel;
    }
  for (; j < dim - 1; j++)
    {
      cur_pixel.red =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
				src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
				src[RIDX(i, j + 1, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) /
			 6);
      cur_pixel.green =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
				src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
				src[RIDX(i, j + 1, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) /
			 6);
      cur_pixel.blue =
	(unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
				src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
				src[RIDX(i, j + 1, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) /
			 6);
      dst[RIDX(i, j, dim)] = cur_pixel;
    }

  //The main part
  cur_idx = dim + 1;
  cur_idx_u = cur_idx - dim;
  cur_idx_d = cur_idx + dim;
  for (i = 1; i < dim - 1; i++)
    {
      r_1 = src[cur_idx_u-1].red + src[cur_idx-1].red + src[cur_idx_d-1].red;
      g_1 = src[cur_idx_u-1].green + src[cur_idx-1].green + src[cur_idx_d-1].green;
      b_1 = src[cur_idx_u-1].blue + src[cur_idx-1].blue + src[cur_idx_d-1].blue;

      r_2 = src[cur_idx_u].red + src[cur_idx].red + src[cur_idx_d].red;
      g_2 = src[cur_idx_u].green + src[cur_idx].green + src[cur_idx_d].green;
      b_2 = src[cur_idx_u].blue + src[cur_idx].blue + src[cur_idx_d].blue; 

      r_3 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
      g_3 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
      b_3 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

      dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
      dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
      dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

      cur_idx++;
      cur_idx_u++;
      cur_idx_d++;

      for (j = 2; j < dim - 12; j+=12)
	{
	  r_1 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_1 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_1 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_2 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_2 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_2 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_3 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_3 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_3 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;


	  r_1 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_1 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_1 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_2 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_2 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_2 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_3 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_3 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_3 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;


	  r_1 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_1 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_1 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_2 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_2 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_2 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_3 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_3 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_3 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;


	  r_1 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_1 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_1 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_2 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_2 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_2 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_3 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_3 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_3 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;
	}

      for (; j < dim - 3; j+=3)
	{
	  r_1 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_1 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_1 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_2 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_2 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_2 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;

	  r_3 = src[cur_idx_u+1].red + src[cur_idx+1].red + src[cur_idx_d+1].red;
          g_3 = src[cur_idx_u+1].green + src[cur_idx+1].green + src[cur_idx_d+1].green;
          b_3 = src[cur_idx_u+1].blue + src[cur_idx+1].blue + src[cur_idx_d+1].blue;

          dst[cur_idx].red = (unsigned short)(((int)(r_1 + r_2 + r_3)) / 9);
          dst[cur_idx].green = (unsigned short)(((int)(g_1 + g_2 + g_3)) / 9);
          dst[cur_idx].blue = (unsigned short)(((int)(b_1 + b_2 + b_3)) / 9);

          cur_idx++;
          cur_idx_u++;
          cur_idx_d++;
	}

      for (; j < dim - 1; j++)
	{
	  cur_pixel.red =
	    (unsigned short)(((int)(src[cur_idx + dim].red + src[cur_idx + dim - 1].red +
				    src[cur_idx].red + src[cur_idx - dim].red +
				    src[cur_idx - 1].red + src[cur_idx - dim - 1].red +
				    src[cur_idx + 1].red + src[cur_idx - dim + 1].red +
				    src[cur_idx + dim + 1].red)) / 9);
	  cur_pixel.green =
	    (unsigned short)(((int)(src[cur_idx + dim].green + src[cur_idx + dim - 1].green +
				    src[cur_idx].green + src[cur_idx - dim].green +
				    src[cur_idx - 1].green + src[cur_idx - dim - 1].green +
				    src[cur_idx + 1].green + src[cur_idx - dim + 1].green +
				    src[cur_idx + dim + 1].green)) / 9);
	  cur_pixel.blue =
	    (unsigned short)(((int)(src[cur_idx + dim].blue + src[cur_idx + dim - 1].blue +
				    src[cur_idx].blue + src[cur_idx - dim].blue +
				    src[cur_idx - 1].blue + src[cur_idx - dim - 1].blue +
				    src[cur_idx + 1].blue + src[cur_idx - dim + 1].blue +
				    src[cur_idx + dim + 1].blue)) / 9);
	  dst[cur_idx] = cur_pixel;
	  cur_idx++;
	  cur_idx_u++;
	  cur_idx_d++;
	}
      cur_idx+=2;
      cur_idx_u+=2;
      cur_idx_d+=2;
    }
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

