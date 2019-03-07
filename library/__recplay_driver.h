/*
    __recplay_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __recplay_driver.h
@brief    REC_n_PLAY Driver
@mainpage REC_n_PLAY Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RECPLAY
@brief      REC_n_PLAY Click Driver
@{

| Global Library Prefix | **RECPLAY** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Aug 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RECPLAY_H_
#define _RECPLAY_H_

/** 
 * @macro T_RECPLAY_P
 * @brief Driver Abstract type 
 */
#define T_RECPLAY_P    const uint8_t*
#define T_RECPLAY_RETVAL     uint8_t

/** @defgroup RECPLAY_COMPILE Compilation Config */              /** @{ */

   #define   __RECPLAY_DRV_SPI__                            /**<     @macro __RECPLAY_DRV_SPI__  @brief SPI driver selector */
//  #define   __RECPLAY_DRV_I2C__                            /**<     @macro __RECPLAY_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __RECPLAY_DRV_UART__                           /**<     @macro __RECPLAY_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RECPLAY_VAR Variables */                           /** @{ */

/** SPI Commands for REC&PLAY click */
extern const uint8_t _RECPLAY_PLAY_VP         ;
extern const uint8_t _RECPLAY_PLAY_VP_RN      ;
extern const uint8_t _RECPLAY_EXE_VM          ;
extern const uint8_t _RECPLAY_REC_MSG         ;
extern const uint8_t _RECPLAY_REC_MSG_ADDR    ;
extern const uint8_t _RECPLAY_PLAY_MSG        ;
extern const uint8_t _RECPLAY_PLAY_SIL        ;
extern const uint8_t _RECPLAY_STOP            ;
extern const uint8_t _RECPLAY_ERASE_MSG       ;
extern const uint8_t _RECPLAY_SPI_PCM_WRITE   ;
extern const uint8_t _RECPLAY_SPI_PCM_READ    ;
extern const uint8_t _RECPLAY_SPI_SND_DEC     ;
extern const uint8_t _RECPLAY_SPI_RCV_ENC     ;
extern const uint8_t _RECPLAY_READ_STATUS     ;
extern const uint8_t _RECPLAY_READ_INT        ;
extern const uint8_t _RECPLAY_READ_MSG_ADDR   ;
extern const uint8_t _RECPLAY_READ_MSG_LEN    ;
extern const uint8_t _RECPLAY_READ_ID         ;
extern const uint8_t _RECPLAY_DIG_READ        ;
extern const uint8_t _RECPLAY_DIG_WRITE       ;
extern const uint8_t _RECPLAY_ERASE_MEM       ;
extern const uint8_t _RECPLAY_CHIP_ERASE      ;
extern const uint8_t _RECPLAY_PWR_UP          ;
extern const uint8_t _RECPLAY_PWR_DOWN        ;
extern const uint8_t _RECPLAY_SET_CLK_CFG     ;
extern const uint8_t _RECPLAY_READ_CLK_CFG    ;
extern const uint8_t _RECPLAY_WRITE_CFG_REG   ;
extern const uint8_t _RECPLAY_READ_CFG_REG    ;

