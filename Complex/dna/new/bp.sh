#!/bin/bash

echo Begin Base Pair Analysis `date +"%Y%m%d%H%M%S"`
echo

for i in `ls data/*10a.txt`;
do
	j=`basename $i`
	geneid=`basename $j hgp10a.txt`
	echo DNA strand number $geneid
	echo
	ls -s --block-size=1 $i
	ls -s --block-size=1 /mnt/cdrom/$j.bz2
	echo
	time ./bp < $i
	echo

done

echo End Base Pair Analysis `date +"%Y%m%d%H%M%S"`
echo
