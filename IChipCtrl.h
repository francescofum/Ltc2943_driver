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
    Object* object;

    bool (* initialise) (Object *object);
    ChipCtrl_Mode   (* getAdcMode) (Object *object);
    ChipCtrl_Status (* setAdcMode) (Object *object, ChipCtrl_Mode mode);
    bool            (* isTempAlert) (Object *object);
    ChipCtrl_Status (* setChrgThr) (Object *object, uint8_t upper, uint8_t lower);
    bool            (* isChrgInThr) (Object *object);

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
inline static bool IChipCtrl_getChrgAlert(IChipCtrl* const self);


inline static void IChipCtrl_init(IChipCtrl* const self, void* object, 
                                  void* initialise, void* getAdcMode,
                                  void* setAdcMode, void* isTempAlert,
                                  void* setChrgThr, void* isChrgInThr)
{
    self->object = object;
    
    self->getAdcMode = (ChipCtrl_Mode (*) (Object*)) getAdcMode;

    self->setAdcMode = (ChipCtrl_Status (*) (Object*, ChipCtrl_Mode mode)) setAdcMode;

    self->isTempAlert = (bool (*) (Object*)) isTempAlert;

    self->setChrgThr = (ChipCtrl_Status (*) (Object *object, uint8_t upper, uint8_t lower)) setChrgThr;

    self->isChrgInThr = (bool (*) (Object*)) isChrgInThr;
}

inline static ChipCtrl_Mode IChipCtrl_getAdcMode(IChipCtrl* const self)
{
    return (self->getAdcMode)(self->object);
}

inline static ChipCtrl_Status IChipCtrl_setAdcMode(IChipCtrl* const self, ChipCtrl_Mode mode)
{
    return (self->setAdcMode)(self->object, mode);
}

inline static ChipCtrl_Alert IChipCtrl_getTempAlert(IChipCtrl* const self)
{
    return (self->isTempAlert)(self->object);
}

inline static ChipCtrl_Status IChipCtrl_setChrgThr(IChipCtrl* const self, uint8_t upper, uint8_t lower)
{
    return (self->setChrgThr)(self->object, upper, lower); 
}

inline static bool IChipCtrl_getChrgAlert(IChipCtrl* const self)
{
    return (self->isChrgInThr)(self->object);
}

#endif