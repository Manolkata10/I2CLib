#include "i2c.h"                                                                
#include <stdio.h>                                                              
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>


int I2C::openFile(unsigned char address)
{
        file = (int)open("/dev/i2c-2", O_RDWR);

        if (file < 0)
                return -1;

        if(ioctl(file, I2C_SLAVE, address) < 0)
                return -2;

        return 0;
}

int I2C::closeFile()
{
        close(file);
        return 0;
}

int I2C::sendFile(char *buffer, int num)
{
        int bytes = write(file, buffer, num);

        if(bytes != num)
                return -1;
        return 0;
}

int I2C::readFile(unsigned char *buffer, int num)
{
        int bytes = read(file, buffer, num);

        if(bytes != num)
                return -1;

        return 0;
}

I2C::I2C()
{
        openFile(0x58);
}

I2C::~I2C()
{
        closeFile();
}
