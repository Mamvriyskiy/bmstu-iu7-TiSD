FLAGS := -std=c99 -Iinc -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -pedantic

OBJ_DIR := ./out
SRC_DIR := ./src
INC_DIR := ./inc

$(shell mkdir -p ./out)
SRC := $(wildcard $(SRC_DIR)/*.c)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
APP := app.exe

$(APP) : $(OBJ)
	gcc $(OBJ) -o $@


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC)
	gcc $(FLAGS) -c $< -o $@

.PHONY : clean start

clean :
	rm -rf *.exe ./out *.out

start : $(APP)
	./$(APP)