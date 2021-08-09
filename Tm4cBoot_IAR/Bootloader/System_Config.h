#ifndef __SYSTEM_CONFIG__
#define __SYSTEM_CONFIG__
//---------------------------------Boot Configurations

#define ENABLE  (1)
#define DISABLE (0)

//---------------------------------Boot Conditions

#define MANUAL_BOOTING  DISABLE
#define AUTO_BOOTING    ENABLE

//---------------------------------Boot Communications

#define BOOT_UART_COMM  ENABLE
#define BOOT_I2C_COMM   DISABLE
#define BOOT_SPI_COMM   DISABLE
#define BOOT_CAN_COMM   DISABLE

//---------------------------------Boot Image Formate

#define IMAGE_SRECORD_FORMAT    ENABLE
#define IMAGE_TEXT_FORMAT       DISABLE
#define IMAGE_CUSTOM_FORMAT     DISABLE
#define IMAGE_INTEL_HEX_FORMAT  DISABLE

//---------------------------------Boot Image Formate

#undef  BOOT_SECURITY
#define BOOT_CRC_CHECK
#undef  BOOT_CHECKSUM_CHECK
#undef  BOOT_PASSWORD
#define BOOT_IMAGES_MAX_NUMB  (1)
#define BOOT_IMG_FORMAT       IMAGE_SRECORD_FORMAT
#define BOOT_COMM_INTERFACE   BOOT_UART_COMM

#endif //__SYSTEM_CONFIG__