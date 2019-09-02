# -*- encoding=utf8 -*-

import math
import re
from functools import reduce
from operator import mul

def red_add(expr):
    ''' Reduit les entiers simples de l'equation. Les supprime et ajoute
    la somme a la fin de la liste en place. '''
    to_rm = []
    total = 0
    for i,ex in enumerate(expr):
        if ex.strip('+-').isdigit():# or ex.startswith('-'):
            total += int(ex)
            to_rm.append(i)
    nb_rm = 0
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if total != 0:
        expr.append(str(total))

def red_sub(expr):
    op = []
    to_rm = []
    #this part split the sub
    sub = []
    for ind,i in enumerate(expr):
        if len(i.split('-')) > 1:
            sub.append(i.split('-'))
            to_rm.append(ind)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    for i in sub:
        for ind,j in enumerate(i):
            if len(j.strip()) and ind == 0:
                expr.append(j.strip())
            elif len(j.strip()):
                expr.append('-' + j.strip())
    #resolve the sub
    to_rm = []
    for i,ex in enumerate(expr):
        if not ex.strip('-+').isdigit() and not '*' in ex and not '/' in ex and not '^' in ex:
            op.append(ex.split('- '))
            to_rm.append(i)
    if to_rm:
        for i in sorted(to_rm)[::-1]:
            expr.pop(i)
    total = 0
    cantadd = []
    for oo in op:
        for i,pp in enumerate(oo):
            if not pp.strip().isdigit():
                if i == 0:
                    cantadd.append(pp)
                else:
                    cantadd.append('-' + pp)
            else:
                if i == 0:
                    total += int(pp)
                    continue
                total -= int(pp)
    for i in cantadd:
        expr.append(i)
    if total != 0:
        expr.append(str(total))

def red_ent(expr_liste):
    ''' Reduit entiers de la liste en place'''
    total = 0
    to_rm = []
    for i,e in enumerate(expr_liste):
        if e.strip('-+').isdigit():
            total += int(e)
            to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr_liste.pop(i)
    if total != 0:
        expr_liste.append(str(total))

def red_mul(expr):
    total = 0
    to_rm = []
    for i,e in enumerate(expr):
        if '*' in e and not 'x' in e.lower() and not '^' in e and not '/' in e:
           new_e = list(map(int,e.split('*')))
           total = reduce(mul,new_e)
           to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if total:
        expr.append(str(total))

def red_div(expr):
    nb = []
    to_rm = []
    for i,e in enumerate(expr):
        if '/' in e and not 'x' in e.lower():
           nb.append(e)
           to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    total = 0
    curr = 0
    for i in nb:
        for ind,j in enumerate(i.split('/')):
            if ind == 0:
                curr = int(j.strip())
            else:
                curr /= int(j.strip())
        total += curr
    if total:
        expr.append(str(int(total)))

def red_x(expr):
    '''Reduit les multiplications et division avec des x'''
    total = 0
    to_rm = []
    to_add = []
#penser au cas 3* x * 4 * x / 3 * x^2 = 0
    for ind_expr,e in enumerate(expr):
        nb = 1
        x = 0
        # * et X
        if 'x' in e.lower() and not '/' in e and '*' in e:
            elems = e.split('*')
            for i in elems :
                if i.strip().lower().startswith('x'):
                    i = 'x'
                elif i.strip().lower().startswith('-x'):
                    i = '-x'
                if 'x^2' in i.lower():
                    x += 2
                    nb *= int(i.lower().strip('x^2 '))
                elif 'x' in i.lower():
                    x += 1
                    nb *= int(i.lower().strip('x '))
                else:
                    nb *= int(i)
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
                        nb = int(i.lower().strip('x^2 '))
                    else:
                        x -= 2
                        nb /= int(i.lower().strip('x^2 '))
                elif 'x' in i.lower():
                    if ind == 0:
                        x = 1
                        nb = int(i.lower().strip('x '))
                    else:
                        x -= 1
                        nb /= int(i.lower().strip('x '))
                else:
                    if ind == 0:
                        nb = int(i)
                    else:
                        nb /= int(i)
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

def red_x2(expr):
    for exp in expr:
        print('Expr : ', expr)
        if 'x' in exp.lower():
            last_digit = 0
            x = []
            mul_nb = []
            div_nb = []
            for i,e in enumerate(exp.split('*')):
                print('Ee : ', e)
                if e.strip(' ').isdigit():
                    cur_digit = 1
                elif e == '*':
                    op = 1
                elif e == '/':
                    op = 2
                elif e.lower() == 'x':
                    if first_digit:
                        nb = 1
                        x = 1
                        first_digit = 0
                    elif op == 1:
                        x += 1
                    elif op == 2:
                        x -= 1

def red_pow(expr):
    total = 0
    totalx = 0
    to_rm = []
    for i,e in enumerate(expr):
        if '^' in e and not 'x' in e.lower():
            total += pow(int(e.split('^')[0]), int(e.split('^')[1]))
            to_rm.append(i)
        elif '^' in e and 'x' in e.lower() and e.lower().find('x') > e.find('^'):
            totalx += pow(int(e.split('^')[0]), int(e.split('^')[1].lower().strip('x')))
            to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if total:
        expr.append(str(total))
    if totalx:
        expr.append(str(totalx) + 'X')

def res_to_0(expr, res):
    for i,r in enumerate(res):
        expr.append('-' + r)

def chain_red(expr):
    print('Expr to see : ',expr)
    red_add(expr)
    red_sub(expr)
    red_mul(expr)
    print('Expr to see : ',expr)
    red_div(expr)
    red_pow(expr)
    red_ent(expr)
    red_x2(expr)
