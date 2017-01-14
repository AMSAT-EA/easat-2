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
LIBS:max6369
LIBS:MCU-cache
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
L PIC18F45K22 U3
U 1 1 5827203A
P 6330 2900
F 0 "U3" H 6330 2575 60  0000 C CNN
F 1 "PIC18F45K22" H 6305 3825 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-28W_7.5x17.9mm_Pitch1.27mm" H 6330 2900 60  0001 C CNN
F 3 "" H 6330 2900 60  0001 C CNN
	1    6330 2900
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 58272070
P 2900 1750
F 0 "Y1" H 2900 1900 50  0000 C CNN
F 1 "Crystal" H 2900 1600 50  0000 C CNN
F 2 "Oscillators:Oscillator_DIP-14" H 2900 1750 50  0001 C CNN
F 3 "" H 2900 1750 50  0000 C CNN
	1    2900 1750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 5827209D
P 3350 1900
F 0 "C2" H 3360 1970 50  0000 L CNN
F 1 "C_Small" H 3360 1820 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3350 1900 50  0001 C CNN
F 3 "" H 3350 1900 50  0000 C CNN
	1    3350 1900
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 582720CA
P 2350 1900
F 0 "C1" H 2360 1970 50  0000 L CNN
F 1 "C_Small" H 2360 1820 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2350 1900 50  0001 C CNN
F 3 "" H 2350 1900 50  0000 C CNN
	1    2350 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 58272117
P 2350 2100
F 0 "#PWR01" H 2350 1850 50  0001 C CNN
F 1 "GND" H 2350 1950 50  0000 C CNN
F 2 "" H 2350 2100 50  0000 C CNN
F 3 "" H 2350 2100 50  0000 C CNN
	1    2350 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5827213B
P 3350 2150
F 0 "#PWR02" H 3350 1900 50  0001 C CNN
F 1 "GND" H 3350 2000 50  0000 C CNN
F 2 "" H 3350 2150 50  0000 C CNN
F 3 "" H 3350 2150 50  0000 C CNN
	1    3350 2150
	1    0    0    -1  
$EndComp
Text Label 2500 1750 0    60   ~ 0
RA6
Text Label 3150 1750 0    60   ~ 0
RA7
Text Label 5480 2700 2    39   ~ 0
RA7
Text Label 5355 2250 0    39   ~ 0
SOL
Text Label 5355 2325 0    39   ~ 0
PWD
$Comp
L VCC #PWR03
U 1 1 5827428A
P 3476 2770
F 0 "#PWR03" H 3476 2620 50  0001 C CNN
F 1 "VCC" V 3476 2920 50  0000 C CNN
F 2 "" H 3476 2770 50  0000 C CNN
F 3 "" H 3476 2770 50  0000 C CNN
	1    3476 2770
	-1   0    0    1   
$EndComp
$Comp
L MAX6369 U1
U 1 1 58272E1A
P 2906 2420
F 0 "U1" H 2906 2345 60  0000 C CNN
F 1 "MAX6369" H 2906 2920 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6_Handsoldering" H 2906 2420 60  0001 C CNN
F 3 "" H 2906 2420 60  0001 C CNN
	1    2906 2420
	1    0    0    1   
$EndComp
$Comp
L GND #PWR04
U 1 1 58274C58
P 2181 2730
F 0 "#PWR04" H 2181 2480 50  0001 C CNN
F 1 "GND" H 2181 2580 50  0000 C CNN
F 2 "" H 2181 2730 50  0000 C CNN
F 3 "" H 2181 2730 50  0000 C CNN
	1    2181 2730
	1    0    0    -1  
