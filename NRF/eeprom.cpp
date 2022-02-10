


uint8_t I2CEE3ReadInt8(uint16_t Address)
{
   int b = 1 ;
   int c = 1;
   
    char da[2];
    char re[2] ;
    da[0]= (Address>> 8) & 0xff;
    da[1]= Address & 0xff;
    b= i2c.write(0xA0 + 1, da, 2); 
    //thread_sleep_for(10);
    wait_ms(3) ;
    c= i2c.read(0xA0 + 1, re, 2);
    
    if ((b!= 0) || (c!= 0))
    {
        g_Serial_pc.printf("error in e2prom read \n") ;
    }
    
    return re[0] ;
    
}

bool I2CEE3WriteByte(uint16_t Address, uint8_t data)
{
    char da[3];
    da[0]= (Address >> 8) & 0xff;
    da[1]= Address & 0xff;
    da[2]= data;
    int a;
    bool ret= true;
            a= 0; 
            a= i2c.write(0xA0, da, 3);
            if (a!= 0)
            {
                g_Serial_pc.printf("error in e2prom write \n") ;
                ret= false;
            }
           // ThisThread::sleep_for(10);
           wait_ms(3);
            return ret;
}

uint16_t Read16(uint16_t Address)

{
    data16 data ;
    data.b[1] = I2CEE3ReadInt8(Address) ;
    data.b[0] = I2CEE3ReadInt8(Address+4) ;
    
    return data.u16 ;
    }
    
void Write16(uint16_t Address , uint16_t data)
{
    
    data16 data_ ;
    data_.u16 = data;
    I2CEE3WriteByte(Address  , data_.b[1]) ;
    I2CEE3WriteByte(Address+4  , data_.b[0]) ;
    
    
    }
