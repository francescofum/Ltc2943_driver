
#include "Ltc2943.h"
#include "Ltc2943_Regs.h"

#include <stdio.h>

/***********************/
/*   Obj Operations    */
/***********************/

/******************************************
 * @brief LTC2943_Initialise - Initialise the LTC2943
 * @param[in] self: Ltc2943 - Reference on the object
 * 
 ******************************************/
bool LTC2943_Initialise(Ltc2943* const self)
{
    bool result = false;

    /* TODO: Complete LTC2943_Initialise*/
    printf("LTC2943_Initialise called.\n");

    return result;
}

/******************************************
 * @brief LTC2943_Read - Read from LTC2943
 * @param[in] self: Ltc2943 - Reference on the object
 * @param[in] address: Ltc2943_Regs - Address to read from
 *            (Note for Astroscale: I changed it from uint8_t to Ltc2943_Regs for clarity.)
 * @param[in] dest: uint8_t - Buffer to store read value to
 * @param[in] dataSize: uint8_t - Number of bytes to read
 * @return bool: true if successful, false if unsuccessful
 * 
 ******************************************/
bool LTC2943_Read(Ltc2943* const self, Ltc2943_Regs address, uint8_t *dest, uint8_t dataSize)
{
    bool result = false;

    /* TODO: Complete LTC2943_Read*/
    printf("LTC2943_Read called.\n");

    return result;
}

/******************************************
 * @brief LTC2943_Write - Write from LTC2943
 * @param[in] self: Ltc2943 - Reference on the object
 * @param[in] address: Ltc2943_Regs - Address to write to 
 *            (Note for Astroscale: I changed it from uint8_t to Ltc2943_Regs for clarity.)
 * @param[in] dest: uint8_t - Buffer to store write data
 * @param[in] dataSize: uint8_t - Number of bytes to write
 * @return bool: true if successful, false if unsuccessful
 * 
 ******************************************/
bool LTC2943_Write(Ltc2943* const self, Ltc2943_Regs address, uint8_t *src, uint8_t dataSize)
{
    bool result = false;
    
    /* TODO: Complete LTC2943_Write*/
    printf("LTC2943_Write called.\n");

    return result;
}

/**************************************/
/* Methods for implemented interfaces */
/**************************************/

/******************************************
 * @brief LTC2943_getAdcMode - Get the adc mode
 * @param[in] self: Ltc2943 - Reference on the object
 * @return ChipCtrl_Mode: The adc mode or E_MODE_ERROR
 *   if something went wrong with the read.
 * 
 ******************************************/
ChipCtrl_Mode LTC2943_getAdcMode(Ltc2943* const self)
{
    ChipCtrl_Mode result = E_MODE_ERROR;
    uint8_t ctrl_reg = 0;
    bool rRes = false;

    /* Read the control register */
    rRes = LTC2943_Read(self, LTC2943_REG_CTRL, &ctrl_reg, LTC2943_REG_SIZE);
    ctrl_reg &= (LTC2943_ADC_BITS);

    if (true == rRes)
    {
        if (LTC2943_AUTOMATIC_MODE== ctrl_reg) 
        {
            result = E_MODE_AUTOMATIC;
        }
        else if (LTC2943_SCAN_MODE == ctrl_reg) 
        {
            result = E_MODE_SCAN;
        }
        else if (LTC2943_MANUAL_MODE == ctrl_reg) 
        {
            result = E_MODE_MANUAL;
        }
        else if (LTC2943_SLEEP_MODE == ctrl_reg) 
        {
            result = E_MODE_SLEEP;
        }
        else { /* Error case */
            result = E_MODE_ERROR;
            printf("Error, mode not recognised: %d.\n", ctrl_reg);
        }
    }

    return result; 
}

/******************************************
 * @brief LTC2943_setAdcMode - Set the adc mode
 * @param[in] self: Ltc2943 - Reference on the object
 * @param[in] mode: ChipCtrl_Mode - The adc mode
 * @return ChipCtrl_Status: Status of the operation, E_STATUS_OK or E_STATUS_ERROR 
 *   if something went wrong with the read.
 * 
 ******************************************/
