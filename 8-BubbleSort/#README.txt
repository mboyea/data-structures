HOW TO COMPILE:
1.) Ensure GCC is installed and referencable by PATH.
Open Command prompt and run the following.

For a debug build:
cd /d "P:\C++\CSCI251DataStructures\8-BubbleSort\" && g++ *.cpp -Wall -o build

For a debug build & run:
cd /d "P:\C++\CSCI251DataStructures\8-BubbleSort\" && g++ *.cpp -Wall -o build && start cmd /C "P:\C++\CSCI251DataStructures\8-BubbleSort\"build

For a release build:
cd /d "P:\C++\CSCI251DataStructures\8-BubbleSort\" && g++ *.cpp -static-libgcc -static-libstdc++ -Wall -o build

For a release build:
cd /d "P:\C++\CSCI251DataStructures\8-BubbleSort\" && g++ *.cpp -static-libgcc -static-libstdc++ -Wall -o build && start cmd /C "P:\C++\CSCI251DataStructures\8-BubbleSort\"build

TODO: Look into including external libraries
TODO: Look into Makefile