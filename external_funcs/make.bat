path c:\Users\rarossi\portable\Cpp\App\Dev-Cpp\MinGW64\bin

mkdir out
gcc    -c -O2  -MMD -MP -MF out/OrcFxAPIExplicitLink.o.d -o out/OrcFxAPIExplicitLink.o OrcFxAPIExplicitLink.c
g++ -municode   -c -O2  -MMD -MP -MF out/ExternalFunction.o.d -o out/ExternalFunction.o ExternalFunction.cpp
g++ -municode   -c -O2  -MMD -MP -MF out/PIDController.o.d -o out/PIDController.o PIDController.cpp
g++ -municode   -c -O2  -MMD -MP -MF out/RegisterCapabilities.o.d -o out/RegisterCapabilities.o RegisterCapabilities.cpp
g++ -municode    -o out/ExternalFunction.dll out/ExternalFunction.o out/OrcFxAPIExplicitLink.o out/PIDController.o out/RegisterCapabilities.o  -shared

:: g++ options for my curiosity
:: -o file       : output filename
:: -c             : do not run the linker, just assemble the object .o file
:: -O2             : turns on various optimisation flags
:: -shared          : produces a shared object (library, dll)
:: -municode         : handles unicode code
:: -MMD -MP -MF file  : specifies a file to write the user's dependencies
