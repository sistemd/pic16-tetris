EESchema Schematic File Version 4
LIBS:project-cache
EELAYER 29 0
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
Wire Wire Line
	3500 2100 3850 2100
Wire Wire Line
	3850 5100 3850 5400
NoConn ~ 3950 5100
NoConn ~ 3950 2100
$Comp
L project-rescue:PIC-mylib U1
U 1 1 5CCC1C25
P 3950 3600
F 0 "U1" H 3950 5281 50  0000 C CNN
F 1 "PIC16F884" H 3950 5190 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm" H 3950 3600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/41291D.pdf" H 3950 3600 50  0001 C CNN
	1    3950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3100 2450 3100
Wire Wire Line
	5050 4150 6750 4150
Wire Wire Line
	5450 3250 5050 3250
Wire Wire Line
	5450 3350 5050 3350
Wire Wire Line
	5350 3450 5050 3450
Wire Wire Line
	5450 3850 5250 3850
Wire Wire Line
	5250 3850 5250 3550
Wire Wire Line
	5250 3550 5050 3550
Wire Wire Line
	5850 4000 5150 4000
Wire Wire Line
	5150 4000 5150 3650
Wire Wire Line
	5150 3650 5050 3650
Wire Wire Line
	5450 3350 5450 3450
Wire Wire Line
	5350 3650 5350 3450
Wire Wire Line
	5350 3650 5450 3650
NoConn ~ 5050 3750
NoConn ~ 5050 3850
NoConn ~ 5050 3950
NoConn ~ 5050 4550
NoConn ~ 5050 4650
NoConn ~ 5050 4750
NoConn ~ 5050 4850
NoConn ~ 2850 4200
NoConn ~ 2850 4100
NoConn ~ 2850 4000
NoConn ~ 2850 3800
NoConn ~ 2850 3700
NoConn ~ 2850 3600
NoConn ~ 2850 3500
NoConn ~ 2850 3400
NoConn ~ 2850 3300
$Comp
L power:VCC #PWR0106
U 1 1 5CD44CC2
P 3400 1700
F 0 "#PWR0106" H 3400 1550 50  0001 C CNN
F 1 "VCC" H 3417 1873 50  0000 C CNN
F 2 "" H 3400 1700 50  0001 C CNN
F 3 "" H 3400 1700 50  0001 C CNN
	1    3400 1700
	1    0    0    -1  
$EndComp
Text Notes 2600 1250 0    50   ~ 0
VCC = 5V
$Comp
L power:GND #PWR0108
U 1 1 5CD48A81
P 3850 5400
F 0 "#PWR0108" H 3850 5150 50  0001 C CNN
F 1 "GND" H 3855 5227 50  0000 C CNN
F 2 "" H 3850 5400 50  0001 C CNN
F 3 "" H 3850 5400 50  0001 C CNN
	1    3850 5400
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5CD4C6E9
P 6000 1200
F 0 "#FLG0101" H 6000 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 6000 1373 50  0000 C CNN
F 2 "" H 6000 1200 50  0001 C CNN
F 3 "~" H 6000 1200 50  0001 C CNN
	1    6000 1200
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5CD4CE8C
P 6550 1200
F 0 "#FLG0102" H 6550 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 6550 1373 50  0000 C CNN
F 2 "" H 6550 1200 50  0001 C CNN
F 3 "~" H 6550 1200 50  0001 C CNN
	1    6550 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5CD4F5CA
P 6000 1350
F 0 "#PWR0110" H 6000 1100 50  0001 C CNN
F 1 "GND" H 6005 1177 50  0000 C CNN
F 2 "" H 6000 1350 50  0001 C CNN
F 3 "" H 6000 1350 50  0001 C CNN
	1    6000 1350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0111
U 1 1 5CD514F9
P 6550 1350
F 0 "#PWR0111" H 6550 1200 50  0001 C CNN
F 1 "VCC" V 6567 1478 50  0000 L CNN
F 2 "" H 6550 1350 50  0001 C CNN
F 3 "" H 6550 1350 50  0001 C CNN
	1    6550 1350
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 1200 6000 1350
Wire Wire Line
	6550 1200 6550 1350
Text Label 6750 4150 0    50   ~ 0
nCS2
Wire Wire Line
	5050 4250 6750 4250
Text Label 6750 4250 0    50   ~ 0
nCS1
Text Label 6750 4350 0    50   ~ 0
DnI
Text Label 6750 4450 0    50   ~ 0
RnW
Wire Wire Line
	5050 4350 6750 4350
Wire Wire Line
	5050 4450 6750 4450
Text Label 6750 2400 0    50   ~ 0
DB0
Text Label 6750 2500 0    50   ~ 0
DB1
Text Label 6750 2600 0    50   ~ 0
DB2
Text Label 6750 2700 0    50   ~ 0
DB3
Text Label 6750 2800 0    50   ~ 0
DB4
Text Label 6750 2900 0    50   ~ 0
DB5
Text Label 6750 3100 0    50   ~ 0
DB6
Text Label 6750 3000 0    50   ~ 0
DB7
Wire Wire Line
	5050 2400 6750 2400
Wire Wire Line
	5050 2500 6750 2500
Wire Wire Line
	5050 2600 6750 2600
Wire Wire Line
	5050 2700 6750 2700
