cmd_/home/krushna/eldd_labexam/eldd_exam/ex.mod := printf '%s\n'   ex.o | awk '!x[$$0]++ { print("/home/krushna/eldd_labexam/eldd_exam/"$$0) }' > /home/krushna/eldd_labexam/eldd_exam/ex.mod
