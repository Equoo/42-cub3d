/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:41:08 by dderny            #+#    #+#             */
/*   Updated: 2025/05/26 04:19:19 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <sys/types.h>

/* ************************************************************************** */
/*                               CHAR FUNCTIONS                               */
/* ************************************************************************** */

/**
** @brief Check if a character is an alphabetic character
**
** @param c: the character to test
** @return 1 if c is an alphabetic character, 0 otherwise.
*/
int					ft_isalpha(int c);

/**
** @brief Check if a character is a digit
**
** @param c: the character to test
** @return 1 if c is a digit, 0 otherwise.
*/
int					ft_isdigit(int c);

/**
** @brief Check if a character is an alphabetic character or a digit
**
** @param c: the character to test
** @return 1 if c is an alphabetic character or a digit, 0 otherwise.
*/
int					ft_isalnum(int c);

/**
** @brief Check if a character is an ASCII character
**
** @param c: the character to test
** @return 1 if c is an ASCII character, 0 otherwise.
*/
int					ft_isascii(int c);

/**
** @brief Check if a character is a printable character
**
** @param c: the character to test
** @return 1 if c is a printable character, 0 otherwise.
*/
int					ft_isprint(int c);

/**
** @brief Check if a character is a space character

** @param c: the character to test
** @return 1 if c is a space character, 0 otherwise.
*/
int					ft_isspace(int c);

/**
** @brief Converts a lowercase letter to its uppercase equivalent.
**
** @param c The character to be converted.
** @return The uppercase equivalent of the character if it is a lowercase
**	letter, otherwise returns the character unchanged.
*/
int					ft_toupper(int c);

/**
** @brief Converts an uppercase letter to its lowercase equivalent.
**
** @param c The character to be converted.
** @return The lowercase equivalent of the character if it is an uppercase
**	letter, otherwise returns the character unchanged.
*/
int					ft_tolower(int c);

/* ************************************************************************** */
/*                               STRING FUNCTIONS                             */
/* ************************************************************************** */

/**
** @brief Split a string into an array of strings using a delimiter
**
** @param s: the string to split
** @param c: the delimiter character
** @return an array of strings
*/
char				**ft_split(const char *s, char c);

/**
** @brief Join two strings and free the two strings passed as arguments
**
** @param s1: the first string
** @param s2: the second string
** @return a new string containing s1 followed by s2
*/
char				*ft_stradd(char *s1, char *s2);

/**
** @brief Locate the first occurrence of a character in a string
**
** @param s: the string to search
** @param c: the character to locate
** @return a pointer to the first occurrence of c in s,
**	or NULL if c is not found
*/
char				*ft_strchr(const char *s, int c);

/**
** @brief Finds the first occurrence of the character c in the string s.
**
** @param s The string to be scanned.
** @param c The character to be searched in s.
** @return The index of the first occurrence of the character c in the string s,
**	or -1 if the character is not found.
*/
int					ft_strchrpos(const char *s, int c);

/**
** @brief Duplicates the given string.
**
** @param s The string to be duplicated.
** @return A pointer to the newly allocated string,
**	which is a duplicate of the string s.
*/
char				*ft_strdup(const char *s);

/**
** @brief Applies the function f to each character of the string s,
**	passing its index as the first argument.
**
** @param s The string on which to iterate.
** @param f The function to apply to each character of s.
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
** @brief Copies up to n - 1 characters from the string src to dest,
**	null-terminating the result.
**
** @param dest The destination buffer.
** @param src The source string.
** @param n The size of the destination buffer.
** @return The total length of the string it tried to create (length of src).
*/
size_t				ft_strlcpy(char *dest, const char *src, size_t n);

/**
** @brief Appends the string src to the end of dest, up to n
**	- 1 characters long, null-terminating the result.
**
** @param dest The destination buffer.
** @param src The source string.
** @param n The size of the destination buffer.
** @return The total length of the string it tried to create
**	(initial length of dest plus length of src).
*/
size_t				ft_strlcat(char *dest, const char *src, size_t n);

