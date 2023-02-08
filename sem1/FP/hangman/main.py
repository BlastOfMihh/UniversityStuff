from ui import UI
from ui import PlayUI
from repo import FileRepo
from game import Game
import test
import unittest

# unittest.main()

ui=UI(PlayUI(), Game(FileRepo()))
ui.main()
