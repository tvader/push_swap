#!/bin/bash
ARG=`./gen.py 100`; ../push_swap $ARG | ../checker $ARG;
../push_swap $ARG | wc -l
