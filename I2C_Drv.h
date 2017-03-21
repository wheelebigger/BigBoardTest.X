/* ************************************************************************** */
/** Descriptive File Name

  @Company
 UCN

  @File Name
    I2C_Drv.h

  @Summary
    I2C priver for UCN PIC32MX250F128B board.

  @Description
    I2C driver.
 */
/* ************************************************************************** */

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <p32xxxx.h>
#include "GenericTypeDefs.h"
//#include <plib.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    #define I2CCON        I2C2CON
    #define I2CCONbits    I2C2CONbits
    #define I2CSTAT       I2C2STAT
    #define I2CSTATbits   I2C2STATbits
    #define I2CMSK        I2C2MSK
    #define I2CRCV        I2C2RCV
    #define I2CTRN        I2C2TRN
    #define I2CADD        I2C2ADD
    #define I2CBRG        I2C2BRG

    #define FCL        400000 // Check the max speed supported by your peripheral!!

    // System related constants
    #define GetSystemClock()         40000000UL       // define the system clock appropriately!
    #define GetPeripheralClock()     GetSystemClock() 
    #define GetInstructionClock()   (GetSystemClock())
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    void drvI2CInit(void);
    BOOL drvI2CReadRegisters(UINT8 reg, UINT8* rxPtr, UINT8 len, UINT8 slave_adr);
    BOOL drvI2CWriteRegisters(UINT8 reg, UINT8* data, UINT8 len, UINT8 slave_adr);
    BOOL drvI2CWriteByte(UINT8 reg, UINT8 byte, UINT8 slave_adr );
    BOOL drvI2CReadByte(UINT8 reg, UINT8 byte, UINT8 slave_adr);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
