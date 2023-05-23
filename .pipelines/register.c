/*
 * register.c
 *
 *  Created on: May 18, 2023
 *      Author: gogoCow
 */

#include "resetRegister.h"
#include "registerMonitor.h"

static RLIN_Register LIN_Rx3;
int baseAddr;
int regBufferRx[255];
int regBufferTx[255];
int dataLen;
int regStatus;


int mirro_regBufferRx[256];
int mirro_regBufferTx[256];

void configureRegister (void)
{
    LIN_Rx3 = RLIN_Rx3_REGISTERCONFIG;
    return;
}

void checkRegisterErr (void)
{
   
    return;
}

void receiveDataHandling (void)
{

    return;
}
void errorHandling (void)
{
    int idx;
    if (LIN_Rx3.registerStatus&TX_ERROR)
    {
        /* clear TX buffer */
        for (idx = 0; idx < 255; idx++)
        {
            LIN_Rx3.regBufferRx[idx] = 0x00;
        }
        
    }
    else if  (LIN_Rx3.registerStatus&RX_ERROR)
    {
        /* clear RX buffer */
        for (idx = 0; idx < 255; idx++)
        {
            LIN_Rx3.regBufferRx[idx] = 0x00;
        }
    }
    
    return;
}
void resetHandling (void)
{
    if (LIN_Rx3.registerStatus&&0xFF)
    {
        LIN_Rx3.registerStatus = 0x00;
    }
    errorHandling();
    return;
}

void rxHandling(void)
{
    int idx = 0;

    idx = LIN_Rx3.length;
    /* copy data to the mirror*/
    do {
        mirro_regBufferRx[idx] = LIN_Rx3.regBufferRx[idx];
        idx--;
    }  while (idx>0)
    return;
}

void txHandling (void)
{
    int idx = 0;

    idx = LIN_Rx3.length;
    /* copy data to the mirror*/
   do {
        LIN_Rx3.regBufferTx[idx] = mirro_regBufferTx[idx];
        idx--;
   }  while (idx>0)
    return;
}

void someTp (void)
{
    int idx = 0;
    int calCS = 0;
    /*Calculate checksum*/
    for (idx = 0; i < (LIN_Rx3.length - 1); i++)
    {
        calCS = calCS + LIN_Rx3.regBufferRx[idx];
    }
    
    if (calCS != LIN_Rx3.regBufferRx[idx])
    {
        resetHandling();
    }
   
}