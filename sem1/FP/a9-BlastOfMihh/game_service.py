from enum import Enum
from player import Player
# from player import Cell
import random

class GameState(Enum):
    PLAYING=1
    OVER=0

class GameService:
    def __init__(self, rows, cols):
        self._rows=rows
        self._cols=cols
        self._state=GameState.PLAYING
        self._human=Player(rows, cols)
        self._bot=Player(rows, cols)
        self._bot.board.add_plane(0, 0)
        self._bot.board.add_plane(7, 3)
        self._bot.board.add_plane(14, 15)
        self._winner="Undetermined"

    @property
    def human(self):
        return self._human
    @property
    def winner(self):
        return self._winner

    def attack_player(self, player, x, y, attacker):
        if player.board[x][y].head!=None and not player.board[x][y].attacked:
            player.plane_cnt-=1
        player.board[x][y].attack()
        attacker._other_board[x][y]=str(player.board[x][y])

    def make_move(self,x,y):
        self.attack_player(self._bot, x, y, self._human)
        self.attack_player(self._human, random.randint(0, self._rows-1), random.randint(0, self._cols-1), self._bot)
        if self._human.plane_cnt==0:
            self._winner="R0BOT"
        elif self._bot.plane_cnt==0:
            self._winner="Only a human, after all"
        if self._bot.board[x][y].head!=None:
            return "Plane down!"
        if self._bot.board[x][y].occupied!=None:
            return "Hit!"
