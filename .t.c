#include <libc.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
        size_t  i;
        size_t  j;

        if (!haystack && !len)
                return (NULL);
        if (!needle[0] || needle == haystack)
                return ((char *)haystack);
        i = 0;
        while (haystack[i] && i < len)
        {
                j = 0;
                while (haystack[i + j] == needle[j] && (i + j) < len)
                {
                        if (!needle[j])
                                return ((char *)&haystack[i]);
                        j++;
                }
                if (!needle[j])
                        return ((char *)(haystack + i));
                i++;
        }
        return (NULL);
}

char    *ft_strrchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i])
                i++;
        while (i >= 0)
        {
                if (s[i] == (char)c)
                        return ((char *)(s + i));
                i--;
        }
        return (NULL);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        size_t  length;
        char    *res;

        if (!s)
                return (NULL);
        if (start >= ft_strlen(s))
                return (ft_strdup(""));
        s += start;
        length = ft_strlen(s);
        if (length > len)
                length = len;
        res = (char *)malloc((length + 1) * sizeof(char));
        if (!res)
                return (NULL);
        ft_memcpy(res, s, length);
        res[length] = '\0';
        return (res);
}

int main()
{
	puts(ft_substr("hi hello; welcome; lol", ';', 2));
}
