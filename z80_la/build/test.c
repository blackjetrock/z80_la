int in;
int out;

// Assume a 2 bit address bus as I'm manually typing this

int eqn[] =
  {
   // Top two bits of index are addr bus
   // Bit 1 is ROM RD
   // Bit 0 is IORQ
   // Value of array is value to write to DIR GPIO
   // Only drive on port 2
   
   0,         // 0000
   0,         // 0001
   1,         // 0010
   1,         // 0011
   0,         // 0100
   0,         // 0101
   1,         // 0110
   1,         // 0111
   0,         // 1000
   0,         // 1001
   0,         // 1010
   1,         // 1011
   0,         // 1100
   0,         // 1101
   1,         // 1110
   1,         // 1111
  };

while(1)
  {
    in=(gpio_states() & 0xf);
    gpio_put(eqn[in]);
  }
