/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 01:03:03 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/09 00:00:06 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <wchar.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define ABS(x) (x < 0) ? -x : x

/*
** Simple linked list, and double linked list
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*before;
	struct s_dlist	*next;
}					t_dlist;

/*
** Affichages
*/
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putaddr(void *ptr);
void				ft_putchar(char c);
void				ft_putnbr(int n);

/*
** Write fd
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Traitements et conditions alphanumeriques
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_islower(int c);

/*
** Memory
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t old, size_t size);
void				ft_memdel(void **ap);

/*
** Itoa & Atoi functions
*/
int					ft_atoi(const char *s);
char				*ft_itoa(int n);
char				*ft_llitoa(long long int nb);
char				*ft_ullitoa(unsigned long long nb);

/*
**	Manipulation de chaine de caracteres
*/
int					ft_intlen(int nb);
size_t				ft_strlen(const char *s);
size_t				ft_strclen(char const *s, char c);
int					ft_charcount(const char *str, char c);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcasecmp(const char *s1, const char *s2);
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
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strrev(char *s);
char				*ft_strchrstr(const char *s1, const char *s2);

/*
** Listes chainees
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstadd_i(t_list **list, t_list *lst_new, unsigned int n);
int					ft_lstlen(t_list *list);
t_list				*ft_lstati(t_list *lst, unsigned int i);
t_list				*ft_lstlast(t_list *list);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_printlist(t_list *list, char sep);

/*
** Double liste chainees
*/
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlstadd_end(t_dlist **alst, t_dlist *new);
void				ft_dlstadd_i(t_dlist **list,
	t_dlist *lst_new, unsigned int n);
int					ft_dlstlen(t_dlist *list);
t_dlist				*ft_dlstati(t_dlist *list, unsigned int i);
t_dlist				*ft_dlstlast(t_dlist *list);
t_dlist				*ft_dlstfirst(t_dlist *list);
void				ft_dlst_insert(t_dlist **list, t_dlist *to_ins);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_printdlist(t_dlist *list, char sep);
void				ft_dlstrev(t_dlist **list);
void				ft_swap_contents(t_dlist **list1, t_dlist **list2);

/*
** Double listes chainees circulaires
*/
t_dlist				*ft_dlstcnew(void const *content, size_t content_size);
void				ft_dlstcadd(t_dlist *root, t_dlist *new);
void				ft_dlstcpop(t_dlist *node, t_dlist *new);
void				ft_dlstcpush(t_dlist *node, t_dlist *new);
t_dlist				*ft_dlstcfirst(t_dlist *root);
t_dlist				*ft_dlstclast(t_dlist *root);
void				ft_dlstcclear(t_dlist *list);
void				ft_dlstcdel_one(t_dlist *node);
void				ft_dlstcdel(t_dlist **list);

/*
**	Wchar_t functions
*/
void				ft_putwchar(wint_t c);
void				ft_putwcs(const wchar_t *str);
size_t				ft_wcslen(const wchar_t *str);
wchar_t				*ft_wcscat(wchar_t *s1, const wchar_t *s2);
wchar_t				*ft_wcsdup(const wchar_t *s1);
wchar_t				*ft_wcscpy(wchar_t *dst, const wchar_t *src);
int					ft_wcsequ(wchar_t const *s1, wchar_t const *s2);

/*
** Misc ..
*/
char				*ft_rotn(char const *str, int n);
int					ft_rand_a_b(int a, int b);
void				ft_putnchar(char c, int n);

#endif
