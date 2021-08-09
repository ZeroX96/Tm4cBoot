#ifndef __BOOTLOADER_H__
#define __BOOTLOADER_H__

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/flash.h"

#include "crc.h"
#include "packet.h"
#include "utils.h"

#define LEDBASE GPIO_PORTF_BASE
#define LEDRED GPIO_PIN_1
#define LEDBLUE GPIO_PIN_2
#define LEDGREEN GPIO_PIN_3

#define SWBASE GPIO_PORTF_BASE
#define SW1 GPIO_PIN_4
#define SW2 GPIO_PIN_0

#define APP_START_ADDRESS ((uint32_t)0x00006000U)

strPacket_t rxBuffer;
strPacket_t txBuffer;

uint32_t flsDrvBuffer[64];
uint8_t flsDrvBufferInd = 0;

uint32_t payloadSize;

crc_t crc;

typedef enum {
    BL_STATE_IDLE,
    BL_STATE_ERASE_STARTED,
    BL_STATE_WRITE_STARTED,
    BL_STATE_WRITE_FINISHED,
} enuState_t;

static enuState_t BL_State = BL_STATE_IDLE;

static uint32_t flashIndex = APP_START_ADDRESS; 
#endif //__BOOTLOADER_H__