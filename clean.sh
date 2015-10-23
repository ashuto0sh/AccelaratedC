#!/bin/bash

## clean the top level
rm *.exe;
rm *~;

## clean all the sub-directories
for dir in `ls .`;
do
	echo "*** cleaning $dir ***"
	cd $dir;
	rm *.exe;
	rm *.cpp~;
done