$EndComp
Text Label 3556 2695 0    39   ~ 0
~WDO
Text Label 3611 2545 2    39   ~ 0
SET1
Text Label 3611 2620 2    39   ~ 0
SET2
Text Label 2271 2545 0    39   ~ 0
SET0
Text Label 7385 3075 0    39   ~ 0
SET0
Text Label 7380 3000 0    39   ~ 0
SET1
Text Label 7380 2925 0    39   ~ 0
SET2
$Comp
L C C3
U 1 1 58275BC2
P 3795 2000
F 0 "C3" H 3820 2100 50  0000 L CNN
F 1 "C" H 3820 1900 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3833 1850 50  0001 C CNN
F 3 "" H 3795 2000 50  0000 C CNN
	1    3795 2000
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 58275C23
P 3795 1550
F 0 "R2" V 3875 1550 50  0000 C CNN
F 1 "R" V 3795 1550 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 3725 1550 50  0001 C CNN
F 3 "" H 3795 1550 50  0000 C CNN
	1    3795 1550
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 58275C66
P 3795 1300
F 0 "#PWR05" H 3795 1150 50  0001 C CNN
F 1 "VCC" H 3795 1450 50  0000 C CNN
F 2 "" H 3795 1300 50  0000 C CNN
F 3 "" H 3795 1300 50  0000 C CNN
	1    3795 1300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 58275E7A
P 3795 2250
F 0 "#PWR06" H 3795 2000 50  0001 C CNN
F 1 "GND" H 3795 2100 50  0000 C CNN
F 2 "" H 3795 2250 50  0000 C CNN
F 3 "" H 3795 2250 50  0000 C CNN
	1    3795 2250
	1    0    0    -1  
$EndComp
Text Label 5480 2775 2    39   ~ 0
RA6
Text Label 4210 1780 0    39   ~ 0
~WDO
Text Label 5355 2100 0    39   ~ 0
~WDO
Text Label 2361 2770 0    39   ~ 0
WDI
Text Label 7380 2850 0    39   ~ 0
WDI
$Comp
L LED D1
U 1 1 5827721F
P 2915 4485
F 0 "D1" H 2915 4585 50  0000 C CNN
F 1 "LED" H 2915 4385 50  0000 C CNN
F 2 "" H 2915 4485 50  0000 C CNN
F 3 "" H 2915 4485 50  0000 C CNN
	1    2915 4485
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 58277390
P 2915 4065
F 0 "R1" V 2995 4065 50  0000 C CNN
F 1 "470" V 2915 4065 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 2845 4065 50  0001 C CNN
F 3 "" H 2915 4065 50  0000 C CNN
	1    2915 4065
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 58277445
P 2915 4735
F 0 "#PWR07" H 2915 4485 50  0001 C CNN
F 1 "GND" H 2915 4585 50  0000 C CNN
F 2 "" H 2915 4735 50  0000 C CNN
F 3 "" H 2915 4735 50  0000 C CNN
	1    2915 4735
	1    0    0    -1  
$EndComp
Text Label 3095 3830 0    39   ~ 0
LED0
Text Label 7375 2625 0    39   ~ 0
LED0
$Comp
L GND #PWR08
U 1 1 58277E6B
P 7655 2860
F 0 "#PWR08" H 7655 2610 50  0001 C CNN
F 1 "GND" H 7655 2710 50  0000 C CNN
F 2 "" H 7655 2860 50  0000 C CNN
F 3 "" H 7655 2860 50  0000 C CNN
	1    7655 2860
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR09
U 1 1 58277E9A
P 7650 2635
F 0 "#PWR09" H 7650 2485 50  0001 C CNN
F 1 "VCC" H 7650 2785 50  0000 C CNN
F 2 "" H 7650 2635 50  0000 C CNN
F 3 "" H 7650 2635 50  0000 C CNN
	1    7650 2635
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5827809B
P 5200 2700
F 0 "#PWR010" H 5200 2450 50  0001 C CNN
F 1 "GND" H 5200 2550 50  0000 C CNN
F 2 "" H 5200 2700 50  0000 C CNN
F 3 "" H 5200 2700 50  0000 C CNN
	1    5200 2700
	1    0    0    -1  
$EndComp
Text Label 7450 2100 0    39   ~ 0
PGD
Text Label 7445 2175 0    39   ~ 0
PGC
$Comp
L SPEAKER SP1
U 1 1 582783C1
P 9460 3135
F 0 "SP1" H 9360 3385 50  0000 C CNN
F 1 "SPEAKER" H 9360 2885 50  0000 C CNN
F 2 "Buzzers_Beepers:BUZZER" H 9460 3135 50  0001 C CNN
F 3 "" H 9460 3135 50  0000 C CNN
	1    9460 3135
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 582785C2
P 9625 1760
F 0 "P2" H 9625 2010 50  0000 C CNN
F 1 "CONN_01X04" V 9725 1760 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_4pol" H 9625 1760 50  0001 C CNN
F 3 "" H 9625 1760 50  0000 C CNN
	1    9625 1760
	1    0    0    -1  
