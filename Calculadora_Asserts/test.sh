#!/bin/bash

echo 'Corriendo Test de unidad de la calculadora multimodulo - Perez / Carrizo'
assert_equals () {
	if [ "$1" = "$2" ]; then 
		echo -e "$Green $Chech_Mark Success $Color_Off"
	else
		echo -e "$Red Failed $Color_Off"
		exit 1
	fi	
}



echo 'Test de suma decimal'
echo 'Test 1: 3 + 5'
response=$(./calc_asm d 3 + 5)
assert_equals "$response" 8

echo 'Test 2: -2 + 5'
response=$(./calc_asm d -2 + 5)
assert_equals "$response" 3

echo 'Test de resta decimal'
echo 'Test 3: 5 - 3'
response=$(./calc_asm d 5 - 3)
assert_equals "$response" 2

echo 'Test 4: -5 - 3'
response=$(./calc_asm d -5 - 3)
assert_equals "$response" -8

echo 'Test de suma binaria'
echo 'Test 5: 1000 + 1010'
response=$(./calc_asm b 1000 + 1010)
assert_equals "$response" 18

echo 'Test de resta binaria'
echo 'Test 6: 1000 - 0101'
response=$(./calc_asm b 1000 - 0101)
assert_equals "$response" 3



