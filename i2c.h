class I2C
{
        private:
                int file;

                int openFile(unsigned char address);
                int closeFile();

        public:
                int sendFile(char *buffer, int num);
                int readFile(unsigned char *buffer, int num);

                I2C();
                ~I2C();
};