/**
** @brief Finds the last occurrence of the character c in the string s.
**
** @param s The string to be scanned.
** @param c The character to be searched in s.
** @return A pointer to the last occurrence of the character c in the string s,
**	or NULL if the character is not found.
*/
char				*ft_strrchr(const char *s, int c);

/**
** @brief Compares up to n characters of the strings s1 and s2.
**
** @param s1 The first string to be compared.
** @param s2 The second string to be compared.
** @param n The maximum number of characters to compare.
** @return An integer less than, equal to, or greater than zero if s1 is found,
**	respectively, to be less than, to match, or be greater than s2.
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
** @brief Compares characters of the strings s1 and s2.
**
** @param s1 The first string to be compared.
** @param s2 The second string to be compared.
** @return An integer less than, equal to, or greater than zero if s1 is found,
**	respectively, to be less than, to match, or be greater than s2.
*/
int					ft_strcmp(const char *s1, const char *s2);

/**
** @brief Locates the first occurrence of the null-terminated string find in
**	the string str, where not more than n characters are searched.
**
** @param str The string to be scanned.
** @param find The string to be searched within str.
** @param n The maximum number of characters to search.
** @return A pointer to the first occurrence of find in str,
**	or NULL if find is not found.
*/
char				*ft_strnstr(const char *str, const char *find, size_t n);

/**
** @brief Allocates and returns a substring from the string s.
**
** @param s The string from which to create the substring.
** @param start The start index of the substring in the string s.
** @param len The maximum length of the substring.
** @return A pointer to the substring, or NULL if the allocation fails.
*/
char				*ft_substr(const char *s, unsigned int start, size_t len);

/**
** @brief Allocates and returns a new string,
**	which is the result of the concatenation of s1 and s2.
**
** @param s1 The prefix string.
** @param s2 The suffix string.
** @return A pointer to the newly allocated string,
	or NULL if the allocation fails.
*/
char				*ft_strjoin(const char *s1, const char *s2);

/**
** @brief Allocates and returns a copy of s1 with the characters specified
**	in set removed from the beginning and the end of the string.
**
** @param s1 The string to be trimmed.
** @param set The reference set of characters to trim.
** @return A pointer to the trimmed string, or NULL if the allocation fails.
*/
char				*ft_strtrim(const char *s1, const char *set);

/**
** @brief Applies the function f to each character of the string s
**	to create a new string resulting from successive applications of f.
**
** @param s The string on which to iterate.
** @param f The function to apply to each character of s.
** @return A pointer to the newly allocated string resulting from the
**	successive applications of f, or NULL if the allocation fails.
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
** @brief Get the length of a string
**
** @param str: the string to get the length of
** @return the length of the string
*/
size_t				ft_strlen(const char *str);

/**
** @brief Compare two strings
**
** @param s1: the first string to compare
** @param s2: the second string to compare
** @return 0 if the strings are identical, a negative value if s1 is less than
** s2, a positive value if s1 is greater than s2
*/
int					ft_strcmp(const char *s1, const char *s2);

/* ************************************************************************** */
/*                               MEMORY FUNCTIONS                             */
/* ************************************************************************** */

typedef struct s__alloc
{
	void			*ptr;
	size_t			size;
	size_t			mapid;
}					t__alloc;

typedef struct s__allocs
{
	t__alloc		*allocations;
	size_t			capacity;
	size_t			freed;
	size_t			size;
}					t__allocs;

t__allocs			*__get_ft_allocations(void);

/**
** @brief Allocates memory of the given size and returns a pointer to it.
**
** @param size The size of memory to allocate.
** @param mapid The map id to associate with the allocation.
** @return A pointer to the allocated memory, or NULL if the allocation fails.
*/
void				*ft_xalloc(size_t size, id_t mapid);

