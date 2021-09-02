CC    =  gcc
CFLAGS  =   -Werror -Wall -Wextra
HEADER  =  cliserv.h
HEADER_BONUS = cliserv_bonus.h
CLIENT  =  client
CLIENT_BONUS  =  client_bonus
SERVER  =  server
SERVER_BONUS  =  server_bonus
SRC1  =  client.c ft_utils.c
SRC2  =  server.c ft_utils.c
SRC1_BONUS  =  client_bonus.c ft_utils_bonus.c
SRC2_BONUS  =  server_bonus.c ft_utils_bonus.c
OBJECTS1 =  $(SRC1:.c=.o)
OBJECTS2 =  $(SRC2:.c=.o)
OBJECTS1_BONUS =  $(SRC1_BONUS:.c=.o)
OBJECTS2_BONUS =  $(SRC2_BONUS:.c=.o)

all:	$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJECTS1) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS1) -I $(HEADER) -o $(CLIENT)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m CLIENT DONE ☆*:.｡.o(≧▽≦)o.｡.:*☆\033[0m"
	@echo ""

$(SERVER):	$(OBJECTS2) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS2) -I $(HEADER) -o $(SERVER)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m SERVER DONE (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\033[0m"
	@echo ""

bonus:	$(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJECTS1_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(OBJECTS1_BONUS) -I $(HEADER_BONUS) -o $(CLIENT_BONUS)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m BONUS CLIENT DONE ☆*:.｡.o(≧▽≦)o.｡.:*☆\033[0m"
	@echo ""

$(SERVER_BONUS): $(OBJECTS2_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(OBJECTS2_BONUS) -I $(HEADER_BONUS) -o $(SERVER_BONUS)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m BONUS SERVER DONE (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\033[0m"
	@echo ""

%.o:    %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $^ -o $@

clean:
	@rm -f $(OBJECTS1) $(OBJECTS2) $(OBJECTS1_BONUS) $(OBJECTS2_BONUS)

fclean:	clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re:	fclean all

.PHONY:	all clean fclean re bonus cli_bonus ser_bonus