import copy

def generate_scores(anses, k=0, a=[0]*4, one_used=False):
    """
    A recursive function that generates the possible score for the game PRONOSCORE
    :param anses: the list that contains the scores that are being generated
    """
    if k==len(a):
        anses.append(copy.deepcopy(a))
        return
    for val in [1, 'X', 2]:
        if val!='X' or k<len(a)-1:
            a[k]=val
            if val==1 and one_used:
                continue
            if val==1:
                generate_scores(anses, k+1, a, True)
            else:
                generate_scores(anses, k+1, a, one_used)

def main():
    anses=[]
    generate_scores(anses)
    print("The genereated scores for the player at PRONOSPORT are the following:")
    for l in anses:
        print(l)
main()