# -*- encoding=utf8 -*-

import math # ??
import re
from functools import reduce
from operator import mul
from red_ope import *
from red_divx import *
from solveabc import *
from red_entier import *

def red_start(expr):
    ''' Reduit l'expression si le premier terme est un entier en place '''
    first = expr[0]
    digit = 0
    neg = 0

pol = input('Entrer : \n')
ert = pol.split('=')
ert = list(map(lambda x:x.strip(),ert))
result = ert.pop(1)


#oth = re.split(r'\\+',ert.pop())
oth = ert.pop().split('+')
#oth = list(filter(lambda x: x and x != ' ', oth))
result = re.split(r'\\+',result)

result = list(map(lambda x:x.strip(),result))
oth = list(map(lambda x:x.strip(),oth))

######################## CALL REDUCE FUNCTION #########################

print('\t', oth,'=',result)

red_sub(oth)
print('\nCALL RED_SUB')
print('\t', oth,'=',result)

print('\nCALL RED_ADD')
red_add(oth)
print('\t', oth,'=',result)

red_mul(oth)
print('\nCALL RED_MUL')
print('\t', oth,'=',result)

red_div(oth)
print('\nCALL RED_DIV')
print('\t', oth,'=',result)

red_pow(oth)
print('\nCALL RED_POW')
print('\t', oth,'=',result)

red_ent(oth)
print('\nCALL RED_ENT')
print('\t', oth,'=',result)

red_multiple_div_mul(oth)
print('\nCALL RED_MULTIPLE_DIV_MUL')
print('\t', oth,'=',result)

print('\nCALL FINAL RED')
red_add(oth)  # do final red, entier, x et x^2
print('\t', oth,'=',result)
'''
delta = calcul_delta(oth)
print('Calcul DELTa : ', delta)
print('Result is : ',calcul_res2(oth))
print('All expressions : ', oth,'\nResult : ', result)
'''
