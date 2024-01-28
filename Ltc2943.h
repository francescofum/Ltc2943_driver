#ifndef LTC2943_H
#define LTC2943_H

#include "IChipCtrl.h"
#include "Ltc2943_Regs.h"

#include <stdbool.h>


typedef struct Ltc2943
{
    /* Implemented interface */
    IChipCtrl iChipCtrl;

    /* The upper charge threshold. These are updated when LTC2943_setChrgThr is called. 
       Currently not used but could be used to optimise the driver so that when a call
       to get the thresholds happens the Ltc2943 won't have to be queried and this value 
       can simply be returned. Same can be done with the ADC mode.
    */
    uint8_t chrgUpprThr; 

    /* The lower charge threshold */
    uint8_t chrgLowThr;

    /* Value of sense resistor */
    uint8_t rSense;

}Ltc2943;

/***********************/
/* Getters and setters */
/***********************/

/* chrgUpprThr getter */
inline static uint8_t LTC2943_getChrgUpprThr(Ltc2943* const self);
/* chrgUpprThr setter */
inline static void LTC2943_setChrgUpprThr(Ltc2943* const self, uint8_t upper);

/* chrgLowThr getter */
inline static uint8_t LTC2943_getChrgLowThr(Ltc2943* const self);
/* chrgLowThr setter */
inline static void LTC2943_setChrgLowThr(Ltc2943* const self, uint8_t lower);

/***********************/
/*  Implemented Intf   */
/***********************/
inline static IChipCtrl* LTC2943_getIChipCtrl(Ltc2943* const self);

/***********************/
/*     Operations      */
/***********************/

/* 
Note to Astroscale: I have slightly modified the functions 
        initialise, read and write. I have added the "self" 
        parameter just to keep it in line with the rest of the code.
*/

/* Initialise the device */
bool LTC2943_Initialise(Ltc2943* const self);
/* Read data from src to the chip @address to dest */
bool LTC2943_Read(Ltc2943* const self, Ltc2943_Regs address, uint8_t *dest, uint8_t dataSize);
/* Write data from src to the chip @address */ 
bool LTC2943_Write(Ltc2943* const self,Ltc2943_Regs address, uint8_t *src, uint8_t dataSize);
/* Default initialiser */
void LTC2943_initDft(Ltc2943* const self);


/**************************************/
/* Methods for implemented interfaces */
/**************************************/
ChipCtrl_Mode LTC2943_getAdcMode(Ltc2943* const self);
ChipCtrl_Status LTC2943_setAdcMode(Ltc2943* const self, ChipCtrl_Mode mode);
ChipCtrl_Alert LTC2943_getTempAlert(Ltc2943* const self);
ChipCtrl_Status LTC2943_setChrgThr(Ltc2943* const self, uint16_t upper, uint16_t lower);
ChipCtrl_Alert LTC2943_getChrgAlert(Ltc2943* const self);


/******************************************/
/* Inline methods for getters and setters */
/******************************************/

/* chrgUpprThr getter */
inline static uint8_t LTC2943_getChrgUpprThr(Ltc2943* const self)
{
    return self->chrgUpprThr;
}
/* chrgUpprThr setter */
inline static void LTC2943_setChrgUpprThr(Ltc2943* const self, uint8_t upper)
{
    self->chrgUpprThr = upper;
}
/* chrgLowThr getter */
inline static uint8_t LTC2943_getChrgLowThr(Ltc2943* const self)
{
    return self->chrgLowThr;
}
/* chrgLowThr setter */
inline static void LTC2943_setChrgLowThr(Ltc2943* const self, uint8_t lower)
{
    self->chrgLowThr = lower;
}
/* rSense getter */
inline static uint8_t LTC2943_getRSense(Ltc2943* const self)
{
    return self->rSense;
}
/* rSense setter */
inline static void LTC2943_setRSense(Ltc2943* const self, uint8_t rSense)
{
    self->rSense = rSense;
}

inline static IChipCtrl* LTC2943_getIChipCtrl(Ltc2943* const self)
{
    return &self->iChipCtrl;
}
#endif /* LTC2943_H */