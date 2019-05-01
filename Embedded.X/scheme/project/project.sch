EESchema Schematic File Version 4
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
$Comp
L mylib:LCD DS1
U 1 1 5CCA6B32
P 8550 3800
F 0 "DS1" V 8504 4644 50  0000 L CNN
F 1 "LCD" V 8595 4644 50  0000 L CNN
F 2 "Display:AG12864E" H 8550 2900 50  0001 C CIN
F 3 "https://www.digchip.com/datasheets/parts/datasheet/1121/AG-12864E-pdf.php" H 8750 3600 50  0001 C CNN
	1    8550 3800
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_MEC_5G SW2
U 1 1 5CCABC26
P 5650 3450
F 0 "SW2" H 5250 3500 50  0000 L CNN
F 1 "Rotate" H 5150 3400 50  0000 L CNN
F 2 "" H 5650 3650 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 5650 3650 50  0001 C CNN
	1    5650 3450
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_MEC_5G SW3
U 1 1 5CCAC7CC
P 5650 3650
F 0 "SW3" H 5250 3700 50  0000 L CNN
F 1 "Left" H 5250 3600 50  0000 L CNN
F 2 "" H 5650 3850 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 5650 3850 50  0001 C CNN
	1    5650 3650
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_MEC_5G SW4
U 1 1 5CCAD244
P 5650 3850
F 0 "SW4" H 5250 3900 50  0000 L CNN
F 1 "Right" H 5200 3800 50  0000 L CNN
F 2 "" H 5650 4050 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 5650 4050 50  0001 C CNN
	1    5650 3850
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_MEC_5G SW5
U 1 1 5CCAD611
P 6050 4000
F 0 "SW5" H 5650 4050 50  0000 L CNN
F 1 "Down" H 5600 3950 50  0000 L CNN
F 2 "" H 6050 4200 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 6050 4200 50  0001 C CNN
	1    6050 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	3500 2100 3850 2100
Wire Wire Line
	3850 5100 3850 5400
NoConn ~ 3950 5100
NoConn ~ 3950 2100
Wire Wire Line
	8650 2400 8650 3300
Wire Wire Line
	8550 2500 8550 3300
Wire Wire Line
	8450 2600 8450 3300
Wire Wire Line
	8350 2700 8350 3300
Wire Wire Line
	8250 2800 8250 3300
Wire Wire Line
	8150 2900 8150 3300
Wire Wire Line
	5050 2400 8650 2400
Wire Wire Line
	5050 2500 8550 2500
Wire Wire Line
	5050 2600 8450 2600
Wire Wire Line
	5050 2700 8350 2700
Wire Wire Line
	5050 2800 8250 2800
Wire Wire Line
	5050 2900 8150 2900
$Comp
L mylib:PIC U1
U 1 1 5CCC1C25
P 3950 3600
F 0 "U1" H 3950 5281 50  0000 C CNN
F 1 "PIC16F884" H 3950 5190 50  0000 C CNN
F 2 "" H 3950 3600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/41291D.pdf" H 3950 3600 50  0001 C CNN
	1    3950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3000 7950 3000
Wire Wire Line
	7950 3000 7950 3300
Wire Wire Line
	5050 3100 8050 3100
Wire Wire Line
	8050 3100 8050 3300
Wire Wire Line
	2850 3100 2450 3100
Wire Wire Line
	2450 3100 2450 1750
Wire Wire Line
	2450 1750 9150 1750
Wire Wire Line
	9150 1750 9150 3300
Wire Wire Line
	2850 3200 2800 3200
Wire Wire Line
	2800 3200 2800 1850
Wire Wire Line
	2800 1850 8950 1850
Wire Wire Line
	8950 1850 8950 3300
Wire Wire Line
	7450 3800 7750 3800
Wire Wire Line
	5050 4150 6750 4150
Wire Wire Line
	6750 4150 6750 4400
Wire Wire Line
	6750 4400 7950 4400
Wire Wire Line
	7950 4400 7950 4300
Wire Wire Line
	5050 4250 6650 4250
Wire Wire Line
	6650 4250 6650 4500
Wire Wire Line
	6650 4500 8050 4500
Wire Wire Line
	8050 4500 8050 4300
NoConn ~ 8350 4300
NoConn ~ 8450 4300
Wire Wire Line
	5050 4350 6550 4350
Wire Wire Line
	6550 4350 6550 4600
Wire Wire Line
	6550 4600 8700 4600
Wire Wire Line
	8700 4600 8700 4300
Wire Wire Line
	5050 4450 6450 4450
Wire Wire Line
	6450 4450 6450 4700
Wire Wire Line
	6450 4700 8800 4700
Wire Wire Line
	8800 4700 8800 4300
Wire Wire Line
	9350 3800 9650 3800
Wire Wire Line
	9000 4300 9000 4700
Wire Wire Line
	9000 4700 9650 4700
Wire Wire Line
	9650 4700 9650 4550
Wire Wire Line
	9150 4300 9150 4400
Wire Wire Line
	9150 4400 9500 4400
Wire Wire Line
	9650 3800 9650 4250
Connection ~ 9650 3800
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
NoConn ~ 2850 2400
$Comp
L Device:R_POT_TRIM RV1
U 1 1 5CD398F6
P 9650 4400
F 0 "RV1" H 9580 4354 50  0000 R CNN
F 1 "10k" H 9580 4445 50  0000 R CNN
F 2 "" H 9650 4400 50  0001 C CNN
F 3 "~" H 9650 4400 50  0001 C CNN
	1    9650 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	9650 3800 9850 3800
$Comp
L power:GND #PWR0101
U 1 1 5CD41B43
P 5750 3250
F 0 "#PWR0101" H 5750 3000 50  0001 C CNN
F 1 "GND" V 5800 3300 50  0000 R CNN
F 2 "" H 5750 3250 50  0001 C CNN
F 3 "" H 5750 3250 50  0001 C CNN
	1    5750 3250
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_MEC_5G SW1
U 1 1 5CCA9172
P 5650 3250
F 0 "SW1" H 5250 3300 50  0000 L CNN
F 1 "Pause" H 5200 3200 50  0000 L CNN
F 2 "" H 5650 3450 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 5650 3450 50  0001 C CNN
	1    5650 3250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CD436F9
P 5750 3450
F 0 "#PWR0102" H 5750 3200 50  0001 C CNN
F 1 "GND" V 5800 3500 50  0000 R CNN
F 2 "" H 5750 3450 50  0001 C CNN
F 3 "" H 5750 3450 50  0001 C CNN
	1    5750 3450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5CD43ECB
P 5750 3650
F 0 "#PWR0103" H 5750 3400 50  0001 C CNN
F 1 "GND" V 5800 3700 50  0000 R CNN
F 2 "" H 5750 3650 50  0001 C CNN
F 3 "" H 5750 3650 50  0001 C CNN
	1    5750 3650
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5CD44155
P 5750 3850
F 0 "#PWR0104" H 5750 3600 50  0001 C CNN
F 1 "GND" V 5800 3900 50  0000 R CNN
F 2 "" H 5750 3850 50  0001 C CNN
F 3 "" H 5750 3850 50  0001 C CNN
	1    5750 3850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5CD44564
P 6150 4000
F 0 "#PWR0105" H 6150 3750 50  0001 C CNN
F 1 "GND" V 6200 4050 50  0000 R CNN
F 2 "" H 6150 4000 50  0001 C CNN
F 3 "" H 6150 4000 50  0001 C CNN
	1    6150 4000
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5CD44CC2
P 3500 2100
F 0 "#PWR0106" H 3500 1950 50  0001 C CNN
F 1 "VCC" H 3517 2273 50  0000 C CNN
F 2 "" H 3500 2100 50  0001 C CNN
F 3 "" H 3500 2100 50  0001 C CNN
	1    3500 2100
	0    -1   -1   0   
$EndComp
Text Notes 2600 1250 0    50   ~ 0
VCC = 5V
$Comp
L power:VCC #PWR0107
U 1 1 5CD4759C
P 9850 3800
F 0 "#PWR0107" H 9850 3650 50  0001 C CNN
F 1 "VCC" V 9867 3928 50  0000 L CNN
F 2 "" H 9850 3800 50  0001 C CNN
F 3 "" H 9850 3800 50  0001 C CNN
	1    9850 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5CD48367
P 7450 3800
F 0 "#PWR0109" H 7450 3550 50  0001 C CNN
F 1 "GND" V 7455 3672 50  0000 R CNN
F 2 "" H 7450 3800 50  0001 C CNN
F 3 "" H 7450 3800 50  0001 C CNN
	1    7450 3800
	0    1    1    0   
$EndComp
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
$EndSCHEMATC
