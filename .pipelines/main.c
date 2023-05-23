/*
 * Main.c
 *
 *  Created on: May 18, 2023
 *      Author: gogoCow
 */


#include "main.h"
#include "resetRegister.h"
#include "registerMonitor.h"

static const cyclic_ptr c_InitJob[] =
{
	&configureRegister,
}


static const cyclic_ptr c_cylicJob[] =
{
	&checkRegisterErr,
	&receiveDataHandling,
	&errorHandling,
	&resetHandling,
	&someTp,
}


void _main (void)
{
	unsigned int index =0;
	
	/* Running starting Jobs */
	while (c_InitJob[index] !=NULL)
	{
		c_InitJob[index]();
		index++;
	}
	/* reset index to prepare for cyclic task*/
	index = 0;
	/* running cyclic task*/
	while (true)
	{
		/* Running cylic Jobs */
		while (c_cylicJob[index] !=NULL)
		{
			c_cylicJob[index]();
			index++;
		}
	}
		
}



