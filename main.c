#include "Ltc2943.h"
#include "IChipCtrl.h"

#include <stdio.h>


/* main.c */
int main(int argc, char *argv[]) {

    ChipCtrl_Mode adcMode = E_MODE_ERROR;
    ChipCtrl_Status status = E_STATUS_ERROR;
    ChipCtrl_Alert alert = E_ALERT_ERROR;

    /* Create a driver object */
    Ltc2943 Ltc2943_driver;
    
    /* Default initialisation of driver object */
    LTC2943_initDft(&Ltc2943_driver);

    /* Create a pointer to the interface, this should belong to the top level 
       structure e.g struct plsw
     */
    IChipCtrl* iChipCtrl;

    /* Get the interface from the driver which realises it
       This interface should be used throughout the code.
     */
    iChipCtrl = LTC2943_getIChipCtrl(&Ltc2943_driver);
    
    /* Get the ADC mode */
    adcMode = IChipCtrl_getAdcMode(iChipCtrl);
    /* Set the ADC mode */
    status = IChipCtrl_setAdcMode(iChipCtrl, E_MODE_AUTOMATIC);
    // status = IChipCtrl_setAdcMode(iChipCtrl, E_MODE_SCAN);
    // status = IChipCtrl_setAdcMode(iChipCtrl, E_MODE_MANUAL);
    // status = IChipCtrl_setAdcMode(iChipCtrl, E_MODE_SLEEP);

    /* Set the charge threshold */
    uint16_t upperThresh = 1; /* 1 amp */
    uint16_t lowerThresh = 1; /* 1 amp */
    alert = IChipCtrl_setChrgThr(iChipCtrl, upperThresh, lowerThresh);

    /* Get the temperature alert status */
    alert = IChipCtrl_getTempAlert(iChipCtrl);
    /* Get the charge alert status */
    alert = IChipCtrl_getChrgAlert(iChipCtrl);

    return 0;
}

