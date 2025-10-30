/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:10 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 11:54:52 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

# define BASE10 "0123456789"
# define BASE16L "0123456789abcdef0x"
# define BASE16U "0123456789ABCDEF0X"

# define ATRIBUTES "# 0+-"
# define ATRIBUTESLEN 6
# define FLAGS "cspdiuxX%fq"

typedef enum e_prnt_flag
{
	F_TAG,
	F_SPACE,
	F_ZERO,
	F_PLUS,
	F_MINUS,
	F_POINT,
	F_CHAR,
	F_STRING,
	F_POINTER,
	F_DECIMAL,
	F_INT,
	F_UNSIGNED,
	F_HEXAL,
	F_HEXAU,
	F_PERCENT,
	F_FLOAT,
	F_NONE
}				t_prnt_flag;

typedef struct s_pflag
{
	t_prnt_flag	flag;
	int			atributs[ATRIBUTESLEN];
	int			min;
}				t_pflag;

typedef struct s_nbrbase
{
	char		*str;
	int			len;
}				t_nbrbase;

typedef struct s_ltoainfo
{
	t_nbrbase	base;
	char		sign;
	int			zeros;
	int			zeronbr;
	char		*prefix;
}				t_ltoainfo;

typedef struct s_pdata
{
	int			last;
	int			next;
	int			count;
	char		*str;
	int			strlen;
}				t_pdata;

int				printf_error_free(t_pdata data);

char			*ft_lltoa_base(long long n, t_ltoainfo info, int *strlen);
char			*ft_ultoa_base(unsigned long n, t_ltoainfo info, int *strlen);
char			*ft_ftoa(double nbr, t_ltoainfo info, int *strlen);

char			*ft_strfreejoin(const char *s1, const char *s2, int free1,
					int free2);
char			*justifytxt(char *str, int reverse, int len, int *strlen);
int				m_atoi(char **str);

char			*convertnbr(va_list ap, t_pflag ptype, int *len);
char			*convertpointer(va_list ap, t_pflag ptype, int *len);
char			*converthexa(long long nbr, t_nbrbase base, t_pflag ptype,
					int *len);
char			*convertchar(char c, int *len);
char			*convertstr(va_list ap, t_pflag ptype, int *len);
char			*convertfloat(double nbr, t_pflag ptype, int *len);

/**
** @brief Prints a formatted string to the standard output using a variable
** argument list.
**
** This function is similar to printf, but it takes a va_list
** argument instead of a variable number of arguments.
**
** @param format The format string that specifies how subsequent
** arguments are converted for output.
** @param ap A va_list that contains the variable arguments to be
** formatted and printed.
**
** @return The number of characters printed (excluding the null byte
** used to end output to strings).
*/
int				ft_vprintf(const char *format, va_list ap);

/**
** @brief Prints a formatted string to the standard output using a variable
** argument list.
**
** This function is similar to printf, but it takes a va_list
** argument instead of a variable number of arguments.
**
** @param fd The fd to print to.
** @param format The format string that specifies how subsequent
** arguments are converted for output.
** @param ap A va_list that contains the variable arguments to be
** formatted and printed.
**
** @return The number of characters printed (excluding the null byte
** used to end output to strings).
*/
int				ft_vdprintf(int fd, const char *format, va_list ap);

/**
** @brief Produces output according to a format.
**
** This function sends formatted output to stdout, using the format string
** specified. The format string can contain format specifiers that are
** replaced by the values of the additional arguments, formatted as requested.
**
** @param format A null-terminated string containing the format specifiers.
**               The format specifiers follow the same specifications as the
**               standard printf function.
** @param ...    Additional arguments specifying the data to be printed
**               according to the format specifiers.
**
** @return The number of characters printed (excluding the null byte used to
**         end output to strings), or a negative value if an output error occurs.
*/
int				ft_printf(const char *format, ...);

/**
** @brief Produces output according to a format.
**
** This function sends formatted output to stdout, using the format string
** specified. The format string can contain format specifiers that are
** replaced by the values of the additional arguments, formatted as requested.
**
** @param fd The fd to print to.
** @param format A null-terminated string containing the format specifiers.
**               The format specifiers follow the same specifications as the
**               standard printf function.
** @param ...    Additional arguments specifying the data to be printed
**               according to the format specifiers.
**
** @return The number of characters printed (excluding the null byte used to
**         end output to strings), or a negative value if an output error occurs.
*/
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vsnprintf(char *str, size_t size, const char *format,
					va_list ap);
int				ft_snprintf(char *str, size_t size, const char *format, ...);



#endif
