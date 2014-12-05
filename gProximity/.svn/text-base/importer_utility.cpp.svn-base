/*
 *  gProximity Library.
 *  
 *  
 *  Copyright (C) 2010 University of North Carolina at Chapel Hill.
 *  All rights reserved.
 *  
 *  Permission to use, copy, modify, and distribute this software and its
 *  documentation for educational, research, and non-profit purposes, without
 *  fee, and without a written agreement is hereby granted, provided that the
 *  above copyright notice, this paragraph, and the following four paragraphs
 *  appear in all copies.
 *  
 *  Permission to incorporate this software into commercial products may be
 *  obtained by contacting the University of North Carolina at Chapel Hill.
 *  
 *  This software program and documentation are copyrighted by the University of
 *  North Carolina at Chapel Hill. The software program and documentation are
 *  supplied "as is", without any accompanying services from the University of
 *  North Carolina at Chapel Hill or the authors. The University of North
 *  Carolina at Chapel Hill and the authors do not warrant that the operation of
 *  the program will be uninterrupted or error-free. The end-user understands
 *  that the program was developed for research purposes and is advised not to
 *  rely exclusively on the program for any reason.
 *  
 *  IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR ITS
 *  EMPLOYEES OR THE AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
 *  SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS,
 *  ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE
 *  UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED
 *  OF THE POSSIBILITY OF SUCH DAMAGE.
 *  
 *  THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
 *  DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY
 *  STATUTORY WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS
 *  ON AN "AS IS" BASIS, AND THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND
 *  THE AUTHORS HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
 *  ENHANCEMENTS, OR MODIFICATIONS.
 *  
 *  Please send all BUG REPORTS to:
 *  
 *  geom@cs.unc.edu
 *  
 *  The authors may be contacted via:
 *  
 *  Christian Lauterbach, Qi Mo, Jia Pan and Dinesh Manocha
 *  Dept. of Computer Science
 *  Frederick P. Brooks Jr. Computer Science Bldg.
 *  3175 University of N.C.
 *  Chapel Hill, N.C. 27599-3175
 *  United States of America
 *  
 *  http://gamma.cs.unc.edu/GPUCOL/
 *  
 */
 
#include "importer_utility.h"
#include "ctype.h"
#include "string.h"

bool importer_equal_strings(char* string1, char* string2)
{
	int i;
	int nchar;
	int nchar1;
	int nchar2;
	
	nchar1 = strlen(string1);
	nchar2 = strlen(string2);
	
	if(nchar1 < nchar2)
	{
		nchar = nchar1;
	}
	else
	{
		nchar = nchar2;
	}
	/*
	  The strings are not equal if they differ over their common length.
	*/
	for(i = 0; i < nchar; i++)
	{
	
		if(toupper(string1[i]) != toupper(string2[i]))
		{
			return false;
		}
	}
	/*
	  The strings are not equal if the longer one includes nonblanks
	  in the tail.
	*/
	if(nchar1 > nchar)
	{
		for(i = nchar; i < nchar1; i++)
		{
			if(string1[i] != ' ')
			{
				return false;
			}
		}
	}
	else if(nchar2 > nchar)
	{
		for(i = nchar; i < nchar2; i++)
		{
			if(string2[i] != ' ')
			{
				return false;
			}
		}
	}
	return true;
}


int importer_rcol_find(float a[][COR3_MAX], int m, int n, float r[])
{
	int i;
	int icol;
	int j;
	
	icol = -1;
	
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < m; i++)
		{
			if(a[i][j] != r[i])
			{
				break;
			}
			if(i == m - 1)
			{
				return j;
			}
		}
	}
	
	return icol;
}


long int importer_long_int_read(FILE *filein, bool byte_swap)
{
	union
	{
		long int yint;
		char ychar[4];
	} y;
	
	if(byte_swap)
	{
		y.ychar[3] = fgetc(filein);
		y.ychar[2] = fgetc(filein);
		y.ychar[1] = fgetc(filein);
		y.ychar[0] = fgetc(filein);
	}
	else
	{
		y.ychar[0] = fgetc(filein);
		y.ychar[1] = fgetc(filein);
		y.ychar[2] = fgetc(filein);
		y.ychar[3] = fgetc(filein);
	}
	
	return y.yint;
}


float importer_float_read(FILE *filein, bool byte_swap)
{
	float rval;
	float temp;
	
	fread(&temp, sizeof(float), 1, filein);
	
	if(byte_swap)
	{
		rval = importer_float_reverse_bytes(temp);
	}
	else
	{
		rval = temp;
	}
	
	return rval;
}

float importer_float_reverse_bytes(float x)
{
	char c;
	union
	{
		float yfloat;
		char ychar[4];
	} y;
	
	y.yfloat = x;
	
	c = y.ychar[0];
	y.ychar[0] = y.ychar[3];
	y.ychar[3] = c;
	
	c = y.ychar[1];
	y.ychar[1] = y.ychar[2];
	y.ychar[2] = c;
	
	return (y.yfloat);
}

short int importer_short_int_read(FILE *filein)
{
	unsigned char  c1;
	unsigned char  c2;
	short int      ival;
	
	c1 = fgetc(filein);
	c2 = fgetc(filein);
	
	ival = c1 | (c2 << 8);
	
	return ival;
}