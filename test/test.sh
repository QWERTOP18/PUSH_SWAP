#!/bin/bash

cc test.c -I../includes -o test
echo test1
./test 1 2 3 -1

echo 
echo 
echo test_duplicate
./test 3 4 4 1 
./test -2 0 -2
# ./push_swap #通常終了
# ./push_swap 1 2 3 4 5 #5以下で１２回100で700回５００で5500
# ./push_swap 2 1 4 5 
# ./push_swap "2 1 4 5" 
# inputarray = {"2","1","4","5",NULL}
