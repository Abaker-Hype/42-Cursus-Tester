#Start Settings
TESTING = $(firstword $(MAKECMDGOALS))
OS=$(shell uname);

#Directories
INCS = ./includes/
TESTS = ./tests/
UTILS = ./utils/
USRFLS = ./userfiles/

#Strings
TESTERS = libft printf gnl
IVDTEST = Invalid Tester
INFO = Welcome to this pile of trash

#compile
CC = gcc
FLAGS = -I$(INCS)
FLAGSM = -L$(USRFLS) -lft -undefined dynamic_lookup
FLAGSL = -lbsd -Wl,--whole-archive -L$(USRFLS) -lft -Wl,--no-whole-archive -D LINUX
RUN = tester
ifeq ($(OS),Darwin;)
	FLAGS += $(FLAGSM)
else ifeq ($(OS),Linux;)
	FLAGS += $(FLAGSL)
endif


#Targets
all:
	@echo $(INFO)

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
	@echo $(IVDTEST)
endif

%:
	@:
