#!/bin/bash

LIB_PATH=$(pwd)
echo "Directory ${LIB_PATH} has been added"
LD_LIBRARY_PATH=${LIB_PATH}:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
	
make -f MAKE 
echo "Project has been collected..."
