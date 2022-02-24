#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>


void	check_guess(char *answer, char *guess, int i, int j)
{
	char *temp = ft_strdup(answer);

	while (i < 5)
	{
		if (guess[i] == answer[i])
		{
			guess[i] -= 32;
		}
		else
		{
			while (temp[j] != '\0')
			{
				if (guess[i] == temp[j])
					break;
				j++;
			}
			if (temp[j] == '\0')
				guess[i] = '-';
		}
		j = 0;
		i++;
	}
}

void	game(char *answer, int i)
{
	char *guess = ft_strnew(100);
	char *compare_guess = ft_strdup(answer);
	while (compare_guess[i] != '\0')
	{
		compare_guess[i] = ft_toupper(compare_guess[i]);
		i++;
	}
	printf("\n\n		       	Guess the WORD in six tries. Each guess must be a valid five-letter word, typed with lower-case!!\n\n						     	Hit the enter button to submit.\n\n	       	After each guess, the case distinction of the letters will change to show how close your guess was to the word.\n");
	printf("\n				      	Lower-case letter = letter was found in word but not in right position\n\n				     	Upper-case letter = letter was found and in the right position\n\n						'-' = blank character, as in letter was not found.\n");
	printf("\n						1st try! Type in your guess and hit enter!\n");
	printf("\n							Your guess : ");
	scanf("%s", guess);
	check_guess(answer, guess, 0, 0);
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("\n				Congratulations! Your answer is correct!\n\n");
		exit (0);
	}
	else
	{
		printf("\n\n						Your answer was incorrect, please try again!\n\n							Feedback : %s\n\n						2nd try! Type in your guess and hit enter!\n", guess);
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("\n				Congratulations! Your answer is correct!\n\n");
		exit (0);
	}
	else
	{
		printf("\n						Your answer was incorrect, please try again!\n\n							Feedback : %s\n\n						3rd try! Type in your guess and hit enter!\n", guess);
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("\n				Congratulations! Your answer is correct!\n\n");
		exit (0);
	}
	else
	{
		printf("\n						Your answer was incorrect, please try again!\n\n							Feedback : %s\n\n						4th try! Type in your guess and hit enter!\n", guess);
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("\n				Congratulations! Your answer is correct!\n\n");
		exit (0);
	}
	else
	{
		printf("\n						Your answer was incorrect, please try again!\n\n							Feedback : %s\n\n						5th try! Type in your guess and hit enter!\n", guess);
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("\n				Congratulations! Your answer is correct!\n\n");
		exit (0);
	}
	else
	{
		printf("\n						Your answer was incorrect, please try again!\n\n							Feedback : %s\n\n					LAST try!!! Type in your guess and hit enter! Good luck!\n", guess);
		printf("\n							Your guess : ");
		scanf("%s", guess);
		check_guess(answer, guess, 0, 0);
	}
	if (strcmp(compare_guess, guess) == 0)
	{
		printf("\n				Congratulations! Your answer is correct!\n\n");
		exit (0);
	}
	else
	{
		printf("\n					Your answer was incorrect.. You are out of tries! Too bad...\n");
		printf("\n\n							Correct answer : %s\n", answer);
	}

}

int	main(void)
{
	int		fd;
	int		i, j, word;
	char	*line;
	char	**dictionary;
	time_t	t;
	j = 0;
	i = 0;
	srand((unsigned) time(&t));
	word = rand() % 3000;
	if (word > 2315)
	{
		while (word > 2315)
		word = rand() % 3000;
	}
	dictionary = (char **)malloc(sizeof(char *) * 2316);
	while (i < 2316)
	{
		dictionary[i] = ft_strnew(5);
		i++;
	}
	i = 0;
	fd = open("dictionary", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		while (line[i] != '\0')
		{
			dictionary[j][i] = line[i];
			i++;
		}
		i = 0;
		j++;
		free (line);
	}
	free (line);
	char *answer = ft_strdup(dictionary[word]);
	game(answer, 0);
	exit (0);
}
