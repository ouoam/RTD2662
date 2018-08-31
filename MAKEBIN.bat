@echo off
mkdir Bin > nul
del Bin\*
copy Output\RTD2662.H00 Bin\RTD2662.H00
copy Output\RTD2662.H00 Bin\RTD2662.H01
CreateBin.exe Bin\Firmware.bin Output\RTD2662.H00 Output\RTD2662.H01