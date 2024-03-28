CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = -Llibft -lft

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

CLIENT_SRC_B = client_bonus.c
CLIENT_OBJ_B = $(CLIENT_SRC_B:.c=.o)

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

SERVER_SRC_B = server_bonus.c
SERVER_OBJ_B = $(SERVER_SRC_B:.c=.o)

OBJ_DIR = obj
OBJECT = $(addprefix $(OBJ_DIR)/, $(CLIENT_OBJ) $(SERVER_OBJ))
OBJECT_B = $(addprefix $(OBJ_DIR)/, $(CLIENT_OBJ_B) $(SERVER_OBJ_B))

NAME = make_mandatory
NAME_B = make_bonus

all : $(OBJ_DIR)/$(NAME)
	
bonus : $(OBJ_DIR)/$(NAME_B)

$(OBJ_DIR)/$(NAME) : $(OBJECT)
	@rm -f $(OBJ_DIR)/$(NAME_B)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(CLIENT_OBJ) -o client $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(SERVER_OBJ) -o server $(LIBFT)
	@touch $@

$(OBJ_DIR)/$(NAME_B) : $(OBJECT_B)
	@rm -f $(OBJ_DIR)/$(NAME)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(CLIENT_OBJ_B) -o client $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(SERVER_OBJ_B) -o server $(LIBFT)
	@touch $@
	
$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFALGS) -c $^ -o $@

clean :
	make -C ./libft clean
	rm -rf obj
	rm -f make_mandatory make_bonus

fclean : clean
	make -C ./libft fclean
	rm -r client server

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus