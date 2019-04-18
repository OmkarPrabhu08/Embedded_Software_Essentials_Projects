#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include "spi.h"

int main(){

        spi_init();
        
        uint8_t port = 117;
        
        uint8_t status;
	uint8_t data_array[5] = {0x01,0x02,0x03,0x04,0x05};
	uint8_t status_array[5];
        FILE *IO_Value;
        char file[128];
        
        uint8_t nop = NRF_NOP;
        uint8_t command,data,index;

        command = (NRF_W_REGISTER|NRF_CONFIG_REG);
        data = 0x03;
        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "0\n");
        fclose(IO_Value);

        write(fd,&command,1);
        write(fd,&data,1);

        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "1\n");
        fclose(IO_Value);

        command = (NRF_R_REGISTER | NRF_CONFIG_REG);
        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "0\n");
        fclose(IO_Value);

        write(fd,&command,1);
        write(fd,&nop,1);
        read(fd,&status,1);

        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "1\n");
        fclose(IO_Value);

        printf("Data to be written was 0x03 and data written is 0x0%x for CONFIG register\n",status);

	command = (NRF_W_REGISTER|NRF_FIFO_STATUS_REG);
        data = 0x10;
        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "0\n");
        fclose(IO_Value);

        write(fd,&command,1);
        write(fd,&data,1);

        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "1\n");
        fclose(IO_Value);

        command = (NRF_R_REGISTER | NRF_FIFO_STATUS_REG);
        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "0\n");
        fclose(IO_Value);

        write(fd,&command,1);
        write(fd,&nop,1);
        read(fd,&status,1);

        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "1\n");
        fclose(IO_Value);

        printf("This is the default value of FIFO STATUS 0x%x\n",status);

	command = (NRF_W_REGISTER | NRF_TXADDR_REG);
        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "0\n");
        fclose(IO_Value);

        write(fd,&command,1);
        write(fd,data_array,5);

        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "1\n");
        fclose(IO_Value);

        command = (NRF_R_REGISTER | NRF_TXADDR_REG);
        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "0\n");
        fclose(IO_Value);

        write(fd,&command,1);
        write(fd,&nop,1);
	write(fd,&nop,1);
	write(fd,&nop,1);
	write(fd,&nop,1);
	write(fd,&nop,1);
	write(fd,&nop,1);
	write(fd,&nop,1);
	write(fd,&nop,1);
        read(fd,status_array,5);

        sprintf(file, "/sys/class/gpio/gpio%d/value", port);
        IO_Value = fopen(file, "w");
        fprintf(IO_Value, "1\n");
        fclose(IO_Value);
	for(index = 0;index < 5; index++)
	{
        printf("Data to be written was 0x0%x and data written is 0x0%x for TXADDR_REG register\n",data_array[index],status_array[index]);
	}
        return 0;
}
