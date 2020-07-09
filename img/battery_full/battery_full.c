
/*******************************************************************************
* image
* filename: D:/Users/alexa/Desktop/Smart_Terrarium/img/battery_full/battery_full.xml
* name: battery_full
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Edge 107
* bits per pixel: 1
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: yes
*******************************************************************************/

/*
 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
     } tImage;
*/
#include <stdint.h>



static const uint8_t image_data_battery_full[20] = {
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe, 
    0xff, 0xfe
};
const tImage battery_full = { image_data_battery_full, 15, 10,
    8 };

