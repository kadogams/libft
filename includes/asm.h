#include "op.h"
#include "../libftprintf/includes/libftprintf.h"
#include "../libftprintf/libft/includes/libft.h"
#include "../libftprintf/libft/includes/get_next_line.h"
#include <fcntl.h>

typedef struct  s_asm
{
	int			fd_s;
	int			fd_cor;
	int			read_name;
	int			read_comment;
	char		*output;
}               t_asm;

int		init_env(t_asm *env);
int		skip_whitespace(char *str);
void	start_parsing(header_t *header, t_asm *env);
void	quit(char **str);
