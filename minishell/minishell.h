/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:11 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/26 16:56:18 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include "utils/utils.h"
# include <wait.h>
# include <signal.h>
# include "globals/global.h"


typedef struct s_program
{
	// prgorgam
	int		exit_code;
	char	**env;
	char	**mtx_line;
	char	*curr_dir;
	char	*pwd;
	char	*home_path;
	char	*old_pwd;

	// utils
	int		i;
	int		j;
	int		k;
	int		i_p;
	int		num_hd;
	int		words;
	int		len;
	int		flag;
	int		nflag;
	int		equal;
	int		output;
	int		input;
	int		fd[2];
	int		flag_builtin;
	int		num_cmd;
	int		*in;
	int		*out;
	char	*tmp;
	int		fork_id;
	int		num_fd;
	int		flag_in_operator;
	// int		exec_dollar_fd;

}	t_program;



// global
// int	signal_flag = 0;




// builtin_command_1.c
int		ft_pwd();
int		ft_env(t_program *shell);
void	ft_exit(t_program *shell);
char	*expansion_variable(char *old_str, t_program *shell);
int		is_there_an_equal(char *str);
void	ft_unset(t_program *shell);

// builtin_command_2.c
void	ft_cd(t_program *shell);

// close.c
void	close_in_out(int *fd, int k, int flag);
void	close_fds(int *fd, int flag, int input);
void	close_all_files(int *fd, int output, int input);

// commands_hub.c
int		check_commands(char *cmd, t_program *shell, int k, char ***mtx_hub);
int		check_builtin(char *cmd, t_program *shell);
int		exec_non_builtin(t_program *shell, int index, char ***mtx_hub);
char	*getpath(char **envp);
char	*path_find(char **envp, char *command);
char	**get_full_cmd(t_program *shell);

// count_words.c
int		count_words(char *str, t_program *shell);
int		isvalid(char *str, int i);
void	count_char(char *str, t_program *shell, int *words, int *flag);
void	count_quotes(char *str, t_program *shell, int *words);
void	count_operators(char *str, t_program *shell, int *words);

// fork.c
int		child(t_program *shell, int i, int pipe_cmd, char ***mtx_hub);
int		open_files_in_child(t_program *shell, int i, char ***mtx_hub);
void    redirect_in_out_child(t_program *shell, int pipe_cmd, char *path);
void	father(t_program *shell, int j);

// exec.c
int		exec(t_program *shell);
int		exec_core(t_program *shell, int j, int num_cmd, char ***mtx_hub);
int		exec_one_command(t_program *shell, int i, char ***mtx_hub);
int		exec_more_commands(t_program *shell, int j, int i, char ***mtx_hub);
int		count_commands(char **mtx_line, t_program *shell);

// exec_utils.c
char	***alloc_mtx(int num_commands, t_program *shell);
void	alloc_mtx_core(t_program *shell, char ***mtx_hub);
void	free_matrix_pointer(char ***mtx_hub);

// ft_cd_utils_1.c
void	env_refresh_dir(t_program *shell);
void	refresh_directory(char *path, t_program *shell, int flag);
char	*format_str(char *old_str);
int		only_backslash(char *str);
int		count_backs(char *str, t_program *shell);

// ft_cd_utils_2.c
void	cd_no_char(char *str, t_program *shell);
int		no_char(char *str);
void	only_cd(t_program *shell);
void	cd_root(t_program *shell);
char	*cd_back(t_program *shell);

// ft_cd_utils_3.c
int		cd_absolute_path(char *str, t_program *shell);
int		cd_relative_path(char *str, t_program *shell);
int		relative_path_core(char *str, int *i, t_program *shell, char *sv);
int		relative_back_slash(char *str, t_program *shell, int i, int j);
void	end_relative_cd(t_program *shell, char *path);


// ft_echo.c
void	ft_echo(t_program *shell);
void	ft_echo_core(t_program *shell, char *str2, int *i, int len);

// ft_echo_utils.c
char	*remove_external_quotes(char *old_str, char q);
char	*remove_external_quotes_core(char *old_str, int c_l, int c_r, int i);
int		count_args(char **mtx, int i);
int		check_nflag(char *str, t_program *shell);
int		check_dollar(char *str);


// ft_export.c
void	ft_export(t_program *shell);
int		export_cicle(char *str);
int		exist_in_env(char *str, t_program *shell);
void	print_export_env(t_program *shell, int i, int j);
void	export_core(t_program *shell, int value, int i, char *str);

