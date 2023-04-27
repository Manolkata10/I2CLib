class I2C
{
        private:
                int file;

        public:
                int openFile(unsigned char address);
                int closeFile();
                int sendFile(char *buffer, int num);
                int readFile(unsigned char *buffer, int num);
};
