# -*- coding: latin-1 -*-

#Approximativa Tal
#Uppgift: Övningsserie 5 - Uppgift 9, 10, 11

resistorTxtFiles = ["txt/bla-motstand.txt", "txt/gula-motstand.txt"]
resistorColor = ["Blue", "Yellow"]
colorCodeValue = 220

#Loops twice: i=0 / i=1
for i in (0,1):
	#reads file lines to list resValues
	with open(resistorTxtFiles[i], 'r') as file:
		resValuesString = file.read().splitlines()
	#Converts string values to float values, sets to new list
	#for each index in resValuesString -> gets converted
	#to float and placed in same index for resValues (?)
	resValues = [float(x) for x in resValuesString]
	#Gets list count / amount of resistors
	resistorCount = len(resValues)
	#sum(x) sums values in list x
	median = sum(resValues)/resistorCount
	print(resistorColor[i], "resistors: ", resistorCount)
	print("Median value: ", median)
	#'{:0.2f}'.format(x) output format #.##
	#abs(x) returns absolute value of x
	print("Difference from marked value: ", '{:0.2f}'.format(abs(colorCodeValue-median)), "\n")
#Infinite loop:
var = 1
while var == 1 :
	resistorInput = float(input("Enter resistor value: "))
	print("Difference from marked value: ", '{:0.2f}'.format(abs(colorCodeValue-resistorInput)), "\n")
print ("Good bye!")