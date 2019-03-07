/*
Example for REC_n_PLAY Click

    Date          : Aug 2018.
    Author        : Nemanja Medakovic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes SPI interface in properly mode and performs the all necessary commands to
  put device in properly working mode (chip reset, chip power up, chip erasing, clock configuration).
- Application Task - (code snippet) - Performs the chip configuration for recording message via microphone, then records a message
  for 8 seconds to specified memory location. After that reads the recorded message address with message length and then plays a
  recorded message. When playback is done erases a recorded message from memory. Repeats the all operation every 10 seconds.
Note : The ISD3900 must be properly configured to work in record mode every time when user wants to record a message.
When user wants to play a recorded message, then ISD3900 must be properly configured, but now to work in play mode.

Additional Functions :

- void waitCmdFin() - Waits until current command has properly finished.
- void waitReady() - Waits until SPI interface was ready for new command.
- void waitPowerUp() - Waits until ISD3900 has powered up.
- void timeRecord( uint32_t secondsTime ) - Performs the desired time in seconds for message recording.
- void setVolume( uint8_t volumeSel ) - Sets a volume on the desired value (0 - 100%) for a message playing.

*/

#include "Click_REC_n_PLAY_types.h"
#include "Click_REC_n_PLAY_config.h"

uint32_t messageAddr;
uint16_t messageLength;
uint8_t tempVar;
uint8_t i;
uint8_t volume;
T_RECPLAY_RETVAL statusByte;
uint8_t interrByte;
char text[ 30 ];

const uint8_t configPlayPwmSpk[ 32 ] = { 0x64, 0x00, 0x44, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x57, 0x01, 0x57, 0x00, 0x00, 0xFF, 0x30, 0x02, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00 };
const uint8_t configPlayAuxOut[ 32 ] = { 0x64, 0x00, 0x48, 0x00, 0x40, 0x80, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x57, 0x01, 0x57, 0x00, 0x00, 0xFF, 0x30, 0x02, 0xAB, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00 };
const uint8_t configRecMic[ 32 ] = { 0xA4, 0x80, 0x02, 0xFF, 0x0D, 0x40, 0x50, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x3E, 0x00, 0xD6, 0x00, 0xFF, 0xFF, 0x11, 0x82, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00 };

void waitCmdFin()
{
    statusByte = recplay_readStatus( &interrByte );
    while ((interrByte != _RECPLAY_INT_CMD_FIN_MASK) || (statusByte != (_RECPLAY_STAT_DBUF_RDY_MASK | _RECPLAY_STAT_INT_GEN_MASK)))
    {
        statusByte = recplay_readStatus( &interrByte );
    }
    statusByte = recplay_readInterr( &interrByte );
}

void waitReady()
{
    statusByte = recplay_readStatus( &interrByte );
    while (statusByte != _RECPLAY_STAT_DBUF_RDY_MASK)
    {
        statusByte = recplay_readStatus( &interrByte );
    }
    statusByte = recplay_readInterr( &interrByte );
}

void waitPowerUp()
{
    statusByte = recplay_readStatus( &interrByte );
    while (statusByte == _RECPLAY_STAT_PWR_DOWN_MASK)
    {
        statusByte = recplay_readStatus( &interrByte );
    }
    statusByte = recplay_readInterr( &interrByte );
}

void timeRecord( uint32_t secondsTime )
{
    for (i = 0; i < secondsTime; i++)
    {
        Delay_ms( 1000 );
        mikrobus_logWrite( ". ", _LOG_TEXT );
    }
    mikrobus_logWrite( "", _LOG_LINE );
}

