#include "op.h"
#include "../libftprintf/includes/libftprintf.h"
#include "../libftprintf/libft/includes/libft.h"
#include "../libftprintf/libft/includes/get_next_line.h"
#include <fcntl.h>

typedef struct  s_asm
{
  int           fd_s;
  int           fd_cor;
}               t_asm;


void	convert_to_hex(header_t *header, t_asm *env);
