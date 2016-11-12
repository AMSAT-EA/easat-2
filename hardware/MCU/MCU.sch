EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:pic18f45k22
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PIC18F45K22 U?
U 1 1 5827203A
P 5050 2350
F 0 "U?" H 5050 2025 60  0000 C CNN
F 1 "PIC18F45K22" H 5025 3275 60  0000 C CNN
F 2 "" H 5050 2350 60  0001 C CNN
F 3 "" H 5050 2350 60  0001 C CNN
	1    5050 2350
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y?
U 1 1 58272070
P 2900 1750
F 0 "Y?" H 2900 1900 50  0000 C CNN
F 1 "Crystal" H 2900 1600 50  0000 C CNN
F 2 "" H 2900 1750 50  0000 C CNN
F 3 "" H 2900 1750 50  0000 C CNN
	1    2900 1750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5827209D
P 3350 1900
F 0 "C?" H 3360 1970 50  0000 L CNN
F 1 "C_Small" H 3360 1820 50  0000 L CNN
F 2 "" H 3350 1900 50  0000 C CNN
F 3 "" H 3350 1900 50  0000 C CNN
	1    3350 1900
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 582720CA
P 2350 1900
F 0 "C?" H 2360 1970 50  0000 L CNN
F 1 "C_Small" H 2360 1820 50  0000 L CNN
F 2 "" H 2350 1900 50  0000 C CNN
F 3 "" H 2350 1900 50  0000 C CNN
	1    2350 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 1750 3350 1750
Wire Wire Line
	3350 1750 3350 1800
Wire Wire Line
	2750 1750 2350 1750
Wire Wire Line
	2350 1750 2350 1800
$Comp
L GND #PWR?
U 1 1 58272117
P 2350 2100
F 0 "#PWR?" H 2350 1850 50  0001 C CNN
F 1 "GND" H 2350 1950 50  0000 C CNN
F 2 "" H 2350 2100 50  0000 C CNN
F 3 "" H 2350 2100 50  0000 C CNN
	1    2350 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5827213B
P 3350 2150
F 0 "#PWR?" H 3350 1900 50  0001 C CNN
F 1 "GND" H 3350 2000 50  0000 C CNN
F 2 "" H 3350 2150 50  0000 C CNN
F 3 "" H 3350 2150 50  0000 C CNN
	1    3350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2100 2350 2000
Wire Wire Line
	3350 2150 3350 2000
Text Label 2500 1750 0    60   ~ 0
RA6
Text Label 3150 1750 0    60   ~ 0
RA7
Text Label 4326 2149 2    60   ~ 0
RA7
Text Label 4326 2223 2    60   ~ 0
RA6
$EndSCHEMATC
