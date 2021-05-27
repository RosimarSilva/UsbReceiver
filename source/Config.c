/*
 * Config.c
 *
 *  Created on: 26 de mai de 2021
 *      Author: Rosimar
 */
#include "Configs.h"

extern uint8_t dadoSalvo[I2C_DATA_LENGTH], dadoEEpromLido[I2C_DATA_LENGTH];

void iniciaPerifericos(void)
{
	inicializaI2c();
}

//inicia o canal I2C1, onde é feita a comunicação com a EEPROM
void inicializaI2c(void)
{
		i2c_master_config_t masterConfig;
    	uint32_t sourceClock;

       I2C_MasterGetDefaultConfig(&masterConfig);
       masterConfig.baudRate_Bps = I2C_BAUDRATE;

       sourceClock = I2C_FREQUENCIA;

       I2C_MasterInit(CANAL_I2C, &masterConfig, sourceClock);
}
/*Escreve apenas 1 byte na EEPROM
 * onde o primeiro parâmetro é o dado a ser gravado e o segundo parâmetro
 * o endereço da memória na EEPROM
 */
void I2cWriteByte(uint8_t data, uint8_t deviceAddress)
{

	i2c_master_transfer_t masterXfer;

	 memset(&masterXfer, 0, sizeof(masterXfer));


   masterXfer.slaveAddress = I2C_ENDERECO;
   masterXfer.direction = kI2C_Write;
   masterXfer.subaddress = (uint32_t)deviceAddress;
   masterXfer.subaddressSize = 2U;
   masterXfer.data = &data;
   masterXfer.dataSize = 1U;//I2C_DATA_LENGTH;
   masterXfer.flags = kI2C_TransferDefaultFlag;

   WC_control(0);

   I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);
}
/*Faz a leitura apenas de 1 byte na EEPROM,
 * onde o  parâmetro é o endereço da memória na EEPROM
 */
uint8_t I2cReadByte(uint8_t deviceAddress)
{
	i2c_master_transfer_t masterXfer;
	i2cDados_t i2c_data;

	 memset(&masterXfer, 0, sizeof(masterXfer));


    masterXfer.slaveAddress = I2C_ENDERECO;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = (uint32_t)deviceAddress;
    masterXfer.subaddressSize = 2U;
    masterXfer.data = &i2c_data.dadoLido;
    masterXfer.dataSize = 1U;//I2C_DATA_LENGTH ;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    WC_control(1);

    I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);

    return i2c_data.dadoLido;;
}
/*Escreve vários bytes na EEPROM
 * onde o primeiro parâmetro são dado a ser gravado que deverão estar armazenados
 * em um vetor e o segundo parâmetro
 * o endereço da memória na EEPROM
 */
void I2cWritePageBytes(uint8_t data, uint8_t deviceAddress)
{
	i2c_master_transfer_t masterXfer;
	i2cDados_t i2c_data;

	memset(&masterXfer, 0, sizeof(masterXfer));

   masterXfer.slaveAddress = 0x50;//I2C_ENDERECO;
   masterXfer.direction = kI2C_Write;
   masterXfer.subaddress = (uint32_t)deviceAddress;
   masterXfer.subaddressSize = 2U;
   masterXfer.data = dadoSalvo;
   masterXfer.dataSize = I2C_DATA_LENGTH;//I2C_DATA_LENGTH;
   masterXfer.flags = kI2C_TransferDefaultFlag;

   WC_control(0);

   I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);
}
/*Faz a leitura de varios bytes na EEPROM,
 * onde o  parâmetro é o endereço da memória na EEPROM
 */
void I2cReadPageBytes(uint8_t deviceAddress)
{
	i2c_master_transfer_t masterXfer;
	i2cDados_t i2c_data;

	 memset(&masterXfer, 0, sizeof(masterXfer));

    masterXfer.slaveAddress =  0x50;//I2C_ENDERECO;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = (uint32_t)deviceAddress;
    masterXfer.subaddressSize = 2U;
    masterXfer.data = dadoEEpromLido;
    masterXfer.dataSize = I2C_DATA_LENGTH;//I2C_DATA_LENGTH ;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    WC_control(1);

    I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);


}
//Estas são as entradas Rotinas que farão Leitura das entrads DS1,2,3 e 4
bool Ds1_GetVal(void){return  (GPIO_PinRead(GPIOC, 1U));}
bool Ds2_GetVal(void){ return (GPIO_PinRead(GPIOC, 0U));}
bool Ds3_GetVal(void){ return (GPIO_PinRead(GPIOB, 19U));}
bool Ds4_GetVal(void){ return (GPIO_PinRead(GPIOB, 18U));}
