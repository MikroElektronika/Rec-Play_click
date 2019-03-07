#include "Click_REC_n_PLAY_types.h"

const uint32_t _RECPLAY_SPI_CFG[ 3 ] = 
{ 
	1000000,  
	_SPI_MSB_FIRST, 
	_SPI_CLK_IDLE_HIGH | 
	_SPI_SAMPLE_DATA_FALLING_EDGE 
};