/** Configuration registers */
extern const uint8_t _RECPLAY_CFG00_REG       ;
extern const uint8_t _RECPLAY_CFG01_REG       ;
extern const uint8_t _RECPLAY_CFG02_REG       ;
extern const uint8_t _RECPLAY_CFG03_REG       ;
extern const uint8_t _RECPLAY_CFG04_REG       ;
extern const uint8_t _RECPLAY_CFG05_REG       ;
extern const uint8_t _RECPLAY_CFG06_REG       ;
extern const uint8_t _RECPLAY_CFG07_REG       ;
extern const uint8_t _RECPLAY_CFG08_REG       ;
extern const uint8_t _RECPLAY_CFG09_REG       ;
extern const uint8_t _RECPLAY_CFG0A_REG       ;
extern const uint8_t _RECPLAY_CFG0B_REG       ;
extern const uint8_t _RECPLAY_CFG0C_REG       ;
extern const uint8_t _RECPLAY_CFG0D_REG       ;
extern const uint8_t _RECPLAY_CFG0E_REG       ;
extern const uint8_t _RECPLAY_CFG0F_REG       ;
extern const uint8_t _RECPLAY_CFG10_REG       ;
extern const uint8_t _RECPLAY_CFG11_REG       ;
extern const uint8_t _RECPLAY_CFG12_REG       ;
extern const uint8_t _RECPLAY_CFG13_REG       ;
extern const uint8_t _RECPLAY_CFG14_REG       ;
extern const uint8_t _RECPLAY_CFG15_REG       ;
extern const uint8_t _RECPLAY_CFG16_REG       ;
extern const uint8_t _RECPLAY_CFG17_REG       ;
extern const uint8_t _RECPLAY_CFG18_REG       ;
extern const uint8_t _RECPLAY_CFG19_REG       ;
extern const uint8_t _RECPLAY_CFG1A_REG       ;
extern const uint8_t _RECPLAY_CFG1B_REG       ;
extern const uint8_t _RECPLAY_CFG1C_REG       ;
extern const uint8_t _RECPLAY_CFG1D_REG       ;
extern const uint8_t _RECPLAY_CFG1E_REG       ;
extern const uint8_t _RECPLAY_CFG1F_REG       ;
extern const uint8_t _RECPLAY_CFG20_REG       ;
extern const uint8_t _RECPLAY_CFG21_REG       ;
extern const uint8_t _RECPLAY_CFG22_REG       ;
extern const uint8_t _RECPLAY_CFG23_REG       ;
extern const uint8_t _RECPLAY_CFG24_REG       ;
extern const uint8_t _RECPLAY_CFG25_REG       ;
extern const uint8_t _RECPLAY_CFG26_REG       ;
extern const uint8_t _RECPLAY_CFG27_REG       ;
extern const uint8_t _RECPLAY_CFG28_REG       ;
extern const uint8_t _RECPLAY_CFG29_REG       ;
extern const uint8_t _RECPLAY_CFG2A_REG       ;
extern const uint8_t _RECPLAY_CFG2B_REG       ;
extern const uint8_t _RECPLAY_CFG2C_REG       ;
extern const uint8_t _RECPLAY_CFG2D_REG       ;
extern const uint8_t _RECPLAY_CFG2E_REG       ;
extern const uint8_t _RECPLAY_CFG2F_REG       ;

/** Bit mask for Interrupt byte */
extern const uint8_t _RECPLAY_INT_PEAK_DET_MASK      ;
extern const uint8_t _RECPLAY_INT_MEM_PROT_ERR_MASK  ;
extern const uint8_t _RECPLAY_INT_WR_FIN_MASK        ;
extern const uint8_t _RECPLAY_INT_CMD_ERR_MASK       ;
extern const uint8_t _RECPLAY_INT_OVF_ERR_MASK       ;
extern const uint8_t _RECPLAY_INT_CMD_FIN_MASK       ;
extern const uint8_t _RECPLAY_INT_ADDR_ERR_MASK      ;
extern const uint8_t _RECPLAY_INT_FULL_ERR_MASK      ;

/** Bit mask for Status byte */
extern const uint8_t _RECPLAY_STAT_PWR_DOWN_MASK     ;
extern const uint8_t _RECPLAY_STAT_DBUF_RDY_MASK     ;
extern const uint8_t _RECPLAY_STAT_INT_GEN_MASK      ;
extern const uint8_t _RECPLAY_STAT_REC_MEM_FULL_MASK ;
extern const uint8_t _RECPLAY_STAT_VM_BSY_MASK       ;
extern const uint8_t _RECPLAY_STAT_CBUF_FULL_MASK    ;
extern const uint8_t _RECPLAY_STAT_CMD_BSY_MASK      ;

/** Output values from the INT and RDY pins */
extern const uint8_t _RECPLAY_INT_GEN_PIN       ;
extern const uint8_t _RECPLAY_INT_NO_GEN_PIN    ;
extern const uint8_t _RECPLAY_SPI_RDY_PIN       ;
extern const uint8_t _RECPLAY_SPI_BSY_PIN       ;

                                                                       /** @} */
/** @defgroup RECPLAY_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RECPLAY_INIT Driver Initialization */              /** @{ */