ChipCtrl_Status LTC2943_setAdcMode(Ltc2943* const self, ChipCtrl_Mode mode)
{
    ChipCtrl_Status result = E_STATUS_ERROR;
    uint8_t ctrl_reg = 0;
    bool rwRes = false;

    /* Read the control register */
    rwRes = LTC2943_Read(self, LTC2943_REG_CTRL, &ctrl_reg, LTC2943_REG_SIZE);

    if (true == rwRes)
    {
        /* Clear the adc bits from control register */
        ctrl_reg &= ~(LTC2943_ADC_BITS);

        if (E_MODE_AUTOMATIC == mode) 
        {
            ctrl_reg |= LTC2943_AUTOMATIC_MODE;
            rwRes = LTC2943_Write(self, LTC2943_REG_CTRL, &ctrl_reg, LTC2943_REG_SIZE);
        }
        else if (E_MODE_SCAN == mode)
        {
            ctrl_reg |= LTC2943_SCAN_MODE;
            rwRes = LTC2943_Write(self, LTC2943_REG_CTRL, &ctrl_reg, LTC2943_REG_SIZE);
        }
        else if (E_MODE_MANUAL == mode)
        {
            ctrl_reg |= LTC2943_MANUAL_MODE;
            rwRes = LTC2943_Write(self, LTC2943_REG_CTRL, &ctrl_reg, LTC2943_REG_SIZE);
        }
        else if (E_MODE_SLEEP == mode)
        {
            ctrl_reg |= LTC2943_SLEEP_MODE;
            rwRes = LTC2943_Write(self, LTC2943_REG_CTRL, &ctrl_reg, LTC2943_REG_SIZE);
        }
        else { /* Error case, mode is not valid. Raise error to user. */
            printf("ChipCtrl_Mode mode is not correct: %d\n", mode);
        }
    }

    /* Update the result */
    if (true ==  rwRes) 
    {
        result = E_STATUS_OK;
    }

    return result;
}

/******************************************
 * @brief LTC2943_getTempAlert - Get the temp alert
 * @param[in] self: Ltc2943 - Reference on the object
 * @return ChipCtrl_Status: Status of the operation, E_STATUS_OK or E_STATUS_ERROR 
 *   if something went wrong with the read.
 * 
 ******************************************/
ChipCtrl_Alert LTC2943_getTempAlert(Ltc2943* const self)
{
    ChipCtrl_Alert result = E_ALERT_ERROR;
    uint8_t sts_reg = 0;
    bool rRes = false;

    /* Read the status register */
    rRes = LTC2943_Read(self, LTC2943_REG_STS, &sts_reg, LTC2943_REG_SIZE);

    if (true == rRes)
    {
        result = (sts_reg & LTC2943_TEMPERATURE_ALERT)? E_ALERT_ON:E_ALERT_OFF;
    }

    return result;
}

/******************************************
 * @brief LTC2943_setChrgThr - Set the upper and lower charge thresholds
 * @param[in] self: Ltc2943 - Reference on the object
 * @param[in] uint16_t: upper - The upper threshold
 * @param[in] uint16_t: lower - The lower threshold
 * @return ChipCtrl_Status: Status of the operation, E_STATUS_OK or E_STATUS_ERROR 
 *   if something went wrong with the read.
 * 
 ******************************************/