void setVolume( uint8_t volumeSel )
{
    uint16_t volumRes;

    if (volumeSel > 100)
    {
        volume = 0;
        mikrobus_logWrite( "Volume is: 100%", _LOG_LINE );
        return;
    }
    
    volumRes = 255 * volumeSel;
    volumRes /= 100;
    volume = 255 - volumRes;
    
    mikrobus_logWrite( "Volume is: ", _LOG_TEXT );
    ByteToStr( volumeSel, text );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( "%", _LOG_LINE );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_RECPLAY_SPI_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite( "*** Initializing ***", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    recplay_spiDriverInit( (T_RECPLAY_P)&_MIKROBUS1_GPIO, (T_RECPLAY_P)&_MIKROBUS1_SPI );
    Delay_ms( 500 );

    mikrobus_logWrite( "---------------------------------------", _LOG_LINE );
    mikrobus_logWrite( "Chip Reset...", _LOG_LINE );
    recplay_reset();
    mikrobus_logWrite( "Power Up...", _LOG_LINE );
    recplay_pwrUp();
    waitPowerUp();
    mikrobus_logWrite( "Chip Erasing...", _LOG_LINE );
    recplay_eraseChip();
    waitCmdFin();
    mikrobus_logWrite( "Clock Configuration...", _LOG_LINE );
    statusByte = recplay_setClkCnfg( 0x34 );
    mikrobus_logWrite( "---------------------------------------", _LOG_LINE );
    volume = 0;
    
    mikrobus_logWrite( "*** REC&PLAY click is initialized ***", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_ms( 1000 );
}

void applicationTask()
{
    mikrobus_logWrite( "Preparing to record a message...", _LOG_LINE );
    for (i = 0; i < 32; i++)
    {
        if ((i != _RECPLAY_CFG0A_REG) && (i != _RECPLAY_CFG1C_REG) && (i != _RECPLAY_CFG1E_REG))
        {
            waitReady();
            tempVar = configRecMic[ i ];
            statusByte = recplay_writeCnfgReg( i, &tempVar, 1 );
        }
    }
    waitReady();
    Delay_ms( 2000 );

    mikrobus_logWrite( "Message Recording", _LOG_TEXT );
    statusByte = recplay_recordMsgAddr( 0x12000 );
    timeRecord( 8 );
    statusByte = recplay_stop();
    waitCmdFin();
    mikrobus_logWrite( "End of recording", _LOG_LINE );
    
    mikrobus_logWrite( "---------------------------------------", _LOG_LINE );
    statusByte = recplay_readMsgAddr( &messageAddr, &messageLength );
    LongWordToHex( messageAddr, text );
    mikrobus_logWrite( "Message Address: 0x", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    WordToStr( messageLength, text );
    mikrobus_logWrite( "Message Length: ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    mikrobus_logWrite( "---------------------------------------", _LOG_LINE );
    Delay_ms( 1000 );

    mikrobus_logWrite( "Preparing to play a message...", _LOG_LINE );
    setVolume( 100 );
    for (i = 0; i < 32; i++)
    {
        if ((i != _RECPLAY_CFG0A_REG) && (i != _RECPLAY_CFG1C_REG) && (i != _RECPLAY_CFG1E_REG))
        {
            waitReady();
            if (i == _RECPLAY_CFG03_REG)
            {
                tempVar = volume;
            }
            else
            {
                tempVar = configPlayPwmSpk[ i ];
            }
            statusByte = recplay_writeCnfgReg( i, &tempVar, 1 );
        }
    }
    waitReady();
    Delay_ms( 2000 );

    mikrobus_logWrite( "Message is playing...", _LOG_LINE );
    statusByte = recplay_playMsg( 0x12000, 0 );
    waitCmdFin();
    mikrobus_logWrite( "End of playing", _LOG_LINE );
    
    mikrobus_logWrite( "---------------------------------------", _LOG_LINE );
    ByteToHex( statusByte, text );
    mikrobus_logWrite( "Status Byte: 0x", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    ByteToHex( interrByte, text );
    mikrobus_logWrite( "Interrupt Byte: 0x", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    mikrobus_logWrite( "---------------------------------------", _LOG_LINE );
    Delay_ms( 1000 );
    
    mikrobus_logWrite( "Message Erasing...", _LOG_LINE );
    statusByte = recplay_eraseMsg( 0x12000 );
    waitCmdFin();
    mikrobus_logWrite( "End of erasing", _LOG_LINE );
    
    mikrobus_logWrite( "***************************************", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_ms( 10000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}