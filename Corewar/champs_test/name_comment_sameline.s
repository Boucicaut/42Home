#COMMENTAIRE
.comment "commentaire du fichier"	.name	"test d'un name"
#COMMENTAIRE
#COMMENTAIRE

fork: fork %:life

load: or %:fork,                        r2,		r3

life: and %:load,r2,r1

ldi 3, %4, r1
