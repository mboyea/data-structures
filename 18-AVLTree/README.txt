HOW TO COMPILE:
1.) Ensure g++ is installed and referencable by PATH
2.) Open Command Prompt in the project directory
3.) Run the following command for a debug build:
g++ *.cpp -Wall -o build && start cmd /C %cd%\build
4.) Run the following command for a release build:
g++ *.cpp -static-libgcc -static-libstdc++ -Wall -o build && start cmd /C %cd%\build
