# -*- encoding=utf8 -*-

import math
import re
from functools import reduce
from operator import mul
from red_ope import *

def red_start(expr):
    ''' Reduit l'expression si le premier terme est un entier en place '''
    first = expr[0]
    digit = 0
    neg = 0

def calcul_abc(expr):
    a = 0
    b = 0
    c = 0
    for i in expr:
        if 'x' in i.lower() and '^' in i:
            a = int(i.lower().strip('x^2'))
        elif 'x' in i.lower():
            b = int(i.lower().strip('x'))
        elif i.isdigit():
            c = int(i)
    return a,b,c

def calcul_delta(expr):
    '''Calcul le delta du polynome, b^2 - 4ac'''
    a,b,c = calcul_abc(expr)
    return (pow(b,2) - (4 * a * c))

def calcul_res(expr):
    a,b,c = calcul_abc(expr)
    if a == 0:
        return calcul_sol1(expr)
    delta = calcul_delta(expr)
    if delta < 0:
        print('Pas de solution')
        return None
    '''Deux solutions : x =( −b + √Δ ) / 2a et x =( −b − √Δ ) / 2a '''
    if delta > 0:
        print('Deux solutions')
        return (-delta + math.sqrt(delta) / (2 * a), -delta + math.sqrt(delta) / (2 * a))
    elif delta == 0:
        '''Une solution, x = −b/2a'''
        print('Une solution')
        return (-delta / (2 * a),)

def calcul_sol1(expr):
    a,b,c = calcul_abc(expr)
    print('ABC :',a,b,c)

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

chain_red(oth)
print('After chainred : ',oth)

delta = calcul_delta(oth)
print('Calcul DELTa : ', delta)
print('Result is : ',calcul_res2(oth))
print('All expressions : ', oth,'\nResult : ', result)