ChipCtrl_Status LTC2943_setChrgThr(Ltc2943* const self, uint16_t upper, uint16_t lower)
{
    ChipCtrl_Status result = E_STATUS_ERROR;
    uint16_t upperThreshold; 
    uint16_t lowerThreshold;
    uint8_t msb;
    uint8_t lsb;
    bool wRes = false;

    /*  
        From the datasheet (https://www.analog.com/media/en/technical-documentation/data-sheets/2943fa.pdf)

        Ihigh (dec) = ((((UpperThreshInAmps * Rsense)/fullScalePositiveVoltage)  * excessRepresentation) + excessRepresentation))
        Ilow  (dec) = ((((-UpperThreshInAmps * Rsense)/fullScalePositiveVoltage) * excessRepresentation) + excessRepresentation))

        Where: 
            1) UpperThreshInAmps is set by the user.
            2) Rsense
            3) fullScalePositiveVoltage is taken from the datasheet to be 60mV
            4) excessRepresentation is taken from the datasheet to be 32767
    */

    /* Conver the threshold to binary representation based on the above equations. TODO: double check */
    upperThreshold = ((
                        (
                            ((float)upper * self->rSense) / LTC2943_FULL_SCALE_POS_VOLTAGE
                        ) * LTC2943_THRESH_EXCESS_REPR
                     ) + LTC2943_THRESH_EXCESS_REPR) + 0.5 /* add 0.5 to ensure that it's rounded up. */;

    lowerThreshold = ((
                        (
                            ((float)(-1*lower) * self->rSense) / LTC2943_FULL_SCALE_POS_VOLTAGE
                        ) * LTC2943_THRESH_EXCESS_REPR
                     ) + LTC2943_THRESH_EXCESS_REPR) + 0.5 /* add 0.5 to ensure that it's rounded up. */;

    /* Write data to registers Q and R for upper */
    msb = ((uint16_t)upperThreshold >> 8);
    lsb = ((uint16_t)upperThreshold & 0xFF);
    /* Write the data */
    wRes = LTC2943_Write(self, LTC2943_REG_CURRENT_THR_HIGH_MSB, &msb, LTC2943_REG_SIZE);
    if (true == wRes) /* Write the lsb if previous write was successful */
    {
        wRes = LTC2943_Write(self, LTC2943_REG_CURRENT_THR_HIGH_MSB, &lsb, LTC2943_REG_SIZE);
        if (true == wRes){ /* Write data to registers S and T for lower thresh, if previous write was success. */
            msb = (lowerThreshold >> 8);
            lsb = (lowerThreshold & 0xFF);
            /* Write the data */
            wRes = LTC2943_Write(self, LTC2943_REG_CURRENT_THR_HIGH_MSB, &msb, LTC2943_REG_SIZE);
            if (true == wRes) /* Write the lsb */
            {
                wRes = LTC2943_Write(self, LTC2943_REG_CURRENT_THR_HIGH_MSB, &lsb, LTC2943_REG_SIZE);
            }
            result = E_STATUS_OK;
            /* Update values in object */
            LTC2943_setChrgUpprThr(self, upperThreshold);
            LTC2943_setChrgLowThr(self, lowerThreshold);
        }

    }
    return result;
}

/******************************************
 * @brief LTC2943_getChrgAlert - Get the charge alert 
 * @param[in] self: Ltc2943 - Reference on the object
 * @return ChipCtrl_Alert: Alert status or E_ALERT_ERROR is operation failed. 
 * 
 ******************************************/
ChipCtrl_Alert LTC2943_getChrgAlert(Ltc2943* const self)
{
    ChipCtrl_Alert result = E_ALERT_ERROR;
    bool rRes = false;
    uint8_t status_reg = 0;
    bool chrgAlertHigh; 
    bool chrgAlertLow;

    /* Check status register bit 2 and bit 3 to get the alert */
    rRes = LTC2943_Read(self, LTC2943_REG_CTRL, &status_reg, LTC2943_REG_SIZE);
    chrgAlertHigh = (status_reg & LTC2943_CHARGE_ALERT_HIGH);
    if (true == rRes)
    {
        rRes = LTC2943_Read(self, LTC2943_REG_CTRL, &status_reg, LTC2943_REG_SIZE);
        chrgAlertLow = (status_reg & LTC2943_CHARGE_ALERT_LOW);  
    }
    if (true == rRes)
    {
        result = ((true == chrgAlertHigh) | (true == chrgAlertLow))
            ? E_ALERT_ON:E_ALERT_OFF;
    }

    return result;
}

/* Default initialiser for the LTC2943 object*/
void LTC2943_initDft(Ltc2943* const self)
{
    self->chrgLowThr = 0;
    self->chrgUpprThr = 0;
    self->rSense = 50; /* Value used in the datasheet */

    IChipCtrl_init(&self->iChipCtrl, self, LTC2943_Initialise, 
                   LTC2943_getAdcMode, LTC2943_setAdcMode,
                   LTC2943_getTempAlert, LTC2943_setChrgThr,
                   LTC2943_getChrgAlert);
}
