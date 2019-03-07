/*
    __recplay_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__recplay_driver.h"
#include "__recplay_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __RECPLAY_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _RECPLAY_PLAY_VP              = 0xA6;
const uint8_t _RECPLAY_PLAY_VP_RN           = 0xAE;
const uint8_t _RECPLAY_EXE_VM               = 0xB0;
const uint8_t _RECPLAY_REC_MSG              = 0x38;
const uint8_t _RECPLAY_REC_MSG_ADDR         = 0x3A;
const uint8_t _RECPLAY_PLAY_MSG             = 0x3C;
const uint8_t _RECPLAY_PLAY_SIL             = 0xA8;
const uint8_t _RECPLAY_STOP                 = 0x2A;
const uint8_t _RECPLAY_ERASE_MSG            = 0x3E;
const uint8_t _RECPLAY_SPI_PCM_WRITE        = 0xAA;
const uint8_t _RECPLAY_SPI_PCM_READ         = 0xAC;
const uint8_t _RECPLAY_SPI_SND_DEC          = 0xC0;
const uint8_t _RECPLAY_SPI_RCV_ENC          = 0xC2;
const uint8_t _RECPLAY_READ_STATUS          = 0x40;
const uint8_t _RECPLAY_READ_INT             = 0x46;
const uint8_t _RECPLAY_READ_MSG_ADDR        = 0x42;
const uint8_t _RECPLAY_READ_MSG_LEN         = 0x44;
const uint8_t _RECPLAY_READ_ID              = 0x48;
const uint8_t _RECPLAY_DIG_READ             = 0xA2;
const uint8_t _RECPLAY_DIG_WRITE            = 0xA0;
const uint8_t _RECPLAY_ERASE_MEM            = 0x24;
const uint8_t _RECPLAY_CHIP_ERASE           = 0x26;
const uint8_t _RECPLAY_PWR_UP               = 0x10;
const uint8_t _RECPLAY_PWR_DOWN             = 0x12;
const uint8_t _RECPLAY_SET_CLK_CFG          = 0xB4;
const uint8_t _RECPLAY_READ_CLK_CFG         = 0xB6;
const uint8_t _RECPLAY_WRITE_CFG_REG        = 0xB8;
const uint8_t _RECPLAY_READ_CFG_REG         = 0xBA;

const uint8_t _RECPLAY_CFG00_REG            = 0x00;
const uint8_t _RECPLAY_CFG01_REG            = 0x01;
const uint8_t _RECPLAY_CFG02_REG            = 0x02;
const uint8_t _RECPLAY_CFG03_REG            = 0x03;
const uint8_t _RECPLAY_CFG04_REG            = 0x04;
const uint8_t _RECPLAY_CFG05_REG            = 0x05;
const uint8_t _RECPLAY_CFG06_REG            = 0x06;
const uint8_t _RECPLAY_CFG07_REG            = 0x07;
const uint8_t _RECPLAY_CFG08_REG            = 0x08;
const uint8_t _RECPLAY_CFG09_REG            = 0x09;
const uint8_t _RECPLAY_CFG0A_REG            = 0x0A;
const uint8_t _RECPLAY_CFG0B_REG            = 0x0B;
const uint8_t _RECPLAY_CFG0C_REG            = 0x0C;
const uint8_t _RECPLAY_CFG0D_REG            = 0x0D;
const uint8_t _RECPLAY_CFG0E_REG            = 0x0E;
const uint8_t _RECPLAY_CFG0F_REG            = 0x0F;
const uint8_t _RECPLAY_CFG10_REG            = 0x10;
const uint8_t _RECPLAY_CFG11_REG            = 0x11;
const uint8_t _RECPLAY_CFG12_REG            = 0x12;
const uint8_t _RECPLAY_CFG13_REG            = 0x13;
const uint8_t _RECPLAY_CFG14_REG            = 0x14;
const uint8_t _RECPLAY_CFG15_REG            = 0x15;
const uint8_t _RECPLAY_CFG16_REG            = 0x16;
const uint8_t _RECPLAY_CFG17_REG            = 0x17;
const uint8_t _RECPLAY_CFG18_REG            = 0x18;
const uint8_t _RECPLAY_CFG19_REG            = 0x19;
const uint8_t _RECPLAY_CFG1A_REG            = 0x1A;
const uint8_t _RECPLAY_CFG1B_REG            = 0x1B;
const uint8_t _RECPLAY_CFG1C_REG            = 0x1C;
const uint8_t _RECPLAY_CFG1D_REG            = 0x1D;
const uint8_t _RECPLAY_CFG1E_REG            = 0x1E;
const uint8_t _RECPLAY_CFG1F_REG            = 0x1F;
const uint8_t _RECPLAY_CFG20_REG            = 0x20;
const uint8_t _RECPLAY_CFG21_REG            = 0x21;
const uint8_t _RECPLAY_CFG22_REG            = 0x22;
const uint8_t _RECPLAY_CFG23_REG            = 0x23;
const uint8_t _RECPLAY_CFG24_REG            = 0x24;
const uint8_t _RECPLAY_CFG25_REG            = 0x25;
const uint8_t _RECPLAY_CFG26_REG            = 0x26;
const uint8_t _RECPLAY_CFG27_REG            = 0x27;
const uint8_t _RECPLAY_CFG28_REG            = 0x28;
const uint8_t _RECPLAY_CFG29_REG            = 0x29;
const uint8_t _RECPLAY_CFG2A_REG            = 0x2A;
const uint8_t _RECPLAY_CFG2B_REG            = 0x2B;
const uint8_t _RECPLAY_CFG2C_REG            = 0x2C;
const uint8_t _RECPLAY_CFG2D_REG            = 0x2D;
const uint8_t _RECPLAY_CFG2E_REG            = 0x2E;
const uint8_t _RECPLAY_CFG2F_REG            = 0x2F;

const uint8_t _RECPLAY_INT_PEAK_DET_MASK           = 0x80;
const uint8_t _RECPLAY_INT_MEM_PROT_ERR_MASK       = 0x40;
const uint8_t _RECPLAY_INT_WR_FIN_MASK             = 0x20;
const uint8_t _RECPLAY_INT_CMD_ERR_MASK            = 0x10;
const uint8_t _RECPLAY_INT_OVF_ERR_MASK            = 0x08;
const uint8_t _RECPLAY_INT_CMD_FIN_MASK            = 0x04;
const uint8_t _RECPLAY_INT_ADDR_ERR_MASK           = 0x02;
const uint8_t _RECPLAY_INT_FULL_ERR_MASK           = 0x01;

const uint8_t _RECPLAY_STAT_PWR_DOWN_MASK          = 0x80;
const uint8_t _RECPLAY_STAT_DBUF_RDY_MASK          = 0x40;
const uint8_t _RECPLAY_STAT_INT_GEN_MASK           = 0x20;
const uint8_t _RECPLAY_STAT_REC_MEM_FULL_MASK      = 0x10;
const uint8_t _RECPLAY_STAT_VM_BSY_MASK            = 0x04;
const uint8_t _RECPLAY_STAT_CBUF_FULL_MASK         = 0x02;
const uint8_t _RECPLAY_STAT_CMD_BSY_MASK           = 0x01;

const uint8_t _RECPLAY_INT_GEN_PIN          = 0x00;
const uint8_t _RECPLAY_INT_NO_GEN_PIN       = 0x01;
const uint8_t _RECPLAY_SPI_RDY_PIN          = 0x01;
const uint8_t _RECPLAY_SPI_BSY_PIN          = 0x00;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __RECPLAY_DRV_SPI__

void recplay_spiDriverInit(T_RECPLAY_P gpioObj, T_RECPLAY_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet( 1 );
    hal_gpio_rstSet( 0 );
}

#endif
#ifdef   __RECPLAY_DRV_I2C__

void recplay_i2cDriverInit(T_RECPLAY_P gpioObj, T_RECPLAY_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RECPLAY_DRV_UART__

void recplay_uartDriverInit(T_RECPLAY_P gpioObj, T_RECPLAY_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

T_RECPLAY_RETVAL recplay_playVP( uint16_t index )
{
    uint8_t tempData[ 3 ];
    uint8_t retVal[ 3 ];
    
    tempData[ 0 ] = _RECPLAY_PLAY_VP;
    tempData[ 1 ] = index >> 8;
    tempData[ 2 ] = index;
    
    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 3 );
    hal_gpio_csSet( 1 );
    
    return retVal[ 2 ];
}

T_RECPLAY_RETVAL recplay_playVPRn( uint8_t valueRn )
{
    uint8_t tempData[ 2 ];
    uint8_t retVal[ 2 ];
    
    tempData[ 0 ] = _RECPLAY_PLAY_VP_RN;
    tempData[ 1 ] = valueRn;
    
    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );
    
    return retVal[ 1 ];
}

T_RECPLAY_RETVAL recplay_executeVM( uint16_t index )
{
    uint8_t tempData[ 3 ];
    uint8_t retVal[ 3 ];
    
    tempData[ 0 ] = _RECPLAY_EXE_VM;
    tempData[ 1 ] = index >> 8;
    tempData[ 2 ] = index;
    
    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 3 );
    hal_gpio_csSet( 1 );
    
    return retVal[ 2 ];
}

T_RECPLAY_RETVAL recplay_recordMsg( void )
{
    uint8_t tempData = _RECPLAY_REC_MSG;
    uint8_t retVal;
    
    hal_gpio_csSet( 0 );
    hal_spiTransfer( &tempData, &retVal, 1 );
    hal_gpio_csSet( 1 );
    
    return retVal;
}

T_RECPLAY_RETVAL recplay_recordMsgAddr( uint32_t memAddr )
{
    uint8_t tempData[ 4 ];
    uint8_t retVal[ 4 ];
    
    tempData[ 0 ] = _RECPLAY_REC_MSG_ADDR;
    tempData[ 1 ] = memAddr >> 16;
    tempData[ 2 ] = memAddr >> 8;
    tempData[ 3 ] = memAddr;
    
    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 4 );
    hal_gpio_csSet( 1 );
    
    return retVal[ 3 ];
}

T_RECPLAY_RETVAL recplay_playMsg( uint32_t memAddr, uint16_t sectorOffset )
{
    uint8_t tempData[ 6 ];
    uint8_t retVal[ 6 ];

    tempData[ 0 ] = _RECPLAY_PLAY_MSG;
    tempData[ 1 ] = memAddr >> 16;
    tempData[ 2 ] = memAddr >> 8;
    tempData[ 3 ] = memAddr;
    tempData[ 4 ] = sectorOffset >> 8;
    tempData[ 5 ] = sectorOffset;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 6 );
    hal_gpio_csSet( 1 );

    return retVal[ 5 ];
}

T_RECPLAY_RETVAL recplay_playSilence( uint8_t silenceLength )
{
    uint8_t tempData[ 2 ];
    uint8_t retVal[ 2 ];

    tempData[ 0 ] = _RECPLAY_PLAY_SIL;
    tempData[ 1 ] = silenceLength;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );

    return retVal[ 1 ];
}

T_RECPLAY_RETVAL recplay_stop( void )
{
    uint8_t tempData = _RECPLAY_STOP;
    uint8_t retVal;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( &tempData, &retVal, 1 );
    hal_gpio_csSet( 1 );

    return retVal;
}

T_RECPLAY_RETVAL recplay_eraseMsg( uint32_t memAddr )
{
    uint8_t tempData[ 4 ];
    uint8_t retVal[ 4 ];

    tempData[ 0 ] = _RECPLAY_ERASE_MSG;
    tempData[ 1 ] = memAddr >> 16;
    tempData[ 2 ] = memAddr >> 8;
    tempData[ 3 ] = memAddr;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 4 );
    hal_gpio_csSet( 1 );

    return retVal[ 3 ];
}

T_RECPLAY_RETVAL recplay_spiWritePCM( uint16_t *dataPCM, uint8_t numPCM )
{
    uint8_t tempData[ 256 ];
    uint8_t retVal[ 256 ];
    uint8_t cnt;
    uint8_t indx;
    uint8_t nPCM = numPCM;
    
    if (nPCM > 127)
    {
        nPCM = 127;
    }

    tempData[ 0 ] = _RECPLAY_SPI_PCM_WRITE;
    indx = 0;
    
    for (cnt = 1; cnt <= nPCM; cnt += 2)
    {
        tempData[ cnt ] = dataPCM[ indx ];
        tempData[ cnt + 1 ] = dataPCM[ indx ] >> 8;
        indx++;
    }
    nPCM = (nPCM * 2) + 1;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, nPCM );
    hal_gpio_csSet( 1 );

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_spiReadPCM( uint16_t *dataPCM, uint8_t numPCM )
{
    uint8_t tempData[ 256 ] = { 0 };
    uint8_t retVal[ 256 ];
    uint8_t cnt;
    uint8_t indx;
    uint8_t nPCM = numPCM;
    
    if (nPCM > 127)
    {
        nPCM = 127;
    }

    tempData[ 0 ] = _RECPLAY_SPI_PCM_READ;
    indx = 0;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, (nPCM * 2) + 1 );
    hal_gpio_csSet( 1 );
    
    for (cnt = 1; cnt <= nPCM; cnt += 2)
    {
        dataPCM[ indx ] = retVal[ cnt + 1 ];
        dataPCM[ indx ] <<= 8;
        dataPCM[ indx ] |= retVal[ cnt ];
        indx++;
    }

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_spiSendCmprsdData( uint8_t *cmprsdData, uint8_t nData )
{
    uint8_t tempData[ 256 ];
    uint8_t retVal[ 256 ];
    uint8_t cnt;
    uint8_t numData = nData;
    
    if (numData > 255)
    {
        numData = 255;
    }

    tempData[ 0 ] = _RECPLAY_SPI_SND_DEC;
    
    for (cnt = 1; cnt <= numData; cnt++)
    {
        tempData[ cnt ] = cmprsdData[ cnt - 1 ];
    }
    numData += 1;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, numData );
    hal_gpio_csSet( 1 );

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_spiReceiveEncData( uint8_t *encodedData, uint8_t nData )
{
    uint8_t tempData[ 256 ] = { 0 };
    uint8_t retVal[ 256 ];
    uint8_t cnt;
    uint8_t numData = nData;
    
    if (numData > 255)
    {
        numData = 255;
    }

    tempData[ 0 ] = _RECPLAY_SPI_RCV_ENC;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, numData + 1 );
    hal_gpio_csSet( 1 );
    
    for (cnt = 1; cnt <= numData; cnt++)
    {
        encodedData[ cnt - 1 ] = retVal[ cnt ];
    }

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_readStatus( uint8_t *interrStatus )
{
    uint8_t tempData[ 2 ] = { 0 };
    uint8_t retVal[ 2 ];

    tempData[ 0 ] = _RECPLAY_READ_STATUS;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );
    
    *interrStatus = retVal[ 1 ];

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_readInterr( uint8_t *interrStatus )
{
    uint8_t tempData[ 2 ] = { 0 };
    uint8_t retVal[ 2 ];

    tempData[ 0 ] = _RECPLAY_READ_INT;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );
    
    *interrStatus = retVal[ 1 ];

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_readMsgAddr( uint32_t *msgAddr, uint16_t *msgLength )
{
    uint8_t tempData[ 6 ] = { 0 };
    uint8_t retVal[ 6 ];

    tempData[ 0 ] = _RECPLAY_READ_MSG_ADDR;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 6 );
    hal_gpio_csSet( 1 );
    
    *msgAddr = retVal[ 1 ];
    *msgAddr <<= 8;
    *msgAddr |= retVal[ 2 ];
    *msgAddr <<= 8;
    *msgAddr |= retVal[ 3 ];
    
    *msgLength = retVal[ 4 ];
    *msgLength <<= 8;
    *msgLength |= retVal[ 5 ];

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_readMsgLength( uint16_t *msgLength )
{
    uint8_t tempData[ 3 ] = { 0 };
    uint8_t retVal[ 3 ];

    tempData[ 0 ] = _RECPLAY_READ_MSG_LEN;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 3 );
    hal_gpio_csSet( 1 );
    
    *msgLength = retVal[ 1 ];
    *msgLength <<= 8;
    *msgLength |= retVal[ 2 ];

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_readID( uint8_t *partID, uint8_t *manID, uint8_t *memType, uint8_t *devID )
{
    uint8_t tempData[ 5 ] = { 0 };
    uint8_t retVal[ 5 ];

    tempData[ 0 ] = _RECPLAY_READ_ID;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 5 );
    hal_gpio_csSet( 1 );
    
    *partID  = retVal[ 1 ];
    *manID   = retVal[ 2 ];
    *memType = retVal[ 3 ];
    *devID   = retVal[ 4 ];

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_digRead( uint32_t memAddr, uint8_t *dataOut, uint8_t nData )
{
    uint8_t tempData[ 256 ] = { 0 };
    uint8_t retVal[ 256 ];
    uint8_t cnt;
    uint8_t numData = nData;
    
    if (numData > 252)
    {
        numData = 252;
    }

    tempData[ 0 ] = _RECPLAY_DIG_READ;
    tempData[ 1 ] = memAddr >> 16;
    tempData[ 2 ] = memAddr >> 8;
    tempData[ 3 ] = memAddr;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, numData + 4 );
    hal_gpio_csSet( 1 );
    
    for (cnt = 4; cnt < numData + 4; cnt++)
    {
        dataOut[ cnt - 4 ] = retVal[ cnt ];
    }

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_digWrite( uint32_t memAddr, uint8_t *dataIn, uint8_t nData )
{
    uint8_t tempData[ 256 ];
    uint8_t retVal[ 256 ];
    uint8_t cnt;
    uint8_t numData = nData;
    
    if (numData > 252)
    {
        numData = 252;
    }

    tempData[ 0 ] = _RECPLAY_DIG_WRITE;
    tempData[ 1 ] = memAddr >> 16;
    tempData[ 2 ] = memAddr >> 8;
    tempData[ 3 ] = memAddr;
    
    for (cnt = 4; cnt < numData + 4; cnt++)
    {
        tempData[ cnt ] = dataIn[ cnt - 4 ];
    }

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, numData + 4 );
    hal_gpio_csSet( 1 );

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_eraseMem( uint32_t startAddr, uint32_t endAddr )
{
    uint8_t tempData[ 7 ];
    uint8_t retVal[ 7 ];

    tempData[ 0 ] = _RECPLAY_ERASE_MEM;
    tempData[ 1 ] = startAddr >> 16;
    tempData[ 2 ] = startAddr >> 8;
    tempData[ 3 ] = startAddr;
    tempData[ 4 ] = endAddr >> 16;
    tempData[ 5 ] = endAddr >> 8;
    tempData[ 6 ] = endAddr;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 7 );
    hal_gpio_csSet( 1 );

    return retVal[ 6 ];
}

T_RECPLAY_RETVAL recplay_eraseChip( void )
{
    uint8_t tempData[ 2 ];
    uint8_t retVal[ 2 ];

    tempData[ 0 ] = _RECPLAY_CHIP_ERASE;
    tempData[ 1 ] = 0x01;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );

    return retVal[ 1 ];
}

T_RECPLAY_RETVAL recplay_pwrUp( void )
{
    uint8_t tempData = _RECPLAY_PWR_UP;
    uint8_t retVal;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( &tempData, &retVal, 1 );
    hal_gpio_csSet( 1 );

    return retVal;
}

T_RECPLAY_RETVAL recplay_pwrDown( void )
{
    uint8_t tempData = _RECPLAY_PWR_DOWN;
    uint8_t retVal;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( &tempData, &retVal, 1 );
    hal_gpio_csSet( 1 );

    return retVal;
}

T_RECPLAY_RETVAL recplay_setClkCnfg( uint8_t clkCnfg )
{
    uint8_t tempData[ 2 ];
    uint8_t retVal[ 2 ];

    tempData[ 0 ] = _RECPLAY_SET_CLK_CFG;
    tempData[ 1 ] = clkCnfg;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );

    return retVal[ 1 ];
}

T_RECPLAY_RETVAL recplay_readClkCnfg( uint8_t *clkCnfg )
{
    uint8_t tempData[ 2 ] = { 0 };
    uint8_t retVal[ 2 ];

    tempData[ 0 ] = _RECPLAY_READ_CLK_CFG;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, 2 );
    hal_gpio_csSet( 1 );
    
    *clkCnfg = retVal[ 1 ];

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_writeCnfgReg( uint8_t regAddr, uint8_t *cnfgData, uint8_t nData )
{
    uint8_t tempData[ 50 ];
    uint8_t retVal[ 50 ];
    uint8_t cnt;
    uint8_t rAddr = regAddr;
    uint8_t numData = nData;
    
    if (rAddr > 0x2F)
    {
        rAddr = 0x2F;
    }
    if (numData > (48 - rAddr))
    {
        numData = 48 - rAddr;
    }

    tempData[ 0 ] = _RECPLAY_WRITE_CFG_REG;
    tempData[ 1 ] = rAddr;
    
    for (cnt = 2; cnt < numData + 2; cnt++)
    {
        tempData[ cnt ] = cnfgData[ cnt - 2 ];
    }

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, numData + 2 );
    hal_gpio_csSet( 1 );

    return retVal[ 0 ];
}

T_RECPLAY_RETVAL recplay_readCnfgReg( uint8_t regAddr, uint8_t *cnfgData, uint8_t nData )
{
    uint8_t tempData[ 50 ] = { 0 };
    uint8_t retVal[ 50 ];
    uint8_t cnt;
    uint8_t rAddr = regAddr;
    uint8_t numData = nData;
    
    if (rAddr > 0x2F)
    {
        rAddr = 0x2F;
    }
    if (numData > (48 - rAddr))
    {
        numData = 48 - rAddr;
    }

    tempData[ 0 ] = _RECPLAY_READ_CFG_REG;
    tempData[ 1 ] = rAddr;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( tempData, retVal, numData + 2 );
    hal_gpio_csSet( 1 );
    
    for (cnt = 2; cnt < numData + 2; cnt++)
    {
        cnfgData[ cnt - 2 ] = retVal[ cnt ];
    }

    return retVal[ 0 ];
}

uint8_t recplay_checkRDY( void )
{
    if (hal_gpio_anGet())
    {
        return _RECPLAY_SPI_RDY_PIN;
    }
    else
    {
        return _RECPLAY_SPI_BSY_PIN;
    }
}

uint8_t recplay_checkINT( void )
{
    if (hal_gpio_intGet())
    {
        return _RECPLAY_INT_NO_GEN_PIN;
    }
    else
    {
        return _RECPLAY_INT_GEN_PIN;
    }
}

void recplay_reset( void )
{
    hal_gpio_rstSet( 1 );
    Delay_100ms();
    hal_gpio_rstSet( 0 );
    Delay_1sec();
}

/* -------------------------------------------------------------------------- */
/*
  __recplay_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */