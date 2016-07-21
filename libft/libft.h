/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:25:30 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:33:24 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <libc.h>
# include <string.h>
# define BUFF_SIZE 1
# define L_LEN 50
# define SPILL_MULT	2
# define MAX_FD	1000
# define NUM_FILES 10
# define MAX_BUFF 800000

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_buff
{
	char			buff[BUFF_SIZE];
	int				buf_pos;
	int				buf_init;
	int				eof;
}				t_buff;

typedef struct		s_stock
{
    char			*spill;
    long			length;
    long			lu;
    int				read_ret;
    char			*line_end;
}					t_stock;


typedef struct	s_mod
{
    int		hash;
    int		pre;
    int		zero;
    int		neg;
    int		pos;
    int		width;
    int		space;
    int		hh;
    int		h;
    int		l;
    int		ll;
    int		j;
    int		z;
}				t_mod;

int					ft_atoi_base(const char *str, int base);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *const dst, const void *const src,
								size_t n);
void				*ft_memccpy (void *const dst, const void *const src, int c,
								size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *const s1, const char *const s2);
char				*ft_strncat(char *const s1, const char *const s2, size_t n);
size_t				ft_strlcat(char *const dst, const char *const src,
								size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_ishex(char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isspace(int c);
int					get_next_line(const int fd, char **line);
int					ft_newword(const char *s, unsigned int i, char del);
int					ft_wordlen(const char *s, int start, char del);
int					ft_numwords(char const *s, char c);
int					ft_picklencon(va_list vl, int c, t_mod mod);
int					ft_prepconvert(int num, int base, int c, t_mod *mod);
void				ft_stringformatwide(wchar_t *s, t_mod *mod);
size_t				ft_strlenwide(wchar_t *str);
void				ft_padwide(wchar_t *s, t_mod *mod, int *chrc);
void				ft_putstrwide(wchar_t *s);
int					ft_printwstring(va_list vl, t_mod mod);
int					ft_lookflag(char *ft, int *chrc);
int					ft_printchar(va_list vl, t_mod mod);
void				ft_stringformat(char *s, t_mod *mod);
void				ft_printnum(char *s, t_mod *mod, int *chrc, int c);
void				ft_incramentmod(t_mod *mod);
void				ft_padwidth(t_mod *mod, int *chrc, int c);
void				ft_addlenmod(int c, t_mod *mod);
char				*ft_findflag(char *s, int *chrc, va_list vl);
void				ft_free_str_arr(char **arr);
int					ft_isflagup(int c, int *chrc, va_list vl, t_mod *mod);
int					ft_isflaglo(int c, int *chrc, va_list vl, t_mod mod);
void				ft_addmod(char c, t_mod *mod);
void				ft_formmod(char c, t_mod *mod);
void				ft_initmod(t_mod *mod);
int					ft_printf(const char *format, ...);
int					ft_pickconvert(va_list vl, int c, t_mod mod);
int					ft_unconvert(uintmax_t n, int base, int c, t_mod *mod);
char				*ft_convert(int num, int base, t_mod *mod);
void				ft_nummoders(t_mod *mod, int *chrc, int c);
int					ft_printstring(va_list vl, t_mod mod);
void				ft_pad(char *s, t_mod *mod, int *chrc);
uintmax_t			ft_oxulenmod(t_mod *mod, va_list vl);
uintmax_t			ft_lenmod(t_mod *mod, va_list vl, int c);
int					ft_checklenmod(t_mod *mod);
int					ft_power(int num, int p);
void				ft_posmod(t_mod *mod, int *chrc, int c);
void				ft_spacemod(t_mod *mod, int *chrc);
void				ft_hashmod(t_mod *mod, int *chrc, int c);
char				*ft_getnum(char *s, t_mod *mod);

#endif
