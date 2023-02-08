#!/usr/bin/env python3
from random import randint

class Word():
    def __init__(self, word):
        self._word=word
        self._visible=[False]*len(word)
        # self._visible[0]=self._visible[-1]=True
        # self.reveal(self._word[0])
        # self.reveal(self._word[-1])

    def reaveal(self, letter):
        for i in range(len(word)):
            l=self._word[i]
            if l==letter:
                visible[i]=True

    def __str__(self):
        ans=""
        for i in range(len(word)):
            l=self._word[i]
            if visible[i]:
                ans+=l
            else:
                ans+="_"
        return ans
        # return self._word


class Sentence():
    def __init__(self, phrase):
        # self._phrase=phrase
        tkns=phrase.split()
        self._words=[Word(tkns[i]) for i in range(len(tkns))]

    def reaveal(self, letter):
        for w in self._words:
            for w2 in self._words:
                w2.reveal(str(w)[0])
                w2.reveal(str(w)[-1])


class Game():


    def reveal(self, letter):
        self._sentence.reveal(letter)

    def __init__(self, repo):
        self._repo=repo
        all=self._repo.get_all()
        self._sentence=Sentence(all[randint(0, len(all)-1)])

    def __str__(self):
        return self._sentence

    def _check_phrase(self, phrase):
        try:
            pass
            assert type(phrase)==str
            tkns = phrase.split()
            assert len(tkns)>=3
            for t in tkns:
                assert len(t)>=3
        except:
            return False
        return True

    def add_phrase(self, phrase):
        if not self._check_phrase(phrase):
            raise ValueError("Ivalid phrase !!!")
        if self._repo.find(phrase):
            raise ValueError("This phrase already exists")
        self._repo.add(phrase)