$EndComp
Text Label 9195 1610 0    39   ~ 0
PGD
Text Label 9200 1710 0    39   ~ 0
PGC
Text Label 9200 1810 0    39   ~ 0
VPP
Text Label 9200 1910 0    39   ~ 0
GND
$Comp
L CONN_01X03 P3
U 1 1 58278903
P 9635 2300
F 0 "P3" H 9635 2500 50  0000 C CNN
F 1 "CONN_01X03" V 9735 2300 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_3pol" H 9635 2300 50  0001 C CNN
F 3 "" H 9635 2300 50  0000 C CNN
	1    9635 2300
	1    0    0    -1  
$EndComp
Text Label 9245 2200 0    39   ~ 0
ENA
Text Label 9245 2300 0    39   ~ 0
F_BEA
Text Label 9245 2400 0    39   ~ 0
GND
$Comp
L CONN_01X05 P1
U 1 1 58278D06
P 9615 1185
F 0 "P1" H 9615 1485 50  0000 C CNN
F 1 "CONN_01X05" V 9715 1185 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_5pol" H 9615 1185 50  0001 C CNN
F 3 "" H 9615 1185 50  0000 C CNN
	1    9615 1185
	1    0    0    -1  
$EndComp
Text Label 9170 985  0    39   ~ 0
VDD
Text Label 9170 1085 0    39   ~ 0
GND
Text Label 9175 1185 0    39   ~ 0
SOL
Text Label 9165 1285 0    39   ~ 0
PWD
Text Label 9175 1385 0    39   ~ 0
DIS
Text Label 5355 2175 0    39   ~ 0
VDD
$Comp
L VCC #PWR011
U 1 1 5827942A
P 8960 940
F 0 "#PWR011" H 8960 790 50  0001 C CNN
F 1 "VCC" H 8960 1090 50  0000 C CNN
F 2 "" H 8960 940 50  0000 C CNN
F 3 "" H 8960 940 50  0000 C CNN
	1    8960 940 
	1    0    0    -1  
$EndComp
$Comp
L DS18B20 U2
U 1 1 58276865
P 4105 4070
F 0 "U2" H 4105 3995 60  0000 C CNN
F 1 "DS18B20" H 4105 4495 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 4105 4070 60  0001 C CNN
F 3 "" H 4105 4070 60  0001 C CNN
	1    4105 4070
	1    0    0    -1  
$EndComp
NoConn ~ 3730 3770
NoConn ~ 3730 3845
NoConn ~ 4505 3770
NoConn ~ 4505 3845
NoConn ~ 4505 3920
$Comp
L GND #PWR012
U 1 1 5827C4C9
P 4620 4050
F 0 "#PWR012" H 4620 3800 50  0001 C CNN
F 1 "GND" H 4620 3900 50  0000 C CNN
F 2 "" H 4620 4050 50  0000 C CNN
F 3 "" H 4620 4050 50  0000 C CNN
	1    4620 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5827C571
P 3325 3935
F 0 "#PWR013" H 3325 3685 50  0001 C CNN
F 1 "GND" H 3325 3785 50  0000 C CNN
F 2 "" H 3325 3935 50  0000 C CNN
F 3 "" H 3325 3935 50  0000 C CNN
	1    3325 3935
	1    0    0    -1  
$EndComp
Text Label 3560 3995 0    39   ~ 0
TEMP
$Comp
L R R3
U 1 1 5827CEF1
P 4970 2230
F 0 "R3" V 5050 2230 50  0000 C CNN
F 1 "4K7" V 4970 2230 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 4900 2230 50  0001 C CNN
F 3 "" H 4970 2230 50  0000 C CNN
	1    4970 2230
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR014
U 1 1 5827D694
P 4970 1990
F 0 "#PWR014" H 4970 1840 50  0001 C CNN
F 1 "VCC" H 4970 2140 50  0000 C CNN
F 2 "" H 4970 1990 50  0000 C CNN
F 3 "" H 4970 1990 50  0000 C CNN
	1    4970 1990
	1    0    0    -1  
