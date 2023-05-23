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
};


static const cyclic_ptr c_cylicJob[] =
{
	&checkRegisterErr,
	&receiveDataHandling,
	&errorHandling,
	&resetHandling,
	&someTp,
};



void run_startup (void)
{
	unsigned int index =0;
	/* Running starting Jobs */
	while (c_InitJob[index] !=NULL)
	{
		c_InitJob[index]();
		index++;
	}
	return;
}

void run_cyclic (void)
{
	unsigned int index =0;
	/* Running cylic Jobs */
	while (c_cylicJob[index] !=NULL)
	{
		c_cylicJob[index]();
		index++;
	}

	return;
}

int main (void)
{
	/* running startup task*/
	run_startup();

	/* running cyclic task*/
	while (true)
	{
		run_cyclic();
	}
		
}



