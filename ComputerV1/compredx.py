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


# den num
#___________ RED DIV AVEC X
def red_divx(expr):
    to_rm = []
    den = []
    num = []
    for i, e in enumerate(expr):
        if '/' in e.lower() and 'x' in e.lower():
            num.append(e.split('/', 1)[0].strip())
            den.append(e.split('/', 1)[1].strip())
            to_rm.append(i)
    chain_red(den)
    chain_red(num)
    den, num = common_den(den, num)
    print("DEN : ", den)
    print("NUM : ", num)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    chain_red(den)
    chain_red(num)
    print("DEN : ", den)
    print("NUM : ", num)

def find_com_ent(ent):
    if len(set(ent)) == 1:
        return ent[0]
    nb = 1
    for i in ent:
        nb *= i
    return nb

def common_den(den, num):
    '''Renvoie les denominateurs communs et les numerateurs de la liste den'''
    x_miss = 0
    den_ent = []
    if any(map(lambda x: 'x' in x.lower(), den)) and not all(map(lambda x: 'x' in x.lower(), den)):
        x_miss = 1
    elif any(map(lambda x: 'x^2' in x.lower(), den)) and not all(map(lambda x: 'x^2' in x.lower(), den)):
        x_miss = 2
    for i in den:
        den_ent.append(int(i.lower().split('*')[0].strip()))
    print(den_ent, 'XMISS : ',x_miss)
    vl = find_com_ent(den_ent)
    for ind,(i,j) in enumerate(zip(den,num)):
        new = vl // int(i.lower().split('*')[0])
        print('Newww :',new)
        nb_x = 0
        if 'x^2' in i.lower():
            nb_x = 2
        elif 'x' in i.lower():
            nb_x = 1
        if x_miss - nb_x == 0:
            den[ind] += ' * ' + str(new)
            num[ind] += (' * ' + str(new))
        elif x_miss - nb_x == 1:
            den[ind] += (' * ' + str(new) + 'X')
            num[ind] += (' * ' + str(new) + 'X')
        else:
            den[ind] += (' * ' + str(new) + 'X^2')
            num[ind] += (' * ' + str(new) + 'X^2')
    return den, num


#chain_red(oth)
red_divx(oth)
print('After chainred : ',oth)

delta = calcul_delta(oth)
print('Calcul DELTa : ', delta)
print('Result is : ',calcul_res2(oth))
print('All expressions : ', oth,'\nResult : ', result)



