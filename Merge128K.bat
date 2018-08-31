@echo off
mkdir Bin > nul
del Bin\* /F /Q
copy Output\RTD2662.H00 Bin\RTD2662.H00
copy Output\RTD2662.H01 Bin\RTD2662.H01
HEX2BIN /Q /L131072   Bin\RTD2662.H00 Bin\RTD2662.BIN
HEX2BIN /Q /O65536 /M Bin\RTD2662.H01 Bin\RTD2662.BIN
echo.
echo --- Resulting file is Bin\Firmware.bin. ---