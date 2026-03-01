.PHONY : all clean fclean re bonus clean-lib clean-bin clean-obj debug debug-CC debug-print test doc
CC := cc
CCFLAGS = -Wall -Wextra -Werror -Ofast -pg -g3
DEPENDANCIES = -MMD -MP
NO_DIR = --no-print-directory
MAKE := $(MAKE) -j $(NO_DIR)
NAME = hotrace

# Debugging flags
CCFLAGS_DEBUG = -Wall -Wextra -g3
CC_DEBUG = clang
CC_DEBUG_CCFLAGS = -g3 -Weverything -Wno-padded -pedantic -O2
# Uncomment the following line to enable debug messages during compilation
DEBUG ?= 1
#############################################################################################
#                                                                                           #
#                                         DIRECTORIES                                       #
#                                                                                           #
#############################################################################################
# Source directories
P_SRC = src/

P_OBJ = .obj/
P_DEPS = .obj/

P_INC = inc/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################
# Headers
INC = \
	hotrace.h \
	get_next_line.h \

# Source files
SRC = \
	main.c \
	hotrace.c \
	hash.c \
	hash_strategy.c \
	get_next_line.c \
	ft_strjoin.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_memset.c \
	ft_memcpy.c \
	garbage.c \
	garbage_utils.c \
	garbage_stack.c \

LIBS = \

#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS = \
	$(addprefix $(P_SRC), $(SRC)) \

# List of object files (redirect to P_OBJ)
OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o))
P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS))

# List of depedencies
DEPS = $(subst $(P_OBJ), $(P_DEPS), $(OBJS:%.o=%.d))

# List of header files
INCS = \
	$(addprefix $(P_INC), $(INC)) \
	$(addprefix $(P_INC)$(P_CMDS), $(INC_CMDS)) \

# 	$(addprefix $(P_INC), $(TPP))

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all: 
	@$(MAKE) $(NAME)

# Create $(NAME) executable
$(NAME): $(OBJS) $(INCS)
	$(eval COMPILE_CMD = $(CC) $(CCFLAGS) $(DEPENDANCIES) -I $(P_INC) -o $(NAME) $(OBJS) $(LIBS))
	@if $(COMPILE_CMD); then \
		echo "$(Green)Creating executable $@$(Color_Off)"; \
		$(if $(DEBUG), echo "  Command: $(COMPILE_CMD)";) \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
		$(if $(DEBUG), echo "  Failed command: $(COMPILE_CMD)";) \
	fi

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c $(INCS)
	@mkdir -p $(dir $@)
	$(eval COMPILE_CMD = $(CC) $(CCFLAGS) $(DEPENDANCIES) -I $(P_INC) -c $< -o $@)
	@if $(COMPILE_CMD); then \
		echo "$(Cyan)Compiling $<$(Color_Off)"; \
		$(if $(DEBUG), echo "  Command: $(COMPILE_CMD)";) \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
		$(if $(DEBUG), echo "  Failed command: $(COMPILE_CMD)";) \
	fi

#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	rm -rfd $(P_OBJ)
	rm -rfd $(P_DEPS)

clean-lib:
	rm -rfd $(P_LIB)

clean-bin:
	rm -f $(NAME)

clean-obj:
	@$(MAKE) clean

fclean:
	@$(MAKE) clean-obj
	@$(MAKE) clean-bin

re:
	@$(MAKE) fclean
	@$(MAKE) all

CLIENTS ?= 1000
LEAKS ?= 0
STRESS ?= 0
LOG ?= 0
BEH ?= 0
#PORT?=6667

test:
ifeq ($(LEAKS),1)
	$(MAKE) fclean
	@$(MAKE) $(NAME) CCFLAGS="$(CCFLAGS_DEBUG) -D USE_TESTER=1"
else
	@$(MAKE) $(NAME)
endif
	./tests/run.sh $(CLIENTS) $(LEAKS) $(STRESS) $(LOG) $(BEH)

doc: 
	$(MAKE) doc-clean
	cd tests/irc_tester && cargo doc --no-deps --target-dir ../../docs/irc_tester
	cd bonus/bot && cargo doc --no-deps --target-dir ../../docs/bot

doc-full:
	$(MAKE) doc-clean
	cd tests/irc_tester && cargo doc --target-dir ../../docs/irc_tester
	cd bonus/bot && cargo doc --target-dir ../../docs/bot

doc-clean:
	rm -rf docs/irc_tester
	rm -rf docs/bot

bonus: 
	./bonus/run_bot.sh

# Aliases
clear: clean
fclear: fclean
fclena: fclean
flcean: fclean
flcear: fclean

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging rules
debug:
	@$(MAKE) $(NAME) CCFLAGS="$(CCFLAGS_DEBUG)"

debug-cc:
	@$(MAKE) $(NAME) CCFLAGS="$(CC_DEBUG_CCFLAGS)" CC="$(CC_DEBUG)" Cyan="$(Yellow)" Green="$(Purple)"

# Debugging print
debug-print:
	@$(MAKE) debug-print-project

debug-print-separator:
	@echo ""
	@echo "$(On_Yellow)____________________$(Color_Off)"
	@echo ""

define check_var
	@if [ "$(strip $(1))" = "" ]; then \
		echo "$(Red)No $(2) found$(Color_Off)"; \
	else \
		echo "$(Red)$(2): \n\t$(Blue)$(1)$(Color_Off)"; \
	fi
endef

debug-print-project:
	$(call check_var,$(NAME),"Project")
	$(call check_var,$(SRCS),"SRCS")
	$(call check_var,$(OBJS),"OBJS")
	$(call check_var,$(INCS),"INCS")
	$(call check_var,$(LIBS),"LIBS")

#############################################################################################
#                                                                                           #
#                                         COSMETIC                                          #
#                                                                                           #
#############################################################################################
# Reset
Color_Off=\033[0m       # Text Reset

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

-include $(DEPS)% 

.PHONY: all clean clean-lib clean-bin clean-obj fclean re test debug debug-print-project debug-print debug-print-separator debug-CC 
