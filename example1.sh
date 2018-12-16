#!/bin/bash -f
awk '
BEGIN{
size=1
user=4
group=$5
u_count[""]=0
g_count[""]=0
ug_count[""]=0
all_count[""]=0
u_size[""]=0

}
{ 
 u_count[$user " *"]++;
g_count["* " group]++;
ug_count[user " " group]++;
all_count["* *"]++;

u_size[$user " *"]+=$size;
g_size["* " group]+=$size;
ug_size[user " " group]+=$size;
all_size["* *"]+=$size;

for (i in u_count) {
if (i != "") {
print u_size[i], u_count[i], i;
}
}
}
END{}
'
