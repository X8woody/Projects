#@COPYRIGHT "ABDULRHMAN"

CC=arm-none-eabi-
CFLAG=-mcpu=cortex-m3  -gdwarf-2
LIBS=
INCS=-I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS= $(wildcard *.s)
AS_OBJ=$(AS:.s=.o)
Name_Proj=PressureDetection
MAP=-Map=$(Name_Proj).map

all: $(Name_Proj).bin
	@echo "        "
	@echo "            =========== Build Done ==========="

$(Name_Proj).bin: $(Name_Proj).elf
	$(CC)objcopy.exe -O binary $< $@

$(Name_Proj).elf: $(OBJ) $(AS_OBJ)
	$(CC)ld.exe  -T linker_script.ld $(LIBS) $(OBJ) $(AS_OBJ) -o $@ $(MAP)
	cp $(Name_Proj).elf $(Name_Proj).axf
	
%.o: %.s
	$(CC)as.exe $(CFLAG) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(CFLAG) $(INCS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(CFLAG) $(INCS) $< -o $@ 

clean_all: 	
	rm *.o *.elf *.bin *.map *.axf

clean: 
	rm *.bin *.elf