fill_it

piece = first;
while (nbpiece != nbpieceposee(t_piece *first))
{
	while (piece->put == 0)
	{
		while (i < carre->size)
		{
			while (j < carre->size)
			{
				if (check_piece(piece, carre, i, j) == 1)
				{
					piece->put = 1;
				}
				j++;
			}
			i++;
			j++;
		}
		if (piece->next)
			piece = piece->next;
		else
			piece = first;
	}
	piece = first;
	while (piece->put == 0)
		piece = piece->next;
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece = first;

}










