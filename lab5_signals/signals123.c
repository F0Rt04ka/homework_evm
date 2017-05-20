#include "../include/signals.h"
#include "../../ReadKey/include/myReadKey.h"
#include "../../SC/include/sc.h"

void setSignals()
{
  signal(SIGALRM, timerHand);// сигнал таймера
  signal(SIGUSR1, ursignalHand);// пользовательский сигнал
}

extern int accumulator;
extern int instructionRegisterCount; 

void timerHand(int sig)
{
  int reg;
//  CU();
  instructionRegisterCount++;
  make_interface(instructionRegisterCount);
  sc_regGet(FLAG_IGNORING_CLOCK, &reg);
  if (!reg) {
    // raise(SIGALRM);
    alarm(1);
  }
}
/*---------------------------------------------------------------------------*/
void ursignalHand(int sig)
{
  sc_memoryInit();
  sc_regInit();
  sc_regSet(FLAG_IGNORING_CLOCK, 1);
  accumulator = 0;
  instructionRegisterCount = 0; 
}

/*void CU()
{
  int command, operand, mem;
  if (instructionRegisterCount >= sizeRAM) {
    sc_regSet(FLAG_OUTPUT, 1);
    sc_regSet(FLAG_IGNORING_CLOCK, 1);
	int value;	
	sc_getIRC(&value);
    make_interface(value);//refreshGui(value);//instructionRegisterCount);
    sc_setIRC(0);//instructionRegisterCount = 0; 
    return;
  }

  sc_getIRC(&value);
  make_interface(value);
  sc_memoryGet(value, &mem);

  if (sc_commandDecode(mem, &command, &operand)
      != 0) {
    sc_regSet(FLAG_COMMAND, 1);
    sc_regSet(FLAG_INTERRUPT, 1);
    return;
  }
  if ((operand < 0) || (operand >= sizeRAM)) {
    sc_regSet(FLAG_COMMAND, 1);
    sc_regSet(FLAG_INTERRUPT, 1);
    return;
  }
  if ((command >= 0x30) && (command <= 0x33) ||
      (command >= 0x51) && (command <= 0x54) ||
      (command >= 0x60) && (command <= 0x70) ||
      (command >= 0x75) && (command <= 0x76)) {
    if (ALU(command, operand) != 0)
      sc_regSet(FLAG_IGNORING_CLOCK, 1);
  } else {
    commandHandler(command, operand);
  }
value++;
sc_setIRC(value)//instructionRegisterCount++;
}

/*int ALU(int command, int operand)
{
  if ((operand < 0) || (operand >= sizeRAM)) {
    sc_regSet(FLAG_OUTPUT,1);
    return 1;
  } else {

    if (commandHandler(command, operand) != 0) {
      return -1;
    }

    if ((accumulator & 1) == 0) {
      sc_regSet(FLAG_ODD, 0);
    } else {
      sc_regSet(FLAG_ODD, 1);
    }
    if ((accumulator > 0x7FFF) || (accumulator < 0)) {
      accumulator &= 0x7FFF;
      sc_regSet(FLAG_OVERFLOW, 1);
    } else {
      sc_regSet(FLAG_OVERFLOW, 0);
    }
    sc_regSet(FLAG_ODD, accumulator & 1);
    return 0;
  }
}*/


/*int commandHandler(int command, int operand)
{
  int tmp;
  int tmpMem;
  int flag;

switch (command) {
	case 0x10: // READ 
    while (readMcell(operand) != 0);
	break;

    case 0x11: // WRITE 
      writeUse = 1;
      if (sc_memoryGet(operand, &writeValue) != 0) {
        return -1;
      }
      break;

	case 0x20: // LOAD 
      if (sc_memoryGet(operand, &accumulator) != 0) {
        return -1;
      }
      accumulator &= 0x3FFF;
      break;

    case 0x21: // STORE 
      tmp = accumulator | (1 << 14);
      if (sc_memorySet(operand, tmp) != 0) {
        return -1;
      }
	  break;

    case 0x30: // ADD 
      if (sc_memoryGet(operand, &tmpMem) != 0) {
        return -1;
      }

      if (accumulator + tmpMem > 0x7FFF) {
        sc_regSet(FLAG_OVERFLOW, 1);
        accumulator += tmpMem;
        accumulator &= 0x7FFF;
      } else {
        accumulator += tmpMem;
      }
    break;
//-------------------------------------------------------------------------
    case 0x31: // SUB 
      if (sc_memoryGet(operand, &tmpMem) != 0) {
        return -1;
      }

      if (((tmpMem >> 14) & 1) == 1) {
        tmp = tmpMem | (~0x7FFF);
      } else {
        tmp = tmpMem;
      }
      accumulator -= tmp;
      if ((accumulator > ((int)(~0x7FFF))) && (accumulator <= 0x7FFF)) {
        accumulator &= 0x7FFF;
      }
    break;
//--------------------------------------------------------------------------
    case 0x32: // DIV 
      if (sc_memoryGet(operand, &tmpMem) != 0) {
        return -1;
      }

      if (tmpMem != 0) {
        accumulator /= tmpMem;
      } else {
        sc_regSet(FLAG_DIVISION, 1);
        return -1;
      }
    break;
//--------------------------------------------------------------------------
    case 0x33: // MUL 
      if (sc_memoryGet(operand, &tmpMem) != 0) {
        return -1;
      }
      accumulator *= tmpMem;
	break;

    case 0x43: // HALT 
      //flagHalt = 1;
      sc_regSet(FLAG_INTERRUPT, 1);
      instructionRegisterCount--;
      refreshGui(instructionRegisterCount);
		break;
}

}


int readMcell(int pos)
{
  int plusFlag, num, ret = 0;
  int command, operand, mem;

  struct termios orig_options;
  
  if (tcgetattr(STDIN_FILENO, &orig_options) != 0) {
    return -1;
  }
  rk_mytermregime(0, 0, 1, 1, 1);
 
  int value;
  cs_getIRC(&value);
  make_interface(value);//instructionRegisterCount);
  mt_gotoXY(1, 23);
  writeChar(1,"READ: ");
  mt_gotoXY(1, 24);

  ret = changeCell(pos);

  if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_options) != 0) {
    return -1;
  }

  return ret;
}*/
/*---------------------------------------------------------------------------
void ursignalHand2(int sig)
{
  sc_regSet(FLAG_INTERRUPT, 1);
}
/*---------------------------------------------------------------------------
void windHand(int sig)
{
  refreshGuiSt(0);
}
/*---------------------------------------------------------------------------
void killHand(int sig)
{ 
  mt_clrscr();
  rk_mytermrestore();
  system("rm -f termsettings");
  exit(0);
}*/
