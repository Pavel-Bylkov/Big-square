#ifndef BSQ_HEAD_H
# define BSQ_HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

char	*check_valid(char *argv, int *lib);
void	check_symbol_map(char *buff, int *lib);
void	check_even_columns(char *buff, int *lib);
void	check_library_double(char *buff, int *lib);
void	delete_first_line(char *buff, int *lib);
void	creat_lib_strings(char *buff, int *lib);
void	creat_lib_symbol(char *buff, int *lib);
void	lib_numbers(char *buff, int *lib, int k);
void	lib_symbol(char *buff, int *lib, int i, int k);
char	*create_buff(char *argv);
int		size_file(int fd);
void	free_buff(char **buff);
char	*check_valid_fifo(int *lib);
char	*create_buff_fifo(void);
int		**analis_map(char *buf, int *lib);
void	fill_arr(int **arr, int *lib, char *buf);
void	map_processing(char *buf, char *argv, int *lib, int **arr);
void	final_process(int **arr, int *lib, char *buf);
int		search_square(int **arr, int *lib);
int		max_square(int **arr, int *sum, int *i, int k);
void	print_result(int **arr, int *lib, int max);
void	arr_null(int **arr, int *lib, int max);
void	fill_square_max(int **arr, int *lib, int max);
void	free_arr(int **arr, int size, char *buf);
int		error(void);
int		map_error(void);

#endif