/**
** @brief Allocates memory of the given size and returns a pointer to it.
**	NEVER FREE THIS POINTER WITHOUT FT_FREE.
**
** @param size The size of memory to allocate.
** @return A pointer to the allocated memory, or NULL if the allocation fails.
*/
void				*ft_alloc(size_t size);

/**
** @brief Allocates memory of the given size and initializes it to zero.
** @param size The size of memory to allocate.
** @param mapid The map id to associate with the allocation.
** @return A pointer to the allocated memory, or NULL if the allocation fails.
*/
void				*ft_xcalloc(size_t size, id_t mapid);

/**
** @brief Reallocates memory to the given size and returns a pointer to it.
** @param ptr The pointer to the memory to reallocate.
** @param size The new size of memory to allocate.
** @param mapid The map id to associate with the allocation.
** @return A pointer to the reallocated memory, or NULL if the allocation fails.
*/
void				*ft_xrealloc(void *ptr, size_t size, id_t mapid);

/**
** @brief Reallocates memory to the given size and returns a pointer to it.
** @param ptr The pointer to the memory to reallocate.
** @param size The new size of memory to allocate.
** @return A pointer to the reallocated memory, or NULL if the allocation fails.
*/
void				*ft_realloc(void *ptr, size_t size);

/**
** @brief Frees the memory pointed to by ptr.
**	NEVER FREE NON FT_ALLOCATED POINTERS.
** @param ptr The pointer to the memory to free.
** @return NULL
*/
void				*ft_free(void *ptr);

/**
** @brief Frees the memory associated with the given mapid.
** @param mapid The map id of the memory to free.
** @return NULL
*/
void				*ft_xfree(id_t mapid);

/**
** @brief Compares the first n bytes of memory areas s1 and s2.
**
** @param s1 Pointer to the first memory area.
** @param s2 Pointer to the second memory area.
** @param n Number of bytes to compare.
** @return An integer less than, equal to,
**	or greater than zero if the first n bytes of s1
**         is found to be less than, to match,
**	or be greater than the first n bytes of s2.
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
** @brief Scans the initial n bytes of the memory area pointed to by s for
**	the first instance of c.
**
** @param s Pointer to the memory area.
** @param c Value to be located.
** @param n Number of bytes to be analyzed.
** @return A pointer to the matching byte or NULL if the character does
**	not occur in the given memory area.
*/
void				*ft_memchr(const void *s, int c, size_t n);

/**
** @brief Copies n bytes from memory area src to memory area dest.
**
** @param dest Pointer to the destination memory area.
** @param src Pointer to the source memory area.
** @param n Number of bytes to copy.
** @return A pointer to dest.
*/
void				*ft_memcpy(void *dest, const void *src, size_t n);

/**
** @brief Copies n bytes from memory area src to memory area dest.
**	The memory areas may overlap.
**
** @param dest Pointer to the destination memory area.
** @param src Pointer to the source memory area.
** @param n Number of bytes to copy.
** @return A pointer to dest.
*/
void				*ft_memmove(void *dest, const void *src, size_t n);

/**
** @brief Fills the first n bytes of the memory area pointed to by s
**	with the constant byte c.
**
** @param s Pointer to the memory area.
** @param c Value to be set.
** @param n Number of bytes to be set to the value.
** @return A pointer to the memory area s.
*/
void				*ft_memset(void *s, int c, size_t n);

void				*ft_memsetint(u_int *s, u_int v, size_t n);

/**
** @brief Erases the data in the n bytes of the memory starting at
**	the location pointed to by s, by writing zeros (bytes containing '\0')
**	to that area.
**
** @param s Pointer to the memory area.
** @param n Number of bytes to be set to zero.
*/
void				ft_bzero(void *s, size_t n);
/**
** @brief Allocates memory for an array of `nmemb` elements of `size` bytes
**	each and returns a pointer to the allocated memory.
**	The memory is set to zero.
**
** @param nmemb The number of elements to allocate.
** @param size The size of each element.
** @return A pointer to the allocated memory, or NULL if the allocation fails.
*/
void				*ft_calloc(size_t nmemb, size_t size);

/**
** @brief Frees a dynamically allocated array of pointers.
**
** @param array A pointer to the array of pointers to be freed.
*/
void				ft_freearray(void **array);

/**
** @brief Calculates the length of a NULL-terminated array.
**
** This function takes a pointer to a NULL-terminated array and returns the
** number of elements in the array, excluding the NULL terminator.
**
** @param array A pointer to the NULL-terminated array.
** @return The number of elements in the array, excluding the NULL terminator.
*/
size_t				ft_arraylen(void **array);

/**
** @brief Prints the memory content of a given address.
**
** This function prints the memory content starting from the specified address
** up to the given size in bytes. The output format is typically in hexadecimal
** representation, making it useful for debugging purposes.
**
** @param addr The starting address of the memory to be printed.
** @param size The number of bytes to be printed from the starting address.
** @return A pointer to the memory area addr.
*/
void				*ft_print_memory(void *addr, unsigned int size);

/* ************************************************************************** */
/*                               NUMBER FUNCTIONS                             */
/* ************************************************************************** */

/**
** @brief Converts the initial portion of the string pointed to by str to int.
**
** @param str The string to be converted.
** @return The converted value as an int.
*/
int					ft_atoi(const char *str);

/**
** @brief Converts the initial portion of the string pointed to by str to
**	double.
**
** @param str The string to be converted.
** @return The converted value as a double.
*/
double				ft_atof(const char *str);

/**
** @brief Converts the initial portion of the string pointed to by str to
**	long long.
**
** @param str The string to be converted.
** @return The converted value as a long long.
*/
long long			ft_atoll(const char *str);

/**
** @brief Converts an integer value to a null-terminated string using
**	the specified base and stores the result in the array
**	given by strparameter.
**
** @param n The integer to be converted.
** @return A pointer to the resulting null-terminated string.
*/
char				*ft_itoa(int n);

/**
** @brief Converts an integer value to a null-terminated string using
**	the specified base and stores the result in the array
**	given by strparameter.
**
** @param n The integer to be converted.
** @param dst String destination.
** @return Len of the conversion
*/
int					ft_itoato(int n, char *dst);

/**
** @brief Converts a string to a long integer.
**
** This function converts the initial part of the string pointed to by
**	nptr to a long integer value according to the given base.
**
** @param nptr Pointer to the null-terminated string to be interpreted.
** @param endptr Pointer to a pointer to character. If endptr is not NULL,
**	a pointer to the character after the last character used in the conversion
**	is stored in the location referenced by endptr.
** @param base Base of the number in the string. Must be between 2
**	and 36 inclusive,
**	or be the special value 0.
**
** @return The converted value as a long integer.
**         If no valid conversion could be performed, 0 is returned.
**         If the value is out of range,
	LONG_MAX or LONG_MIN is returned and errno
**				is set to ERANGE.
*/
long				ft_strtol(const char *nptr, char **endptr, int base);

/**
** @brief Converts a string to a int integer.
**
** This function converts the initial part of the string pointed to by
**	nptr to a int integer value according to the given base.
**
** @param nptr Pointer to the null-terminated string to be interpreted.
** @param endptr Pointer to a pointer to character. If endptr is not NULL,
**	a pointer to the character after the last character used in the conversion
**	is stored in the location referenced by endptr.
** @param base Base of the number in the string. Must be between 2
**	and 36 inclusive,
**	or be the special value 0.
**
** @return The converted value as a int integer.
**         If no valid conversion could be performed, 0 is returned.
**         If the value is out of range,
	INT_MAX or INT_MIN is returned and errno
**				is set to ERANGE.
*/
int					ft_strtoi(const char *nptr, char **endptr, int base);

