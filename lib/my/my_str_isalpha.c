/*
** EPITECH PROJECT, 2017
** my_str_isalphanum
** File description:
** return 1 if alphabetical 0 if not
*/

int	is_alphanum(char c)
{
	if (c >= '0' && c <= '9' ||
	    c >= 'a' && c <= 'z' ||
	    c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	my_str_isalphanum(char const *str)
{
	for (int i = 0; str[i]; i++)
		if (!is_alphanum(str[i]))
			return (0);
	return (1);
}
