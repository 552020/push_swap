#!/bin/zsh

echo "Compiling C program"
cc argv_bash_vs_zsh.c


echo "Running './a.out 1 2 3'"
./a.out 1 2 3

echo "Running './a.out \"1 2 3\"'"
./a.out "1 2 3"

echo "Running './a.out '1 2 3''"
./a.out '1 2 3'

echo "Running 'ARG=\"1 2 3\"; ./a.out \$ARG'"
ARG="1 2 3"; ./a.out $ARG

echo "Running 'ARG='1 2 3'; ./a.out \$ARG'"
ARG='1 2 3'; ./a.out $ARG

echo "Switching to bash"
bash <<EOF

echo "Running './a.out 1 2 3'"
./a.out 1 2 3

echo "Running './a.out \"1 2 3\"'"
./a.out "1 2 3"

echo "Running './a.out '1 2 3''"
./a.out '1 2 3'

echo "Running 'ARG=\"1 2 3\"; ./a.out \$ ARG'"
ARG="1 2 3"; ./a.out $ARG

echo "Running 'ARG='1 2 3'; ./a.out \$ ARG'"
ARG='1 2 3'; ./a.out $ARG
EOF

