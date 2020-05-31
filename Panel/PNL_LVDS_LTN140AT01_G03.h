#define _DISPLAY_RATIO            _DISABLE

#define _PANEL_DOUBLE_H             0

#ifdef __RTDACCESS__
//__SCALER__

//--------------------------------------------------
// Panel Style : 
//(_PANEL_TTL / _PANEL_HZ / _PANEL_LVDS / _PANEL_RSDS) |
//_AUTOCALC_PIXCLK |
//(_LVDS_MAP1 / _LVDS_MAP2) | 
//(_DISP_24_BIT / _DISP_18_BIT) |
//_RSDS_GC_SWAP |
//_RSDS_HL_SWAP |
//_RSDS_PN_SWAP |


//--------------------------------------------------
// Panel Configuration :
//_DHS_MASK |
//_DISP_EO_SWAP |
//_DISP_RB_SWAP |
//_DISP_ML_SWAP |
//(_DISP_SINGLE_PORT / _DISP_DOUBLE_PORT) |
//_DVS_INVERT |
//_DHS_INVERT |
//_DEN_INVERT,

//--------------------------------------------------

// 1366x768
code PanelType Panel0 =
{
	// Panel Style
    _PANEL_LVDS |		//_PANEL_TTL,_PANEL_HZ,_PANEL_LVDS,_PANEL_RSDS
    //_AUTOCALC_PIXCLK |
    _LVDS_MAP2 |		//_LVDS_MAP1,_LVDS_MAP2
    _DISP_18_BIT | 		//_DISP_24_BIT,_DISP_18_BIT
    //_RSDS_GC_SWAP |
   ///_RSDS_HL_SWAP |
    //_RSDS_PN_SWAP |
    0x00,                            

	// Panel Configuration
	//_DHS_MASK |
	//_DISP_EO_SWAP | // Display Data Port Even/Odd Data Swap
	//_DISP_RB_SWAP | // Display Data Port Red/Blue Data Swap 
	//_DISP_ML_SWAP | // Display Data Port MSB/LSB Data Swap 
	_DISP_SINGLE_PORT |	//_DISP_SINGLE_PORT,_DISP_DOUBLE_PORT
	//_DVS_INVERT | // Display Vertical Sync
	//_DHS_INVERT | // Display Horizontal Sync
	//_DEN_INVERT | // Display Data Enable
	0x00,


	160,         // Display Horizontal Start Position
	1366,        // Display Horizontal Width

	1526,        // Display Horizontal Total Clock Number in One Display Line

	1526,        // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
	1526,        // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

	22,         // Display Vertical Start Position
	768,        // Display Vertical Height

	790,        // Display Vertical Total Line Number in One Frame

	32,         // Display H Sync Width
	5,          // Display V Sync Height

	72,         // Typical Pixel Clock in MHz

	1100,		// H Sync Max Freq Unit in 0.1 kHZ
	100,		// H Sync Min Freq Unit in 0.1 kHZ
	880,		// V Sync Max Freq Unit in 0.1 HZ
	500,		// V Sync Min Freq Unit in 0.1 HZ

    // TTL setting   
    //(2 << 4) |  // Delay
    (1 << 1) |    // DCLK output enable
    0x00,         // DCLK Polarity

};

//--------------------------------------------------
// Select panel
BYTE idata ucPanelSelect = 0;


//--------------------------------------------------
code PanelType *Panel[] = 
{
     &Panel0
};

//--------------------------------------------------
BYTE code g_ucPanelCnt = sizeof(Panel)/3;

#if(_VGA_EDID == _ON)
BYTE code tVGA_EDID_DATA[] =
{
    0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x4a,0x8b,0x00,0x00,0x01,0x01,0x01,0x01,
    0x1e,0x0c,0x01,0x01,0x0e,0x24,0x1b,0x78,0xe8,0x8a,0x01,0x9a,0x58,0x52,0x8b,0x28,
    0x1e,0x50,0x54,0xff,0xff,0x80,0x61,0x40,0x61,0x4f,0x61,0x59,0x71,0x4f,0x81,0x40,
    0x81,0x59,0x81,0x99,0xa9,0x40,0x00,0x00,0x00,0xfc,0x00,0x31,0x37,0x27,0x27,0x20,
    0x4c,0x43,0x44,0x0a,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xfc,0x00,0x4d,0x6f,0x6e,
    0x69,0x74,0x6f,0x72,0x0a,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xfd,0x00,0x2b,
    0x55,0x14,0x5c,0x0e,0x00,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xff,
    0x00,0x30,0x30,0x30,0x30,0x30,0x31,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0xbd,
};
#endif

