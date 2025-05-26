CC=sdcc
IHX2SMS=ihx2sms
DEVKITSMS_BASE=../../
PLATFORM=SGlib
VARIANT=
BASE=$(DEVKITSMS_BASE)$(PLATFORM)
INCDIR=$(BASE)/src
PEEP_RULES=$(BASE)/src/peep-rules.txt
ifeq ($(PLATFORM),SGlib)
	CRT0=$(DEVKITSMS_BASE)/crt0/crt0_sg.rel
else 
	CRT0=$(DEVKITSMS_BASE)/crt0/crt0_sms.rel
endif

PLATFORM_LIB=$(BASE)/$(PLATFORM).rel
ifeq ($(PLATFORM), GG)
	PLATFORM_LIB=$(BASE)/$(PLATFORM)SMSlib_GG.rel
endif
LIB=$(BASE)/$(PLATFORM_LIB).rel          # Use distributed lib
#SMSLIB_LIB=$(SMSLIB_BASE)/src/SMSlib.lib      # Use locally compiled lib

PROGNAME=keycheck

CFLAGS=-mz80 -I$(INCDIR) --peep-file $(PEEP_RULES) -DPROG_NAME=\"$(PROGNAME)\"
LDFLAGS=-mz80 --no-std-crt0 --data-loc 0xC000


FILE_EXT=.sc

OBJS=assets.rel keyboard.rel strings.rel console.rel $(PROGNAME).rel 

all: $(PROGNAME)$(FILE_EXT)

%.rel: %.c
	$(CC) $(CFLAGS) -c $<

%.rel: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(PROGNAME).ihx: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(CRT0) $(PLATFORM_LIB) $^

$(PROGNAME)$(FILE_EXT): $(PROGNAME).ihx
	$(IHX2SMS) $< $@

clean:
ifeq ($(OS),Windows_NT)
	del /Q *.rel *.ihx *.asm *.sym *.lst *.noi *.lk *.map *.sms *.gg *.sc *.sg
else
	rm -f *.rel *.ihx *.asm *.sym *.lst *.noi *.lk *.map *.sms *.gg *.sc *.sg
endif
# When a linking error occurs, sdcc returns an error and make fails. However
# a .ihx output file still gets created. This leads to make thinking that the .ihx
# file is up to date the next time it runs... This forces linking to take place
# every time make is called.
.PHONY: $(PROGNAME).ihx
