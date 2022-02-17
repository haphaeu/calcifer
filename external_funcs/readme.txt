* How to compile OrcFxAPI external functions in MinGW

 - Add ~-municode~ compile option to g++

 - Set compiler to release mode

 - Include and compile these files
   - ExternalFunction.cpp and .h
   - OrcFxAPI.h
   - OrcFxAPIExplicitLink.c
   - RegisterCapabilities.cpp

 - In the code, change ~__stdcall~ to ~__declspec(dllexport)~ for the functions to be exported. 
   - RegisterCapabilities
   - InitializeOrcFxAPI in OrcFxAPIExplicitLink.c
   - Your entry point function, e.g. PIDController

 - Wrap the cpp function above with ~extern "C"~ clause. This is to get names right.

** Note

Had a strange error in PIDController.cpp, where WingName could not be read:

#+BEGIN_SRC
234 // this line crashes
235 // pData->WingName=Params.GetValueOf(L"ObjectExtra.WingName");
#+END_SRC

GetValueOf works fine. Errors occurs during assignment to pData->WingName.

Since it is not needed, I have simply commented out and the rest works fine.

** Full make file
#+BEGIN_SRC
path c:\Users\rarossi\portable\Cpp\App\Dev-Cpp\MinGW64\bin

mkdir out
gcc    -c -O2  -MMD -MP -MF out/OrcFxAPIExplicitLink.o.d -o out/OrcFxAPIExplicitLink.o OrcFxAPIExplicitLink.c
g++ -municode   -c -O2  -MMD -MP -MF out/ExternalFunction.o.d -o out/ExternalFunction.o ExternalFunction.cpp
g++ -municode   -c -O2  -MMD -MP -MF out/PIDController.o.d -o out/PIDController.o PIDController.cpp
g++ -municode   -c -O2  -MMD -MP -MF out/RegisterCapabilities.o.d -o out/RegisterCapabilities.o RegisterCapabilities.cpp
g++ -municode    -o out/ExternalFunction.dll out/ExternalFunction.o out/OrcFxAPIExplicitLink.o out/PIDController.o out/RegisterCapabilities.o  -shared
#+END_SRC
