EESchema Schematic File Version 4
EELAYER 30 0
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
L Connector:AudioJack2_SwitchT J1
U 1 1 5FC82E98
P 3650 4200
F 0 "J1" H 3654 4542 50  0000 C CNN
F 1 "IN" H 3654 4451 50  0000 C CNN
F 2 "Connector_Thonk:ThonkiconnJack" H 3650 4200 50  0001 C CNN
F 3 "~" H 3650 4200 50  0001 C CNN
F 4 "Jack Connector" H 3650 4200 50  0001 C CNN "Device"
F 5 "ElectroDemo – 3.5mm Jack Sockets" H 3650 4200 50  0001 C CNN "Description"
F 6 "ED-POT" H 3650 4200 50  0001 C CNN "IPN"
F 7 "THT" H 3650 4200 50  0001 C CNN "Mounting"
	1    3650 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 60B90F5A
P 3850 4100
F 0 "#PWR0101" H 3850 3850 50  0001 C CNN
F 1 "GND" V 3855 3972 50  0000 R CNN
F 2 "" H 3850 4100 50  0001 C CNN
F 3 "" H 3850 4100 50  0001 C CNN
	1    3850 4100
	0    -1   -1   0   
$EndComp
Text GLabel 3850 4200 2    50   Output ~ 0
Pin0
Text GLabel 3850 4300 2    50   Output ~ 0
Cascade0
$EndSCHEMATC