// ft_export_utils_1.c
int		is_there_in_env(t_program *shell, int len, char *str, int *flag);
int		replace(t_program *shell, int len, char *dup);
char	*remove_plus(char *old_str);
void	change_export_value(t_program *shell, int i, int value, char *str);
int		realloc_env(t_program *shell, char *str);

// ft_export_utils_2.c
int		only_export(t_program *shell);
int		export_parsing(t_program *shell);
int		export_parsing_2(t_program *shell, char *str);
int		export_parsing_quote(char *str);
int		export_quote(char *str, int *i, char q1, char q2);

//	ft_unset_utils.c

// ft_unset.c
void	ft_unset(t_program *shell);
char	*search_env_and_allocate(char *env_str, t_program *shell);
char	*expansion_variable(char *old_str, t_program *shell);
char	*split_dollar(char *old_str, t_program *shell);

// here_doc.c
int		open_here_doc(t_program *shell, char **mtx);
void	write_in_file(int fd, char *limiter, t_program *shell);
int		write_in_file_check(char **str, int *flag, t_program *shell, char *limiter);
void	close_here_doc(t_program *shell);
int		open_here_doc_core(int *i, char **file, int *num_hd);

// here_doc_utils.c
void	set_hd_g_signals(int flag);


// expansion_in_hd.c
void	exec_dollar(char *str, t_program *shell, int fd);
int		exec_dollar_core(char *str, t_program *shell, int fd, int *i);
int		exec_dollar_core_2(t_program *shell, char *str, int fd, int *i);
void	search_env(char *env_str, t_program *shell, int fd);

// main_utils.c
char	*print_directory(t_program *shell);
int		initialize(t_program *shell);
void	free_all(t_program *shell, int flag);

// main.c
int		main_core(t_program *shell);
int		open_here_doc(t_program *shell, char **mtx);
int		readline_core(t_program *shell, char **str);

// matrix_utils.c
void	print_matrix(char **matrix);
int		matrix_len(char **matrix);
void	free_matrix(char **matrix);
void	free_matrix_len(char **matrix, int len);
char	**matrix_dup(char **old_mtx);

// manage_in_out.c
int		counter_in_out(char c, char **mtx);
char	**realloc_without_redir(char **mtx, int k, char c);
int		open_files_out(char **mtx, t_program *shell);
int		redir_output(t_program *shell, int k, int i, char ***mtx_hub);
// manage_input.c
int		redir_input(t_program *shell, int i, char ***mtx_hub, int flag);
int		open_files_in(char **mtx, t_program *shell);
int		open_file_in_hd(int *i, int *j, int *num_hd, int *shell_in);
int 	open_file_in_fd(int *i, int *j, char **mtx, t_program *shell);
void	initialize_files_in(int *i, int *j, int *num_hd, int flag);

// manage_output.c
int	double_redirection(int *i, int *j, char **mtx, int *shell_out);
int	single_redirection(int *i, int *j, char **mtx, int *shell_out);


// matrix_handler.c
int		matrix_handler(char *str, t_program *shell);
int		matrix_handler_core(char *str, t_program *shell, int *i, int *j);
int		quotes_in_word(char *str, int *i);
void	operators_core(char *str, t_program *shell, int *i, int *j);
int		operators_allocation(char *str, t_program *shell, int i, int j);

//parsing_checks.c
int		only_operator(char *str);
int		near_operators(char *str);
int		double_operators(char *str);
int		check_operators(char *str, t_program *shell);
int		check_quotes(char *str);

// parsing_utils.c
char	*remove_internal_quotes(char *old_str);
char	*remove_internal_quotes_core(char *old_str, int i, int *j);
char	*remove_all_quotes(char *old_str);
char	*remove_all_quotes_core(char *old_str, int i, int j);

// parsing.c
int		parsing(char *str, t_program *shell);
char	**realloc_mtx_parsing(char **old_mtx, int k);
int		print_parsing_errors(int flag, t_program *shell);
int		only_dollar(char *str);
char	*expansion_variable2(char *old_str);

// quotes_core.c
int		quotes_core(char *str, t_program *shell, int *i_p);
int		double_quote(char *str, t_program *shell);
int		single_quote(char *str, t_program *shell);
int		alloc_quote(t_program *shell, int flag, char *str, char q);

// g_signals.c
void	sig_handler_child(int sig);
void	sig_handler(int sig);
void	sig_handler_hd(int sig);

#endif
