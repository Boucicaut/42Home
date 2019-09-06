#___________ RED DIV AVEC X
def red_divx(expr):
    to_rm = []
    den = []
    num = []
    for i, e in enumerate(expr):
        if '/' in e.lower() and 'x' in e.lower(): #count '/' and not '*' ?
            num.append(e.split('/', 1)[0].strip())
            den.append(e.split('/', 1)[1].strip())
            to_rm.append(i)
    #chain_red(den)
    #chain_red(num)
    print("First DEN : ", den)
    print("First NUM : ", num)
    den, num = common_den(den, num)
    for i in sorted(to_rm)[::-1]:
        expr.pop(i)
    #chain_red(den)
    #chain_red(num)
    print("DEN : ", den)
    print("NUM : ", num)
    save = 0
    x = 0
    for i,n in enumerate(num):
        nb = 1
        for j in n.split('*'):
            if 'x^2' in j.lower():
                x += 2
            elif 'x' in j.lower():
                x += 1
            else:
                nb *= float(j.strip())
        save += nb
    if x == 0:
        expr.append(str(save) + ' / ' + den[0])
    elif x == 1:
        expr.append(str(save) + '* x' + ' / ' + den[0])
    elif x == 2:
        expr.append(str(save) + '* x^2' + ' / ' + den[0])

def find_com_ent(ent):
    if len(set(ent)) == 1:
        return ent[0]
    ent = sorted(ent)[::-1]
    print('Findcoment : ',ent)
    nb = ent[0]
    for i in ent[1:]:
        if nb % i != 0:
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
        if i.lower().strip().startswith('x'):
            den_ent.append(1)
        else:
            den_ent.append(int(i.lower().split('*')[0].strip()))
    print('Den_ent : ',den_ent, 'XMISS : ',x_miss)
    vl = find_com_ent(den_ent)
    print('Com_ent vl : ',vl)
    for ind,(i,j) in enumerate(zip(den,num)):
        if i.lower().strip().startswith('x'):
            new = 1
        else:
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
            den[ind] += (' * ' + str(new) + ' * X')
            num[ind] += (' * ' + str(new) + ' * X')
        else:
            den[ind] += (' * ' + str(new) + ' * X^2')
            num[ind] += (' * ' + str(new) + ' * X^2')
    return den, num

