/*
 * resetRegister.h
 *
 *  Created on: May 18, 2023
 *      Author: gogoCow
 */

#ifndef RESETREGISTER_H
#define RESETREGISTER_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "registerMonitor.h"


#define TX_ERROR  0x01
#define RX_ERROR  0x02
typedef struct registerCb_ST
{
    void (* funcRxCb) (void);
    void (* funcTxCb) (void);
    void (* funcErrHandlercb) (void);
} ;


typedef struct RLIN_Register
{
    /* data */
    int baseAddr;
    int * bufferRx;
    int * bufferTx;
    int length;
    int registerStatus;
    registerCb_ST CbFunc;
} ;


extern void configureRegister (void);

/*Pointers to callback function*/


#endif RESETREGISTER_H