all: remote

OUTPUT_NAME=i2c
COMPILER=g++
CONFIG=
BUILD=$(COMPILER) $^ $(CONFIG) -o $(OUTPUT_NAME)

local: i2c.cpp main.cpp
		make clean
		$(BUILD)

remote: i2c.cpp main.cpp
		make clean
		git pull
		$(BUILD)

clean:
	rm -f $(OUTPUT_NAME)