Wire Wire Line
	5050 2800 6750 2800
Wire Wire Line
	5050 2900 6750 2900
Wire Wire Line
	5050 3000 6750 3000
Wire Wire Line
	5050 3100 6750 3100
Text Label 2450 3100 0    50   ~ 0
E
Text Label 2450 3200 0    50   ~ 0
nRST
Wire Wire Line
	2450 3200 2850 3200
NoConn ~ 6750 2400
NoConn ~ 6750 2500
NoConn ~ 6750 2600
NoConn ~ 6750 2700
NoConn ~ 6750 2800
NoConn ~ 6750 2900
NoConn ~ 6750 3000
NoConn ~ 6750 3100
NoConn ~ 6750 4150
NoConn ~ 6750 4250
NoConn ~ 6750 4350
NoConn ~ 6750 4450
NoConn ~ 2450 3100
NoConn ~ 2450 3200
$Comp
L power:GND #PWR0109
U 1 1 5CDBFDEB
P 3600 1700
F 0 "#PWR0109" H 3600 1450 50  0001 C CNN
F 1 "GND" H 3605 1527 50  0000 C CNN
F 2 "" H 3600 1700 50  0001 C CNN
F 3 "" H 3600 1700 50  0001 C CNN
	1    3600 1700
	-1   0    0    1   
$EndComp
$Comp
L mylib:SW_SPDT SW6
U 1 1 5CDEE1B6
P 3500 1900
F 0 "SW6" V 3550 2200 50  0000 R CNN
F 1 "Power_sw" V 3450 2300 50  0000 R CNN
F 2 "Button_Switch_THT:SW_Slide_1P2T_CK_OS102011MS2Q" H 3500 1900 50  0001 C CNN
F 3 "~" H 3500 1900 50  0001 C CNN
	1    3500 1900
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 5CDF1379
P 5650 3250
F 0 "SW1" H 5850 3200 50  0000 C CNN
F 1 "Pause" H 5850 3300 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5650 3250 50  0001 C CNN
F 3 "~" H 5650 3250 50  0001 C CNN
	1    5650 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW5
U 1 1 5CDF245B
P 6050 4000
F 0 "SW5" H 6200 3950 50  0000 C CNN
F 1 "Down" H 6200 4050 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6050 4000 50  0001 C CNN
F 3 "~" H 6050 4000 50  0001 C CNN
	1    6050 4000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW2
U 1 1 5CDF2BCA
P 5650 3450
F 0 "SW2" H 5850 3400 50  0000 C CNN
F 1 "Rotate" H 5850 3500 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5650 3450 50  0001 C CNN
F 3 "~" H 5650 3450 50  0001 C CNN
	1    5650 3450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 5CDF714F
P 5650 3650
F 0 "SW3" H 5800 3600 50  0000 C CNN
F 1 "Right" H 5800 3700 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5650 3650 50  0001 C CNN
F 3 "~" H 5650 3650 50  0001 C CNN
	1    5650 3650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW4
U 1 1 5CDF91D7
P 5650 3850
F 0 "SW4" H 5800 3800 50  0000 C CNN
F 1 "Left" H 5800 3900 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5650 3850 50  0001 C CNN
F 3 "~" H 5650 3850 50  0001 C CNN
	1    5650 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CDFD67C
P 6450 3250
F 0 "#PWR0101" H 6450 3000 50  0001 C CNN
F 1 "GND" H 6455 3077 50  0000 C CNN
F 2 "" H 6450 3250 50  0001 C CNN
F 3 "" H 6450 3250 50  0001 C CNN
	1    6450 3250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CDFE0C1
P 6450 3450
F 0 "#PWR0102" H 6450 3200 50  0001 C CNN
F 1 "GND" H 6455 3277 50  0000 C CNN
F 2 "" H 6450 3450 50  0001 C CNN
F 3 "" H 6450 3450 50  0001 C CNN
	1    6450 3450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5CDFE313
P 6450 3650
F 0 "#PWR0103" H 6450 3400 50  0001 C CNN
F 1 "GND" H 6455 3477 50  0000 C CNN
F 2 "" H 6450 3650 50  0001 C CNN
F 3 "" H 6450 3650 50  0001 C CNN
	1    6450 3650
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5CDFE896
P 6450 3850
F 0 "#PWR0104" H 6450 3600 50  0001 C CNN
F 1 "GND" H 6455 3677 50  0000 C CNN
F 2 "" H 6450 3850 50  0001 C CNN
F 3 "" H 6450 3850 50  0001 C CNN
	1    6450 3850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5CDFF2DC
P 6450 4000
F 0 "#PWR0105" H 6450 3750 50  0001 C CNN
F 1 "GND" H 6455 3827 50  0000 C CNN
F 2 "" H 6450 4000 50  0001 C CNN
F 3 "" H 6450 4000 50  0001 C CNN
	1    6450 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6450 3250 5850 3250
Wire Wire Line
	5850 3450 6450 3450
Wire Wire Line
	5850 3650 6450 3650
Wire Wire Line
	5850 3850 6450 3850
Wire Wire Line
	6250 4000 6450 4000
Wire Wire Line
	3500 2100 2850 2100
Wire Wire Line
	2850 2100 2850 2400
Connection ~ 3500 2100
$EndSCHEMATC
