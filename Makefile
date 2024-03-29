#----- Colors ------
BLACK 	= "\033[1;30m"
RED 	= "\033[1;31m"
GREEN 	= "\033[1;32m"
YELLOW 	= "\033[1;33m"
BLUE 	= "\033[1;34m"
MAGENTA = "\033[1;35m"
CYAN 	= "\033[1;35m"
PURPLE 	= "\033[1;36m"
WHITE 	= "\033[1;37m"
RESET 	= "\033[0;0m"
#-------------------

CXX 		= clang++
CXXFLAGS 	= -Wall -Wextra -Werror

NAME = avm


#------ path -------
FILES_PATH		= ./files
OBJECTS_PATH	= ./objects


#------ files ------
FILES_FILES		= main AVM Factory Exception Parser Lexer

#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))


#------ make ------
all: $(NAME)

$(NAME): $(FILES_OBJ) 
	@echo "\n"
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@$(CXX) -o $@ $^
	@echo $(GREEN) "\tavm\t\t- has been made\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.cpp
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@$(CXX) $(CXXFLAGS) -o $@ -c $<


#------ make tests ------
# tests:
# 	@mkdir -p "misc/output"
# 	@echo "\n\033[1;33m\033[4;33mLaunching unit tests for abstract VM...\n\033[0m"
# 	@i=1; for d in misc/tests/* ; do \
# 		echo "$$i - Running test file \"$$d\":" ; \
# 		ruby $$d ; \
# 		i=$$(($$i+1)) ; \
# 		echo "" ; \
# 	done
# 	@echo "\033[1;33m\033[4;33mDone.\n\033[0m"

#------ make clean ------

clean:
	@echo $(YELLOW)"\t\t\t\tAVM"$(RESET)
	@rm -f $(FILES_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------

fclean:
	@echo $(YELLOW)"\t\t\t\tAVM"$(RESET)
	@rm -f $(FILES_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tavm have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all

