#include "so_long.h"

char	*to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	ask_n(char *str, char *pass, int n)
{
	char	*answer;

	printf("%s\n", str);
	while (n)
	{
		answer = calloc(999, sizeof(char));
		read(1, answer, 100);
		answer = to_lower(answer);
		if (ft_strcmp(answer, pass) == 0)
		{
			printf("You are way off baseline.");
			free(answer);
			exit(EXIT_FAILURE);
		}
		else
			free(answer);
		n--;
	}
}

void	ask(char *str, char *pass)
{
	char	*answer;

	printf("%s\n", str);
	answer = calloc(999, sizeof(char));
	read(0, answer, 100);
	answer = to_lower(answer);
	if (ft_strcmp(answer, pass) == 0)
	{
		printf("You are way off baseline.");
		free(answer);
		exit(EXIT_FAILURE);
	}
	else
		free(answer);
}

void	ask_s(char *str, char *pass)
{
	char	*answer;

	printf("%s\n", str);
	answer = calloc(999, sizeof(char));
	read(0, answer, 100);
	answer = to_lower(answer);
	if (ft_strcmp(answer, pass) == 1 && ft_strlen(answer) == ft_strlen(pass))
		free(answer);
	else
	{
		printf("Exiting.");
		free(answer);
		exit(EXIT_FAILURE);
	}
}

void	loading_screen(void)
{
    char spinner[] = { '|', '/', '-', '\\' };
    int i;

    for (i = 0; i < 30; i++)
	{
        printf("\rLoading %c attend jte DDOS en 22 le sang 😂😂", spinner[i % 4]);
        fflush(stdout);
        usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
    }

    printf("\nLoading complete!\n");
}


void	start(void)
{
	ask_s("Launch game ? [yes / no]", "yes\n");
	printf("Initializing...\n");
	sleep(1);
	write(1, "mdr ta grosse adresse ip : ", 28);
	system("ifconfig | grep -oP 'inet \\K[\\d.]+' | sed -n '2p'");
	sleep(1);
	loading_screen();
	sleep(1);
}