$EndComp
Text Label 5130 2400 0    39   ~ 0
TEMP
Text Label 7450 2250 0    39   ~ 0
BUZZER
$Comp
L GND #PWR015
U 1 1 5827E8B2
P 8740 3425
F 0 "#PWR015" H 8740 3175 50  0001 C CNN
F 1 "GND" H 8740 3275 50  0000 C CNN
F 2 "" H 8740 3425 50  0000 C CNN
F 3 "" H 8740 3425 50  0000 C CNN
	1    8740 3425
	1    0    0    -1  
$EndComp
NoConn ~ 7155 2550
NoConn ~ 5605 2850
NoConn ~ 5605 2925
NoConn ~ 5605 3000
NoConn ~ 5605 3075
NoConn ~ 5605 2475
NoConn ~ 5605 2550
Text Label 7460 2320 0    39   ~ 0
ENA
Text Label 7470 2400 0    39   ~ 0
BEA
NoConn ~ 2481 2620
Text Label 7475 2475 0    39   ~ 0
DIS
$Comp
L VCC #PWR016
U 1 1 586B51FC
P 8995 1775
F 0 "#PWR016" H 8995 1625 50  0001 C CNN
F 1 "VCC" H 8995 1925 50  0000 C CNN
F 2 "" H 8995 1775 50  0000 C CNN
F 3 "" H 8995 1775 50  0000 C CNN
	1    8995 1775
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 586B5EB4
P 5640 4740
F 0 "R4" V 5720 4740 50  0000 C CNN
F 1 "6,19K" V 5640 4740 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 5570 4740 50  0001 C CNN
F 3 "" H 5640 4740 50  0000 C CNN
	1    5640 4740
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 586B5F6B
P 7295 4640
F 0 "R5" V 7375 4640 50  0000 C CNN
F 1 "4,99K" V 7295 4640 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 7225 4640 50  0001 C CNN
F 3 "" H 7295 4640 50  0000 C CNN
	1    7295 4640
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 586B5FDC
P 7715 4640
F 0 "R6" V 7795 4640 50  0000 C CNN
F 1 "6,65K" V 7715 4640 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 7645 4640 50  0001 C CNN
F 3 "" H 7715 4640 50  0000 C CNN
	1    7715 4640
	0    -1   -1   0   
$EndComp
$Comp
L C C4
U 1 1 586B65B7
P 6040 4900
F 0 "C4" H 6065 5000 50  0000 L CNN
F 1 "10nF" H 6065 4800 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6078 4750 50  0001 C CNN
F 3 "" H 6040 4900 50  0000 C CNN
	1    6040 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 586B6FE9
P 6040 5095
F 0 "#PWR017" H 6040 4845 50  0001 C CNN
F 1 "GND" H 6040 4945 50  0000 C CNN
F 2 "" H 6040 5095 50  0000 C CNN
F 3 "" H 6040 5095 50  0000 C CNN
	1    6040 5095
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 586B809A
P 8100 4855
F 0 "C5" H 8125 4955 50  0000 L CNN
F 1 "10nF" H 8125 4755 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 8138 4705 50  0001 C CNN
F 3 "" H 8100 4855 50  0000 C CNN
	1    8100 4855
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 586B8117
P 8550 5490
F 0 "C6" H 8575 5590 50  0000 L CNN
F 1 "10nF" H 8575 5390 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 8588 5340 50  0001 C CNN
F 3 "" H 8550 5490 50  0000 C CNN
	1    8550 5490
	0    1    1    0   
$EndComp
$Comp
L GND #PWR018
U 1 1 586B929C
P 8100 5150
F 0 "#PWR018" H 8100 4900 50  0001 C CNN
F 1 "GND" H 8100 5000 50  0000 C CNN
F 2 "" H 8100 5150 50  0000 C CNN
F 3 "" H 8100 5150 50  0000 C CNN
	1    8100 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 586BA29D
