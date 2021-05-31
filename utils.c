#include "push_swap.h"

int ft_strlen(const char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return(i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	i = 0;
	j = 0;
	news = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	while (s1[i] != '\0')
	{
		news[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		news[i] = s2[j];
		j++;
		i++;
	}
	news[i] = '\0';
	return (news);
}

int midle_number(t_stack *stack)
{
    int *array;
    array = malloc(sizeof(int *) * find_new_size(stack));
    memcpy(array , stack->stackA, sizeof(int *) * find_new_size(stack));
    ft_sort(find_new_size(stack), array);
    int middle = find_new_size(stack) / 2;
    middle = array[middle];
    free(array);
    return (middle);
}

int has_less(t_stack *stack, int middle)
{
    int i = 0;
    while (i < stack->size)
    {
        if (stack->stackA[i] < middle && stack->stackA[i] != 0)
        {
            stack->pos = i;
            return (1);
        }
        i++;
    }
    return (0);
}