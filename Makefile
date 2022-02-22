#Start Settings
TESTING = $(firstword $(MAKECMDGOALS))
OS=$(shell uname)

#Directories
INCS = ./includes/
TESTS = ./tests/
UTILS = ./utils/
USRFLS = ./userfiles/
OBJDIR = ./compiled/

#Testers list
TESTERS = libft printf gnl
IVDTEST = "Invalid or Not Coded (yet) Tester\n"
ifneq ($(TESTING), $(filter $(TESTING), $(TESTERS)))
$(error $(IVDTEST))
endif

#Strings
define INFO
Welcome to this pile of trash

Usages: make [tester] [opt:funcname, groupname or "Bonus"] [(Only after a funcname) opt:testnum or "detail"]

Available Testers:
  libft (Not all bonuses added)
  printf
  gnl (Manditory Done)
  Whatever I decide to SUFFER on to add!

Make sure this folder is outside the project you are wanting to Test!
To update project paths for testing please edit the script.sh file (The Path variables are at the top)
If you want to make sure your Bonuses get tested then have the Bonus Flag in your Makefiles Make Re target

Note this is in its pretty early stages. Not every feature is added yet!
If you have any ideas/bugs/errors please let me know.
Discord = HypeSwarm#7837
endef
export INFO

#SRC/OBJS
TESTPTRS := $(UTILS)testpointers.c
UTILSRC := $(wildcard $(UTILS)*.c)
UTILSRC := $(filter-out $(TESTPTRS), $(UTILSRC))
UTILOBJ := $(addprefix $(OBJDIR), $(notdir $(UTILSRC:.c=.o)))
TESTSRC := $(wildcard $(TESTS)$(TESTING)/*.c)

#Compile Flags
LIB = -L$(USRFLS)
ifeq ($(TESTING), libft)
	LIB += -lft
else ifeq ($(TESTING), printf)
	LIB += -lftprintf
else ifeq ($(TESTING), gnl)
	LIB += -lgnl
endif
CC = gcc
FLAGS = -Wno-constant-conversion -Wno-format-security -I$(INCS)
MAC = $(LIB) -undefined dynamic_lookup
LINUX = -lbsd -Wl,--whole-archive $(LIB) -Wl,--no-whole-archive -D LINUX
RUN = tester
ifeq ($(OS),Darwin)
	FLAGS += $(MAC)
else ifeq ($(OS),Linux)
	FLAGS += $(LINUX)
endif

#Targets
all:
	@echo "$$INFO"

$(TESTING): $(RUN)
	@echo Beginning Tests
	@./$(RUN) $(MAKECMDGOALS)
	@rm -rf $(RUN) $(USRFLS)

$(RUN): $(USRFLS) $(UTILOBJ)
	@$(CC) $(FLAGS) $(UTILOBJ) $(TESTSRC) $(TESTPTRS) -o $(RUN)
	@echo Done

$(USRFLS):
	@clear
	@./script.sh $(TESTING)
	@echo -n Making User Files...
ifneq ($(TESTING), gnl) ##Tester Check
	@make re -s -C $(USRFLS)
else
##GNL Specific Compile
ifeq (,`find $(USRFLS) -type f -name "*bonus.c"`)
	@gcc -c `find $(USRFLS) -type f -name "*bonus.c"`
else
	@gcc -c `find $(USRFLS) -type f \( -name "*line.c" -o -name "*utils.c" \)`
endif
	@ar rcs $(USRFLS)libgnl.a *.o
	@rm -f *.o
##End GNL Specific Compile
endif ##End tester Check
	@echo Done
	@echo -n Compiling Tester...

$(OBJDIR)%.o: $(UTILS)/%.c | $(OBJDIR)
	@$(CC) -I$(INCS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

%:
	@:
