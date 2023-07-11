#!/bin/bash

cc argv_bash_vs_zsh.c
echo "$0"
./a.out 1 2 3
./a.out "1 2 3"
./a.out '1 2 3'
ARG="1 2 3"; ./a.out $ARG
ARG='1 2 3'; ./a.out $ARG

echo "Switching to bash"
bash <<EOF
./a.out 1 2 3
./a.out "1 2 3"
./a.out '1 2 3'
ARG="1 2 3"; ./a.out $ARG
ARG='1 2 3'; ./a.out $ARG
EOF

