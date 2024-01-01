cmd_/home/krushna/eldd_labexam/eldd_exam/im.mod := printf '%s\n'   im.o | awk '!x[$$0]++ { print("/home/krushna/eldd_labexam/eldd_exam/"$$0) }' > /home/krushna/eldd_labexam/eldd_exam/im.mod
