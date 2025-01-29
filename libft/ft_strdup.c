#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}