P 6460 4340
F 0 "#PWR019" H 6460 4090 50  0001 C CNN
F 1 "GND" H 6460 4190 50  0000 C CNN
F 2 "" H 6460 4340 50  0000 C CNN
F 3 "" H 6460 4340 50  0000 C CNN
	1    6460 4340
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR020
U 1 1 586BA2DF
P 8380 4240
F 0 "#PWR020" H 8380 3990 50  0001 C CNN
F 1 "GND" H 8380 4090 50  0000 C CNN
F 2 "" H 8380 4240 50  0000 C CNN
F 3 "" H 8380 4240 50  0000 C CNN
	1    8380 4240
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR021
U 1 1 586BA394
P 6460 4940
F 0 "#PWR021" H 6460 4790 50  0001 C CNN
F 1 "VCC" H 6460 5090 50  0000 C CNN
F 2 "" H 6460 4940 50  0000 C CNN
F 3 "" H 6460 4940 50  0000 C CNN
	1    6460 4940
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR022
U 1 1 586BA892
P 8380 4840
F 0 "#PWR022" H 8380 4690 50  0001 C CNN
F 1 "VCC" H 8380 4990 50  0000 C CNN
F 2 "" H 8380 4840 50  0000 C CNN
F 3 "" H 8380 4840 50  0000 C CNN
	1    8380 4840
	-1   0    0    1   
$EndComp
Text Label 5110 4740 0    39   ~ 0
BEA
Text Label 9625 4540 0    39   ~ 0
F_BEA
$Comp
L PWR_FLAG #FLG023
U 1 1 586BEB0A
P 3760 5165
F 0 "#FLG023" H 3760 5260 50  0001 C CNN
F 1 "PWR_FLAG" H 3760 5345 50  0000 C CNN
F 2 "" H 3760 5165 50  0000 C CNN
F 3 "" H 3760 5165 50  0000 C CNN
	1    3760 5165
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG024
U 1 1 586BEB4C
P 4165 5155
F 0 "#FLG024" H 4165 5250 50  0001 C CNN
F 1 "PWR_FLAG" H 4165 5335 50  0000 C CNN
F 2 "" H 4165 5155 50  0000 C CNN
F 3 "" H 4165 5155 50  0000 C CNN
	1    4165 5155
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 586BECFE
P 3760 5285
F 0 "#PWR025" H 3760 5035 50  0001 C CNN
F 1 "GND" H 3760 5135 50  0000 C CNN
F 2 "" H 3760 5285 50  0000 C CNN
F 3 "" H 3760 5285 50  0000 C CNN
	1    3760 5285
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR026
U 1 1 586BED40
P 4165 5245
F 0 "#PWR026" H 4165 5095 50  0001 C CNN
F 1 "VCC" H 4165 5395 50  0000 C CNN
F 2 "" H 4165 5245 50  0000 C CNN
F 3 "" H 4165 5245 50  0000 C CNN
	1    4165 5245
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 58784276
P 7270 1470
F 0 "C?" H 7295 1570 50  0000 L CNN
F 1 "C" H 7295 1370 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 7308 1320 50  0001 C CNN
F 3 "" H 7270 1470 50  0000 C CNN
	1    7270 1470
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 587842D1
P 7410 1660
F 0 "#PWR?" H 7410 1410 50  0001 C CNN
F 1 "GND" H 7410 1510 50  0000 C CNN
F 2 "" H 7410 1660 50  0000 C CNN
F 3 "" H 7410 1660 50  0000 C CNN
	1    7410 1660
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 58786231
P 7560 1470
F 0 "C?" H 7585 1570 50  0000 L CNN
F 1 "C" H 7585 1370 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 7598 1320 50  0001 C CNN
F 3 "" H 7560 1470 50  0000 C CNN
	1    7560 1470
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 587868A5
P 7420 1190
F 0 "#PWR?" H 7420 1040 50  0001 C CNN
F 1 "VCC" H 7420 1340 50  0000 C CNN
F 2 "" H 7420 1190 50  0000 C CNN
F 3 "" H 7420 1190 50  0000 C CNN
	1    7420 1190
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
Wire Wire Line
	2350 2100 2350 2000
Wire Wire Line
	3350 2150 3350 2000
Wire Wire Line
	5605 2175 5355 2175
Wire Wire Line
	5605 2250 5355 2250
Wire Wire Line
	5605 2325 5355 2325
Wire Wire Line
	4970 2400 5605 2400
Wire Wire Line
	2181 2730 2181 2695
Wire Wire Line
	2181 2695 2481 2695
Wire Wire Line
	3356 2770 3476 2770
Wire Wire Line
	2271 2545 2481 2545
Wire Wire Line
	2481 2770 2361 2770
Wire Wire Line
	7155 3075 7385 3075
Wire Wire Line
	7155 3000 7380 3000
Wire Wire Line
	7155 2925 7380 2925
Wire Wire Line
	3795 1400 3795 1300
Wire Wire Line
	3795 1700 3795 1850
Wire Wire Line
	3795 2250 3795 2150
Wire Wire Line
	5605 2100 5355 2100
Wire Wire Line
	5605 2700 5480 2700
Wire Wire Line
	5605 2775 5480 2775
Wire Wire Line
	3800 1780 4210 1780
Connection ~ 3795 1780
Wire Wire Line
	7155 2850 7380 2850
Wire Wire Line
	2915 4285 2915 4215
Wire Wire Line
	2915 4685 2915 4735
Wire Wire Line
	2915 3915 2915 3830
Wire Wire Line
	2915 3830 3095 3830
Wire Wire Line
	7155 2625 7375 2625
Wire Wire Line
	7155 2700 7650 2700
Wire Wire Line
	7650 2700 7650 2635
Wire Wire Line
	7155 2775 7655 2775
Wire Wire Line
	7655 2775 7655 2860
Wire Wire Line
	5605 2625 5200 2625
Wire Wire Line
	5200 2625 5200 2700
Wire Wire Line
	7155 2100 7450 2100
Wire Wire Line
	7155 2175 7445 2175
Wire Wire Line
	9425 1610 9195 1610
Wire Wire Line
	9425 1710 9200 1710
Wire Wire Line
	8995 1810 9425 1810
Wire Wire Line
	9425 1910 9200 1910
Wire Wire Line
	9435 2200 9245 2200
Wire Wire Line
	9435 2300 9245 2300
Wire Wire Line
	9435 2400 9245 2400
Wire Wire Line
	9415 1085 9170 1085
Wire Wire Line
	9415 1185 9175 1185
Wire Wire Line
	9415 1285 9165 1285
Wire Wire Line
	9415 1385 9175 1385
Wire Wire Line
	8960 940  8960 985 
Wire Wire Line
	8960 985  9415 985 
Wire Wire Line
	4505 3995 4620 3995
Wire Wire Line
	4620 3995 4620 4050
Wire Wire Line
	3325 3935 3325 3920
Wire Wire Line
	3325 3920 3730 3920
Wire Wire Line
	3730 3995 3560 3995
Wire Wire Line
	4970 2400 4970 2380
Wire Wire Line
	4970 1990 4970 2080
Wire Wire Line
	7155 2250 7450 2250
Wire Wire Line
	9160 3235 8885 3235
Wire Wire Line
	8885 3235 8885 3395
Wire Wire Line
	3611 2545 3356 2545
Wire Wire Line
	3356 2695 3556 2695
Wire Wire Line
	3356 2620 3611 2620
Wire Wire Line
	7155 2325 7460 2325
Wire Wire Line
	7460 2325 7460 2320
Wire Wire Line
	7155 2400 7470 2400
Wire Wire Line
	7155 2475 7475 2475
Wire Wire Line
	8995 1810 8995 1775
Wire Wire Line
	5790 4740 6260 4740
Wire Wire Line
	6040 4740 6040 4750
Connection ~ 6040 4740
Wire Wire Line
	6040 5050 6040 5095
Wire Wire Line
	6260 4540 6050 4540
Wire Wire Line
	6050 4540 6050 4130
Wire Wire Line
	6050 4130 7020 4130
Wire Wire Line
	7020 4130 7020 4640
Wire Wire Line
	6860 4640 7145 4640
Connection ~ 7020 4640
Wire Wire Line
	7445 4640 7565 4640
Wire Wire Line
	7865 4640 8180 4640
Wire Wire Line
	8100 4705 8100 4640
Wire Wire Line
	8100 4640 8105 4640
Connection ~ 8105 4640
Wire Wire Line
	8100 5005 8100 5150
Wire Wire Line
	8180 4440 7975 4440
Wire Wire Line
	7975 4440 7975 3975
Wire Wire Line
	7975 3975 9005 3975
Wire Wire Line
	9005 3975 9005 4540
Wire Wire Line
	8780 4540 9625 4540
Wire Wire Line
	8700 5490 9120 5490
Wire Wire Line
	9120 5490 9120 4540
Connection ~ 9005 4540
Wire Wire Line
	7500 5490 8400 5490
Wire Wire Line
	7500 5490 7500 4640
Connection ~ 7500 4640
Wire Wire Line
	5490 4740 5110 4740
Connection ~ 9120 4540
Wire Wire Line
	4165 5155 4165 5245
Wire Wire Line
	3760 5285 3760 5165
Wire Wire Line
	7270 1320 7270 1280
Wire Wire Line
	7270 1280 7560 1280
Wire Wire Line
	7560 1280 7560 1320
Wire Wire Line
	7560 1620 7270 1620
Wire Wire Line
	7410 1660 7410 1620
Connection ~ 7410 1620
Wire Wire Line
	7420 1190 7420 1280
Wire Wire Line
	7420 1280 7430 1280
Connection ~ 7430 1280
$Comp
L C C?
U 1 1 58789C1B
P 1630 2990
F 0 "C?" H 1655 3090 50  0000 L CNN
F 1 "C" H 1655 2890 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 1668 2840 50  0001 C CNN
F 3 "" H 1630 2990 50  0000 C CNN
	1    1630 2990
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 58789D01
P 1630 2810
F 0 "#PWR?" H 1630 2660 50  0001 C CNN
F 1 "VCC" H 1630 2960 50  0000 C CNN
F 2 "" H 1630 2810 50  0000 C CNN
F 3 "" H 1630 2810 50  0000 C CNN
	1    1630 2810
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58789D60
P 1630 3190
F 0 "#PWR?" H 1630 2940 50  0001 C CNN
F 1 "GND" H 1630 3040 50  0000 C CNN
F 2 "" H 1630 3190 50  0000 C CNN
F 3 "" H 1630 3190 50  0000 C CNN
	1    1630 3190
	1    0    0    -1  
$EndComp
Wire Wire Line
	1630 3190 1630 3140
Wire Wire Line
	1630 2810 1630 2840
$Comp
L D D?
U 1 1 5878DC37
P 8580 3200
F 0 "D?" H 8580 3300 50  0000 C CNN
F 1 "D" H 8580 3100 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-523" H 8580 3200 50  0001 C CNN
F 3 "" H 8580 3200 50  0000 C CNN
	1    8580 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	9160 3035 8580 3035
Wire Wire Line
	8580 3035 8580 3050
Wire Wire Line
	8580 3350 8580 3395
Wire Wire Line
	8580 3395 8885 3395
Wire Wire Line
	8740 3425 8740 3395
Connection ~ 8740 3395
Text Label 8775 3035 0    39   ~ 0
BUZZER
$Comp
L LM358 U?
U 1 1 587AA4C8
P 6560 4640
F 0 "U?" H 6560 4840 50  0000 L CNN
F 1 "LM358" H 6560 4440 50  0000 L CNN
F 2 "Housings_SOIC:SOIJ-8_5.3x5.3mm_Pitch1.27mm" H 6560 4640 50  0001 C CNN
F 3 "" H 6560 4640 50  0000 C CNN
	1    6560 4640
	1    0    0    1   
$EndComp
$Comp
L LM358 U?
U 2 1 587AA5C2
P 8480 4540
F 0 "U?" H 8480 4740 50  0000 L CNN
F 1 "LM358" H 8480 4340 50  0000 L CNN
F 2 "Housings_SOIC:SOIJ-8_5.3x5.3mm_Pitch1.27mm" H 8480 4540 50  0001 C CNN
F 3 "" H 8480 4540 50  0000 C CNN
	2    8480 4540
	1    0    0    1   
$EndComp
$EndSCHEMATC