/* ************************************************************************** */
/*                               PRINT FUNCTIONS                              */
/* ************************************************************************** */

/**
** @brief Outputs the character 'c' to the given file descriptor.
**
** @param c The character to output.
** @param fd The file descriptor on which to write.
*/
void				ft_putchar_fd(char c, int fd);

/**
** @brief Outputs the string 's' to the given file descriptor.
**
** @param s The string to output.
** @param fd The file descriptor on which to write.
*/
void				ft_putstr_fd(char *s, int fd);

/**
** @brief Outputs the string 's' to the given file descriptor,
	followed by a newline.
**
** @param s The string to output.
** @param fd The file descriptor on which to write.
*/
void				ft_putendl_fd(char *s, int fd);

/**
** @brief Outputs the integer 'n' to the given file descriptor.
**
** @param n The integer to output.
** @param fd The file descriptor on which to write.
*/
void				ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*                               LIST FUNCTIONS                               */
/* ************************************************************************** */

/**
** @struct s_list
** @brief Structure representing a node in a linked list.
**
** @var s_list::content
** Member 'content' contains the data stored in the node.
** @var s_list::next
** Member 'next' points to the next node in the list.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
** @brief Creates a new list node.
**
** @param content The content to store in the new node.
** @return A pointer to the new node.
*/
t_list				*ft_lstnew(void *content);

/**
** @brief Adds a new node at the beginning of the list.
**
** @param lst A pointer to the pointer to the first node of the list.
** @param new The new node to add.
*/
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
** @brief Counts the number of nodes in the list.
**
** @param lst A pointer to the first node of the list.
** @return The number of nodes in the list.
*/
size_t				ft_lstsize(t_list *lst);

/**
** @brief Returns the last node of the list.
**
** @param lst A pointer to the first node of the list.
** @return A pointer to the last node of the list.
*/
t_list				*ft_lstlast(t_list *lst);

/**
** @brief Adds a new node at the end of the list.
**
** @param lst A pointer to the pointer to the first node of the list.
** @param new The new node to add.
*/
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
** @brief Deletes a node from the list.
**
** @param lst The node to delete.
** @param del A function pointer to a function used to delete the
**	content of the node.
*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
** @brief Deletes a node from the list.
**
** @param lst The node to delete.
** @param del A function pointer to a function used to delete the
**	content of the node.
*/
void				ft_lstrmone(t_list **lst, void (*del)(void *));

/**
** @brief Deletes and frees all nodes of the list.
**
** @param lst A pointer to the pointer to the first node of the list.
** @param del A function pointer to a function used to delete the
**	content of each node.
*/
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
** @brief Iterates over the list and applies a function to each node.
**
** @param lst A pointer to the first node of the list.
** @param f A function pointer to a function to apply to each node's content.
*/
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
** @brief Creates a new list by applying a function to each node of
** an existing list.
**
** @param lst A pointer to the first node of the list.
** @param f A function pointer to a function to apply to each node's content.
** @param del A function pointer to a function used to delete the content
**	of a node if needed.
** @return A pointer to the first node of the new list.
*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ************************************************************************** */
/*                                MATH FUNCTIONS                              */
/* ************************************************************************** */

/**
** @brief Returns the absolute value of an integer.
**
** @param n The integer to compute the absolute value of.
** @return The absolute value of the integer.
*/
int					ft_abs(int n);

/**
** @brief Returns the absolute value of an float.
**
** @param n The float to compute the absolute value of.
** @return The absolute value of the float.
*/
float				ft_fabs(float n);

int					ft_min(int a, int b);
float				ft_fmin(float a, float b);

int					ft_max(int a, int b);
float				ft_fmax(float a, float b);

float				ft_lerp(float a, float b, float t);

float				ft_fclamp(float value, float min, float max);
int					ft_clamp(int value, int min, int max);

#endif
