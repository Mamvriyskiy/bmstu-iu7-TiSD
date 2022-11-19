CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -pedantic

SRC_DIR := ./src
INC_DIR := ./inc
OBJ_DIR := ./out

SRC := $(wildcard $(SRC_DIR)/*.c)
INC := $(wildcard $(INC_DIR)/*.h)

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
INC_HD := -I$(INC_DIR)

APP = app.exe

$(APP) : $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) -c $< -o $@

.PHONY : clean

clean:
	rm -rf $(OBJ_DIR) *.exe *.txt *.out;