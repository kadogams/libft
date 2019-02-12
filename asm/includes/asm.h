#include "op.h"
#include "libftprintf.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

#define UPDATE_X 1
#define NO_UPDATE_X 0

typedef struct  s_asm
{
	int			cur_x;
	int			cur_y;
	int			fd_s;
	int			fd_cor;
	char		*output;
	char		*line;
}               t_asm;

int		init_env(t_asm *env);
int		skip_whitespace(char *str, t_asm *env, int update);
int		check_last_line(char *line, int option, t_asm *env);
int		skip_blank_lines(t_asm *env);
int 	start_parsing(header_t *header, t_asm *env);
void	quit(t_asm *env);
