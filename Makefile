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
FLAGS = -I$(INCS) -L$(USRFLS) -lft
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
	@$(CC) $(UTILS)* $(FLAGS) -o $(RUN)
	@clear
	@echo Beginning Tests
	@./$(RUN) $(MAKECMDGOALS)
	@rm -f $(RUN)
else
	@echo $(IVDTEST)
endif

%:
	@:
