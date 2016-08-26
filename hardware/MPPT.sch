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
LIBS:components
LIBS:easat2-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "EASAT-2 MPPT"
Date "2016-08-26"
Rev ""
Comp "AMSAT-EA"
Comment1 "EA4GPZ"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LTC3129 U?
U 1 1 57C086DF
P 3000 1850
F 0 "U?" H 2350 2150 60  0000 C CNN
F 1 "LTC3129" H 2950 1850 60  0000 C CNN
F 2 "" H 3000 1300 60  0000 C CNN
F 3 "http://www.linear.com/docs/42736" H 3000 1300 60  0001 C CNN
	1    3000 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57C086E7
P 2850 2900
F 0 "#PWR?" H 2850 2650 50  0001 C CNN
F 1 "GND" H 2850 2750 50  0000 C CNN
F 2 "" H 2850 2900 60  0000 C CNN
F 3 "" H 2850 2900 60  0000 C CNN
	1    2850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 2850 2850 2900
$Comp
L C C?
U 1 1 57C086EF
P 3750 2600
F 0 "C?" H 3775 2700 50  0000 L CNN
F 1 "2.2u" H 3775 2500 50  0000 L CNN
F 2 "" H 3788 2450 30  0000 C CNN
F 3 "" H 3750 2600 60  0000 C CNN
	1    3750 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2400 3750 2450
Wire Wire Line
	3750 2850 3750 2750
Connection ~ 3100 2850
$Comp
L C C?
U 1 1 57C086F9
P 4000 1950
F 0 "C?" V 4050 2000 50  0000 L CNN
F 1 "10u" V 3950 2000 50  0000 L CNN
F 2 "" H 4038 1800 30  0000 C CNN
F 3 "" H 4000 1950 60  0000 C CNN
	1    4000 1950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 57C08700
P 4250 1950
F 0 "#PWR?" H 4250 1700 50  0001 C CNN
F 1 "GND" H 4250 1800 50  0000 C CNN
F 2 "" H 4250 1950 60  0000 C CNN
F 3 "" H 4250 1950 60  0000 C CNN
	1    4250 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3850 1800 3850 1950
Wire Wire Line
	4150 1950 4250 1950
$Comp
L R R?
U 1 1 57C08709
P 4600 1950
F 0 "R?" V 4680 1950 50  0000 C CNN
F 1 "Ra" V 4600 1950 50  0000 C CNN
F 2 "" V 4530 1950 30  0000 C CNN
F 3 "" H 4600 1950 30  0000 C CNN
	1    4600 1950
	1    0    0    -1  
$EndComp
Connection ~ 3850 1800
Wire Wire Line
	3750 2100 4950 2100
$Comp
L R R?
U 1 1 57C08712
P 4600 2350
F 0 "R?" V 4680 2350 50  0000 C CNN
F 1 "Rb" V 4600 2350 50  0000 C CNN
F 2 "" V 4530 2350 30  0000 C CNN
F 3 "" H 4600 2350 30  0000 C CNN
	1    4600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2100 4600 2200
Wire Wire Line
	4600 2850 4600 2500
Connection ~ 3750 2850
Connection ~ 4600 1800
$Comp
L C C?
U 1 1 57C0871D
P 4950 1950
F 0 "C?" H 4975 2050 50  0000 L CNN
F 1 "66/Ra" H 4975 1850 50  0000 L CNN
F 2 "" H 4988 1800 30  0000 C CNN
F 3 "" H 4950 1950 60  0000 C CNN
	1    4950 1950
	1    0    0    -1  
$EndComp
Connection ~ 4600 2100
Connection ~ 4950 1800
$Comp
L C C?
U 1 1 57C08726
P 1450 2050
F 0 "C?" H 1475 2150 50  0000 L CNN
F 1 "22u" H 1475 1950 50  0000 L CNN
F 2 "" H 1488 1900 30  0000 C CNN
F 3 "" H 1450 2050 60  0000 C CNN
	1    1450 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1800 1450 1900
Connection ~ 1450 1800
Wire Wire Line
	1450 2200 1450 2850
Connection ~ 2850 2850
$Comp
L C C?
U 1 1 57C08731
P 2700 1250
F 0 "C?" V 2550 1200 50  0000 L CNN
F 1 "22n" V 2850 1200 50  0000 L CNN
F 2 "" H 2738 1100 30  0000 C CNN
F 3 "" H 2700 1250 60  0000 C CNN
	1    2700 1250
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 57C08738
P 3300 1250
F 0 "C?" V 3150 1200 50  0000 L CNN
F 1 "22n" V 3450 1200 50  0000 L CNN
F 2 "" H 3338 1100 30  0000 C CNN
F 3 "" H 3300 1250 60  0000 C CNN
	1    3300 1250
	0    1    1    0   
$EndComp
Wire Wire Line
	2550 1300 2550 1250
Wire Wire Line
	2850 1300 2850 1250
Wire Wire Line
	3150 1300 3150 1250
Wire Wire Line
	3450 1250 3450 1300
$Comp
L L_Small L?
U 1 1 57C08743
P 3000 1250
F 0 "L?" V 3100 1200 50  0000 L CNN
F 1 "10u" V 2950 1150 50  0000 L CNN
F 2 "" H 3000 1250 60  0000 C CNN
F 3 "" H 3000 1250 60  0000 C CNN
	1    3000 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2850 1250 2900 1250
Wire Wire Line
	3150 1250 3100 1250
Text Notes 1300 2950 1    60   ~ 0
Cin 22u at least for MPPC
$Comp
L R R?
U 1 1 57C0874D
P 1750 1950
F 0 "R?" V 1830 1950 50  0000 C CNN
F 1 "Rd" V 1750 1950 50  0000 C CNN
F 2 "" V 1680 1950 30  0000 C CNN
F 3 "" H 1750 1950 30  0000 C CNN
	1    1750 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 1800 2250 1800
Connection ~ 1750 1800
$Comp
L R R?
U 1 1 57C08757
P 1750 2500
F 0 "R?" V 1830 2500 50  0000 C CNN
F 1 "Rc" V 1750 2500 50  0000 C CNN
F 2 "" V 1680 2500 30  0000 C CNN
F 3 "" H 1750 2500 30  0000 C CNN
	1    1750 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2100 1750 2350
Connection ~ 1750 2850
Text Notes 1250 1700 0    60   ~ 0
Vin = 1.175V*(1+Rd/Rc)
Text Notes 2400 3200 0    60   ~ 0
FB and MPPC resistors in MOhm range
Text Notes 2550 1050 0    60   ~ 0
C 4.7n to 47n
Wire Wire Line
	2250 2250 2250 2850
Connection ~ 2250 2850
Text GLabel 1150 1800 0    60   Input ~ 0
PV_IN
Text Notes 2550 950  0    60   ~ 0
L see datasheet
Text Notes 4650 2600 0    60   ~ 0
Vout = 1.175V*(1+Ra/Rb)
$Comp
L R R?
U 1 1 57C09E6F
P 2000 1950
F 0 "R?" V 2080 1950 50  0000 C CNN
F 1 "100k" V 2000 1950 50  0000 C CNN
F 2 "" V 1930 1950 30  0000 C CNN
F 3 "" H 2000 1950 30  0000 C CNN
	1    2000 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 1950 2100 1950
Wire Wire Line
	2100 1950 2100 2100
Wire Wire Line
	2100 2100 2000 2100
Wire Wire Line
	2250 2100 2150 2100
Wire Wire Line
	2150 2100 2150 2200
Wire Wire Line
	2150 2200 1750 2200
Connection ~ 1750 2200
Connection ~ 2000 1800
Wire Wire Line
	1750 2650 1750 2850
Text Label 2000 3350 1    60   ~ 0
VR_Shdn
Text Notes 700  700  0    60   ~ 0
One of these blocks per solar panel
Wire Wire Line
	1450 2850 4600 2850
$Comp
L Q_NMOS_DGS Q?
U 1 1 57C0AF6A
P 9300 3500
F 0 "Q?" H 9600 3550 50  0000 R CNN
F 1 "Q_NMOS_DGS" H 9950 3450 50  0001 R CNN
F 2 "" H 9500 3600 29  0000 C CNN
F 3 "" H 9300 3500 60  0000 C CNN
	1    9300 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	9200 3300 9200 3200
Wire Wire Line
	9200 3200 8650 3200
Text Label 8650 3200 0    60   ~ 0
VR_Shdn
Text Notes 9350 3300 0    60   ~ 0
A suitable logic-level FET or BJT\n$50Sat uses an optocoupler
Wire Wire Line
	9200 3700 9200 3800
Wire Wire Line
	9500 3500 9600 3500
