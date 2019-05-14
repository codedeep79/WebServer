# Set compilation flags to report all warnings and enable debugging in the generated.
set(CMAKE_C_FLAGS "-Wall -g")
# The following file GLOB command will search for all files within the current directory 
# that match the specified expressions (*.c *.cpp and *.h) and assign the resulting files 
# to the variables SRCS.
file(GLOB SRCS *.c *.cpp *.h)
# Define the target application executable, list of C source and header files needed for the executable 
add_executable(WebServer ${SRCS})