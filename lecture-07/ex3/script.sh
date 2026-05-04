#!/bin/bash
rm *.txt

touch original.txt
echo "Hello" >> original.txt

ln original.txt hard.txt
ln -s original.txt soft.txt

rm original.txt

cat hard.txt
cat soft.txt