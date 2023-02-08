import copy

def generate_scores():
    """
    An iterative function that generates the possible score for the game PRONOSCORE
    :return anses: the list that contains the scores that are being generated
    """
    anses=[]
    values=[1,'X',2]
    for v1 in values:
        for v2 in values:
            for v3 in values:
                for v4 in [1,2]:
                    pos_ans=[v1,v2,v3,v4]
                    nr_ones=0
                    for i in range(0,4):
                        if pos_ans[i]==1:
                            nr_ones+=1
                    if nr_ones==1:
                        anses.append(pos_ans)
    return anses

def main():
    anses=generate_scores()
    print("The genereated scores for the player at PRONOSPORT are the following:")
    for l in anses:
        print(l)
main()
