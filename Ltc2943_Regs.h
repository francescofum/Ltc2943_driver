#ifndef LTC2943_REG_H
#define LTC2943_REG_H

#include <stdint.h>

#define BIT(n)  (((uint8_t)1) << n)
#define BIT_CLEAR(byte,to_clear) ((byte) &= BIT(to_clear))

/* All registers are 1 byte */
#define LTC2943_REG_SIZE (1)
/************************/
/* Status Register (A) */
/************************/
#define LTC2943_CURRENT_ALERT               (BIT(6))
#define LTC2943_ACC_CHRG_OVER_UNDER_FLOW    (BIT(5))
#define LTC2943_TEMPERATURE_ALERT           (BIT(4))
#define LTC2943_CHARGE_ALERT_HIGH           (BIT(3))
#define LTC2943_CHARGE_ALERT_LOW            (BIT(2))
#define LTC2943_VOLTAGE_ALERT               (BIT(1))
#define LTC2943_UNDERVOLTAGE_LOCK_ALERT     (BIT(0))

/************************/
/* Control Register (B) */
/************************/
/* ADC modes */
#define LTC2943_ADC_BITS		(BIT(7) | BIT(6))
#define LTC2943_AUTOMATIC_MODE  (BIT(7) | BIT(6))
#define LTC2943_SCAN_MODE       (BIT(7))
#define LTC2943_MANUAL_MODE     (BIT(6))
#define LTC2943_SLEEP_MODE      (BIT(0))

/* Prescaler modes */
#define LTC2943_PRESCALER_1     (BIT(0))
#define LTC2943_PRESCALER_4     (BIT(3))
#define LTC2943_PRESCALER_16    (BIT(4))
#define LTC2943_PRESCALER_64    (BIT(4) | BIT(3))
#define LTC2943_PRESCALER_256   (BIT(5))
#define LTC2943_PRESCALER_1024  (BIT(5) | BUT(3))
#define LTC2943_PRESCALER_4096  (BIT(5) | BIT(4))
#define LTC2943_PRESCALER_MAX   (LTC2943_PRESCALER_4096)

/* ALCC */
#define LTC2943_ALCC_ALERT              (BIT(2))
#define LTC2943_ALCC_CHRG_CMPLT_MODE    (BIT(1))
#define LTC2943_ALCC_DISABLE            (BIT(0))

/* Threshold defs */
#define LTC2943_THRESH_EXCESS_REPR (32767) /* Taken from datasheet TODO: double check. */
#define LTC2943_FULL_SCALE_POS_VOLTAGE (60)
/* Shutdown */
#define LTC2943_ALCC_SHUTDOWN    (BIT(0))


typedef enum  {
	LTC2943_REG_STS		                = 0x00,    
	LTC2943_REG_CTRL		            = 0x01,
	LTC2943_REG_ACC_CHRG_MSB	        = 0x02,
	LTC2943_REG_ACC_CHRG_LSB	        = 0x03,
	LTC2943_REG_CHARGE_THR_HIGH_MSB	    = 0x04,
	LTC2943_REG_CHARGE_THR_HIGH_LSB	    = 0x05,
	LTC2943_REG_CHARGE_THR_LOW_MSB	    = 0x06,
	LTC2943_REG_CHARGE_THR_LOW_LSB	    = 0x07,
	LTC2943_REG_VOLTAGE_MSB		        = 0x08,
    LTC2943_REG_VOLTAGE_LSB		        = 0x09,
    LTC2943_REG_VOLTAGE_THR_HIGH_MSB    = 0x0A,
    LTC2943_REG_VOLTAGE_THR_HIGH_LSB    = 0x0B,
    LTC2943_REG_VOLTAGE_THR_LOW_MSB     = 0x0C,
    LTC2943_REG_VOLTAGE_THR_LOW_LSB     = 0x0D,
    LTC2943_REG_CURRENT_MSB             = 0x0E,
    LTC2943_REG_CURRENT_LSB             = 0x0F,
    LTC2943_REG_CURRENT_THR_HIGH_MSB    = 0x10,
    LTC2943_REG_CURRENT_THR_HIGH_LSB    = 0x11,
    LTC2943_REG_CURRENT_THR_LOW_MSB     = 0x12,
    LTC2943_REG_CURRENT_THR_LOW_LSB     = 0x13,
	LTC2943_REG_TEMPERATURE_MSB	        = 0x14,
	LTC2943_REG_TEMPERATURE_LSB	        = 0x15,
	LTC2943_REG_TEMPERATURE_THR_HIGH	= 0x16,
	LTC2943_REG_TEMPERATURE_THR_LOW	    = 0x17

}Ltc2943_Regs;

#endif /* LTC2943_REG_H */