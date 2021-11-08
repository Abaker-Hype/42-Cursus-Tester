#Start Settings
TESTING = $(firstword $(MAKECMDGOALS))
OS=$(shell uname);

#Directories
INCS = ./includes/
TESTS = ./tests/
UTILS = ./utils/
USRFLS = ./userfiles/

#Testers list
TESTERS = libft printf

#Strings
IVDTEST = "Invalid or Not Coded (yet) Tester\n"
define INFO
Welcome to this pile of trash

Usages: make [tester] [opt:funcname, groupname or "Bonus"] [(Only after a funcname) opt:testnum or "detail"]

Available Testers:
  libft
  printf(SoonTM)
  gnl(SoonTM)
  Whatever I decide to SUFFER on to add!

Make sure this folder is outside the project you are wanting to Test!
To update project paths for testing please edit the script.sh file (The Path variables are at the top)
If you want to ake sure your Bonuses get tested then have the Bonus Flag in your Makefiles Make Re target

Note this is in its pretty early stages. Not every feature is added yet!
If you have any ideas/bugs/errors please let me know.
Discord = HypeSwarm#7837
endef
export INFO

#compile
LIB = -L$(USRFLS)
ifeq ($(TESTING), libft)
	LIB += -lft
else ifeq ($(TESTING), printf)
	LIB += -lftprintf
endif
CC = gcc
FLAGS = -Wno-constant-conversion -Wno-format-security -I$(INCS)
MAC = $(LIB) -undefined dynamic_lookup
LINUX = -lbsd -Wl,--whole-archive $(LIB) -Wl,--no-whole-archive -D LINUX
RUN = tester
ifeq ($(OS),Darwin;)
	FLAGS += $(MAC)
else ifeq ($(OS),Linux;)
	FLAGS += $(LINUX)
endif

#Targets
all:
	@echo "$$INFO"

$(TESTING):
ifeq ($(TESTING), $(filter $(TESTING), $(TESTERS)))
	@./script.sh $(TESTING)
	@echo -n Making User Files...
	@make re -s -C $(USRFLS)
	@echo Done
	@echo -n Compiling Tester...
	@$(CC) $(UTILS)* tests/$(TESTING)/* $(FLAGS) -o $(RUN)
	@echo Done
	@clear
	@echo Beginning Tests
	@./$(RUN) $(MAKECMDGOALS)
	@rm -rf $(RUN) $(USRFLS)
else
	@printf $(IVDTEST)
endif

%:
	@:
