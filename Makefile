#Start Settings
TESTING = $(firstword $(MAKECMDGOALS))

#Directories
INCS = ./includes/
TESTS = ./tests/
UTILS = ./utils/
USRFLS = ./userfiles/
USRHDRS = ./userheaders/

#Strings
TESTERS = libft printf gnl
IVDTEST = Invalid Tester
INFO = Welcome to this pile of trash

#compile
CC = gcc
FLAGS = -I$(INCS) -I$(USRHDRS) -L$(USRFLS) -lft -undefined dynamic_lookup
TESTC = `find ./tests/ -type f -name '*.c'`
RUN = tester


#Targets
all:
	@echo $(INFO)

$(TESTING):
ifeq ($(TESTING), $(filter $(TESTING), $(TESTERS)))
	@./script.sh $(TESTING)
	@echo -n Making User Files...
	@make -s -C $(USRFLS)
	@echo Done
	@$(CC) $(UTILS)* $(TESTC) $(FLAGS) -o $(RUN)
	@clear
	@echo Beginning Tests
	@./$(RUN) $(MAKECMDGOALS)
	@rm -rf $(RUN) $(USRFLS) $(USRHDRS)
else
	@echo $(IVDTEST)
endif

%:
	@:
