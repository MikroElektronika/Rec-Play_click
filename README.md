![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# REC_n_PLAY Click

- **CIC Prefix**  : RECPLAY
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Aug 2018.

---


### Software Support

We provide a library for the REC_n_PLAY Click on our [LibStock](https://libstock.mikroe.com/projects/view/2574/rec-amp-play-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library offers a choice to perform control of the REC&PLAY Click board by sending commands to the ISD3900 via SPI interface.
Commands include message recording, recorded message playing, sending or receiving compressed audio data, digital reading and writting, 
device configuration, device status and interrupt checking...
All functions return device status byte, so on that way user can check status of the device and SPI interface after each sent command.
For more details check documentation.

Key functions :

- ``` T_RECPLAY_RETVAL recplay_recordMsg( void ) ``` - Function initiates a managed record at first available location in memory.
- ``` T_RECPLAY_RETVAL recplay_playMsg( uint32_t memAddr, uint16_t sectorOffset ) ``` - Function initiates a play of a recorded message starting 
  at a specified address, with a specified sector offset.
- ``` T_RECPLAY_RETVAL recplay_stop( void ) ``` - Function stops any current audio command.
- ``` T_RECPLAY_RETVAL recplay_eraseMsg( uint32_t memAddr ) ``` - Function erases the message starting at the specified address.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes SPI interface in properly mode and performs the all necessary commands to
  put device in properly working mode (chip reset, chip power up, chip erasing, clock configuration).
- Application Task - (code snippet) - Performs the chip configuration for recording message via microphone, then records a message
  for 8 seconds to specified memory location. After that reads the recorded message address with message length and then plays a
  recorded message. When playback is done erases a recorded message from memory. Repeats the all operation every 10 seconds.
Note : The ISD3900 must be properly configured to work in record mode every time when user wants to record a message.
When user wants to play a recorded message, then ISD3900 must be properly configured, but now to work in play mode.


```.c
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
```

Additional Functions :

- void waitCmdFin() - Waits until current command has properly finished.
- void waitReady() - Waits until SPI interface was ready for new command.
- void waitPowerUp() - Waits until ISD3900 has powered up.
- void timeRecord( uint32_t secondsTime ) - Performs the desired time in seconds for message recording.
- void setVolume( uint8_t volumeSel ) - Sets a volume on the desired value (0 - 100%) for a message playing.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2574/rec-amp-play-click) page.

Other mikroE Libraries used in the example:

- Conversions
- SPI
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
