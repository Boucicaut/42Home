# -*- encoding=utf8 -*-

import math
import re
from functools import reduce
from operator import mul
import itertools
from red_divx import *

#regex to identify float number
isfloat = re.compile('^\d+(\.\d+)?$')

def red_xmul_add(expr):
    ''' On reduit en aggregeant les expressions x simples (ex 5 * x + 4 * x MAIS PAS 5 * x / 2 NI 5 * x * x)'''
    to_rm = []
    to_add = []
    to_add2 = []
    for ind,exp in enumerate(expr):
        print('Exp : ',exp)
        if exp.lower().count('x^2') == 1 and exp.count('/') == 0 and exp.count('*') == 1:
            for i in exp.split('*'):
                if 'x' not in i.lower():
                    to_add2.append(float(i.strip()))
            to_rm.append(ind)
        elif exp.lower().count('x') == 1 and exp.count('/') == 0 and exp.count('*') == 1:
            for i in exp.split('*'):
                if 'x' not in i.lower():
                    to_add.append(float(i.strip()))
            to_rm.append(ind)
        elif exp.lower().strip() == 'x':
            to_add.append(1)
            to_rm.append(ind)
        elif exp.lower().strip() == 'x^2':
            to_add2.append(1)
            to_rm.append(ind)
        print('ToAdd : ',to_add)
        print('ToAdd2 : ',to_add2)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if to_add:
        expr.append(str(sum(to_add)) + ' * X')
    if to_add2:
        expr.append(str(sum(to_add2)) + ' * X^2')

def red_xmulshit(expr):
    to_mul = []
    to_div = []
    for i,d in enumerate(to_div):
        if d in to_mul:
            to_rm.append(i)
            to_mul.pop(to_mul.index(d))
    for i in sorted(to_rm)[::-1]:
        to_div.pop(i)
    x = 0
    nb = 1
    neg = 0
    for i in to_mul:
        if i.strip().startswith('-') and neg == 0:
            neg = 1
        elif i.strip().startswith('-') and neg == 1:
            neg = 0
        if 'x^2' in i.lower():
            x += 2
        elif 'x' in i.lower():
            x += 1
        else:
            nb *= float(i.strip())
    for i in to_div:
        if i.strip().startswith('-') and neg == 0:
            neg = 1
        elif i.strip().startswith('-') and neg == 1:
            neg = 0
        if 'x^2' in i.lower():
            x -= 2
        elif 'x' in i.lower():
            x -= 1
        else:
            nb /= float(i.strip())
    print('x : ',x,'|| nb : ',nb)
    if x == -2:
        x = " / X^2"
    elif x == -1:
        x = " / X"
    elif x == 1:
        x = " * X"
    elif x == 2:
        x = " * X^2"
    elif x == 0:
        x = ""
    else:
        print('Bad exponent for X')
        x = ""
        #quit()
    if x and neg:
        expr.append(str(nb) + '-' + x)
    elif x:
        expr.append(str(nb) + x)
    else:
        expr.append(str(nb))

def chain_red(expr):
    red_add(expr)
    print(expr)
    red_sub(expr)
    print(expr)
    red_mul(expr)
    red_div(expr)
    red_pow(expr)
    red_ent(expr)
    print(expr)
    red_xmul_add(expr)
    red_divx(expr)




def red_x(expr):
    total = 0
    to_rm = []
    to_add = []
    for ind_expr,e in enumerate(expr):
        nb = 1
        x = 0
        # * et X
        if 'x' in e.lower() and not '/' in e and '*' in e:
            elems = e.split('*')
            for i in elems :
                print('i tofloat : ',i)
                if i.strip().lower().startswith('x'):
                    i = 'x'
                elif i.strip().lower().startswith('-x'):
                    i = '-x'
                if 'x^2' in i.lower():
                    x += 2
                    if any(aa.isdigit() for aa in i):
                        nb *= float(i.lower().strip('x^2 '))
                elif 'x' in i.lower():
                    x += 1
                    print('Ipb : ',i)
                    if any(aa.isdigit() for aa in i):
                        nb *= float(i.lower().strip('x '))
                elif any(aa.isdigit() for aa in i):
                    nb *= float(i)
            if nb != 0 and x == 2:
                to_add.append(str(nb) + 'X^2')
            elif nb != 0 and x == 1:
                to_add.append(str(nb) + 'X')
            elif nb != 0:
                to_add.append(str(nb))
            to_rm.append(ind_expr)
        elif 'x' in e.lower() and not '*' in e and '/' in e:
            elems = e.split('/')
            for ind,i in enumerate(elems):
                if i.strip().lower().startswith('x'):
                    i = '1x'
                elif i.strip().lower().startswith('-x'):
                    i = '-1x'
                if 'x^2' in i.lower():
                    if ind == 0:
                        x = 2
                        if any(aa.isdigit() for aa in i):
                            nb = float(i.lower().strip('x^2 '))
                    else:
                        x -= 2
                        if any(aa.isdigit() for aa in i):
                            nb /= float(i.lower().strip('x^2 '))
                elif 'x' in i.lower():
                    if ind == 0:
                        x = 1
                        if any(aa.isdigit() for aa in i):
                            nb = float(i.lower().strip('x '))
                    else:
                        x -= 1
                        if any(aa.isdigit() for aa in i):
                            nb /= float(i.lower().strip('x '))
                else:
                    if ind == 0:
                        nb = float(i)
                    else:
                        nb /= float(i)
            if nb != 0 and x == 2:
                to_add.append(str(nb) + 'X^2')
            elif nb != 0 and x == 1:
                to_add.append(str(nb) + 'X')
            elif nb != 0 and x == -2:
                to_add.append(str(nb) + ' / X^2')
            elif nb != 0 and x == -1:
                to_add.append(str(nb) + ' / X')
            elif nb != 0:
                to_add.append(str(nb))
            to_rm.append(ind_expr)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    for i in to_add:
        expr.append(i)

