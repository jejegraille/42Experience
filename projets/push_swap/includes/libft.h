/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:52:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/08 16:14:15 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <ft_printf.h>

# define ABS(x)	(x > 0 ? x : -x)

# define WARN  "\x1b[4m\x1b[31m/!\\\x1b[0m"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RST   "\x1B[0m"

# define FRED   "\x1B[41m"
# define FGRN   "\x1B[43m"
# define FYEL   "\x1B[42m"
# define FBLU   "\x1B[44m"
# define FMAG   "\x1B[45m"
# define FCYN   "\x1B[46m"
# define FWHT   "\x1B[47m"
# define FBLK   "\x1B[40m"

# define PRED(x)   ft_putstr("\x1B[31m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PGRN(x)   ft_putstr("\x1B[32m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PYEL(x)   ft_putstr("\x1B[33m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PBLU(x)   ft_putstr("\x1B[34m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PMAG(x)   ft_putstr("\x1B[35m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PCYN(x)   ft_putstr("\x1B[36m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PWHT(x)   ft_putstr("\x1B[37m");ft_putstr(x),ft_putstr("\x1B[0m");
# define PWARN     ft_putstr("\x1b[4m\x1b[31m/!\\\x1b[0m");

# define NL			ft_putchar('\n');
# define NBR(x)		ft_putnbr(x);
# define STR(x)		ft_putstr(x);
# define END(x)		ft_putendl(x);
# define CHAR(x)	ft_putchar(x);
# define TAB(x)		ft_putstrtab(x, '\n');
# define UINT_MAX 4294967295
# define BASE_HEX "0123456789ABCDEF"
# define BASE_DEC "0123456789"
# define BASE_OCT "01234567"
# define BASE_BIN "01"
# define BUFF_SIZE 666

typedef struct		s_fd
{
	char	*name;
	char	*path;
	char	*ts_a;
	char	*ts_m;
	char	*ts_c;
	int		ti_a;
	int		ti_m;
	int		ti_c;
	int		link;
	char	devma;
	char	devmi;
	char	*chmod;
	char	type;
	size_t	size;
	char	*usr;
	char	*grp;
	char	*lname;
	int		bsize;
	int		analysed;
}					t_fd;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_fdtable
{
	int			init;
	int			*state;
	int			*fd;
	int			*len;
	char		**data;
}					t_fdtable;

typedef struct		s_point
{
	double x;
	double y;
	double z;
}					t_point;

typedef struct		s_line
{
	double	a;
	double	b;
	double	c;
	t_point	pa;
	t_point	pb;
	double	l;
}					t_line;

typedef struct		s_tri
{
	t_point a;
	t_point b;
	t_point c;
}					t_tri;

int					ft_gnl(const int fd, char **line);
char				*ft_stronly(char *str, char *list);
size_t				ft_tablen(void **tab);
char				*ft_token_at(char *list, char separator, int index);
char				**ft_diretab(char *path, int path_format_boolean);
int					ft_filed(char *name, t_fd *filebuf);
char				*ft_str_charnoutrev(char const *s, char *l, size_t start);
char				*ft_strrev(char *str);
int					ft_recursive_power(int nb, int power);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dst, char const *src);
char				*ft_strncat(char *dst, char const *src, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *litle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_nbrlen(int nbr);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strisalnum(char *str);
void				*ft_memalloc(size_t len);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_ustrncmp(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_str_charout(char const *s, char *listc);
char				*ft_str_charnout(char const *s, char *listc, size_t start);
char				**ft_strsplit(char const *s1, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstrtab(char **tab, char separator);
void				ft_putstrtab_fd(char **tab, char separator, int fd);
t_list				*ft_lstcpy(t_list *list);
t_list				*ft_lstnew(const void *content, size_t size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				*ft_filetostr(char *filepath);
void				*ft_realloc(void **ptr, size_t buff);
char				*ft_newcat(char *str1, char *str2);
char				**ft_split(const char *str, const char *separator);
char				**ft_split_c(char const *s1, char *c);
int					ft_countchar(const char *s, char c);
void				ft_debug(int nb, int need);
int					ft_atoi_base(char *nbr, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *bas_to);
char				*ft_convert_ubase(char *nbr, char *base_from, char *bas_to);
unsigned int		ft_itounsigned(int n);
char				*ft_uitoa(unsigned int nbr);
char				*ft_ustoa(unsigned short nbr);
char				*ft_ulltoa(unsigned long long nbr);
char				*ft_ultoa(unsigned long nbr);
char				*ft_lltoa(long long nbr);
char				*ft_ltoa(long nbr);
char				*ft_ftoa(double nbr, size_t precision);
char				*ft_stoa(short nbr);
char				*ft_str_tolower(char *str);
char				*ft_str_toupper(char *str);
char				*ft_delwords(char *str, int nb);
void				swap_any(void **a, void **b);
int					ft_count_word(const char *s1, const char *s2);
double				mt_link(double min, double x, double max);
double				mt_angle(double xa, double ya, double xb, double yb);
double				mt_dtor(double degree);
double				mt_rtod(double rad);
double				mt_distance(double xa, double ya, double xb, double yb);
int					mt_rgba(int red, int green, int blue, int alpha);
int					mt_range(int min, int x, int max);
void				mt_point(double x, double y, double z, t_point *p);
void				mt_line(t_point a, t_point b, t_line *line);
void				mt_tri(t_point a, t_point b, t_point c, t_tri *tri);
char				**ft_tabsdup(char **tab);
void				ft_deltabs(char **tab);
void				ft_pushtabs(char ***tab, char *str);
void				ft_remtabs(char ***tab, size_t index);
void				ft_log(char *str, char *separator);
double				ft_rand(void);
void				ft_sorttabi(int *tab, int len, int dec);
#endif
