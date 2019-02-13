#include "op.h"
#include "libftprintf.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

#define UPDATE_X 1
#define NO_UPDATE_X 0

typedef struct	s_asm
{
	int				cur_x;
	int				cur_y;
	int				fd_s;
	int				fd_cor;
	char			*output;
	char			*line;
	unsigned char	code[CHAMP_MAX_SIZE + 1];
	int				index;
	struct s_label	*label;
	struct s_zjump	*zjump;
}               t_asm;

opcode
params
unsigned char octet de codage = 0;


typedef struct		s_label
{
	char			*name;
	int				index;
	struct s_label	*next;
}

typedef struct		s_zjump
{
	char			*label_name;
	int				index;
	struct s_zjump	*next;
}					t_jump;

typedef struct		s_op
{
	char			*opcode;
	int				(*ptr_fct)(t_asm *env);
}					t_op;

static const t_op	g_op[] = {
	{"live", ft_live},
	{"ld", ft_ld},
	{"st", ft_st},
	{"add", ft_add},
	{"sub", ft_sub},
	{"and", ft_and},
	{"or", ft_or},
	{"xor", ft_xor},
	{"zjmp", ft_zjmp},
	{"ldi", ft_ldi},
	{"sti", ft_sti},
	{"fork", ft_fork},
	{"lld", ft_lld},
	{"lldi", ft_lldi},
	{"lfork", ft_lfork},
	{"aff", ft_aff},
};
int		init_env(t_asm *env);
int		skip_whitespace(char *str, t_asm *env, int update);
int		check_last_line(char *line, int option, t_asm *env);
int		skip_blank_lines(t_asm *env);
int 	start_parsing(header_t *header, t_asm *env);

int		parse_instructions(t_asm *env);


void	quit(t_asm *env);
