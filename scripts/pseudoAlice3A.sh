#!/bin/sh

# pseudoAlice3A.sh

# Prev update: Wed Mar  1 07:19:00 AST 2023
# Last update: Fri Nov 17 08:10:20 JST 2023

(which -a jot > /dev/null 2>&1 || (echo "We need jot command to run this $0 (install athena-jot on apt)"; exit 1)) || exit 1

key="PseudoAlice3A"

cnt=0
nnn=0
Pr=512; Pg=512; Pb=512
Xr=0; Xg=0; Xb=0

while [ 1 ]; do
  cnt=$(expr $cnt + 100 + $(jot -r 1 -5 5))
  nnn=$(expr $nnn + 10)

  Sr=$(jot -r 1 0 7);  if [ $Sr -le 2 ]; then Sr=0; else Sr=1; fi
  Pr=$(expr $Pr + $(jot -r 1 -31 31)); [ $Pr -lt 0 ] && Pr=0; [ $Pr -gt 1023 ] && Pr=1023;
  # Xr=$(expr $Xr + $(jot -r 1 -50 50));
  Xr=$(echo $nnn | awk '{printf "%8.5f\n", sin($1/180*3.1416);fflush()}')

  Sg=$(jot -r 1 0 11); if [ $Sg -le 3 ]; then Sg=0; else Sg=1; fi
  Pg=$(expr $Pg - $(jot -r 1 -31 31)); [ $Pg -lt 0 ] && Pg=0; [ $Pg -gt 1023 ] && Pg=1023;
  # Xg=$(expr $Xg + $(jot -r 1 -50 50));
  Xg=$(echo $nnn | awk '{printf "%8.5f\n", cos($1/180*3.1416);fflush()}')

  Sb=$(jot -r 1 0 13); if [ $Sb -le 4 ]; then Sb=0; else Sb=1; fi
  Pb=$(expr $Pb + 2 '*' $(jot -r 1 -31 31)); [ $Pb -lt 0 ] && Pb=0; [ $Pb -gt 1023 ] && Pb=1023;
  # Xb=$(expr $Xb + $(jot -r 1 -50 50));
  Xb=$(echo $nnn | awk '{printf "%8.5f\n",cos($1/180*3.1416)*cos($1/180*3.1416);fflush()}')

  echo "$key\t$cnt\t$Sr\t$Pr\t$Xr\t$Sg\t$Pg\t$Xg\t$Sb\t$Pb\t$Xb"
  sleep 0.1 
done
