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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
#include "I2C_Drv.h"
//#define _BANK1    // Default BANK0 uncomment this line for BANK1 
#include "portext.h"
#include "delay.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
void portextDir(PORT_NAME portName, UINT8 value)
{
    switch(portName)
    {
        case PORT_A: drvI2CWriteByte(0x00,value,ADDR); break;
        case PORT_B: drvI2CWriteByte(0x01,value,ADDR); break;
        default: 
        break;
    }
}
void portextWrite(PORT_NAME portName, UINT8 value)
{
    switch(portName)
    {
        case PORT_A: drvI2CWriteByte(OLATA, value, ADDR); break;
        case PORT_B: drvI2CWriteByte(OLATB, value, ADDR); break;
        default:
        break;
    }   
}
UINT8 portextRead(PORT_NAME portName) {
    UINT8 value;
    switch (portName) {
        case PORT_A: drvI2CReadRegisters(GPIOA, &value, 1, ADDR ); break;
        case PORT_B: drvI2CReadRegisters(GPIOB, &value, 1, ADDR); break;
        default: value = 0; break;
    }
    return value;
}

void LCDletter(UINT8 letter){
    portextWrite(PORT_B,0x01);
    portextWrite(PORT_A,letter);
    portextWrite(PORT_B,0x03); //triggering E to accept the data(this time whilst RS is ON)
    portextWrite(PORT_B,0x01);
}
void LCDword(char word[])
{
    int w=0;
    //for(w = 0;w<=sizeof(word)/sizeof(word[0]);w++)
    while(word[w]) //mit for loop var bedre
    {
        LCDletter(word[w]);
        w++;
    }
}
void LCDinit(void){
                DelayMs(40);
                portextWrite(PORT_B,0x00); //RS to 0
                portextWrite(PORT_A,0x30);
                portextWrite(PORT_B,0x02); //triggering E to accept the data
                portextWrite(PORT_B,0x00);
                DelayMs(5);
                portextWrite(PORT_B,0x00);
                portextWrite(PORT_A,0x30);
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                DelayUs(100);
                portextWrite(PORT_B,0x00);
                portextWrite(PORT_A,0x30); //random init number
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                DelayUs(48);
                portextWrite(PORT_A,0x38);//The number of display lines and character font. (4 lines 5x8 font)
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                portextWrite(PORT_A,0x08);//turns off the display.
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                portextWrite(PORT_A,0x01);//clears the display.
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                DelayMs(2);
                portextWrite(PORT_A,0x06);//sets the writing direction to right, and the shifting off.
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                DelayMs(2);
                portextWrite(PORT_A,0x0F);//turns on the display with the cursor on, and blinking
                portextWrite(PORT_B,0x02);
                portextWrite(PORT_B,0x00);
                DelayMs(2);
 }

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */

/* *****************************************************************************
 End of File
 */
