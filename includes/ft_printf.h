/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:41:35 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/29 23:04:20 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_field
{
	long	init_value;
	char	formspec;
	char	*value;
	size_t	size_value;
	int		size; //size of the whole field in the original format
	char	options;
	int		width;
	int		precision;
	char	length;
}				t_field;

typedef struct	s_func
{
	void	(*f)(t_field*, va_list);
	char	key;
}				t_func;

int				ft_printf(const char *restrict format, ...);

t_list			*build_list(const char *restrict format);
void			process_list(t_list *list, va_list ap);
void			print_list(t_list *list);

void			(*get_func(char c))(t_field *field, va_list ap);
void			spec_d(t_field *field, va_list ap);
void			spec_D(t_field *field, va_list ap);
void			spec_s(t_field *field, va_list ap);
void			spec_p(t_field *field, va_list ap);
void			spec_o(t_field *field, va_list ap);
void			spec_O(t_field *field, va_list ap);
void			spec_u(t_field *field, va_list ap);
void			spec_x(t_field *field, va_list ap);
void			spec_X(t_field *field, va_list ap);
void			spec_c(t_field *field, va_list ap);
void			spec_i(t_field *field, va_list ap);

char			get_options(const char *restrict *format);
int				get_width(const char *restrict *format);
int				get_precision(const char *restrict *format);
char			get_length(const char *restrict *format);
char			get_specif(const char *restrict *format);

char			*get_width_str(t_field *field);
void			option_0(t_field *field);
void			option_1(t_field *field);
void			option_2(t_field *field);
void			option_3(t_field *field);
void			option_4(t_field *field);

int				is_option(int c);
int				is_formspec(int c);
int				is_length(int c);
int				is_bit_on(int c, int offset);
char			cut_sign(t_field *field);

static t_func g_tab[] = 
{
	{spec_d, 'i'},
	{spec_D, 'D'},
	{spec_d, 'd'},
	{spec_s, 's'},
	{spec_p, 'p'},
	{spec_o, 'o'},
	{spec_O, 'O'},
	{spec_u, 'u'},
	{spec_x, 'x'},
	{spec_X, 'X'},
	{spec_c, 'c'},
	{NULL, -1}
};

#endif
