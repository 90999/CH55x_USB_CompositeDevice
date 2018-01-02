#include "types.h"

#include "usb_mal.h"

xdata uint32_t Mass_Block_Size[MAL_MAX_LUN+1];
xdata uint32_t Mass_Block_Count[MAL_MAX_LUN+1];

#define FLASH25_SIZE 0x180000			//Capacity 2MB
#define FLASH25_SECTORSIZE 0x1000	//Sector Size 4KB

uint8_t MAL_GetStatus (uint8_t lun) {
	 switch (lun){
		 case 0:	//SPI Flash
			 Mass_Block_Count[0] = FLASH25_SIZE/FLASH25_SECTORSIZE;
			 Mass_Block_Size[0] =  FLASH25_SECTORSIZE;
			 return MAL_OK;
		 default:
			 return MAL_FAIL;
	 }
}

uint8_t MAL_Read(uint8_t lun, uint32_t Memory_Offset, uint8_t *Readbuff, uint16_t Transfer_Length) {
	return MAL_OK;
}