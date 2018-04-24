/*
** EPITECH PROJECT, 2017
** is_number
** File description:
** return 1 if number, 0 else
*/

int my_is_digit(char c)
{
	if (c >= '0' && c <= '9') {
		return (1);
	}
	return (0);
}

int my_contains(char *s, char *cont)
{
	int i;
	int j;
	int ret = 0;

	for (i = 0; cont[i]; i += 1) {
		for (j = 0; s[j]; j += 1) {
			(cont[i] == s[j]) ? (ret = 1) : (ret = ret);
		}
	}
	return (ret);
}