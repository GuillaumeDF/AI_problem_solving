CC			=	g++

CPPFLAGS	+=	-std=c++0x -I./include

RM			=	rm -f

NAME		=	ai

SRCS		=	source/Neighbours.cpp \
				source/Node.cpp \
				source/Puzzle.cpp \
				source/Solver.cpp \
				source/Ai.cpp \
				source/main.cpp

OBJS		=	$(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re