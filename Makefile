#Start Settings
TESTING = $(firstword $(MAKECMDGOALS))
OS=$(shell uname);

#Directories
INCS = ./includes/
TESTS = ./tests/
UTILS = ./utils/
USRFLS = ./userfiles/

#Testers list
TESTERS = libft

#Strings
IVDTEST = "Invalid or Not Coded (yet) Tester\n"
define INFO =
Welcome to this pile of trash

Usages: make [tester] [opt:func name] [opt:testnum]

Available Testers:
  libft(Slightly made)
  printf(SoonTM)
  gnl(SoonTM)
  Whatever I decide to SUFFER on to add!

Make sure this folder is outside the project you are wanting to Test!
To update project paths for testing please edit the script.sh file (The Path variables are at the top)

Note this is in its pretty early stages. Not every feature is added yet!
If you have any ideas/bugs/errors please let me know.
Discord = HypeSwarm#7837
endef
export INFO

#compile
CC = gcc
FLAGS = -I$(INCS)
MAC = -L$(USRFLS) -lft -undefined dynamic_lookup
LINUX = -lbsd -Wl,--whole-archive -L$(USRFLS) -lft -Wl,--no-whole-archive -D LINUX
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
	@make -s -C $(USRFLS)
	@echo Done
	@$(CC) $(UTILS)* tests/$(TESTING)/* $(FLAGS) -o $(RUN)
	@clear
	@echo Beginning Tests
	@./$(RUN) $(MAKECMDGOALS)
	@rm -rf $(RUN) $(USRFLS)
else
	@printf $(IVDTEST)
endif

%:
	@:
