#!/bin/bash
ARG=`./gen.py 500`; ../push_swap $ARG > resps;  < resps ../checker $ARG;
< resps wc -l
rm resps
