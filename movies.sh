#!/bin/bash -f
awk '
BEGIN {
# Print the squares from 1 to 10 the first way
i=1;
while (i <= 10) {
print "The square of ", i, " is ", i*i;
i = i+1;
}
for(i=0;i<10;i++)
{
print "Square number using loops is " , i*i;
}
# now end
exit;
} '
