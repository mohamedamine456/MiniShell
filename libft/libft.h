
#ifndef LIBFT_H
# define LIBFT_H
# define SEPARATORS " ><|\t"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include "../parse/cmd.h"
int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
char            *ft_itoa(long number);
void			ft_putnbr(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isspace(char c);
int				ft_isalnum(int c);
int				ft_putchar(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isseparator(int c);
int				ft_isescape(char c);
int				ft_isenv(char *env);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strstri(const char *haystack, const char *needle);
int				ft_char_in_string(char c, char *str);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_free_args(char **args);
int				ft_size_args(char **tab);
int				ft_next_space(char *str);
int				ft_next_separator(char *str);
char			*ft_remove_spaces(char *str);
char			**ft_split_white_spaces(char *str);
t_escapes		ft_check_escapes(t_escapes escp, char c);
int				ft_char_to_func(char c);
int				ft_str_in_args(char *str, char **args);
char			**ft_resize_tab(char **old, char *chaine);
void			ft_print_args(char **args);
int				ft_isoutput(char *str);
int				ft_isinput(char c);
int				ft_is_string(char *str);
int				ft_ispipe(char *str);
char			**ft_strjoin_args(char **tab, char *str);
char			*search_env(char *str, char **envp);
int				ft_only_digits(char *str);
int				ft_strlen_tab(char **tab);
char			**ft_strjoin_tables(char **str1, char **str2);
char			**ft_jointabstr(char **tab, char *str);
void			sort_strings(char **tab);
char			**ft_tabdup(char **tab);
char			**ft_dup_env(char **envp);

#endif