#if(_DVI_EDID == _ON)
BYTE code tDVI_EDID_DATA[] =
{
    0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x26,0xCD,0x68,0x46,0x00,0x00,0x00,0x00,
    0x23,0x0c,0x01,0x03,0x81,0x24,0x1D,0x78,0xeF,0x0D,0xC2,0xa0,0x57,0x47,0x98,0x27,
    0x12,0x48,0x4F,0xBF,0xEF,0x00,0x81,0x80,0x81,0x8F,0x61,0x40,0x61,0x59,0x45,0x40,
    0x45,0x59,0x31,0x40,0x31,0x59,0xBC,0x34,0x00,0x98,0x51,0x00,0x2A,0x40,0x10,0x90,
    0x13,0x00,0x68,0x22,0x11,0x00,0x00,0x1e,0x00,0x00,0x00,0xFF,0x00,0x30,0x0A,0x20,
    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x41,
    0x53,0x34,0x36,0x33,0x37,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFD,
    0x00,0x38,0x55,0x18,0x50,0x0E,0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x06,
};
#endif

#if(_HDMI_EDID == _ON)
BYTE code tHDMI_EDID_DATA[] =
{
    /* ORIGINAL EDID
	
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,	0x4a, 0x8b, 0x20, 0x61, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x0e, 0x01, 0x03, 0x80, 0x45, 0x27, 0x78, 0x2a, 0x7c, 0x11, 0x9e, 0x59, 0x47, 0x9b, 0x27, 
	0x10, 0x50, 0x54, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1d, 0x80, 0x18, 0x71, 0x1c, 0x16, 0x20, 0x58, 0x2c, 
	0x25, 0x00, 0xb4, 0x86, 0x21, 0x00, 0x00, 0x9e, 0x8c, 0x0a, 0xd0, 0x8a, 0x20, 0xe0, 0x2d, 0x10, 
	0x10, 0x3e, 0x96, 0x00, 0x08, 0x86, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x4c, 
	0x54, 0x2d, 0x33, 0x32, 0x58, 0x35, 0x37, 0x35, 0x0a, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xfd, 
	0x00, 0x3b, 0x3d, 0x0f, 0x2e, 0x08,	0x00, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0xb2, 
	0x02, 0x03, 0x1a, 0x72, 0x47, 0x85, 0x02, 0x03, 0x04, 0x01, 0x06, 0x07, 0x23, 0x09, 0x07, 0x07, 
    0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0c, 0x00, 0x10, 0x00, 0x01, 0x1d, 0x00, 0x72, 0x51, 0xd0, 
    0x1e, 0x20, 0x6e, 0x28, 0x55, 0x00, 0xb4, 0x86, 0x21, 0x00, 0x00, 0x1e, 0xd6, 0x09, 0x80, 0xa0, 
    0x20, 0xe0, 0x2d, 0x10, 0x10, 0x60, 0xa2, 0x00, 0x08, 0x86, 0x21, 0x00, 0x00, 0x18, 0x8c, 0x0a, 
    0xd0, 0x8a, 0x20, 0xe0, 0x2d, 0x10, 0x10, 0x3e, 0x96, 0x00, 0xb4, 0x86, 0x21, 0x00, 0x00, 0x18, 
    0x8c, 0x0a, 0xa0, 0x14, 0x51, 0xf0, 0x16, 0x00, 0x26, 0x7c, 0x43, 0x00, 0x08, 0x86, 0x21, 0x00, 
    0x00, 0x98, 0x8c, 0x0a, 0xa0, 0x14, 0x51, 0xf0, 0x16, 0x00, 0x26, 0x7c, 0x43, 0x00, 0xb4, 0x86, 
    0x21, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18 */

	/* MODIFIED*/

	0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x10, 0xAC, 0x24, 0xF0, 0x4C, 0x4B, 0x52, 0x45,
	0x29, 0x18, 0x01, 0x03, 0x80, 0x33, 0x1D, 0x78, 0xEA, 0x1E, 0x55, 0xA0, 0x59, 0x56, 0x9F, 0x27,
	0x0D, 0x50, 0x54, 0xA5, 0x4B, 0x00, 0x71, 0x4F, 0x81, 0x80, 0xD1, 0xC0, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
	0x45, 0x00, 0xFD, 0x1E, 0x11, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x4D, 0x32, 0x4E,
	0x4E, 0x36, 0x31, 0x41, 0x36, 0x45, 0x52, 0x4B, 0x4C, 0x0A, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x44,
	0x45, 0x4C, 0x4C, 0x20, 0x53, 0x54, 0x32, 0x33, 0x32, 0x30, 0x4C, 0x0A, 0x00, 0x00, 0x00, 0xFD,
	0x00, 0x38, 0x4C, 0x1E, 0x53, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x10,
	0x02, 0x03, 0x1F, 0xF1, 0x4C, 0x90, 0x02, 0x03, 0x01, 0x07, 0x16, 0x12, 0x04, 0x1F, 0x13, 0x14,
	0x05, 0x23, 0x09, 0x07, 0x07, 0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0C, 0x00, 0x10, 0x00, 0x02,
	0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C, 0x45, 0x00, 0xFE, 0x1F, 0x11, 0x00, 0x00,
	0x1E, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00, 0xFE, 0x1F, 0x11,
	0x00, 0x00, 0x9E, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E, 0x28, 0x55, 0x00, 0xFE,
	0x1F, 0x11, 0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96,
	0x00, 0xFE, 0x1F, 0x11, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDF

	/*0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x4A, 0x8B, 0x54, 0x4C, 0x01, 0x00, 0x00, 0x00,
	0x0C, 0x11, 0x01, 0x03, 0x81, 0x46, 0x27, 0x78, 0x8A, 0xA5, 0x8E, 0xA6, 0x54, 0x4A, 0x9C, 0x26,
	0x12, 0x45, 0x46, 0xAF, 0xCF, 0x00, 0x95, 0x00, 0x95, 0x0F, 0x95, 0x19, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E, 0x28,
	0x55, 0x00, 0xB9, 0x88, 0x21, 0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
	0x01, 0x3E, 0x96, 0x00, 0xB9, 0x88, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x32,
	0x4B, 0x18, 0x3C, 0x0B, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFC,
	0x00, 0x33, 0x32, 0x56, 0x33, 0x48, 0x2D, 0x48, 0x36, 0x41, 0x0A, 0x20, 0x20, 0x20, 0x01, 0x38,
	0x02, 0x03, 0x21, 0x71, 0x4E, 0x06, 0x07, 0x02, 0x03, 0x15, 0x96, 0x11, 0x12, 0x13, 0x04, 0x14,
	0x05, 0x1F, 0x90, 0x23, 0x09, 0x07, 0x07, 0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0C, 0x00, 0x10,
	0x00, 0x8C, 0x0A, 0xD0, 0x90, 0x20, 0x40, 0x31, 0x20, 0x0C, 0x40, 0x55, 0x00, 0xB9, 0x88, 0x21,
	0x00, 0x00, 0x18, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00, 0xB9,
	0x88, 0x21, 0x00, 0x00, 0x9E, 0x01, 0x1D, 0x80, 0xD0, 0x72, 0x1C, 0x16, 0x20, 0x10, 0x2C, 0x25,
	0x80, 0xB9, 0x88, 0x21, 0x00, 0x00, 0x9E, 0x01, 0x1D, 0x00, 0xBC, 0x52, 0xD0, 0x1E, 0x20, 0xB8,
	0x28, 0x55, 0x40, 0xB9, 0x88, 0x21, 0x00, 0x00, 0x1E, 0x02, 0x3A, 0x80, 0xD0, 0x72, 0x38, 0x2D,
	0x40, 0x10, 0x2C, 0x45, 0x80, 0xB9, 0x88, 0x21, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xD0*/	

};
#endif//End of #if(_HDMI_EDID == _ON)

#else	// else of . #ifdef __MAIN__

extern code PanelType *Panel[];
extern BYTE code g_ucPanelCnt;
extern BYTE code tVGA_EDID_DATA[];
extern BYTE code tDVI_EDID_DATA[];
extern BYTE code tHDMI_EDID_DATA[];
extern BYTE idata ucPanelSelect;

#endif	// endif of . #ifdef __MAIN__




