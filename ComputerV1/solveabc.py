# -*- encoding=utf8 -*-

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
