#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

t_piece	*next_piecesoluce(t_piece *piece, int *tab)
{
	int	i;

	i = 0;
	while (piece->index != tab[i])
		i++;
	i++;
	i = tab[i];
	while (piece && piece->index != 0)
		piece = piece->previous;
	while (piece && piece->index != i)
		piece = piece->next;
	return (piece);
}

int	solve(t_carre *carre, t_piece *first, int *soluce)
{
	int	i;
	int	j;
	int	p;
	unsigned long long	try;
	t_piece	*piece;

	piece = first;
	i = 0;
	j = 0;
	while (p < carre->nbpiece && i < carre->size - 1)
	{
printf("p : %d, i : %d, j : %d\n", p, i, j);
		if (check_piece(piece, carre, i, j))
			piece = next_piecesoluce(piece, soluce);
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
	}
	return (0);
}

unsigned long long nfact (size_t n)
{   if (n <= 0) return 1;
    unsigned long long s = n;

    while (--n) s *= n;

    return s;
}
unsigned long long pnk (size_t n, size_t k)
{   size_t d = (k < n ) ? n - k : 1;
    return nfact (n) / nfact (d);
}

void prnarray (int *a, size_t sz)
{   size_t i;
    for (i = 0; i < sz; i++) printf (" %2d", a[i]);
    putchar ('\n');
}

void swap (int *x, int *y)
{   int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute (int *tab, unsigned int i, t_carre *carre, t_piece *first)
{   
	unsigned int	j;

	carre->tab = fill_tab(create_tab(carre, 0), carre->size++);
    if (i == carre->nbpiece)
	{
		solve (carre, first, tab);
		getchar();
	}
    else
        for (j = i; j < carre->nbpiece; j++) {
            swap ((tab+i), (tab+j));
            permute (tab, i+1, carre, first);
            swap ((tab+i), (tab+j));  // backtrack
        }
}

int allorder (t_carre *carre, t_piece *first)
{
    int	*tab;
	int	i;
	int	poss;

	i = 0;
	tab = malloc(sizeof(int) * carre->nbpiece);
	while (i < carre->nbpiece)
	{
		tab[i] = i;
		i++;
	}
	permute(tab, 0, carre, first);
	poss = pnk(carre->nbpiece, carre->nbpiece);
    return 0;
}
