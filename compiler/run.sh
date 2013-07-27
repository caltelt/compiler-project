#!/bin/sh
./Compiler test$1 output > output.asm && cat output && java -jar Mars4_3.jar output.asm
