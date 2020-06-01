@echo off
mkdir Bin > nul
del Bin\* /F /Q
copy Output\RTD2662.H00 Bin\RTD2662.H00
copy Output\RTD2662.H01 Bin\RTD2662.H01
CreateBin.exe Bin\Firmware.bin Output\RTD2662.H00 Output\RTD2662.H01
echo.
echo --- Resulting file is Bin\Firmware.bin. ---