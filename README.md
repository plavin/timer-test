# Timer Test

This repo report the minimum representable clock resolution by the highest available precision clock. It also reads the time 101 times and reports the min/average/max delta between successive reads.

## Compiling and Running

Typing `make` will compile and run the code.

## Bugs

As of right now, the executable is deleted by the make file. This is because compiling the executable acts as a cpu warm, leading to a shorter loop time. This will be fixed in the future. If you don't like this behavior, use `make timer-test` to build the code.