#ifdef   __RECPLAY_DRV_SPI__
void recplay_spiDriverInit(T_RECPLAY_P gpioObj, T_RECPLAY_P spiObj);
#endif
#ifdef   __RECPLAY_DRV_I2C__
void recplay_i2cDriverInit(T_RECPLAY_P gpioObj, T_RECPLAY_P i2cObj, uint8_t slave);
#endif
#ifdef   __RECPLAY_DRV_UART__
void recplay_uartDriverInit(T_RECPLAY_P gpioObj, T_RECPLAY_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup RECPLAY_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Voice Prompt Play Command
 *
 * @param[in] index  Index of Voice Prompt
 *
 * @returns Status byte
 *
 * Function initiates a play of a pre-recorded voice prompt.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when playback is finished.
 */
T_RECPLAY_RETVAL recplay_playVP( uint16_t index );

/**
 * @brief Voice Prompt @Rn Play Command
 *
 * @param[in] valueRn  R(n) selection from 0 to 7
 *
 * @returns Status byte
 *
 * Function initiates a play of a pre-recorded voice prompt, but 16bit index is stored in Rn.
 * The 16 bit value of Rn, user can find in Configuration registers from CFG20 to CFG2F.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when playback is finished.
 */
T_RECPLAY_RETVAL recplay_playVPRn( uint8_t valueRn );

/**
 * @brief Voice Macro Execute Command
 *
 * @param[in] index  Index of Voice Macro
 *
 * @returns Status byte
 *
 * Function initiates the execution of a pre-recorded voice group.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when playback is finished.
 */
T_RECPLAY_RETVAL recplay_executeVM( uint16_t index );

/**
 * @brief Message Record Command
 *
 * @returns Status byte
 *
 * Function initiates a managed record at first available location in memory.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when recording complete,
 *                       FULL_ERR when device fills available memory.
 */
T_RECPLAY_RETVAL recplay_recordMsg( void );

/**
 * @brief Message Record at Address Command
 *
 * @param[in] memAddr  Memory location
 *
 * @returns Status byte
 *
 * Function initiates a managed record starting at a specified address.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when recording complete,
 *                       FULL_ERR when device fills available memory, ADDR_ERR if invalid address sent.
 */
T_RECPLAY_RETVAL recplay_recordMsgAddr( uint32_t memAddr );

/**
 * @brief Message Play at Address Command
 *
 * @param[in] memAddr  Memory location
 * @param[in] sectorOffset  Sector offset
 *
 * @returns Status byte
 *
 * Function initiates a play of a recorded message starting at a specified address, with a specified sector offset.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when playback complete,
 *                       ADDR_ERR if invalid address sent.
 */
T_RECPLAY_RETVAL recplay_playMsg( uint32_t memAddr, uint16_t sectorOffset );

/**
 * @brief Silence Play Command
 *
 * @param[in] silenceLength  Silence length * 32ms
 *
 * @returns Status byte
 *
 * Function plays a period of silence to the signal path.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when silence playback complete.
 */
T_RECPLAY_RETVAL recplay_playSilence( uint8_t silenceLength );

/**
 * @brief Stop Command
 *
 * @returns Status byte
 *
 * Function stops any current audio command.
 *
 * Interrupt Generation: Command itself does not generate interrupt, only those commands that it is stopping.
 */
T_RECPLAY_RETVAL recplay_stop( void );

/**
 * @brief Message Erase at Address Command
 *
 * @param[in] memAddr  Memory location
 *
 * @returns Status byte
 *
 * Function erases the message starting at the specified address.
 *
 * Interrupt Generation: CMD_ERR if not accepted, CMD_FIN when erase complete,
 *                       ADDR_ERR if invalid address sent.
 */
T_RECPLAY_RETVAL recplay_eraseMsg( uint32_t memAddr );

/**
 * @brief PCM Data SPI Write Command
 *
 * @param[in] dataPCM  Audio data in 16bit PCM format
 * @param[in] numPCM  Number of PCM words
 *
 * @returns Status byte
 *
 * Function writes audio data in 16bit PCM format via SPI interface.
 *
 * Interrupt Generation: OVF_ERR if RDY/BSY violated.
 */
T_RECPLAY_RETVAL recplay_spiWritePCM( uint16_t *dataPCM, uint8_t numPCM );

/**
 * @brief PCM Data SPI Read Command
 *
 * @param[out] dataPCM  Memory where PCM data be stored
 * @param[in] numPCM  Number of PCM words
 *
 * @returns Status byte
 *
 * Function reads audio data in 16bit PCM format via SPI interface.
 *
 * Interrupt Generation: OVF_ERR if RDY/BSY violated.
 */
T_RECPLAY_RETVAL recplay_spiReadPCM( uint16_t *dataPCM, uint8_t numPCM );

/**
 * @brief SPI Send Compressed Data to Decode Command
 *
 * @param[in] cmprsdData  Compressed audio data
 * @param[in] nData  Number of compressed data bytes
 *
 * @returns Status byte
 *
 * Function writes compressed audio data via SPI interface.
 *
 * Interrupt Generation: OVF_ERR if RDY/BSYB violated.
 */
T_RECPLAY_RETVAL recplay_spiSendCmprsdData( uint8_t *cmprsdData, uint8_t nData );

/**
 * @brief SPI Receive Encoded Data Command
 *
 * @param[out] encodedData  Memory where compressed audio data be stored
 * @param[in] nData  Number of compressed data bytes
 *
 * @returns Status byte
 *
 * Function reads compressed audio data via SPI intreface.
 *
 * Interrupt Generation: OVF_ERR if RDY/BSYB violated.
 */
T_RECPLAY_RETVAL recplay_spiReceiveEncData( uint8_t *encodedData, uint8_t nData );

/**
 * @brief Status Read Command
 *
 * @param[out] interrStatus  Memory where interrupt status byte be stored
 *
 * @returns Status byte
 *
 * Function queries the ISD3900 device status.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readStatus( uint8_t *interrStatus );

/**
 * @brief Interrupt Read Command
 *
 * @param[out] interrStatus  Memory where interrupt status byte be stored
 *
 * @returns Status byte
 *
 * Function queries the ISD3900 device status and clears any pending interrupts.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readInterr( uint8_t *interrStatus );

/**
 * @brief Recorded Message Address Read Command
 *
 * @param[out] msgAddr  Memory where recorded message address be stored
 * @param[out] msgLength  Memory where recorded message length be stored
 *
 * @returns Status byte
 *
 * Function reports the start address of the last or current message and message length.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readMsgAddr( uint32_t *msgAddr, uint16_t *msgLength );

/**
 * @brief Message Length Read Command
 *
 * @param[out] msgLength  Memory where message length be stored
 *
 * @returns Status byte
 *
 * Function reads number of sectors played by the last or current PLAY command.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readMsgLength( uint16_t *msgLength );

/**
 * @brief ISD3900 ID Read Command
 *
 * @param[out] partID  Identifies which 3900 family member
 * @param[out] manID  Manufacturer ID
 * @param[out] memType  Memory type
 * @param[out] devID  Device ID indicates the memory size
 *
 * @returns Status byte
 *
 * Function reads device and memory ID.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readID( uint8_t *partID, uint8_t *manID, uint8_t *memType, uint8_t *devID );

/**
 * @brief Digital Read Command
 *
 * @param[in] memAddr  Memory address
 * @param[out] dataOut  Memory where data be stored
 * @param[in] nData  Number of data bytes to be read
 *
 * @returns Status byte
 *
 * Function initiates a read of flash memory from specified address.
 *
 * Interrupt Generation: ADDR_ERR if memory protected or RDY/BSYB violated,
 *                       OVF_ERR if read past end of array.
 */
T_RECPLAY_RETVAL recplay_digRead( uint32_t memAddr, uint8_t *dataOut, uint8_t nData );

/**
 * @brief Digital Write Command
 *
 * @param[in] memAddr  Memory address
 * @param[in] dataIn  Data to be written
 * @param[in] nData  Number of data bytes to be written
 *
 * @returns Status byte
 *
 * Function initiates a write to flash memory from specified address.
 *
 * Interrupt Generation: ADDR_ERR if memory protected or RDY/BSYB violated,
 *                       OVF_ERR if write past end of array.
 */
T_RECPLAY_RETVAL recplay_digWrite( uint32_t memAddr, uint8_t *dataIn, uint8_t nData );

/**
 * @brief Memory Erase Command
 *
 * @param[in] startAddr  Start address
 * @param[in] endAddr  End address
 *
 * @returns Status byte
 *
 * Function erases memory from sector containing Start address to sector containing End address.
 *
 * Interrupt Generation: ADDR_ERR if memory protected, CMD_ERR if device is busy,
 *                       CMD_FIN when erase operation complete.
 */
T_RECPLAY_RETVAL recplay_eraseMem( uint32_t startAddr, uint32_t endAddr );

/**
 * @brief Chip Erase Command
 *
 * @returns Status byte
 *
 * Function erases the entire contents of the external memory.
 *
 * Interrupt Generation: CMD_ERR if device is busy and cannot accept command, 
 *                       CMD_FIN when erase operation complete.
 */
T_RECPLAY_RETVAL recplay_eraseChip( void );

/**
 * @brief Power Up Command
 *
 * @returns Status byte
 *
 * Function powers up the device.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_pwrUp( void );

/**
 * @brief Power Down Command
 *
 * @returns Status byte
 *
 * Function powers down the device.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_pwrDown( void );

/**
 * @brief Clock Configuration Set Command
 *
 * @param[in] clkCnfg  Configuration byte for clock
 *
 * @returns Status byte
 *
 * Function loads the clock configuration register.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_setClkCnfg( uint8_t clkCnfg );

/**
 * @brief Clock Configuration Read Command
 *
 * @param[out] clkCnfg  Memory where clock configuration byte be stored
 *
 * @returns Status byte
 *
 * Function reads the clock configuration register.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readClkCnfg( uint8_t *clkCnfg );

/**
 * @brief Configuration Write Command
 *
 * @param[in] regAddr  Configuration register address (from 0x00 to 0x2F)
 * @param[in] cnfgData  Configuration data to be written
 * @param[in] nData  Number of data bytes to be written
 *
 * @returns Status byte
 *
 * Function loads configuration registers starting at the specified address.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_writeCnfgReg( uint8_t regAddr, uint8_t *cnfgData, uint8_t nData );

/**
 * @brief Configuration Read Command
 *
 * @param[in] regAddr  Configuration register address (from 0x00 to 0x2F)
 * @param[out] cnfgData  Memory where configuration data be stored
 * @param[in] nData  Number of data bytes to be read
 *
 * @returns Status byte
 *
 * Function reads the configuration registers starting at the specified address.
 *
 * Interrupt Generation: This command does not generate interrupt.
 */
T_RECPLAY_RETVAL recplay_readCnfgReg( uint8_t regAddr, uint8_t *cnfgData, uint8_t nData );

/**
 * @brief SPI Data Transfer Status Check Command
 *
 * @returns 1 - ISD3900 is ready for new command, 0 - ISD3900 is busy
 *
 * Function reports the status of data transfer on the SPI interface.
 */
uint8_t recplay_checkRDY( void );

/**
 * @brief Interrupt Request Pin Check Command
 *
 * @returns 0 - Interrupt is generated, 1 - Interrupt is not generated
 *
 * Function reports the status of the INT pin, does interrupt generated or not.
 */
uint8_t recplay_checkINT( void );

/**
 * @brief ISD3900 Reset Command
 *
 * Function performs the device reset and after that puts the device in normal operation mode.
 */
void recplay_reset( void );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_REC_n_PLAY_STM.c
    @example Click_REC_n_PLAY_TIVA.c
    @example Click_REC_n_PLAY_CEC.c
    @example Click_REC_n_PLAY_KINETIS.c
    @example Click_REC_n_PLAY_MSP.c
    @example Click_REC_n_PLAY_PIC.c
    @example Click_REC_n_PLAY_PIC32.c
    @example Click_REC_n_PLAY_DSPIC.c
    @example Click_REC_n_PLAY_AVR.c
    @example Click_REC_n_PLAY_FT90x.c
    @example Click_REC_n_PLAY_STM.mbas
    @example Click_REC_n_PLAY_TIVA.mbas
    @example Click_REC_n_PLAY_CEC.mbas
    @example Click_REC_n_PLAY_KINETIS.mbas
    @example Click_REC_n_PLAY_MSP.mbas
    @example Click_REC_n_PLAY_PIC.mbas
    @example Click_REC_n_PLAY_PIC32.mbas
    @example Click_REC_n_PLAY_DSPIC.mbas
    @example Click_REC_n_PLAY_AVR.mbas
    @example Click_REC_n_PLAY_FT90x.mbas
    @example Click_REC_n_PLAY_STM.mpas
    @example Click_REC_n_PLAY_TIVA.mpas
    @example Click_REC_n_PLAY_CEC.mpas
    @example Click_REC_n_PLAY_KINETIS.mpas
    @example Click_REC_n_PLAY_MSP.mpas
    @example Click_REC_n_PLAY_PIC.mpas
    @example Click_REC_n_PLAY_PIC32.mpas
    @example Click_REC_n_PLAY_DSPIC.mpas
    @example Click_REC_n_PLAY_AVR.mpas
    @example Click_REC_n_PLAY_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __recplay_driver.h

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