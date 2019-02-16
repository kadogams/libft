#include "op.h"
#include "libftprintf.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

#define UPDATE_X 1
#define NO_UPDATE_X 0
#define INSTR_SIZE 4

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

/*opcode
params
unsigned char octet de codage = 0;*/

typedef struct		s_arg
{
	int				nb_arg;
	int				value[3];
	int				type[3];
}					t_arg;

typedef struct		s_label
{
	char			*name;
	int				index;
	struct s_label	*next;
}					t_label;

typedef struct		s_zjump
{
	char			*label_name;
	int				index;
	struct s_zjump	*next;
}					t_jump;

typedef struct		s_op
{
	char			*opcode;
	int				size;
	int				(*ptr_fct)(t_asm *env, int i);
}					t_op;


int		init_env(t_asm *env);
int		skip_whitespace(char *str, t_asm *env, int update);
int		check_last_line(char *line, int option, t_asm *env);
int		check_space_digit(char *line, t_asm *env);
int		skip_blank_lines(t_asm *env);
int 	start_parsing(header_t *header, t_asm *env);
void	init_arg(t_arg *arg);
int		handle_arg(t_asm *env, t_arg *arg, int i, char *line);
void	fill_code(t_asm *env, int type, int value, int octet);
int		parse_instructions(t_asm *env);

int		ft_live(t_asm *env, int i);
int		ft_ld(t_asm *env, int i);
int		ft_st(t_asm *env, int i);
int		ft_add(t_asm *env, int i);
int		ft_sub(t_asm *env, int i);

static const t_op	g_op[] = {
	{"live", 4, ft_live},
	{"ld", 2, ft_ld},
	{"st", 2, ft_st},
	{"add", 3, ft_add},
	{"sub", 3, ft_sub}
	/*{"and", 3, ft_and},
	{"or", 2, ft_or},
	{"xor", 3, ft_xor},
	{"zjmp", 4, ft_zjmp},
	{"ldi", 3, ft_ldi},
	{"sti", 3, ft_sti},
	{"fork", 4, ft_fork},
	{"lld", 3, ft_lld},
	{"lldi", 4, ft_lldi},
	{"lfork", 5, ft_lfork},
	{"aff", 3, ft_aff},*/
};

void	quit(t_asm *env);
