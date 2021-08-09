#include <TM4C123GH6PM.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/flash.h"

int Boot_main()
{
    //Disable interrupts so complete the initialization safely 
    IntMasterDisable();
    
    //Initialize the system clock
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ );
    
    //
    
  return 0;
}

/*
= Firmware update signaled using a push button
= By default the system remains in the boot-mode if the application firm is corrupted or not existing
= Boot-Mode Led Indicator
= Boot to App jump only occurs if the app is existing and verified
= Each Program has its Interrupt Vector Table, Bootloader IVT is located at Address "0"
= Boot Manager should be as a part of the bootloader memory space
= CRC/Checksum Verification
= Extended Error Handling
                          ****SysDesign****
      Reset ---->>>> BootManager ---->>> BootLoader ---->>>> ---->>>> |
          ^              |---->>>> Application ---->>>> |             |
          | <<<<---- <<<<---- <<<<---- <<<<---- <<<<----|<<<<---------|
                            ****Memory Layout****
                               /************/
                               /*          */
                               /* Boot IVT */
                               /*          */
                               /************/
                               /*   .....  */
                               /*Bootloader*/
                               /*   .....  */
                               /************/
                               /*          */
                               /*  App IVT */
                               /*          */
                               /************/
                               /*   .....  */
                               /*     A    */
                               /*     P    */
                               /*     P    */
                               /*   .....  */
                               /************/
