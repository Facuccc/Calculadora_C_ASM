b 9
b 16
b 29
run $(python -c "print('A'*10 + '\xd0')")
disass main
x/16wx $sp
x/16wx $sp
print &auth_flag
x/s 0xf7fb6c68
c
x/16wx $sp
c
quit
