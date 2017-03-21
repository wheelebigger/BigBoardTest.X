/* ************************************************************************** */
/** Descriptive File Name

  @Company
    University College Nordjylland

  @File Name
    portext.c

  @Summary
    Driver for MCP23017/MCP23S17 port extender from Microchip

  @Description
    Upper layer device driver
 */
/* ************************************************************************** */

#ifndef _PORTEXT_H    /* Guard against multiple inclusion */
#define _PORTEXT_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <p32xxxx.h>
#include "GenericTypeDefs.h"
#include "I2C_Drv.h"

typedef enum
{
    PORT_A,
    PORT_B
}PORT_NAME;

extern void portextDir(PORT_NAME portName, UINT8 value);
extern UINT8 portextRead(PORT_NAME portName);
extern void portextWrite(PORT_NAME portName, UINT8 value);


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */
#define ADDR        0x20   // Change acording to the MCP23017's port 
#ifdef _BANK1       
    #define IODIRA      0x00
    #define IODIRB      0x10
    #define IPOLA       0x01
    #define IPOLB       0x11
    #define GPINTENA    0x02
    #define GPINTENB    0x12
    #define DEFVALA     0x03
    #define DEFVALB     0x13
    #define INTCONA     0x04
    #define INTCONB     0x14
    #define IOCON       0x15
    #define GPPUA       0x06
    #define GPPUB       0x16
    #define INTFA       0x07
    #define INTFB       0x17
    #define INTCAPA     0x08
    #define INTCAPB     0x18
    #define GPIOA       0x09
    #define GPIOB       0x19
    #define OLATA       0x0a
    #define OLATB       0x1a
#else      // BANK = 0
    #define IODIRA      0x00
    #define IODIRB      0x01
    #define IPOLA       0x02
    #define IPOLB       0x03
    #define GPINTENA    0x04
    #define GPINTENB    0x05
    #define DEFVALA     0x06
    #define DEFVALB     0x07
    #define INTCONA     0x08
    #define INTCONB     0x09
    #define IOCON       0x0A
    #define GPPUA       0x0C
    #define GPPUB       0x0D
    #define INTFA       0x0E
    #define INTFB       0x0F
    #define INTCAPA     0x10
    #define INTCAPB     0x11
    #define GPIOA       0x12
    #define GPIOB       0x13
    #define OLATA       0x14
    #define OLATB       0x15   
#endif



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
