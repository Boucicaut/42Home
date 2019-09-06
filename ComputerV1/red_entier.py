# -*- encoding=utf8 -*-

import math
import re
from functools import reduce
from operator import mul
import itertools
from red_divx import *

#regex to identify float number
isfloat = re.compile('^\d+(\.\d+)?$')

def red_add(expr):
    ''' Reduit les entiers simples de l'equation. Les supprime et ajoute
    la somme a la fin de la liste en place. '''
    print('BEFORE CALL ADD :',expr)
    if len(expr) == 1:
        print('AFTER CALL ADD Len 1 so ntohghing')
        return
    to_rm = []
    total = 0
    for i,ex in enumerate(expr):
        if isfloat.match(ex.strip('+- ')) != None:# or ex.startswith('-'):
            total += float(ex)
            to_rm.append(i)
    nb_rm = 0
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if total != 0:
        expr.append(str(total))
    print('AFTER CALL ADD :',expr)

def red_sub(expr):
    print('BEFORE CALL SUB :',expr)
    to_rm = []
    #this part split the sub
    sub = []
    for ind,i in enumerate(expr):
        if '- ' in i:
            sub.append(i.split('- '))
            to_rm.append(ind)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    for i in sub:
        print('Sub in sub : ',sub)
        for ind,j in enumerate(i):
            print('J before red : ',j)
            j = split_expr_red(j)
            print('J red : ',j)
            if len(j.strip()) and ind == 0:
                expr.append(j.strip())
            elif len(j.strip()):
                if not j.startswith('-'):
                    expr.append('-' + j.strip())
                else:
                    expr.append(j.strip(' -'))
                print('J strip : ',j)
    print('AFTER CALL SUB :',expr)

def red_ent(expr_liste):
    ''' Reduit entiers de la liste en place'''
    print('BEFORE CALL ENT :',expr_liste)
    total = 0
    to_rm = []
    for i,e in enumerate(expr_liste):
        if isfloat.match(e.strip('-+')):
            total += float(e)
            to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr_liste.pop(i)
    if total != 0:
        expr_liste.append(str(total))
    print('AFTER CALL ENT :',expr_liste)

def red_mul(expr):
    print('BEFORE CALL MUL :',expr)
    total = 0
    to_rm = []
    for i,e in enumerate(expr):
        subtotal = 0
        if '*' in e and not 'x' in e.lower() and not '/' in e:
           new_e = e.split('*')
           new_e = split_expr_red(new_e)
           new_e = list(map(float,new_e))
           subtotal = reduce(mul,new_e)
           to_rm.append(i)
        total += subtotal
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if total:
        expr.append(str(total))
    print('AFTER CALL MUL :',expr)

def red_div(expr):
    print('BEFORE CALL DIV :',expr)
    nb = []
    to_rm = []
    for i,e in enumerate(expr):
        if '/' in e and not 'x' in e.lower() and not '*' in e:
           nb.append(e)
           to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    total = 0
    for i in nb:
        curr = 0
        i = i.split('/')
        for ind,j in enumerate(i):
            j = split_expr_red(j)
            if ind == 0:
                curr = float(j.strip())
            else:
                curr /= float(j.strip())
        total += curr
    if total:
        expr.append(str(float(total)))
    print('AFTER CALL DIV :',expr)

def red_pow(expr):
    print('BEFORE CALL POW :',expr)
    total = 0
    totalx = 0
    to_rm = []
    for i,e in enumerate(expr):
        if '^' in e and not 'x' in e.lower() and not '/' in e and not '*' in e:
            total += pow(float(e.split('^')[0]), float(e.split('^')[1]))
            to_rm.append(i)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if total:
        expr.append(str(total))
    if totalx:
        expr.append(str(totalx) + 'X')
    print('AFTER CALL POW :',expr)

def red_multiple_div_mul(expr):
    print('BEFORE CALL RED_MUL_DIV :',expr)
    pattern = re.compile(r'([\*\/])')
    #print('EXPR in div-mul : ',expr)
    to_rm = []
    big_total = 0
    for ind, e in enumerate(expr):
        total = 0
        if '/' in e and '*' in e and 'x' not in e.lower():
            to_rm.append(ind)
            exp = re.split(pattern, e)
            print('E inside ok : ',exp)
            nb = ''
            op = ''
            for i,e in enumerate(exp):
                #print('\n\t\tTour : ',i,'\tNb : ',nb,'\tOp : ',op,'\tTotal et big : ',total,'||',big_total,'\n')
                if '*' not in e and '/' not in e:
                    #print('E to red : ',e)
                    nb = split_expr_red(e)
                else:
                    op = e.strip()
                #print("OP = ",op,'\tNb : ',nb,'\tTotal : ',total)
                if op == '' and nb != '':
                    total = float(nb)
                elif op == '*' and nb != '':
                    total *= float(nb)
                elif op == '/' and nb != '':
                    total /= float(nb)
                else:
                    print('GROS BUG RED MULTIPLE DIV MUL')
                nb = ''
        big_total += total
        #print('BiiiG TOTAL : ',big_total)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    if big_total != 0:
        expr.append(str(big_total))
    print('AFTER CALL RED_MUL_DIV :',expr)

def split_expr_red(expr):
    to_ret = []
    if type(expr) == list:
        for i in expr:
            i = [i]
            red_entier_all(i)
            to_ret += i
        return to_ret
    expr = [expr]
    red_entier_all(expr)
    expr = "".join(expr)
    return expr


def red_entier_all(expr):
    red_add(expr)
    red_sub(expr)
    red_div(expr)
    red_mul(expr)
    red_pow(expr)
    red_multiple_div_mul(expr)
    #red_ent(expr) no it does + ///  same shit as red_add ?
