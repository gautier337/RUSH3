##
## EPITECH PROJECT, 2023
## Makefile for MyGKrellM
## File description:
## Makefile
##

NAME                =           myGKrellM
TEST_NAME           =           unit_tests

SRC_MAIN            =           main.cpp

SRC                 =           graphics/modules/NCurses.cpp                 \
								graphics/modules/SFML.cpp                    \
								modules/date_hours/ModuleDate.cpp			 \
								modules/host/ModuleHost.cpp                  \
								modules/AModule.cpp                          \
								modules/kernel/ModuleKernel.cpp              \
								modules/processor/ModuleCpu.cpp              \
								modules/network/ModuleNetwork.cpp            \
								modules/ram/ModuleRam.cpp                    \
								modules/user/ModuleUser.cpp                  \
								modules/Core.cpp					   	 	 \
								modules/pid/ModulePid.cpp                    \
								tools/FileHandler.cpp						 \
								CheckEnv.cpp                                 \
								MyGKrellm.cpp                                \

SRC_CSFML           =           $(addprefix graphics/sfml/,                  \
								clock.cpp                                    \
								init.cpp                                     \
								ProgressBar.cpp                              \
								shape.cpp                                    \
								text.cpp                                     \
								window.cpp)

OBJ                 =           $(SRC:.cpp=.o) $(SRC_CSFML:.cpp=.o)
OBJ_MAIN            =           $(SRC_MAIN:.cpp=.o)
OBJ_TESTS           =           $(SRC_TESTS:.cpp=.o)

CFLAGS              +=          -Wall -Wextra -Werror -std=c++2a
LDFLAGS             =           -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CRITERION           =           --coverage -lcriterion

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	@echo -e "$(GREEN)[OK]$(RESET)" "Compilation of $(NAME)"
	@g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

tests_run: $(OBJ) $(OBJ_TESTS)
	@echo -e "$(GREEN)[OK]$(RESET)" "Compilation of $(TEST_NAME)"
	@g++ -o $(TEST_NAME) $(OBJ) $(OBJ_TESTS) $(CRITERION)
	@./$(TEST_NAME)

clean:
	@echo -e "$(RED)[OK]$(RESET)" "Cleaning of $(NAME)"
	@rm -f $(OBJ) $(OBJ_MAIN) $(OBJ_TESTS)
	@rm -f *.gcda *.gcno

fclean: clean
	@echo -e "$(RED)[OK]$(RESET)" "Full cleaning of $(NAME)"
	@rm -f $(NAME) $(TEST_NAME)

fast: fclean
	@make -j
	@make clean
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re tests_run
