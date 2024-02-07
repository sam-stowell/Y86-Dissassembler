#include <stdio.h>
#include <stdlib.h>

//This is an array of register mnemonics in y86
const char *register_names[] =
    {
        "%eax",
        "%ecx",
        "%edx",
        "%ebx",
        "%esp",
        "%ebp",
        "%esi",
        "%edi",
        "UNKNOWN_REGSITER"};

//This is the help function that reads y86 binary code from a file
unsigned int loadBinFromFile(const char *filename, unsigned char memory[], unsigned int memsize);

int main(int argc, char **argv)
{
  unsigned int MAX_MEMSIZE = 4096;
  unsigned char memory[MAX_MEMSIZE]; //This array represents the 4KB memory space
  unsigned int PC = 0;               //This is the initial program counter address

  if (argc < 2)
  {
    printf("Usage: please specify a y86 binary program file in the argument.\n");
    return -1;
  }

  unsigned int program_size = loadBinFromFile(argv[1], memory, MAX_MEMSIZE);

  if (program_size == 0)
    return 0;

  

  //TODO: Implement your disassembler from here
  //At the moment, it simply display each byte from the memory.
  while (PC < program_size)
  {
    if (memory[PC]==0x00) {
      printf("halt\n");
      PC = PC + 1;
    }
    
    else if (memory[PC]==0x10) {
      printf("nop\n");
      PC = PC + 1;
    }
    
    else if (memory[PC]==0x90) {
      printf("ret\n");
      PC = PC + 1;
    }

    else if (memory[PC]==0x30) {
    printf("irmovl");
    int operandB = memory[PC+1] % 0x10; //2nd register
    // little endian so flip
    int value = memory[PC+2]+(memory[PC+3]<<8)+(memory[PC+4]<<16)+(memory[PC+5]<<24);
    printf(" $%d,",value);
    printf(" %s\n",register_names[operandB]);
    PC = PC + 6;
    }
      
    else if (memory[PC]==0x20) {
    printf("rrmovl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x21) {
    printf("cmovle");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x22) {
    printf("cmovl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x23) {
    printf("cmove");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }
    
    else if (memory[PC]==0x24) {
    printf("cmovne");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x25) {
    printf("cmovge");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x26) {
    printf("cmovg");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x60) {
    printf("addl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x61) {
    printf("subl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x62) {
    printf("andl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0x63) {
    printf("xorl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    printf(" %s, %s\n",register_names[operandA],register_names[operandB]);
    PC = PC + 2;
    }

    else if (memory[PC]==0xA0) {
    printf("pushl");
    int operandA = memory[PC+1] / 0x10;
    printf(" %s\n",register_names[operandA]);
    PC = PC + 2;
    }

    else if (memory[PC]==0xB0) {
    printf("popl");
    int operandA = memory[PC+1] / 0x10;
    printf(" %s\n",register_names[operandA]);
    PC = PC + 2;
    }
      
    else if (memory[PC]==0x30) {
    printf("irmovl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    int value = memory[PC+2]+(memory[PC+3]<<8)+(memory[PC+4]<<16)+(memory[PC+5]<<24);
    printf(" %s, %d(%s)\n",register_names[operandA],value,register_names[operandB]);
    PC = PC + 6;
    }
      
    else if (memory[PC]==0x40) {
    printf("rmmovl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    int value = memory[PC+2]+(memory[PC+3]<<8)+(memory[PC+4]<<16)+(memory[PC+5]<<24);
    printf(" %s, %d(%s)\n",register_names[operandA],value,register_names[operandB]);
    PC = PC + 6;
    }
      
    else if (memory[PC]==0x50) {
    printf("mrmovl");
    int operandA = memory[PC+1] / 0x10;
    int operandB = memory[PC+1] % 0x10;
    int value = memory[PC+2]+(memory[PC+3]<<8)+(memory[PC+4]<<16)+(memory[PC+5]<<24);
    printf(" %d(%s), %s\n",value,register_names[operandB],register_names[operandA]);
    PC = PC + 6;
    }
            
    else if (memory[PC]==0x70) {
    printf("jmp");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
            
    else if (memory[PC]==0x71) {
    printf("jle");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
                
    else if (memory[PC]==0x72) {
    printf("jl");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
                
    else if (memory[PC]==0x73) {
    printf("je");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
                
    else if (memory[PC]==0x74) {
    printf("jne");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
                
    else if (memory[PC]==0x75) {
    printf("jge");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
                
    else if (memory[PC]==0x76) {
    printf("jg");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
                
    else if (memory[PC]==0x80) {
    printf("call");
    int value = memory[PC+1]+(memory[PC+2]<<8)+(memory[PC+3]<<16)+(memory[PC+4]<<24);
    printf(" %u\n",value);
    PC = PC + 5;
    }
        
    else {
    //printf("%02X\n", memory[PC]);
    PC++;
    }
  }

  return 0;
}

/****************************************************************************
N.B. You do not need to modify or work in this function.
Description:
This function reads in a y86 machine bytecode from file and
store them in an unsigned char array.
******************************************************************************/
unsigned int loadBinFromFile(const char *filename, unsigned char memory[], unsigned int memsize)
{
  unsigned int bytes_read = 0;

  unsigned int file_size = 0;

  FILE *pfile = fopen(filename, "rb");

  if (!pfile)
  {
    printf("Unable to load file %s, please check if the path and name are correct.\n", filename);
    return 0;
  }

  fseek(pfile, 0, SEEK_END);
  file_size = ftell(pfile);
  rewind(pfile);

  if (file_size > memsize)
  {
    printf("Program size exceeds memory size of %d.\n", memsize);
    return 0;
  }

  bytes_read = fread(memory, 1, file_size, pfile);

  if (bytes_read != file_size)
  {
    printf("Bytes read does not match the file size.\n");
    return 0;
  }

  fclose(pfile);

  return bytes_read;
}
