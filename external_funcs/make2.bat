:: this is a kiss version of make.bat

path c:\Users\rarossi\portable\Cpp\App\Dev-Cpp\MinGW64\bin

mkdir out
gcc -municode -c -O3 -o out/OrcFxAPIExplicitLink.o   OrcFxAPIExplicitLink.c
g++ -municode -c -O3 -o out/ExternalFunction.o       ExternalFunction.cpp
g++ -municode -c -O3 -o out/PIDController.o          PIDController.cpp
g++ -municode -c -O3 -o out/RegisterCapabilities.o   RegisterCapabilities.cpp
g++ -municode -shared -o out/ExternalFunction.dll out/ExternalFunction.o out/OrcFxAPIExplicitLink.o out/PIDController.o out/RegisterCapabilities.o  

:: g++ options for my curiosity
:: -o file       : output filename
:: -c             : do not run the linker, just assemble the object .o file
:: -O2             : turns on various optimisation flags
:: -shared          : produces a shared object (library, dll)
:: -municode         : handles unicode code
:: -MMD -MP -MF file  : specifies a file to write the user's dependencies
