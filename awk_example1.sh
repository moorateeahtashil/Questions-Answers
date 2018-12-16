#!/bin/bash -f
# Linux users have to change $8 to $9
awk '
BEGIN 	{ print "File\tOwner" }
 
		{ 
x=1;
print $x}	
END   	{ print " - DONE -" } 
'
