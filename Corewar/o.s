    .comment				"  'c  e"   			   	    	
	.name	" test d'un name   " 			

label:
  ld 	%4 , r1
tst_:          		fork %:life

load:   or %:life,   r2,		r3

life: and %:load,r2,r1

ldi 3, %4, r1