Text GLabel 9600 3500 2    60   Input ~ 0
DISABLE_SOLAR
$Comp
L GND #PWR?
U 1 1 57C0B33D
P 9200 3800
F 0 "#PWR?" H 9200 3550 50  0001 C CNN
F 1 "GND" H 9200 3650 50  0000 C CNN
F 2 "" H 9200 3800 60  0000 C CNN
F 3 "" H 9200 3800 60  0000 C CNN
	1    9200 3800
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D?
U 1 1 57C0B664
P 2000 2500
F 0 "D?" H 2000 2600 50  0000 C CNN
F 1 "D_Schottky" H 2000 2400 50  0001 C CNN
F 2 "" H 2000 2500 60  0000 C CNN
F 3 "" H 2000 2500 60  0000 C CNN
	1    2000 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2000 2100 2000 2350
Wire Wire Line
	2000 2650 2000 3350
Text Notes 1400 3550 0    60   ~ 0
A suitable small-signal Schottky
$Comp
L R R?
U 1 1 57C0BCA9
P 8850 1050
F 0 "R?" V 8930 1050 50  0000 C CNN
F 1 "shunt" V 8850 1050 50  0000 C CNN
F 2 "" V 8780 1050 30  0000 C CNN
F 3 "" H 8850 1050 30  0000 C CNN
	1    8850 1050
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 57C0BCEE
P 9750 1050
F 0 "R?" V 9830 1050 50  0000 C CNN
F 1 "shunt" V 9750 1050 50  0000 C CNN
F 2 "" V 9680 1050 30  0000 C CNN
F 3 "" H 9750 1050 30  0000 C CNN
	1    9750 1050
	0    1    1    0   
$EndComp
$Comp
L D_Schottky D?
U 1 1 57C0BD5C
P 5300 1800
F 0 "D?" H 5300 1900 50  0000 C CNN
F 1 "D_Schottky" H 5300 1700 50  0001 C CNN
F 2 "" H 5300 1800 60  0000 C CNN
F 3 "" H 5300 1800 60  0000 C CNN
	1    5300 1800
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 1800 3750 1800
Text Notes 4450 1700 0    60   ~ 0
high current Schottky
Text Label 5550 1800 0    60   ~ 0
solar
Wire Wire Line
	5450 1800 5550 1800
Wire Wire Line
	8700 1050 8150 1050
Text Label 8150 1050 0    60   ~ 0
solar
Text Notes 8000 1600 0    60   ~ 0
TODO: high-side current senses\n$50Sat uses ZXCT1009, which require an external shunt resistor
$Comp
L D_Schottky D?
U 1 1 57C0D536
P 9250 1050
F 0 "D?" H 9250 1150 50  0000 C CNN
F 1 "D_Schottky" H 9250 950 50  0001 C CNN
F 2 "" H 9250 1050 60  0000 C CNN
F 3 "" H 9250 1050 60  0000 C CNN
	1    9250 1050
	-1   0    0    1   
$EndComp
Wire Wire Line
	9000 1050 9100 1050
Wire Wire Line
	9400 1050 9600 1050
Wire Wire Line
	9500 1050 9500 850 
Connection ~ 9500 1050
$Comp
L +BATT #PWR?
U 1 1 57C0D8F3
P 9500 850
F 0 "#PWR?" H 9500 700 50  0001 C CNN
F 1 "+BATT" H 9500 990 50  0000 C CNN
F 2 "" H 9500 850 60  0000 C CNN
F 3 "" H 9500 850 60  0000 C CNN
	1    9500 850 
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P?
U 1 1 57C0DB54
P 10250 1100
F 0 "P?" H 10250 1250 50  0000 C CNN
F 1 "CONN_01X02" V 10350 1100 50  0001 C CNN
F 2 "" H 10250 1100 60  0000 C CNN
F 3 "" H 10250 1100 60  0000 C CNN
	1    10250 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 1050 10050 1050
$Comp
L GND #PWR?
U 1 1 57C0DBDE
P 10050 1250
F 0 "#PWR?" H 10050 1000 50  0001 C CNN
F 1 "GND" H 10050 1100 50  0000 C CNN
F 2 "" H 10050 1250 60  0000 C CNN
F 3 "" H 10050 1250 60  0000 C CNN
	1    10050 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1150 10050 1250
Text Notes 10400 1050 0    60   ~ 0
battery connector
Wire Notes Line
	700  750  5900 750 
Wire Notes Line
	5900 750  5900 3600
Wire Notes Line
	5900 3600 700  3600
Wire Notes Line
	700  3600 700  750 
$EndSCHEMATC
