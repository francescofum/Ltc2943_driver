#ifndef ICHIPCTRL_H
#define ICHIPCTRL_H

#include "ChipCtrl_Mode.h"
#include "ChipCtrl_Status.h"
#include "ChipCtrl_Alert.h"

#include <stdint.h>
#include <stdbool.h>

typedef void Object;

typedef struct IChipCtrl
{
    /* Reference on the class that realises the current interface */
    Object* object;
    /* Reference of the interface method: initialise*/
    bool (* initialise) (Object *object);
    /* Reference of the interface method: getAdcMode*/
    ChipCtrl_Mode   (* getAdcMode) (Object *object);
    /* Reference of the interface method: setAdcMode*/
    ChipCtrl_Status (* setAdcMode) (Object *object, ChipCtrl_Mode mode);
    /* Reference of the interface method: isTempAlert*/
    ChipCtrl_Alert  (* getTempAlert) (Object *object);
    /* Reference of the interface method: setChrgThr*/
    ChipCtrl_Status (* setChrgThr) (Object *object, uint8_t upper, uint8_t lower);
    /* Reference of the interface method: isChrgInThr*/
    ChipCtrl_Alert  (* getChrgAlert) (Object *object);

} IChipCtrl;


/* Public methods */
inline static void IChipCtrl_init(IChipCtrl* const self, void* object, 
                                  void* initialise, void* getAdcMode,
                                  void* setAdcMode, void* isTempAlert,
                                  void* setChrgThr, void* isChrgInThr);
inline static ChipCtrl_Mode IChipCtrl_getAdcMode(IChipCtrl* const self);
inline static ChipCtrl_Status IChipCtrl_setAdcMode(IChipCtrl* const self, ChipCtrl_Mode mode);
inline static ChipCtrl_Alert IChipCtrl_getTempAlert(IChipCtrl* const self);
inline static ChipCtrl_Status IChipCtrl_setChrgThr(IChipCtrl* const self, uint8_t upper, uint8_t lower);
inline static ChipCtrl_Alert IChipCtrl_getChrgAlert(IChipCtrl* const self);


inline static void IChipCtrl_init(IChipCtrl* const self, void* object, 
                                  void* initialise, void* getAdcMode,
                                  void* setAdcMode, void* isTempAlert,
                                  void* setChrgThr, void* isChrgInThr)
{
    self->object = object;
    
    self->getAdcMode = (ChipCtrl_Mode (*) (Object*)) getAdcMode;

    self->setAdcMode = (ChipCtrl_Status (*) (Object*, ChipCtrl_Mode mode)) setAdcMode;

    self->getTempAlert = (ChipCtrl_Alert (*) (Object*)) isTempAlert;

    self->setChrgThr = (ChipCtrl_Status (*) (Object *object, uint8_t upper, uint8_t lower)) setChrgThr;

    self->getChrgAlert = (ChipCtrl_Alert (*) (Object*)) isChrgInThr;
}

/******************************************
 * @brief IChipCtrl_getAdcMode - Get the adc mode
 * @param[in] self: IChipCtrl - Reference on the object
 * @return ChipCtrl_Mode: The adc mode or E_MODE_ERROR
 *   if something went wrong with the read.
 * 
 ******************************************/
inline static ChipCtrl_Mode IChipCtrl_getAdcMode(IChipCtrl* const self)
{
    return (self->getAdcMode)(self->object);
}

/******************************************
 * @brief IChipCtrl_setAdcMode - Set the adc mode
 * @param[in] self: IChipCtrl - Reference on the object
 * @param[in] mode: ChipCtrl_Mode - The adc mode
 * @return ChipCtrl_Status: Status of the operation, E_STATUS_OK or E_STATUS_ERROR 
 *   if something went wrong with the read.
 * 
 ******************************************/
inline static ChipCtrl_Status IChipCtrl_setAdcMode(IChipCtrl* const self, ChipCtrl_Mode mode)
{
    return (self->setAdcMode)(self->object, mode);
}

/******************************************
 * @brief IChipCtrl_getTempAlert - Get the temp alert
 * @param[in] self: IChipCtrl - Reference on the object
 * @return ChipCtrl_Status: Status of the operation, E_STATUS_OK or E_STATUS_ERROR 
 *   if something went wrong with the read.
 * 
 ******************************************/
inline static ChipCtrl_Alert IChipCtrl_getTempAlert(IChipCtrl* const self)
{
    return (self->getTempAlert)(self->object);
}

/******************************************
 * @brief IChipCtrl_setChrgThr - Set the upper and lower charge thresholds
 * @param[in] self: IChipCtrl - Reference on the object
 * @param[in] uint16_t: upper - The upper threshold
 * @param[in] uint16_t: lower - The lower threshold
 * @return ChipCtrl_Status: Status of the operation, E_STATUS_OK or E_STATUS_ERROR 
 *   if something went wrong with the read.
 * 
 ******************************************/
inline static ChipCtrl_Status IChipCtrl_setChrgThr(IChipCtrl* const self, uint8_t upper, uint8_t lower)
{
    return (self->setChrgThr)(self->object, upper, lower); 
}

/******************************************
 * @brief IChipCtrl_getChrgAlert - Get the charge alert 
 * @param[in] self: IChipCtrl - Reference on the object
 * @return ChipCtrl_Alert: Alert status or E_ALERT_ERROR is operation failed. 
 * 
 ******************************************/
inline static ChipCtrl_Alert IChipCtrl_getChrgAlert(IChipCtrl* const self)
{
    return (self->getChrgAlert)(self->object);
}

#endif