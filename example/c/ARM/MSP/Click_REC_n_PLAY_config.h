#include "Click_REC_n_PLAY_types.h"

const uint32_t _RECPLAY_SPI_CFG[ 7 ] = 
{ 
	_SPI_MASTER, 
	64, 
	_SPI_CLOCKSOURCE_SMCLK, 
	_SPI_MSB_FIRST, 
	_SPI_PHASE_DATA_CHANGE_SECOND_CAPTURE_NEXT, 
	_SPI_CLK_IDLE_HIGH, 
	_SPI_3PIN 
};
